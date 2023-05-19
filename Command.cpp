#include "Command.hpp"

using namespace std;

	Command::Command(int nums, char* parms[]) {
		vector<string> input;
		for (int i = 0; i < nums; i++) {
			input.push_back(parms[i]);
		}

		if (input.size() > 1) {
			if (input[1] == "wt") {
				ShellProgram = input[1];
			}
			else {
				ShellProgram = "powershell";
			}
		}
		else {
			ShellProgram = "wt";
		}

		// pwd
		char cwd[MAX_PATH];
		ShellPwd = !_getcwd(cwd, MAX_PATH) ? "c:\\" : cwd;
		
		if (ShellProgram == "powershell") {
			if (input.size() > 2) {

				ShellCommand += " Start-process " + input[1] + "  -WorkingDirectory \'" + ShellPwd + "\' -ArgumentList  ";
			}
			else {
				ShellCommand += " Start-process " + input[1] + "  -WorkingDirectory  \'" + ShellPwd + "\' ";
			}
		}
		else if(ShellProgram == "wt") {
			ShellCommand += " -d \""+ShellPwd+"\" ";
		}


		bool runtag = false;
		for (int i = 2; i < input.size(); i++) {
			if (runtag == false) {
				ShellCommand += "\"";
			}
			ShellCommand += input[i] + " ";
			runtag = true;
		}
		if (runtag == true ) {
			ShellCommand.pop_back();
			ShellCommand += "\"";
		}

	};


	string Command::GetProgram() {
		string tmp = ShellProgram;
		return tmp;
	}
	string Command::GetCommand() {
		string tmp = ShellCommand;
		return tmp;

	}
	string Command::GetPwd() {
		string tmp = ShellPwd;
		return tmp;

	}
