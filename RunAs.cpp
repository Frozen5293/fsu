#include "RunAs.hpp"

namespace RunAs {
	//static string cmdrun= "cmd / c start / d ";
	//static string pwshrun = "powershell Start-Process powershell -Verb runAs -WorkingDirectory  ";
	//static string cmdrun = "cmd / c start / d ";
	//static string cmdrun = "cmd / c start / d ";
	int Run(Command cm) {
		std::cout << "====Fsu v0.0.9====" << std::endl;


		SHELLEXECUTEINFOA v = SHELLEXECUTEINFOA();
		string file = cm.GetProgram();
		string dir = cm.GetPwd();
		string parms = cm.GetCommand();

		cout << file << parms << endl;

		v.lpFile = file.c_str();
		v.lpDirectory = dir.c_str();
		v.lpParameters = parms.c_str();
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
		return 0;
	}
};