/*
* Copyright (C) 2015  Wael Daoud (wael.daoud@hotmail.com)
Microsoft Public License (Ms-PL)

This license governs use of the accompanying software. If you use the software, you accept this license. If you do not accept the license, do not use the software.

1. Definitions

The terms "reproduce," "reproduction," "derivative works," and "distribution" have the same meaning here as under U.S. copyright law.

A "contribution" is the original software, or any additions or changes to the software.

A "contributor" is any person that distributes its contribution under this license.

"Licensed patents" are a contributor's patent claims that read directly on its contribution.

2. Grant of Rights

(A) Copyright Grant- Subject to the terms of this license, including the license conditions and limitations in section 3, each contributor grants you a non-exclusive, worldwide, royalty-free copyright license to reproduce its contribution, prepare derivative works of its contribution, and distribute its contribution or any derivative works that you create.

(B) Patent Grant- Subject to the terms of this license, including the license conditions and limitations in section 3, each contributor grants you a non-exclusive, worldwide, royalty-free license under its licensed patents to make, have made, use, sell, offer for sale, import, and/or otherwise dispose of its contribution in the software or derivative works of the contribution in the software.

3. Conditions and Limitations

(A) No Trademark License- This license does not grant you rights to use any contributors' name, logo, or trademarks.

(B) If you bring a patent claim against any contributor over patents that you claim are infringed by the software, your patent license from such contributor to the software ends automatically.

(C) If you distribute any portion of the software, you must retain all copyright, patent, trademark, and attribution notices that are present in the software.

(D) If you distribute any portion of the software in source code form, you may do so only under this license by including a complete copy of this license with your distribution. If you distribute any portion of the software in compiled or object code form, you may only do so under a license that complies with this license.

(E) The software is licensed "as-is." You bear the risk of using it. The contributors give no express warranties, guarantees or conditions. You may have additional consumer rights under your local laws which this license cannot change. To the extent permitted under your local laws, the contributors exclude the implied warranties of merchantability, fitness for a particular purpose and non-infringement.
*/


#include "stdafx.h"

#include "logger.h"
#include "msiHelp.h"
#include "WindowsMI.h"
#include "WMIClassesInfo.h"
#include "ClassTranslator.h"
#include "Tokenizer.h"
#include <fstream>
#include <iostream>
#include "utils.h"
#include <future>



HRESULT m_hres;

BOOL APIENTRY DllMain(HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	switch (ul_reason_for_call)
	{

	case DLL_PROCESS_ATTACH:
		
		m_hres = CoInitializeEx(0, COINIT_MULTITHREADED);
		if (FAILED(m_hres))
		{
			CoUninitialize();
			
			return S_FALSE;                  // Program has failed.
		}

		break;
	case DLL_THREAD_ATTACH:
		
		break;
	case DLL_THREAD_DETACH:
		
		break;
	case DLL_PROCESS_DETACH:
		
		CoUninitialize();
		break;

	default:
		break;
	}


    return TRUE;
}


/*

	[MSI_PROPERTIES_EXT = VERB1:PROP1,PROP2;VERB2:PROP3,PROP4;VERB3;VERB4]
	[PROP1]
	[PROP2]
	[PROP3]
	[PROP4]
	[PROP8]
	[PROP9]
	...
*/

//------------------------------------------------------------------------------------
//	UINT __stdcall MSIPropertiesExt(MSIHANDLE hInstall) - Installer entry point
//------------------------------------------------------------------------------------
UINT __stdcall MSIPropertiesExt(MSIHANDLE hInstall)
{
	::logger logger(hInstall);
	logger.log(Loglevel::DEBUG, L"start the function - [%ls:%d]", __FUNCTIONW__, __LINE__);

	std::unique_ptr<msiHelp> _msiHelper(new msiHelp(hInstall));
	std::unique_ptr<ClassTranslator> _classTranslator(new ClassTranslator(hInstall));
	std::unique_ptr<WindowsMI> _WindowsMangment(new WindowsMI(hInstall));
	std::unique_ptr<Tokenizer> _tokenizer(new Tokenizer(hInstall));
	utils _utils;
	
	
	_WindowsMangment->setHandle(m_hres);

	WMI_ALIASES_MAP MSIAliasVerbsCol;
	WMI_ALIASES_MAP wmiRevisedCol;

	
	TCHAR* MSI_PROPERTY_EXT = _T("MSIPROPERTYEXT");
	const ::WS PROPERTY_NAME_HEADER = L"WMIEXT_";
	const ::WS WMI_QUERY_STATEMENT = L"select * from";
	
	
	::WS MSI_PROPERTY_EXT_VALUE;
	
		logger.log(Loglevel::INFO,L"retrieve MSI Property MSI_PROPERTY_EXT= %ls - [%ls:%d]", MSI_PROPERTY_EXT,  __FUNCTIONW__, __LINE__);

		if (ERROR_SUCCESS != _msiHelper->getMSIProperty(MSI_PROPERTY_EXT, MSI_PROPERTY_EXT_VALUE))
		{
			logger.log(Loglevel::ERR,L"Fatal error extracting MSI Value %ls:%d ", __FUNCTIONW__, __LINE__);
			return S_FALSE;

		}
		
		logger.log(Loglevel::INFO,L"retrieve MSI Property getRevisedColMSI PROPERTY EXT value=(%ls) - [%ls:%d]", MSI_PROPERTY_EXT_VALUE.c_str(), __FUNCTIONW__, __LINE__);

		//get a collection of tonkenized data 
		MSIAliasVerbsCol = _tokenizer->getTokenizedData(MSI_PROPERTY_EXT_VALUE);
		
	
		//get allowed properties collection
		if (ERROR_SUCCESS != _classTranslator->getRevisedCol(MSIAliasVerbsCol, wmiRevisedCol))
		{

			logger.log(Loglevel::ERR,L"fatal error getting properties from a list of Aliases - [%ls:%d]", __FUNCTIONW__, __LINE__);
			return S_FALSE;
		}

		
		if (_classTranslator->getClassesList().size() < 1)
		{
			logger.log(Loglevel::ERR,L"collection has no assigned aliases : [%ls:%d]", __FUNCTIONW__, __LINE__);
			return S_FALSE;

		}
	
		//return a list of WMI info
		ClassInfo_list classNamesQueryList = _classTranslator->getClassesList();
		
		for (WMI_ALIASES_MAP::iterator revisedData = wmiRevisedCol.begin(); revisedData != wmiRevisedCol.end(); revisedData++)
		{
			logger.log(Loglevel::DEBUG, L"revised Data: \n Alias (%ls) \n properties count (%d) : [%ls:%d]"
				, (TCHAR*)revisedData->first.c_str(), revisedData->second.size(), __FUNCTIONW__, __LINE__);

			
			for (ClassInfo_list::iterator classNameQuery = classNamesQueryList.begin(); classNameQuery != classNamesQueryList.end(); classNameQuery++)
			{
				logger.log(Loglevel::INFO,L"retrieving Aliases name: (%ls) = (%ls) : [%ls:%d]", classNameQuery->getAlias().c_str(), revisedData->first.c_str(), __FUNCTIONW__, __LINE__);

				
				if (revisedData->first == classNameQuery->getAlias())
				{
					logger.log(Loglevel::INFO, L"found a matching alias (%ls) : [%ls:%d]", revisedData->first.c_str(), __FUNCTIONW__, __LINE__);

					
					std::wstring psNameSpace(classNameQuery->getNameSpace().c_str());
					_WindowsMangment->Namespace = (LPWSTR)psNameSpace.c_str();
					logger.log(Loglevel::INFO,L"namespace assigned (%ls) : [%ls:%d]", _WindowsMangment->Namespace, __FUNCTIONW__, __LINE__);



					value_list revisedPropsList = revisedData->second; //getPropList();
					for (value_list::iterator valProperty = revisedPropsList.begin(); valProperty != revisedPropsList.end(); valProperty++)
					{
						
						value_list wmi_data;
						_ASSERT(valProperty == NULL);
						WS strPropertyName(*valProperty);
						_ASSERT(valProperty == NULL);
						logger.log(Loglevel::INFO,L"retrieving propertey (%ls) : [%ls:%d]", strPropertyName.c_str(), __FUNCTIONW__, __LINE__);
						


						WS QuerySelectStatemnt = WMI_QUERY_STATEMENT + L" " + classNameQuery->getClass();

						_WindowsMangment->WMI_ClassQuery = QuerySelectStatemnt.c_str();	

						_WindowsMangment->WMI_PropertyName = (LPWSTR)strPropertyName.c_str();

						// initialization and execution process				
						
						if (ERROR_SUCCESS != _WindowsMangment->init())
						{
							logger.log(Loglevel::ERR,L"failed to inializeing wbem service : [%ls:%d]", __FUNCTIONW__, __LINE__);
							return S_FALSE;
						}
						
						//execute per property
						if (ERROR_SUCCESS != _WindowsMangment->Execute())
						{
							logger.log(Loglevel::ERR,L"failed to exuecute the query : [%ls:%d]", __FUNCTIONW__, __LINE__);
							return S_FALSE;
						}
					
						if (ERROR_SUCCESS != _WindowsMangment->getPropertyValues(wmi_data))
						{
							logger.log(Loglevel::ERR,L"failed to return the query data : [%ls:%d]", __FUNCTIONW__, __LINE__);
							return S_FALSE;
						}

						

						WS PublicPropName;  						
						WS PublicPropValue;
						bool bDilimtedData = false;
						int iDilimterCounter = 0;
						for (value_list::const_iterator data = wmi_data.begin(); data != wmi_data.end(); ++data)
						{
							WS prpertyValueStr(*data);
							logger.log(Loglevel::INFO,L"retrieving properties value list : [%ls:%d]", __FUNCTIONW__, __LINE__);
							//
							PublicPropName = PROPERTY_NAME_HEADER;
							PublicPropName.append(classNameQuery->getAlias());
							PublicPropName.append(L"_");
							PublicPropName.append(strPropertyName);
							
							_utils.ToUpper(PublicPropName);
							
							logger.log(Loglevel::INFO,L"assigning public property name (%ls)  : [%ls:%d]", PublicPropName.c_str(), __FUNCTIONW__, __LINE__);
							
							if (wmi_data.size() > 1)
							{
								bDilimtedData = true;
								iDilimterCounter++;
								if (prpertyValueStr != L"")
								{

									logger.log(Loglevel::DEBUG, L"concatenation operations for new value (%ls) : [%ls:%d]", prpertyValueStr.c_str()
										, __FUNCTIONW__, __LINE__);
									PublicPropValue.append(prpertyValueStr);

									if (iDilimterCounter < wmi_data.size())
										PublicPropValue.append(L",");
								}
								

							}
							else
							{
								PublicPropValue = prpertyValueStr;
								if (ERROR_SUCCESS != _msiHelper->setMSIProperty(PublicPropName, PublicPropValue))
								{
									logger.log(Loglevel::ERR,LR"(failed to set public property (%ls) name with (%ls) value : [%ls:%d])", 
										PublicPropName.c_str(), PublicPropValue.c_str() , __FUNCTIONW__, __LINE__);
									return S_FALSE;
								}
								
							}

							
						}
						if (bDilimtedData)
						{
							if (ERROR_SUCCESS != _msiHelper->setMSIProperty(PublicPropName, PublicPropValue))
							{
								logger.log(Loglevel::ERR,LR"(failed to set public property (%ls) name with (%ls) value : [%ls:%d])",
									PublicPropName.c_str(), PublicPropValue.c_str(), __FUNCTIONW__, __LINE__);
								return S_FALSE;
							}
						}

					}
				}

			}

		}

		logger.log(Loglevel::DEBUG, L"exit the function - [%ls:%d]", __FUNCTIONW__, __LINE__);
	return ERROR_SUCCESS;
}




//---------------------------------------------------------------------------------------------------------------------------
// UnitTest() : should be squenced after MSIPropertiesExt(). the log file will be stored under the current user %TEMP% folder
//---------------------------------------------------------------------------------------------------------------------------
UINT __stdcall UnitTest(MSIHANDLE hInstall)
{
	
	
	::msiHelp _msiHelper(hInstall);
	::ClassTranslator _classTrans(hInstall);
	utils _utils;
	::WS Property_Name_Header_Value;
	::WS UniTestEnabled;
	
	WCHAR tempDir[MAX_PATH];
	int retVal = ::GetTempPath(MAX_PATH, tempDir);
	std::wstring ut_fileName(tempDir);
	ut_fileName.append(L"WMI_unitTest.txt");
	
	if (PathFileExists(ut_fileName.c_str()))
	{
		if (false == DeleteFile(ut_fileName.c_str()))
		{
			int rand_num = std::rand();
			std::wstring ut_fileName(tempDir);
			
			ut_fileName.append(L"WMI_unitTest" + rand_num);
			ut_fileName.append(L".txt");

		}
	}

	_msiHelper.getMSIProperty(_T("MSIWMI_EXT"), UniTestEnabled);

	
	ClassInfo_list classesCol = _classTrans.getClassesList();
	
	
		for (ClassInfo_list::iterator it = classesCol.begin(); it != classesCol.end(); it++)
		{
			
								  
			value_list propertyList = it->getPropList();
			
			std::wofstream fOut;
			
			fOut.open(ut_fileName, std::ios_base::app);
			for (value_list::const_iterator it2 = propertyList.begin(); it2 != propertyList.end(); it2++)
			{
				WS PROPERTY_NAME_HEADER = L"WMIEXT_";
				PROPERTY_NAME_HEADER.append(it->getAlias());
				PROPERTY_NAME_HEADER.append(L"_");

				WS PropertyNameHeader = PROPERTY_NAME_HEADER;				
				PropertyNameHeader.append(*it2);

				
				_utils.ToUpper(PropertyNameHeader);
				_msiHelper.getMSIProperty((TCHAR*)PropertyNameHeader.c_str(), Property_Name_Header_Value);

				if (Property_Name_Header_Value == L"")
					Property_Name_Header_Value = L"";
				
				fOut << PropertyNameHeader;
				fOut << "=";
				fOut << Property_Name_Header_Value;
				fOut << std::endl;
			
				
			}
			fOut.close();
		}
	

	
	return ERROR_SUCCESS;
}

