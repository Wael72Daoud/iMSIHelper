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
#include "WMIClassesInfo.h"
#include "wmiClassesData.h"


wmiClassesData::wmiClassesData()
{
}


//-----------------------------------------------------------------------
//	   getWMI_Info() get a list of WMI Classes Information 
//-----------------------------------------------------------------------
ClassInfo_list wmiClassesData::getWMI_Info()
{

	return m_listOfWMIInfo;

}

//-----------------------------------------------------------------------
// 	  setWMI_Info() set a list of WMI classes data
//-----------------------------------------------------------------------

void wmiClassesData::setWMI_Info()
{

	WMIClassesInfo _wmiClassInfo;
	

	
	_wmiClassInfo.setAlias(L"CPU");
	_wmiClassInfo.setClass(L"WIN32_PROCESSOR");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Name",
	L"ProcessorId",
	L"SocketDesignation",
	L"Revision",
	L"NumberOfLogicalProcessors",
	L"NumberOfCores"
	});

	m_listOfWMIInfo.push_back(_wmiClassInfo);

	_wmiClassInfo.setAlias(L"SCSICONTROLLER");
	_wmiClassInfo.setClass(L"Win32_SCSIController");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Caption",
	L"Description",
	L"DeviceID",
	L"PNPDeviceID",
	L"Availability"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);

	
	_wmiClassInfo.setAlias(L"OS");
	_wmiClassInfo.setClass(L"Win32_ComputerSystem");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Name",
	L"HypervisorPresent",
	L"PartOfDomain",
	L"PrimaryOwnerName",
	L"UserName",
	L"TotalPhysicalMemory",
	L"Workgroup",
	L"UserName"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);


	_wmiClassInfo.setAlias(L"NIC");
	_wmiClassInfo.setClass(L"Win32_NetworkAdapter");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Name",
	L"AdapterType",
	L"MACAddress",
	L"PNPDeviceID",
	L"Speed"
	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);


	_wmiClassInfo.setAlias(L"BASEBOARD");
	_wmiClassInfo.setClass(L"Win32_BaseBoard");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Name"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);


	_wmiClassInfo.setAlias(L"PRINTER");
	_wmiClassInfo.setClass(L"Win32_Printer");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Caption",
	L"DeviceID",
	L"PrintProcessor",
	L"ShareName"
	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);



	_wmiClassInfo.setAlias(L"BOOTCONFIG");
	_wmiClassInfo.setClass(L"WIN32_PROCESSOR");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Caption",
	L"BootDirectory"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);



	_wmiClassInfo.setAlias(L"CSPRODUCT");
	_wmiClassInfo.setClass(L"Win32_ComputerSystemProduct");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"UUID"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);


	_wmiClassInfo.setAlias(L"BIOS");
	_wmiClassInfo.setClass(L"Win32_BIOS");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"BIOSVersion",
	L"Manufacturer",
	L"SMBIOSBIOSVersion",
	L"SMBIOSMajorVersion",
	L"SMBIOSMinorVersion"


	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);

	_wmiClassInfo.setAlias(L"SOUNDDEV");
	_wmiClassInfo.setClass(L"WIN32_SoundDevice");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Caption",
	L"DeviceID"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);

	_wmiClassInfo.setAlias(L"VOLUME");
	_wmiClassInfo.setClass(L"Win32_Volume");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"SerialNumber",
	L"DeviceID",
	L"Caption"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);

	_wmiClassInfo.setAlias(L"ONBOARDDEVICE");
	_wmiClassInfo.setClass(L"Win32_OnBoardDevice");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Description",
	L"DeviceType"
	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);

	_wmiClassInfo.setAlias(L"SYSTEMSLOT");
	_wmiClassInfo.setClass(L"Win32_SystemSlot");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"SlotDesignation"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);

	_wmiClassInfo.setAlias(L"VOLTAGE");
	_wmiClassInfo.setClass(L"Win32_VoltageProbe");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Name"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);

	
	_wmiClassInfo.setAlias(L"DISPLAY");
	_wmiClassInfo.setClass(L"Win32_VideoController");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
	L"Name",
	L"DriverVersion",
	L"PNPDeviceID",
	L"DeviceID",
	L"InstalledDisplayDrivers",
	L"DriverDate",
	L"CurrentVerticalResolution",
	L"CurrentHorizontalResolution",
	L"CurrentNumberOfColors",
	L"AdapterRAM" 
	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);


	_wmiClassInfo.setAlias(L"MONITOR");
	_wmiClassInfo.setClass(L"WMIMonitorID");
	_wmiClassInfo.setNameSpace(L"ROOT\\wmi");
	_wmiClassInfo.setPropList(
	{
	L"InstanceName",
	L"Active"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);


	_wmiClassInfo.setAlias(L"BATTERY");
	_wmiClassInfo.setClass(L"Win32_Battery");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
		L"Availability",
		L"Status",
		L"SystemName",
		L"StatusInfo",
		L"SmartBatteryVersion",
		L"Caption",
		L"BatteryStatus",
		L"BatteryRechargeTime"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);

	_wmiClassInfo.setAlias(L"PNP");
	_wmiClassInfo.setClass(L"Win32_PnPEntity");
	_wmiClassInfo.setNameSpace(L"ROOT\\CIMV2");
	_wmiClassInfo.setPropList(
	{
		L"Name",
		L"DeviceID",
		L"Service"

	});
	m_listOfWMIInfo.push_back(_wmiClassInfo);

	

	if (m_listOfWMIInfo.size() < 1)
	{
	_wmiClassInfo.setAlias(L"NO_VALUE");
	_wmiClassInfo.setClass(L"NO_VALUE");
	_wmiClassInfo.setNameSpace(L"NO_VALUE");
	_wmiClassInfo.setPropList({ _T("NO_VALUE") });
	}

	
}


wmiClassesData::~wmiClassesData()
{
}
