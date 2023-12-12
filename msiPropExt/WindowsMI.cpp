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
#include "Err.h"
#include "utils.h"
#include "WindowsMI.h"



WindowsMI::WindowsMI(MSIHANDLE hInstall) :Namespace(_T("ROOT\\CIMV2")), WindowsMI_Data(NULL), WMI_PropertyName(NULL),
WMI_ClassQuery(NULL), m_pSvc(NULL), m_pLoc(NULL), m_pclsObj(NULL), m_hInstall(hInstall)
{

}


//----------------------------------------------------------------------------------------
//	 HRESULT WindowsMI::getHandle() - return a COM Handle
//----------------------------------------------------------------------------------------

HRESULT WindowsMI::getHandle()
{

	return this->m_hInstall;
}

//----------------------------------------------------------------------------------------
//	  WindowsMI::setHandle(HRESULT hres) - set COM handle
//----------------------------------------------------------------------------------------
void WindowsMI::setHandle(HRESULT hres)
{

	this->m_hres = hres;

}

//----------------------------------------------------------------------------------------
//		 DWORD WindowsMI::init() - Initalize COM
//----------------------------------------------------------------------------------------
DWORD WindowsMI::init()
{
	
	logger logger(this->m_hInstall);
	logger.log(Loglevel::DEBUG,L"start function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	Err _err;
	this->m_hres = getHandle();
	
	
	this->m_hres = CoCreateInstance(
		CLSID_WbemLocator,
		0,
		CLSCTX_INPROC_SERVER,
		IID_IWbemLocator, (LPVOID *)&m_pLoc);

		
	
	if (FAILED(this->m_hres))
	{
		CoUninitialize();

		logger.log(Loglevel::ERR, L"Failed to instaniate the WMI object (%lx) : [%ls:%d]", this->m_hres, __FUNCTIONW__, __LINE__);
		logger.log(Loglevel::DEBUG, L"Failed to CoCreateInstance() (%lx) : [%ls:%d]", this->m_hres, __FUNCTIONW__, __LINE__);


		return S_FALSE;                 // Program has failed.
	}


	// Connect IWbemLocator::ConnectServer method		

	if (this->Namespace == nullptr)
	{	
		CoUninitialize();
		logger.log(Loglevel::ERR,L"no NameSpace assigned : [%ls:%d]", __FUNCTIONW__, __LINE__);
		return S_FALSE;
	}
	

	logger.log(Loglevel::INFO,L"NameSpace assigned (%ls) : [%ls:%d]", Namespace, __FUNCTIONW__, __LINE__);

	// and obtain pointer pSvc to make IWbemServices calls.
	this->m_hres = m_pLoc->ConnectServer(
		_bstr_t(Namespace),
		NULL,
		NULL,
		0,
		NULL,
		0,
		0,
		&this->m_pSvc
		);


	this->m_ErrHandle = _err.ErrorToString(m_hres);
	
	if (FAILED(this->m_hres))
	{
		CoUninitialize();
		
		logger.log(Loglevel::DEBUG, L"failed to execute query: \n HResult = (%lx) \n Error = (%ls)  \n Data = (%ls) \n Namespace = (%ls) \n PropertyName = (%ls), : [%ls:%d]",
			this->m_hres, this->m_ErrHandle.c_str(), (TCHAR*) this->WMI_ClassQuery.m_str, this->Namespace,
			this->WMI_PropertyName, __FUNCTIONW__, __LINE__);

		logger.log(Loglevel::ERR, L"Connection to IWbem had failed (%lx) : [%ls:%d]", this->m_hres, __FUNCTIONW__, __LINE__);

		return S_FALSE;                // Program has failed.
	}


	// Set security levels for the proxy ------------------------

	this->m_hres = CoSetProxyBlanket(
		m_pSvc,                        // Indicates the proxy to set
		RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx 
		RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx 
		NULL,                        // Server principal name 
		RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx 
		RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
		NULL,                        // client identity
		EOAC_NONE                    // proxy capabilities 
		);

		

	if (FAILED(this->m_hres))
	{
		CoUninitialize();
		logger.log(Loglevel::DEBUG, L"Failed to CoSetProxyBlanket() (%lx) for namespace(%s) : [%ls:%d]"
			, this->m_hres, Namespace, __FUNCTIONW__, __LINE__);

		logger.log(Loglevel::ERR, L"Failed to set RPC security (%lx) : [%ls:%d]", this->m_hres, __FUNCTIONW__, __LINE__);
		return S_FALSE;               // Program has failed.
	}

	return S_OK;
}


//---------------------------------------------------------------------------
//	 UINT WindowsMI::Execute(__out) -- exeucte and return list of names values
//---------------------------------------------------------------------------
UINT WindowsMI::Execute()
{
	
	logger logger(this->m_hInstall);
	logger.log(Loglevel::DEBUG,L"start function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	utils _utils;
	Err _err;
	
	CComBSTR QueryLang = "WQL";		

	if (this->WMI_ClassQuery.m_str == NULL)
	{

		logger.log(Loglevel::DEBUG, L"fatal error, value for WMI_ClassQuery=%s : [%ls:%d]",
			(TCHAR*)this->WMI_ClassQuery.m_str, __FUNCTIONW__, __LINE__);

		logger.log(Loglevel::ERR,L"fatal error, no available query statement : [%ls:%d]", __FUNCTIONW__, __LINE__);
		
		return S_FALSE;
	}
	logger.log(Loglevel::INFO,L"executing query (%ls)  : [%ls:%d]", (TCHAR*) this->WMI_ClassQuery.m_str, __FUNCTIONW__, __LINE__);
	
	m_hres = m_pSvc->ExecQuery(
		QueryLang, this->WMI_ClassQuery,
		WBEM_FLAG_FORWARD_ONLY,
		NULL,
		&m_pEnumerator);

	
	this->m_ErrHandle = _err.ErrorToString(m_hres);


	if (FAILED(m_hres))
	{
		logger.log(Loglevel::DEBUG, L"failed to execute query: \n HResult = (%lx) \n Error = (%ls)  \n Data = (%ls) \n Namespace = (%ls) \n PropertyName = (%ls), : [%ls:%d]",
			m_hres, this->m_ErrHandle.c_str(), (TCHAR*) this->WMI_ClassQuery.m_str, this->Namespace,
			this->WMI_PropertyName, __FUNCTIONW__, __LINE__);


		logger.log(Loglevel::ERR, L"failed to execute query (%ls) (%lx) : [%ls:%d]", this->m_ErrHandle.c_str(), m_hres, __FUNCTIONW__, __LINE__);
		return S_FALSE;               // Program has failed.
		
	}

	logger.log(Loglevel::DEBUG,L"Exit function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	return S_OK;
}


//------------------------------------------------------------------------------------------------
//	WindowsMI::getPropertyValues(__out  value_list& data) - get list of queried data values
//------------------------------------------------------------------------------------------------

UINT WindowsMI::getPropertyValues(__out  value_list& data)
{
	logger logger(this->m_hInstall);
	logger.log(Loglevel::DEBUG,L"start function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	ULONG uReturn = 0;
	CComVariant vtProp;
	WS strDataValue;
	utils _utils;
	Err _err;


		if (WMI_PropertyName == NULL)
		{

			logger.log(Loglevel::DEBUG, L"failed to execute query: \n Error = (%ls)  \n Data = (%ls) \n Namespace = (%ls) \n PropertyName = (%ls), : [%ls:%d]",
				this->m_ErrHandle.c_str(), (TCHAR*) this->WMI_ClassQuery.m_str, this->Namespace,
				this->WMI_PropertyName, __FUNCTIONW__, __LINE__);

			logger.log(Loglevel::ERR,L"Query data not found : [%ls:%d]", __FUNCTIONW__, __LINE__);	   			
			return S_FALSE;
		}

		VariantInit(&vtProp);
		while (m_pEnumerator)
		{

			HRESULT hr = m_pEnumerator->Next(WBEM_INFINITE, 1,
				&m_pclsObj, &uReturn);

			if (0 == uReturn)
			{
				logger.log(Loglevel::INFO,L"done retrieving all available data : [%ls:%d]", __FUNCTIONW__, __LINE__);
				
				break;
			}

			if (SUCCEEDED(hr))
			{
				
				logger.log(Loglevel::INFO,L"retrieving data for (%ls) property : [%ls:%d]", WMI_PropertyName, __FUNCTIONW__, __LINE__);
				// Get the value of the Name property

				hr = m_pclsObj->Get(WMI_PropertyName, 0, &vtProp, 0, 0);

				WS strError = 	_err.ErrorToString(hr);
				
				if (WBEM_S_NO_ERROR == hr)
				{
					_utils.VariantToString(vtProp, strDataValue);
					data.push_back(strDataValue);

					logger.log(Loglevel::INFO, L"getting property values list (%ls) : [%ls:%d]", strDataValue.c_str(), __FUNCTIONW__, __LINE__);
														  
				}
				else 
				{
					logger.log(Loglevel::DEBUG, L"failed to execute query: \n HResult = (%lx) \n Error = (%ls)  \n Data = (%ls) \n Namespace = (%ls) \n PropertyName = (%ls), : [%ls:%d]",
						hr, this->m_ErrHandle.c_str(), (TCHAR*) this->WMI_ClassQuery.m_str, this->Namespace,
						this->WMI_PropertyName, __FUNCTIONW__, __LINE__);

					data.push_back(strError);
					
				}

	
				
			}

		}
	
	VariantClear(&vtProp);
	
	logger.log(Loglevel::DEBUG,L"exit function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	return ERROR_SUCCESS;
}


WindowsMI::~WindowsMI()
{
	m_pSvc->Release();
	m_pclsObj = NULL;
	m_pLoc->Release();
	m_pEnumerator->Release();
	SysFreeString(WMI_ClassQuery);
	CoUninitialize();
}