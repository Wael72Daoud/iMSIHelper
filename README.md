# iMSIHelper
various helpers for core Installation development.

MSI Properties Extender:
-	Extending the Windows Installer public properties list 	(https://msdn.microsoft.com/en-us/library/aa370905%28v=vs.85%29.aspx) with 	devices and hardware attached settings.
- Variety of Aliases per Hardware type, contains many supported properties.
- You can choose from any number of the Hardware types (Aliases below) and you can minimize the list of properties to enhance performance or to get what you really needs.
- The list of Aliases and properties can grow to add new hardware types.
- Ability to retrieve the full list of the hardware on the machine (if machine contains more the display drive, monitor, cpu, etc).
- Example and Samples (See Docs)...



Extender List (a subset):

Alias Name : “CPU"
Properties : 	
			"Name"
			"ProcessorId"
			"SocketDesignation"
			"Revision"
			"NumberOfLogicalProcessors"
			"NumberOfCores"
			

Alias Name :	"SCSICONTROLLER"
Properties :
			"Caption"
			"Description"
			"DeviceID"
			"PNPDeviceID"
			"Availability"


Alias Name :	"OS"
Properties :	
	
			"Name"
			"HypervisorPresent"
			"PartOfDomain"
			"PrimaryOwnerName"
			"UserName"
			"TotalPhysicalMemory"
			"Workgroup"
			"UserName"

	
	

Alias Name :	"NIC"
Properties :	
			"Name"
			"AdapterType"
			"MACAddress"
			"PNPDeviceID"
			"Speed"

Alias Name :	"BASEBOARD"
Properties :	
			"Name"

	
Alias Name :	"PRINTER"
Properties :	
	
			"Caption"
			"DeviceID"
			"PrintProcessor"
			"ShareName"
			
	


Alias Name :	"BOOTCONFIG"
Properties :	

			"Caption"
			"BootDirectory"

	
Alias Name :	"CSPRODUCT"
Properties :	
	
			"UUID"

Alias Name :	"BIOS"
Properties :

			"BIOSVersion"
			"Manufacturer"
			"SMBIOSBIOSVersion"
			"SMBIOSMajorVersion"
			"SMBIOSMinorVersion"


	
	
Alias Name :	"SOUNDDEV"
Properties :	
	
			"Caption"
			"DeviceID"


Alias Name :	"VOLUME"
Properties :	
	
			"SerialNumber"
			"DeviceID"
			"Caption"

			
			
Alias Name :	"ONBOARDDEVICE"
Properties :	
	
			"Description"
			"DeviceType"
			

Alias Name :	"SYSTEMSLOT"
Properties :

			"SlotDesignation"

	
	

Alias Name :	"VOLTAGE"
Properties :
			"Name"

	
Alias Name :	"DISPLAY"
Properties :	
	
			"Name"
			"DriverVersion"
			"PNPDeviceID"
			"DeviceID"
			"InstalledDisplayDrivers"
			"DriverDate"
			"CurrentVerticalResolution"
			"CurrentHorizontalResolution"
			"CurrentNumberOfColors"
			"AdapterRAM" 
			
	


Alias Name :	"MONITOR"
Properties :	
			"InstanceName"
			"Active"

	
	


Alias Name :	"BATTERY"
Properties :
	
			"Availability"
			"Status"
			"SystemName"
			"StatusInfo"
			"SmartBatteryVersion"
			"Caption"
			"BatteryStatus"
			"BatteryRechargeTime"


Alias Name :	"PNP"
Properties :
	
			"Name"
			"DeviceID"
			"Service"

	
	

