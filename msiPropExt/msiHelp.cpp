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



msiHelp::msiHelp(__in MSIHANDLE hModule) : hinstall(hModule)
{
	

}


//-------------------------------------------------------------------------------------------------------
//	getMSIProperty(__in MSIHANDLE, __in TCHAR*, __out ::WS&) -- simple method to set MSI Property
//-------------------------------------------------------------------------------------------------------
UINT msiHelp::getMSIProperty(__in const TCHAR* PropertyName, __out ::WS &PropertyValue)
{
	
	TCHAR* valueBuff = NULL;
	DWORD ccvalBuff = 0;
	
	
	::logger logger(this->hinstall);
	logger.log(Loglevel::DEBUG, L"start function : [%ls:%d]", __FUNCTIONW__, __LINE__);

	logger.log(Loglevel::INFO,L"getting a MSI property Name=%ls : [%ls:%d]", PropertyName, __FUNCTIONW__, __LINE__);

	

		UINT uistat = MsiGetProperty(this->hinstall, PropertyName, _T(""), &ccvalBuff);
		if (ERROR_MORE_DATA == uistat)
		{
			++ccvalBuff;
			valueBuff = new TCHAR[ccvalBuff];
			if (valueBuff)
			{

				if (ERROR_SUCCESS == MsiGetProperty(this->hinstall, PropertyName, valueBuff, &ccvalBuff))
				{
					::WS strPropertyValue((LPTSTR)valueBuff);
					logger.log(Loglevel::INFO,L"getting MSI valueBuff (%ls) : [%ls:%d]", valueBuff, __FUNCTIONW__, __LINE__);

					PropertyValue = strPropertyValue;
					logger.log(Loglevel::INFO,L"getting  MSI value=%ls : [%ls:%d]", strPropertyValue.c_str(), __FUNCTIONW__, __LINE__);
				}
				else
				{
					logger.log(Loglevel::ERR,L"fatal error (%d), %ls:%d",GetLastError(), __FUNCTIONW__, __LINE__);
					if (valueBuff!=NULL)
						delete[] valueBuff;
					
					return MSIDBERROR_BADPROPERTY;

				}

			}
		}
	


		delete[] valueBuff;
	
		
		logger.log(Loglevel::DEBUG,L"Exit function : [%ls:%d]", __FUNCTIONW__, __LINE__);


	return ERROR_SUCCESS;	
}

//-------------------------------------------------------------------------------------------------------
//	setMSIProperty(__in MSIHANDLE, __in ::WS, __in ::WS) -- simple method to set MSI Property
//-------------------------------------------------------------------------------------------------------
UINT msiHelp::setMSIProperty(__in ::WS PropertyName, __in ::WS PropertyValue)
{
	::logger logger(this->hinstall);
	logger.log(Loglevel::DEBUG, L"info function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	//LPCTSTR m_PropertyName = PropertyName.c_str();
	//LPCTSTR m_PropertyVal = PropertyValue.c_str();

	//if (ERROR_SUCCESS != ::MsiSetProperty(hinstall, m_PropertyName, m_PropertyVal))
	if (ERROR_SUCCESS != ::MsiSetProperty(hinstall, PropertyName.c_str(), PropertyValue.c_str()))
	{
		logger.log(Loglevel::ERR,L"failed to set property name (%ls) with (%ls) value : [%ls:%d]", PropertyName.c_str(), 
			PropertyValue.c_str(), __FUNCTIONW__, __LINE__);
		return ERROR_INSTALL_FAILURE;
	}
	else
	{
		logger.log(Loglevel::INFO, LR"(successfull setting new public property value %ls=%ls : [%ls:%d])", PropertyName.c_str(),
			PropertyValue.c_str() , __FUNCTIONW__, __LINE__);
	}

	logger.log(Loglevel::DEBUG, L"Exit function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	return ERROR_SUCCESS;
}


msiHelp::~msiHelp()
{
	
}
