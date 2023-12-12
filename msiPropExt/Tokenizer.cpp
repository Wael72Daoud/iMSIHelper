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
#include "Tokenizer.h"


Tokenizer::Tokenizer(MSIHANDLE hInstall) : m_hinstall(hInstall)
{
}


//-----------------------------------------------------------------------------------
// WMI_ALIASES_MAP TokenizeDTMFData(__in const std::wstring) - specialized Tokenizer:
// Exmaple: (Alias1:Property1,Property2;Alias2;Alias3)
//-----------------------------------------------------------------------------------
WMI_ALIASES_MAP Tokenizer::getTokenizedData(__in const std::wstring MSIPropertyValue)
{

	::logger logger(this->m_hinstall);
	logger.log(Loglevel::DEBUG, L"start function : [%ls:%d]", __FUNCTIONW__, __LINE__);

	WMI_ALIASES_MAP tokenizedDataMap;
	value_list 	strPropertiesList;
	size_t iNextPosSemiComma = 0;
	size_t iDataSize = MSIPropertyValue.size();
	size_t iPosSemiColon = MSIPropertyValue.find(';');

	while (iPosSemiColon < MSIPropertyValue.size())
	{

		std::wstring strSemiColon = MSIPropertyValue.substr(iNextPosSemiComma, iPosSemiColon - iNextPosSemiComma);

		size_t posColon = strSemiColon.find(':');

		value_list strPropertiesList = TokenizeSubData(strSemiColon, iPosSemiColon);

		if (iPosSemiColon != std::wstring::npos)
		{


			std::wstring strAlias = strSemiColon.substr(0, posColon);

			//logger.log(Loglevel::DEBUG, L"Adding alias token (%ls) : [%ls:%d]",(TCHAR*)strAlias.c_str(), __FUNCTIONW__, __LINE__);
			tokenizedDataMap.insert(std::pair<std::wstring, value_list>(strAlias, strPropertiesList));
			iNextPosSemiComma = ++iPosSemiColon;
			iPosSemiColon = MSIPropertyValue.find(';', iNextPosSemiComma);	

		}


	}
	if (iPosSemiColon > MSIPropertyValue.size())
	{


		std::wstring strSemiColon = MSIPropertyValue.substr(iNextPosSemiComma, MSIPropertyValue.size());
		size_t iPosColon = strSemiColon.find(':');							 		
		strPropertiesList = TokenizeSubData(strSemiColon, iPosColon);
		std::wstring strAlias = strSemiColon.substr(0, iPosColon);

		//logger.log(Loglevel::DEBUG, L"Adding alias token (%ls) : [%ls:%d]", (TCHAR*)strAlias.c_str(), __FUNCTIONW__, __LINE__);
		tokenizedDataMap.insert(std::pair<std::wstring, value_list>(strAlias, strPropertiesList));

	}

	logger.log(Loglevel::DEBUG, L"exit function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	return 	tokenizedDataMap;
}


//-------------------------------------------------------------------------------------------------
//	value_list TokenizeSubDTMFData(std::wstring _DATA, size_t posSemiColon) - specialzed tokenizer
//-------------------------------------------------------------------------------------------------
value_list Tokenizer::TokenizeSubData(std::wstring _DATA, size_t posSemiColon)
{
	::logger logger(this->m_hinstall);
	logger.log(Loglevel::DEBUG, L"start function : [%ls:%d]", __FUNCTIONW__, __LINE__);

	value_list strPropertiesList;
	if (_DATA.find(':') != std::wstring::npos)
	{
		size_t posColon = _DATA.find(':');

		std::wstring strColon = _DATA.substr(posColon + 1, posSemiColon - posColon - 1);

		size_t nextPosComma = 0;
		size_t posComma = strColon.find(',');
		while (posComma != std::wstring::npos)
		{

			{
				std::wstring CommaString = strColon.substr(nextPosComma, posComma - nextPosComma);
				logger.log(Loglevel::DEBUG, L"Adding property token (%ls) : [%ls:%d]", (TCHAR*)CommaString.c_str(), __FUNCTIONW__, __LINE__);
				strPropertiesList.push_back(CommaString);
				nextPosComma = ++posComma;
				posComma = strColon.find(',', nextPosComma);
			}
		}
		if (posComma > strColon.size())
		{
			std::wstring CommaString = strColon.substr(nextPosComma, strColon.size());
			logger.log(Loglevel::DEBUG, L"Adding property token (%ls) : [%ls:%d]", (TCHAR*)CommaString.c_str(), __FUNCTIONW__, __LINE__);
			strPropertiesList.push_back(CommaString);
		}

	}
	logger.log(Loglevel::DEBUG, L"exit function : [%ls:%d]", __FUNCTIONW__, __LINE__);
	return strPropertiesList;
}


Tokenizer::~Tokenizer()
{
}
