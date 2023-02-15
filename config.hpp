#pragma once
#include "include.hpp"
void Config();
std::string  wcharToString(LPCWSTR s);
size_t  wchars2char(char* s, wchar_t* w);
size_t  chars2wchars(wchar_t* w, char* s);

#pragma once
#include "config.hpp"

class CommandLine {
public:
	const char* ConsoleExec;
	const char* PWD;
	char* Commands;

	CommandLine(int command, char* parms[]);
	
	char* WrapPwdToWt();
	char* WrapPwdToCmd();
	char* WrapPwdToPwsh();
	char* WrapPwdToPowershell();

	char* WrapWtParms();
	char* WrapCmdParms();
	char* WrapPwshParms();
	char* WrapPowershellParms();

	char* WrapCommand();
};