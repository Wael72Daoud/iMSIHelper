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
#include "Err.h"


Err::Err()
{
}

WS Err::ErrorToString(__in HRESULT hres)
{

	
	switch (hres)
	{
	case WBEM_E_NOT_FOUND:
		return L"WBEM_E_NOT_FOUND";
	
	break;

	case WBEM_E_ACCESS_DENIED:
		return L"WBEM_E_ACCESS_DENIED";

		break;
	case WBEM_E_PROVIDER_FAILURE:
		return L"WBEM_E_PROVIDER_FAILURE";

		break;
	case WBEM_E_TYPE_MISMATCH:
		return L"WBEM_E_TYPE_MISMATCH";

		break;
	case WBEM_E_OUT_OF_MEMORY:
		return L"WBEM_E_OUT_OF_MEMORY";

		break;
	case WBEM_E_INVALID_CONTEXT:
		return L"WBEM_E_INVALID_CONTEXT";
		break;
	case WBEM_E_INVALID_PARAMETER:
		return L"WBEM_E_INVALID_PARAMETER";
		break;
	case WBEM_E_NOT_AVAILABLE:
		return L"WBEM_E_NOT_AVAILABLE";
		break;
	case WBEM_E_CRITICAL_ERROR:
		return L"WBEM_E_CRITICAL_ERROR";
		break;
	case WBEM_E_INVALID_STREAM:
		return L"WBEM_E_INVALID_STREAM";
		break;
	case WBEM_E_NOT_SUPPORTED:
		return L"WBEM_E_NOT_SUPPORTED";
		break;
	
	case WBEM_E_INVALID_SUPERCLASS:
		return L"WBEM_E_INVALID_SUPERCLASS";
		break;

	case WBEM_E_INVALID_NAMESPACE:
		return L"WBEM_E_INVALID_NAMESPACE";
		break;

	case WBEM_E_INVALID_OBJECT:
		return L"WBEM_E_INVALID_OBJECT";
		break;

	case WBEM_E_INVALID_CLASS:
		return L"WBEM_E_INVALID_CLASS";
		break;

	case WBEM_E_PROVIDER_NOT_FOUND:
		return L"WBEM_E_PROVIDER_NOT_FOUND";
		break;

	case WBEM_E_INVALID_PROVIDER_REGISTRATION:
		return L"WBEM_E_INVALID_PROVIDER_REGISTRATION";
		break;

	case WBEM_E_PROVIDER_LOAD_FAILURE:
		return L"WBEM_E_PROVIDER_LOAD_FAILURE";
		break;

	case WBEM_E_INITIALIZATION_FAILURE:
		return L"WBEM_E_INITIALIZATION_FAILURE";
		break;
	case WBEM_E_TRANSPORT_FAILURE:
		return L"WBEM_E_TRANSPORT_FAILURE";
		break;


	case WBEM_E_INVALID_OPERATION:
		return L"WBEM_E_INVALID_OPERATION";
		break;

	case WBEM_E_INVALID_QUERY:
		return L"WBEM_E_INVALID_QUERY";
		break;

	case WBEM_E_INVALID_QUERY_TYPE:
		return L"WBEM_E_INVALID_QUERY_TYPE";
		break;
	case WBEM_E_ALREADY_EXISTS:
		return L"WBEM_E_ALREADY_EXISTS";
		break;

	case WBEM_E_OVERRIDE_NOT_ALLOWED:
		return L"WBEM_E_OVERRIDE_NOT_ALLOWED";
		break;

	case WBEM_E_PROPAGATED_QUALIFIER:
		return L"WBEM_E_PROPAGATED_QUALIFIER";
		break;


	case WBEM_E_PROPAGATED_PROPERTY:
		return L"WBEM_E_PROPAGATED_PROPERTY";
		break;

	case WBEM_E_UNEXPECTED:
		return L"WBEM_E_UNEXPECTED";
		break;

	case WBEM_E_ILLEGAL_OPERATION:
		return L"WBEM_E_ILLEGAL_OPERATION";
		break;

	case WBEM_E_CANNOT_BE_KEY:
		return L"WBEM_E_CANNOT_BE_KEY";
		break;
	case WBEM_E_INCOMPLETE_CLASS:
		return L"WBEM_E_INCOMPLETE_CLASS";
		break;
	case WBEM_E_INVALID_SYNTAX:
		return L"WBEM_E_INVALID_SYNTAX";
		break;
	case WBEM_E_NONDECORATED_OBJECT:
		return L"WBEM_E_NONDECORATED_OBJECT";
		break;

	case WBEM_E_READ_ONLY:
		return L"WBEM_E_READ_ONLY";
		break;

	case WBEM_E_PROVIDER_NOT_CAPABLE:
		return L"WBEM_E_PROVIDER_NOT_CAPABLE";
		break;

	case WBEM_E_CLASS_HAS_CHILDREN:
		return L"WBEM_E_CLASS_HAS_CHILDREN";
		break;
	case WBEM_E_CLASS_HAS_INSTANCES:
		return L"WBEM_E_CLASS_HAS_INSTANCES";
		break;

	case WBEM_E_QUERY_NOT_IMPLEMENTED:
		return L"WBEM_E_QUERY_NOT_IMPLEMENTED";
		break;
	case WBEM_E_ILLEGAL_NULL:
		return L"WBEM_E_ILLEGAL_NULL";
		break;
	case WBEM_E_INVALID_QUALIFIER_TYPE:
		return L"WBEM_E_INVALID_QUALIFIER_TYPE";
		break;
	case WBEM_E_INVALID_PROPERTY_TYPE:
		return L"WBEM_E_INVALID_PROPERTY_TYPE";
		break;
	case WBEM_E_VALUE_OUT_OF_RANGE:
		return L"WBEM_E_VALUE_OUT_OF_RANGE";
		break;
	case WBEM_E_CANNOT_BE_SINGLETON:
		return L"WBEM_E_CANNOT_BE_SINGLETON";
		break;
	case WBEM_E_INVALID_CIM_TYPE:
		return L"WBEM_E_INVALID_CIM_TYPE";
		break;
	case WBEM_E_INVALID_METHOD:
		return L"WBEM_E_INVALID_METHOD";
		break;
	case WBEM_E_INVALID_METHOD_PARAMETERS:
		return L"WBEM_E_INVALID_METHOD_PARAMETERS";
		break;
	case WBEM_E_SYSTEM_PROPERTY:
		return L"WBEM_E_SYSTEM_PROPERTY";
		break;
	case WBEM_E_INVALID_PROPERTY:
		return L"WBEM_E_INVALID_PROPERTY";
		break;

	case WBEM_E_CALL_CANCELLED:
		return L"WBEM_E_CALL_CANCELLED";
		break;
	case WBEM_E_SHUTTING_DOWN:
		return L"WBEM_E_SHUTTING_DOWN";
		break;
	case WBEM_E_PROPAGATED_METHOD:
		return L"WBEM_E_PROPAGATED_METHOD";
		break;
	case WBEM_E_UNSUPPORTED_PARAMETER:
		return L"WBEM_E_PROPAGATED_METHOD";
		break;
	case WBEM_E_MISSING_PARAMETER_ID:
		return L"WBEM_E_MISSING_PARAMETER_ID";
		break;
	case WBEM_E_INVALID_PARAMETER_ID:
		return L"WBEM_E_INVALID_PARAMETER_ID";
		break;

	case WBEM_E_NONCONSECUTIVE_PARAMETER_IDS:
		return L"WBEM_E_NONCONSECUTIVE_PARAMETER_IDS";
		break;

	case WBEM_E_PARAMETER_ID_ON_RETVAL:
		return L"WBEM_E_PARAMETER_ID_ON_RETVAL";
		break;

	case WBEM_E_INVALID_OBJECT_PATH:
		return L"WBEM_E_INVALID_OBJECT_PATH";
		break;
	case WBEM_E_OUT_OF_DISK_SPACE:
		return L"WBEM_E_OUT_OF_DISK_SPACE";
		break;
	case WBEM_E_BUFFER_TOO_SMALL:
		return L"WBEM_E_BUFFER_TOO_SMALL";
		break;


	case WBEM_E_UNSUPPORTED_PUT_EXTENSION:
		return L"WBEM_E_UNSUPPORTED_PUT_EXTENSION";
		break;

	case WBEM_E_UNKNOWN_OBJECT_TYPE:
		return L"WBEM_E_UNKNOWN_OBJECT_TYPE";
		break;

	case WBEM_E_UNKNOWN_PACKET_TYPE:
		return L"WBEM_E_UNKNOWN_PACKET_TYPE";
		break;

	case WBEM_E_MARSHAL_VERSION_MISMATCH:
		return L"WBEM_E_MARSHAL_VERSION_MISMATCH";
		break;

	case WBEM_E_MARSHAL_INVALID_SIGNATURE:
		return L"WBEM_E_MARSHAL_INVALID_SIGNATURE";
		break;
	case WBEM_E_INVALID_QUALIFIER:
		return L"WBEM_E_INVALID_QUALIFIER";
		break;
	case WBEM_E_INVALID_DUPLICATE_PARAMETER:
		return L"WBEM_E_INVALID_DUPLICATE_PARAMETER";
		break;
	case WBEM_E_TOO_MUCH_DATA:
		return L"WBEM_E_TOO_MUCH_DATA";
		break;
	case WBEM_E_SERVER_TOO_BUSY:
		return L"WBEM_E_SERVER_TOO_BUSY";
		break;
	case WBEM_E_INVALID_FLAVOR:
		return L"WBEM_E_INVALID_FLAVOR";
		break;
	case WBEM_E_UNSUPPORTED_CLASS_UPDATE:
		return L"WBEM_E_UNSUPPORTED_CLASS_UPDATE";
		break;


	case WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE:
		return L"WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE";
		break;


	case WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE:
		return L"WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE";
		break;

	case WBEM_E_TOO_MANY_PROPERTIES:
		return L"WBEM_E_TOO_MANY_PROPERTIES";
		break;
	case WBEM_E_UPDATE_TYPE_MISMATCH:
		return L"WBEM_E_UPDATE_TYPE_MISMATCH";
		break;
	case WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED:
		return L"WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED";
		break;
	case WBEM_E_UPDATE_PROPAGATED_METHOD:
		return L"WBEM_E_UPDATE_PROPAGATED_METHOD";
		break;
	case WBEM_E_METHOD_NOT_IMPLEMENTED:
		return L"WBEM_E_METHOD_NOT_IMPLEMENTED";
		break;
	case WBEM_E_METHOD_DISABLED:
		return L"WBEM_E_METHOD_DISABLED";
		break;
	case WBEM_E_REFRESHER_BUSY:
		return L"WBEM_E_REFRESHER_BUSY";
		break;
	case WBEM_E_UNPARSABLE_QUERY:
		return L"WBEM_E_UNPARSABLE_QUERY";
		break;

	case WBEM_E_NOT_EVENT_CLASS:
		return L"WBEM_E_NOT_EVENT_CLASS";
		break;

	case WBEM_E_MISSING_GROUP_WITHIN:
		return L"WBEM_E_MISSING_GROUP_WITHIN";
		break;

	case WBEM_E_MISSING_AGGREGATION_LIST:
		return L"WBEM_E_MISSING_AGGREGATION_LIST";
		break;
	case WBEM_E_PROPERTY_NOT_AN_OBJECT:
		return L"WBEM_E_PROPERTY_NOT_AN_OBJECT";
		break;
	case WBEM_E_AGGREGATING_BY_OBJECT:
		return L"WBEM_E_AGGREGATING_BY_OBJECT";
		break;
	case WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY:
		return L"WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY";
		break;
	case WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING:
		return L"WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING";
		break;
	case WBEM_E_QUEUE_OVERFLOW:
		return L"WBEM_E_QUEUE_OVERFLOW";

		break;


	case WBEM_E_PRIVILEGE_NOT_HELD:
		return L"WBEM_E_PRIVILEGE_NOT_HELD";

		break;


	case WBEM_E_INVALID_OPERATOR:
		return L"WBEM_E_INVALID_OPERATOR";

		break;


	case WBEM_E_LOCAL_CREDENTIALS:
		return L"WBEM_E_LOCAL_CREDENTIALS";

		break;


	case WBEM_E_CANNOT_BE_ABSTRACT:
		return L"WBEM_E_CANNOT_BE_ABSTRACT";

		break;


	case WBEM_E_AMENDED_OBJECT:
		return L"WBEM_E_AMENDED_OBJECT";

		break;


	case WBEM_E_CLIENT_TOO_SLOW:
		return L"WBEM_E_CLIENT_TOO_SLOW";

		break;


	case WBEM_E_NULL_SECURITY_DESCRIPTOR:
		return L"WBEM_E_NULL_SECURITY_DESCRIPTOR";

		break;

	case WBEM_E_TIMED_OUT:
		return L"WBEM_E_TIMED_OUT";

		break;


	case WBEM_E_INVALID_ASSOCIATION:
		return L"WBEM_E_INVALID_ASSOCIATION";

		break;

	case WBEM_E_AMBIGUOUS_OPERATION:
		return L"WBEM_E_AMBIGUOUS_OPERATION";

		break;

	case WBEM_E_QUOTA_VIOLATION:
		return L"WBEM_E_QUOTA_VIOLATION";

		break;

	case WBEM_E_UNSUPPORTED_LOCALE:
		return L"WBEM_E_UNSUPPORTED_LOCALE";

		break;


	case WBEM_E_HANDLE_OUT_OF_DATE:
		return L"WBEM_E_HANDLE_OUT_OF_DATE";

		break;

	case WBEM_E_CONNECTION_FAILED:
		return L"WBEM_E_CONNECTION_FAILED";

		break;

	case WBEM_E_INVALID_HANDLE_REQUEST:
		return L"WBEM_E_INVALID_HANDLE_REQUEST";

		break;

	case WBEM_E_PROPERTY_NAME_TOO_WIDE:
		return L"WBEM_E_PROPERTY_NAME_TOO_WIDE";

		break;

	case WBEM_E_CLASS_NAME_TOO_WIDE:
		return L"WBEM_E_CLASS_NAME_TOO_WIDE";

		break;
	case WBEM_E_METHOD_NAME_TOO_WIDE:
		return L"WBEM_E_METHOD_NAME_TOO_WIDE";

		break;
	case WBEM_E_QUALIFIER_NAME_TOO_WIDE:
		return L"WBEM_E_QUALIFIER_NAME_TOO_WIDE";

		break;
	case WBEM_E_RERUN_COMMAND:
		return L"WBEM_E_RERUN_COMMAND";

		break;

	case WBEM_E_DATABASE_VER_MISMATCH:
		return L"WBEM_E_DATABASE_VER_MISMATCH";

		break;
	case WBEM_E_VETO_DELETE:
		return L"WBEM_E_VETO_DELETE";

		break;

	case WBEM_E_VETO_PUT:
		return L"WBEM_E_VETO_PUT";

		break;

	case WBEM_E_INVALID_LOCALE:
		return L"WBEM_E_INVALID_LOCALE";

		break;

	case WBEM_E_PROVIDER_SUSPENDED:
		return L"WBEM_E_PROVIDER_SUSPENDED";

		break;
	case WBEM_E_SYNCHRONIZATION_REQUIRED:
		return L"WBEM_E_SYNCHRONIZATION_REQUIRED";

		break;
	case WBEM_E_NO_SCHEMA:
		return L"WBEM_E_NO_SCHEMA";

		break;
	case WBEM_E_PROVIDER_ALREADY_REGISTERED:
		return L"WBEM_E_PROVIDER_ALREADY_REGISTERED";

		break;

	case WBEM_E_PROVIDER_NOT_REGISTERED:
		return L"WBEM_E_PROVIDER_NOT_REGISTERED";

		break;

	case WBEM_E_FATAL_TRANSPORT_ERROR:
		return L"WBEM_E_FATAL_TRANSPORT_ERROR";

		break;
	case WBEM_E_ENCRYPTED_CONNECTION_REQUIRED:
		return L"WBEM_E_ENCRYPTED_CONNECTION_REQUIRED";

		break;

	case WBEM_E_PROVIDER_TIMED_OUT:
		return L"WBEM_E_PROVIDER_TIMED_OUT";

		break;

	case WBEM_E_NO_KEY:
		return L"WBEM_E_NO_KEY";

		break;

	case WBEM_E_PROVIDER_DISABLED:
		return L"WBEM_E_PROVIDER_DISABLED";

		break;

	case WBEM_E_FAILED:
		return L"WBEM_E_FAILED";

		break;

	default:
		return L"Unknown Error";
		break;
	}

	/*
		WBEM_E_FAILED = 0x80041001,
		WBEM_E_NOT_FOUND = 0x80041002,
		WBEM_E_ACCESS_DENIED = 0x80041003,
		WBEM_E_PROVIDER_FAILURE = 0x80041004,
		WBEM_E_TYPE_MISMATCH = 0x80041005,
		WBEM_E_OUT_OF_MEMORY = 0x80041006,
		WBEM_E_INVALID_CONTEXT = 0x80041007,
		WBEM_E_INVALID_PARAMETER = 0x80041008,
		WBEM_E_NOT_AVAILABLE = 0x80041009,
		WBEM_E_CRITICAL_ERROR = 0x8004100a,
		WBEM_E_INVALID_STREAM = 0x8004100b,
		WBEM_E_NOT_SUPPORTED = 0x8004100c,
		WBEM_E_INVALID_SUPERCLASS = 0x8004100d,
		WBEM_E_INVALID_NAMESPACE = 0x8004100e,
		WBEM_E_INVALID_OBJECT = 0x8004100f,
		WBEM_E_INVALID_CLASS = 0x80041010,
		WBEM_E_PROVIDER_NOT_FOUND = 0x80041011,
		WBEM_E_INVALID_PROVIDER_REGISTRATION = 0x80041012,
		WBEM_E_PROVIDER_LOAD_FAILURE = 0x80041013,
		WBEM_E_INITIALIZATION_FAILURE = 0x80041014,
		WBEM_E_TRANSPORT_FAILURE = 0x80041015,
		WBEM_E_INVALID_OPERATION = 0x80041016,
		WBEM_E_INVALID_QUERY = 0x80041017,
		WBEM_E_INVALID_QUERY_TYPE = 0x80041018,
		WBEM_E_ALREADY_EXISTS = 0x80041019,
		WBEM_E_OVERRIDE_NOT_ALLOWED = 0x8004101a,
		WBEM_E_PROPAGATED_QUALIFIER = 0x8004101b,
		WBEM_E_PROPAGATED_PROPERTY = 0x8004101c,
		WBEM_E_UNEXPECTED = 0x8004101d,
		WBEM_E_ILLEGAL_OPERATION = 0x8004101e,
		WBEM_E_CANNOT_BE_KEY = 0x8004101f,
		WBEM_E_INCOMPLETE_CLASS = 0x80041020,
		WBEM_E_INVALID_SYNTAX = 0x80041021,
		WBEM_E_NONDECORATED_OBJECT = 0x80041022,
		WBEM_E_READ_ONLY = 0x80041023,
		WBEM_E_PROVIDER_NOT_CAPABLE = 0x80041024,
		WBEM_E_CLASS_HAS_CHILDREN = 0x80041025,
		WBEM_E_CLASS_HAS_INSTANCES = 0x80041026,
		WBEM_E_QUERY_NOT_IMPLEMENTED = 0x80041027,
		WBEM_E_ILLEGAL_NULL = 0x80041028,
		WBEM_E_INVALID_QUALIFIER_TYPE = 0x80041029,
		WBEM_E_INVALID_PROPERTY_TYPE = 0x8004102a,
		WBEM_E_VALUE_OUT_OF_RANGE = 0x8004102b,
		WBEM_E_CANNOT_BE_SINGLETON = 0x8004102c,
		WBEM_E_INVALID_CIM_TYPE = 0x8004102d,
		WBEM_E_INVALID_METHOD = 0x8004102e,
		WBEM_E_INVALID_METHOD_PARAMETERS = 0x8004102f,
		WBEM_E_SYSTEM_PROPERTY = 0x80041030,
		WBEM_E_INVALID_PROPERTY = 0x80041031,
		WBEM_E_CALL_CANCELLED = 0x80041032,
		WBEM_E_SHUTTING_DOWN = 0x80041033,
		WBEM_E_PROPAGATED_METHOD = 0x80041034,
		WBEM_E_UNSUPPORTED_PARAMETER = 0x80041035,
		WBEM_E_MISSING_PARAMETER_ID = 0x80041036,
		WBEM_E_INVALID_PARAMETER_ID = 0x80041037,
		WBEM_E_NONCONSECUTIVE_PARAMETER_IDS = 0x80041038,
		WBEM_E_PARAMETER_ID_ON_RETVAL = 0x80041039,
		WBEM_E_INVALID_OBJECT_PATH = 0x8004103a,
		WBEM_E_OUT_OF_DISK_SPACE = 0x8004103b,
		WBEM_E_BUFFER_TOO_SMALL = 0x8004103c,
		WBEM_E_UNSUPPORTED_PUT_EXTENSION = 0x8004103d,
		WBEM_E_UNKNOWN_OBJECT_TYPE = 0x8004103e,
		WBEM_E_UNKNOWN_PACKET_TYPE = 0x8004103f,
		WBEM_E_MARSHAL_VERSION_MISMATCH = 0x80041040,
		WBEM_E_MARSHAL_INVALID_SIGNATURE = 0x80041041,
		WBEM_E_INVALID_QUALIFIER = 0x80041042,
		WBEM_E_INVALID_DUPLICATE_PARAMETER = 0x80041043,
		WBEM_E_TOO_MUCH_DATA = 0x80041044,
		WBEM_E_SERVER_TOO_BUSY = 0x80041045,
		WBEM_E_INVALID_FLAVOR = 0x80041046,
		WBEM_E_CIRCULAR_REFERENCE = 0x80041047,
		WBEM_E_UNSUPPORTED_CLASS_UPDATE = 0x80041048,
		WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE = 0x80041049,
		WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE = 0x80041050,
		WBEM_E_TOO_MANY_PROPERTIES = 0x80041051,
		WBEM_E_UPDATE_TYPE_MISMATCH = 0x80041052,
		WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED = 0x80041053,
		WBEM_E_UPDATE_PROPAGATED_METHOD = 0x80041054,
		WBEM_E_METHOD_NOT_IMPLEMENTED = 0x80041055,
		WBEM_E_METHOD_DISABLED = 0x80041056,
		WBEM_E_REFRESHER_BUSY = 0x80041057,
		WBEM_E_UNPARSABLE_QUERY = 0x80041058,
		WBEM_E_NOT_EVENT_CLASS = 0x80041059,
		WBEM_E_MISSING_GROUP_WITHIN = 0x8004105a,
		WBEM_E_MISSING_AGGREGATION_LIST = 0x8004105b,
		WBEM_E_PROPERTY_NOT_AN_OBJECT = 0x8004105c,
		WBEM_E_AGGREGATING_BY_OBJECT = 0x8004105d,
		WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY = 0x8004105f,
		WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING = 0x80041060,
		WBEM_E_QUEUE_OVERFLOW = 0x80041061,
		WBEM_E_PRIVILEGE_NOT_HELD = 0x80041062,
		WBEM_E_INVALID_OPERATOR = 0x80041063,
		WBEM_E_LOCAL_CREDENTIALS = 0x80041064,
		WBEM_E_CANNOT_BE_ABSTRACT = 0x80041065,
		WBEM_E_AMENDED_OBJECT = 0x80041066,
		WBEM_E_CLIENT_TOO_SLOW = 0x80041067,
		WBEM_E_NULL_SECURITY_DESCRIPTOR = 0x80041068,
		WBEM_E_TIMED_OUT = 0x80041069,
		WBEM_E_INVALID_ASSOCIATION = 0x8004106a,
		WBEM_E_AMBIGUOUS_OPERATION = 0x8004106b,
		WBEM_E_QUOTA_VIOLATION = 0x8004106c,
		WBEM_E_RESERVED_001 = 0x8004106d,
		WBEM_E_RESERVED_002 = 0x8004106e,
		WBEM_E_UNSUPPORTED_LOCALE = 0x8004106f,
		WBEM_E_HANDLE_OUT_OF_DATE = 0x80041070,
		WBEM_E_CONNECTION_FAILED = 0x80041071,
		WBEM_E_INVALID_HANDLE_REQUEST = 0x80041072,
		WBEM_E_PROPERTY_NAME_TOO_WIDE = 0x80041073,
		WBEM_E_CLASS_NAME_TOO_WIDE = 0x80041074,
		WBEM_E_METHOD_NAME_TOO_WIDE = 0x80041075,
		WBEM_E_QUALIFIER_NAME_TOO_WIDE = 0x80041076,
		WBEM_E_RERUN_COMMAND = 0x80041077,
		WBEM_E_DATABASE_VER_MISMATCH = 0x80041078,
		WBEM_E_VETO_DELETE = 0x80041079,
		WBEM_E_VETO_PUT = 0x8004107a,
		WBEM_E_INVALID_LOCALE = 0x80041080,
		WBEM_E_PROVIDER_SUSPENDED = 0x80041081,
		WBEM_E_SYNCHRONIZATION_REQUIRED = 0x80041082,
		WBEM_E_NO_SCHEMA = 0x80041083,
		WBEM_E_PROVIDER_ALREADY_REGISTERED = 0x80041084,
		WBEM_E_PROVIDER_NOT_REGISTERED = 0x80041085,
		WBEM_E_FATAL_TRANSPORT_ERROR = 0x80041086,
		WBEM_E_ENCRYPTED_CONNECTION_REQUIRED = 0x80041087,
		WBEM_E_PROVIDER_TIMED_OUT = 0x80041088,
		WBEM_E_NO_KEY = 0x80041089,
		WBEM_E_PROVIDER_DISABLED = 0x8004108a,
	  */


		//wbemNoErr = 0,
		//wbemErrFailed = 0x80041001,
		//wbemErrNotFound = 0x80041002,
		//wbemErrAccessDenied = 0x80041003,
		//wbemErrProviderFailure = 0x80041004,
		//wbemErrTypeMismatch = 0x80041005,
		//wbemErrOutOfMemory = 0x80041006,
		//wbemErrInvalidContext = 0x80041007,
		//wbemErrInvalidParameter = 0x80041008,
		//wbemErrNotAvailable = 0x80041009,
		//wbemErrCriticalError = 0x8004100a,
		//wbemErrInvalidStream = 0x8004100b,
		//wbemErrNotSupported = 0x8004100c,
		//wbemErrInvalidSuperclass = 0x8004100d,
		//wbemErrInvalidNamespace = 0x8004100e,
		//wbemErrInvalidObject = 0x8004100f,
		//wbemErrInvalidClass = 0x80041010,
		//wbemErrProviderNotFound = 0x80041011,
		//wbemErrInvalidProviderRegistration = 0x80041012,
		//wbemErrProviderLoadFailure = 0x80041013,
		//wbemErrInitializationFailure = 0x80041014,
		//wbemErrTransportFailure = 0x80041015,
		//wbemErrInvalidOperation = 0x80041016,
		//wbemErrInvalidQuery = 0x80041017,
		//wbemErrInvalidQueryType = 0x80041018,
		//wbemErrAlreadyExists = 0x80041019,
		//wbemErrOverrideNotAllowed = 0x8004101a,
		//wbemErrPropagatedQualifier = 0x8004101b,
		//wbemErrPropagatedProperty = 0x8004101c,
		//wbemErrUnexpected = 0x8004101d,
		//wbemErrIllegalOperation = 0x8004101e,
		//wbemErrCannotBeKey = 0x8004101f,
		//wbemErrIncompleteClass = 0x80041020,
		//wbemErrInvalidSyntax = 0x80041021,
		//wbemErrNondecoratedObject = 0x80041022,
		//wbemErrReadOnly = 0x80041023,
		//wbemErrProviderNotCapable = 0x80041024,
		//wbemErrClassHasChildren = 0x80041025,
		//wbemErrClassHasInstances = 0x80041026,
		//wbemErrQueryNotImplemented = 0x80041027,
		//wbemErrIllegalNull = 0x80041028,
		//wbemErrInvalidQualifierType = 0x80041029,
		//wbemErrInvalidPropertyType = 0x8004102a,
		//wbemErrValueOutOfRange = 0x8004102b,
		//wbemErrCannotBeSingleton = 0x8004102c,
		//wbemErrInvalidCimType = 0x8004102d,
		//wbemErrInvalidMethod = 0x8004102e,
		//wbemErrInvalidMethodParameters = 0x8004102f,
		//wbemErrSystemProperty = 0x80041030,
		//wbemErrInvalidProperty = 0x80041031,
		//wbemErrCallCancelled = 0x80041032,
		//wbemErrShuttingDown = 0x80041033,
		//wbemErrPropagatedMethod = 0x80041034,
		//wbemErrUnsupportedParameter = 0x80041035,
		//wbemErrMissingParameter = 0x80041036,
		//wbemErrInvalidParameterId = 0x80041037,
		//wbemErrNonConsecutiveParameterIds = 0x80041038,
		//wbemErrParameterIdOnRetval = 0x80041039,
		//wbemErrInvalidObjectPath = 0x8004103a,
		//wbemErrOutOfDiskSpace = 0x8004103b,
		//wbemErrBufferTooSmall = 0x8004103c,
		//wbemErrUnsupportedPutExtension = 0x8004103d,
		//wbemErrUnknownObjectType = 0x8004103e,
		//wbemErrUnknownPacketType = 0x8004103f,
		//wbemErrMarshalVersionMismatch = 0x80041040,
		//wbemErrMarshalInvalidSignature = 0x80041041,
		//wbemErrInvalidQualifier = 0x80041042,
		//wbemErrInvalidDuplicateParameter = 0x80041043,
		//wbemErrTooMuchData = 0x80041044,
		//wbemErrServerTooBusy = 0x80041045,
		//wbemErrInvalidFlavor = 0x80041046,
		//wbemErrCircularReference = 0x80041047,
		//wbemErrUnsupportedClassUpdate = 0x80041048,
		//wbemErrCannotChangeKeyInheritance = 0x80041049,
		//wbemErrCannotChangeIndexInheritance = 0x80041050,
		//wbemErrTooManyProperties = 0x80041051,
		//wbemErrUpdateTypeMismatch = 0x80041052,
		//wbemErrUpdateOverrideNotAllowed = 0x80041053,
		//wbemErrUpdatePropagatedMethod = 0x80041054,
		//wbemErrMethodNotImplemented = 0x80041055,
		//wbemErrMethodDisabled = 0x80041056,
		//wbemErrRefresherBusy = 0x80041057,
		//wbemErrUnparsableQuery = 0x80041058,
		//wbemErrNotEventClass = 0x80041059,
		//wbemErrMissingGroupWithin = 0x8004105a,
		//wbemErrMissingAggregationList = 0x8004105b,
		//wbemErrPropertyNotAnObject = 0x8004105c,
		//wbemErrAggregatingByObject = 0x8004105d,
		//wbemErrUninterpretableProviderQuery = 0x8004105f,
		//wbemErrBackupRestoreWinmgmtRunning = 0x80041060,
		//wbemErrQueueOverflow = 0x80041061,
		//wbemErrPrivilegeNotHeld = 0x80041062,
		//wbemErrInvalidOperator = 0x80041063,
		//wbemErrLocalCredentials = 0x80041064,
		//wbemErrCannotBeAbstract = 0x80041065,
		//wbemErrAmendedObject = 0x80041066,
		//wbemErrClientTooSlow = 0x80041067,
		//wbemErrNullSecurityDescriptor = 0x80041068,
		//wbemErrTimeout = 0x80041069,
		//wbemErrInvalidAssociation = 0x8004106a,
		//wbemErrAmbiguousOperation = 0x8004106b,
		//wbemErrQuotaViolation = 0x8004106c,
		//wbemErrTransactionConflict = 0x8004106d,
		//wbemErrForcedRollback = 0x8004106e,
		//wbemErrUnsupportedLocale = 0x8004106f,
		//wbemErrHandleOutOfDate = 0x80041070,
		//wbemErrConnectionFailed = 0x80041071,
		//wbemErrInvalidHandleRequest = 0x80041072,
		//wbemErrPropertyNameTooWide = 0x80041073,
		//wbemErrClassNameTooWide = 0x80041074,
		//wbemErrMethodNameTooWide = 0x80041075,
		//wbemErrQualifierNameTooWide = 0x80041076,
		//wbemErrRerunCommand = 0x80041077,
		//wbemErrDatabaseVerMismatch = 0x80041078,
		//wbemErrVetoPut = 0x80041079,
		//wbemErrVetoDelete = 0x8004107a,
		//wbemErrInvalidLocale = 0x80041080,
		//wbemErrProviderSuspended = 0x80041081,
		//wbemErrSynchronizationRequired = 0x80041082,
		//wbemErrNoSchema = 0x80041083,
		//wbemErrProviderAlreadyRegistered = 0x80041084,
		//wbemErrProviderNotRegistered = 0x80041085,
		//wbemErrFatalTransportError = 0x80041086,
		//wbemErrEncryptedConnectionRequired = 0x80041087,
		//wbemErrRegistrationTooBroad = 0x80042001,
		//wbemErrRegistrationTooPrecise = 0x80042002,
		//wbemErrTimedout = 0x80043001,
		//wbemErrResetToDefault = 0x80043002

}

Err::~Err()
{
}
