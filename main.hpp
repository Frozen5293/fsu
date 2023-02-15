#pragma once
#include "config.hpp"

class CommandLine {
public:
	int mod;
	const char* ConsoleExec;
	const char* PWD;
	char* Commands;

	CommandLine(int command, char* parms[]) {
		char cwd[MAX_PATH];
		PWD = !_getcwd(cwd, MAX_PATH) ? "c:\\" : cwd;
		ConsoleExec = command > 1 ? parms[1] : "wt";
		Commands = (char*)malloc(sizeof(char) * 8191);
		if (!Commands) exit(-1);
		ZeroMemory(Commands, 8191);
		Commands[0] = 0;
		for (int i = 2; i < command; i++) {
			if (i != 2)strcat(Commands, " ");
			strcat(Commands, parms[i]);
		}
		std::cout << "WorkDirectory: " << PWD << std::endl;
		std::cout << "Command: " << ConsoleExec << std::endl;
		std::cout << "Parms:" << Commands << std::endl;
	}
};
