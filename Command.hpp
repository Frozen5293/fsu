#pragma once
#include "include.hpp"

using namespace std;
class Command {
private:
	string ShellProgram;
	string ShellCommand;
	string ShellPwd;
public:
	Command(int nums, char* parms[]);
	string GetProgram();
	string GetCommand();
	string GetPwd();
};