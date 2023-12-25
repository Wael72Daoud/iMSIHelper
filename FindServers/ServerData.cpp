
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
#include "pch.h"
#include "ServerData.h"


/// <summary>
/// 
/// </summary>
/// <param name=""></param>
ServerData::ServerData(void)
{
}


/// <summary>
/// Translate the platform to 
/// </summary>
/// <param name=""></param>
/// <returns></returns>
LPCWSTR const ServerData::TranslatePlatformID(__in DWORD sv101_platform_id)
{
	LPCWSTR svPlatform_ts = nullptr;

	switch (sv101_platform_id)
	{
	case PLATFORM_ID_DOS:
		svPlatform_ts = L"MS-DOS";
		break;

	case PLATFORM_ID_NT:
		svPlatform_ts = L"Windows NT";
		break;

	case PLATFORM_ID_OS2:
		svPlatform_ts = L"OS/2";
		break;
	case PLATFORM_ID_OSF:
		svPlatform_ts = L"OSF";
		break;
	case PLATFORM_ID_VMS:
		svPlatform_ts = L"VMS";
		
	default:
		break;
	}

	return svPlatform_ts;
}

/// <summary>
/// Translate platform type.
/// </summary>
/// <param name="server_type"></param>
/// <returns></returns>
LPCWSTR const ServerData::TranslatePlatformType(__in DWORD server_type)
{

	LPCWSTR svPlatformType = nullptr;

	switch (server_type)
	{

	case SV_TYPE_WORKSTATION:
		svPlatformType = L"Workstation";
	break;
	
	case SV_TYPE_SERVER:
		svPlatformType = L"Server";
		break;

	case SV_TYPE_SQLSERVER:
		svPlatformType = L"Microsoft SQL Server";
		break;

	case SV_TYPE_DOMAIN_CTRL:
		svPlatformType = L"Primary domain controller";
		break;

	case SV_TYPE_DOMAIN_BAKCTRL:
		svPlatformType = L"Backup domain controller";
		break;

	case SV_TYPE_TIME_SOURCE:
		svPlatformType = L"Timesource service";
		break;

	case SV_TYPE_AFP:
		svPlatformType = L"Apple Filing Protocol(AFP)";
		break;

	case SV_TYPE_NOVELL:
		svPlatformType = L"Novell";
		break;

	case SV_TYPE_DOMAIN_MEMBER:
		svPlatformType = L"LAN Manager 2.x domain";
		break;

	case SV_TYPE_PRINTQ_SERVER:
		svPlatformType = L"Print Queue Server";
		break;

	case SV_TYPE_DIALIN_SERVER:
		svPlatformType = L"Dial-in Service Server";
		break;

	case SV_TYPE_XENIX_SERVER:
		svPlatformType = L"Unix Server";
		break;

	/*case SV_TYPE_SERVER_UNIX:
		svPlatformType = L"";
		break;*/

	case SV_TYPE_NT:
		svPlatformType = L"Windows Workstation";
		break;
	
	case SV_TYPE_WFW:
		svPlatformType = L"Windows for Workgroups";
		break;

	case SV_TYPE_SERVER_MFPN:
		svPlatformType = L"Microsoft File and Print for NetWare service";
		break;

	case SV_TYPE_SERVER_NT:
		svPlatformType = L"Not a domain controller";
		break;

	case SV_TYPE_POTENTIAL_BROWSER:
		svPlatformType = L"Browser service";
		break;

	case SV_TYPE_BACKUP_BROWSER:
		svPlatformType = L"Browser service as backup";
		break;

	case SV_TYPE_MASTER_BROWSER:
		svPlatformType = L"Master browser service";
		break;

	case SV_TYPE_DOMAIN_MASTER:
		svPlatformType = L"Domain master browser";
		break;

	case SV_TYPE_SERVER_OSF:
		svPlatformType = L"OSF Pltafrom Server";
		break;

	case SV_TYPE_SERVER_VMS:
		svPlatformType = L"VMS";
		break;

	case SV_TYPE_WINDOWS:
		svPlatformType = L"Windows";
		break;

	case SV_TYPE_ALL:
		svPlatformType = L"";
		break;

	case SV_TYPE_DFS:
		svPlatformType = L"DFS";
		break;

	case SV_TYPE_CLUSTER_NT:
		svPlatformType = L"Cluster";
		break;

	case SV_TYPE_TERMINALSERVER:
		svPlatformType = L"Terminal";
		break;

	case SV_TYPE_CLUSTER_VS_NT:
		svPlatformType = L"Cluster virtual";
		break;

	case SV_TYPE_DCE:
		svPlatformType = L"Directory and Security";
		break;

	case SV_TYPE_ALTERNATE_XPORT:
		svPlatformType = L"Alternate transport";
		break;

	case SV_TYPE_LOCAL_LIST_ONLY:
		svPlatformType = L"Browser";
		break;

	case SV_TYPE_DOMAIN_ENUM:
		svPlatformType = L"Domain";
		break;
	
	default:
		break;
	}

	return svPlatformType;
}

