#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <lmcons.h>
#include <LMServer.h>
#include <string>

#include <tchar.h>
#include <strsafe.h>
#include <msi.h>
#include <msiquery.h>
#include <array>
#include <memory>
#include <vector>
#include <map>
#include <algorithm>


#pragma comment(lib,"msi.lib")