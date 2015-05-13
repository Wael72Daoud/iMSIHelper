#pragma once

//----------------------------
//
//---------------------------
enum class Loglevel
{
	INFO,
	ERR,
	DEBUG
};

class logger
{

	MSIHANDLE m_hInstall;
	
	
public:
	logger(__in MSIHANDLE hInstall): m_hInstall(NULL){}
	void logger::log(__in Loglevel level, __in const TCHAR* message, ...);
	~logger();


};



