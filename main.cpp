#include "main.hpp"


using namespace std;


int main(int n, char** parms) {
	std::cout << "====Fsu v0.0.6====" << std::endl;
	CommandLine cm = CommandLine(n, parms);
	SHELLEXECUTEINFOA v = SHELLEXECUTEINFOA();

	v.lpFile = cm.ConsoleExec;

	char* pwdtmp = cm.WrapPwdToCmd();
	v.lpDirectory = pwdtmp;
	delete pwdtmp;

	char* tmpparms = (char*)malloc(sizeof(char) * MAX_PATH);
	if (!tmpparms) return 0;
	ZeroMemory(tmpparms, MAX_PATH);

	char* tmp;
	if (strcmp(cm.ConsoleExec, "wt") == 0 || strcmp(cm.ConsoleExec, "wt.exe") == 0) {
		tmp = cm.WrapWtParms();
		strcat(tmpparms,tmp);
		delete tmp;
	}
	else if (strcmp(cm.ConsoleExec, "powershell") == 0 || strcmp(cm.ConsoleExec, "powershell.exe") == 0 ) {
		tmp = cm.WrapPowershellParms();
		strcat(tmpparms, tmp);
		delete tmp;
	}	
	else if (strcmp(cm.ConsoleExec, "pwsh") == 0 || strcmp(cm.ConsoleExec, "pwsh.exe")==0 ){
		tmp = cm.WrapPwshParms();
		strcat(tmpparms, tmp);
		delete tmp;
	}
	else if (strcmp(cm.ConsoleExec, "cmd") == 0 || strcmp(cm.ConsoleExec, "cmd.exe") == 0) {
		tmp = cm.WrapCmdParms();
		strcat(tmpparms, tmp);
		delete tmp;
	}
	else {
		if (strlen(cm.Commands) != 0) {
			strcat(tmpparms, cm.Commands);
		}
	}

	cout << "FParms:" << tmpparms << endl;

	v.lpParameters = tmpparms;
	tmpparms = nullptr;

	v.cbSize = sizeof(v);
	v.lpVerb = "runas";
	v.nShow = SW_SHOWNORMAL;



	if (!ShellExecuteExA(&v)) {
		DWORD dwStatus = GetLastError();
		if (dwStatus == ERROR_CANCELLED) {
			std::cout << "The permission request failed" << std::endl;
		}
		else if (dwStatus == ERROR_FILE_NOT_FOUND) {
			std::cout << "FILE NOT FOUND!!" << std::endl;
		}
		else if (dwStatus == ERROR_ACCESS_DENIED) {
			std::cout << "ACCESS_DENIED" << std::endl;
		}
		else if (dwStatus == ERROR_PATH_NOT_FOUND) {
			std::cout << "PATH NOT FOUND" << std::endl;
		}
	};

	return 1;
}




