/*
* Copyright (C) 2015 - 2023  Wael Daoud (wael.daoud@hotmail.com)
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
#include "ClassTranslator.h"





ClassTranslator::ClassTranslator(__in MSIHANDLE hinstall) : hinstall(hinstall)
{

}


//-------------------------------------------------------------------------------------------------------------------
//  ::getRevisedCol( WMI_ALIASES_MAP AliasCol, WMI_ALIASES_MAP& revisedList) - get a collection of allowed Aliases
//-------------------------------------------------------------------------------------------------------------------
UINT ClassTranslator::getRevisedCol(__in WMI_ALIASES_MAP AliasCol, __out WMI_ALIASES_MAP& revisedCol)
{
	::logger logger(this->hinstall);

	logger.log(Loglevel::DEBUG,L"start function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	
	if (AliasCol.size() < 1)
	{
		logger.log(Loglevel::ERR,L"user data collection has no data : [%ls:%d]", __FUNCTIONW__, __LINE__);
		return S_FALSE;
	}
	
	ClassInfo_list m_classesInfoList = getClassesList();

	if (m_classesInfoList.size() < 1)
	{
		logger.log(Loglevel::ERR,L"assigned aliases list has no data : [%ls:%d]", __FUNCTIONW__, __LINE__);
		return S_FALSE;

	}

	
	logger.log(Loglevel::DEBUG, L" Aliases collection contains (%d) item(s) : [%ls:%d]", AliasCol.size() , __FUNCTIONW__, __LINE__);

		
	for (WMI_ALIASES_MAP::iterator userSelectedCol = AliasCol.begin(); userSelectedCol != AliasCol.end(); userSelectedCol++)
	{
		logger.log(Loglevel::INFO, L"retrieving a list of revised collection for (%d) : [%ls:%d]", userSelectedCol->first.size(), __FUNCTIONW__, __LINE__);

		   //add all assignd properties to the revised collection
		std::vector<int> ::size_type size;
		size = userSelectedCol->second.size();
			if (size < 1)
			{
				
				logger.log(Loglevel::INFO, L"processing the revised collection for (%d) item(s) : [%ls:%d]", m_classesInfoList.size(), __FUNCTIONW__, __LINE__);

				for (ClassInfo_list::iterator allowedList = m_classesInfoList.begin(); allowedList != m_classesInfoList.end(); allowedList++)
				{
					
					if (userSelectedCol->first == allowedList->getAlias())
					{
						logger.log(Loglevel::INFO, L"assigning all the properties to the matching alias (%ls) : [%ls:%d]", 
							userSelectedCol->first.c_str(), __FUNCTIONW__, __LINE__);

						revisedCol.insert(std::pair<WS, value_list>(userSelectedCol->first.c_str(), allowedList->getPropList()));
							
					}
					

				}

				
			}
			else
			{	//adding user selected properties
				
					logger.log(Loglevel::DEBUG, L"assigning user selected properties with: \n class = (%ls) \n PropertiesCount = (%d) : [%ls:%d]"
						, (TCHAR*)userSelectedCol->first.c_str(), userSelectedCol->second.size(), __FUNCTIONW__, __LINE__);

					revisedCol.insert(std::pair<WS, value_list>(userSelectedCol->first.c_str(), userSelectedCol->second));
				
			}
			

	}
	
	
	logger.log(Loglevel::DEBUG, L" filled the revised collection with (%d) item(s) : [%ls:%d]", revisedCol.size(), __FUNCTIONW__, __LINE__);

	if (revisedCol.size() < 1)
	{
		logger.log(Loglevel::ERR, L" collection has (%d) item(s) : [%ls:%d]", revisedCol.size(), __FUNCTIONW__, __LINE__);

		return S_FALSE;
	}
	

		
	logger.log(Loglevel::DEBUG,L"Exit function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	
		return S_OK;
}



//-----------------------------------------------------------------------------------------
//	WMI_ALIASES_MAP ClassTranslator::getClassesCol() -- return collection of data
//-----------------------------------------------------------------------------------------
ClassInfo_list ClassTranslator::getClassesList()
{
	::logger logger(this->hinstall);
	logger.log(Loglevel::DEBUG, L"start function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	std::unique_ptr<wmiClassesData> _classesList(new wmiClassesData());
	
	_classesList->setWMI_Info();	 
	
	logger.log(Loglevel::INFO,L"retrieving properties collection : [%ls:%d]", __FUNCTIONW__, __LINE__);
	logger.log(Loglevel::DEBUG, L"exit function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	return _classesList->getWMI_Info();
	
	
}



ClassTranslator::~ClassTranslator(void)
{
	
	//MsiCloseHandle(this->hinstall);
}
