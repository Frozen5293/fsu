#include "include.hpp"
#include "config.hpp"

std::string  wcharToString(LPCWSTR s) {
	size_t len = wcslen(s);
	char* res = (char*)malloc(sizeof(char) * len + 1);
	if (!res) exit(-1);
	wcstombs(res, s, len + 1);
	std::string r = std::string(res);
	free(res);
	return r;
}

size_t  wchars2char(char* s, wchar_t* w) {
	size_t len = WideCharToMultiByte(CP_ACP, 0, w, wcslen(w), NULL, 0, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, w, wcslen(w), s, len, NULL, NULL);
	s[len] = '\0';
	return len;
}

size_t  chars2wchars(wchar_t* w, char* s) {
	size_t len = MultiByteToWideChar(CP_ACP, 0, s, strlen(s), NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, s, strlen(s), w, len);
	w[len] = '\0';
	return len;
}

void Config() {
	wchar_t out[MAX_PATH] = { 0 };
	wchar_t var[MAX_PATH] = { 0 };
	char  varsp[MAX_PATH] = { 0 };
	strcpy(varsp, "APPDATA");
	chars2wchars(var, varsp);
	if (!GetEnvironmentVariable(var, out, MAX_PATH)) {
		std::cout << "不存在APPDATA环境变量,作者完全不懂为什么" << std::endl;
	}
	std::string configfile = wcharToString(out) + "\\fsu\\config.json";
}


char* CommandLine::WrapWtParms() {
	char* res = new char[MAX_PATH];
	if (!res) return nullptr;
	ZeroMemory(res, MAX_PATH);
	char* tmp;

	strcat(res, " -d ");
	tmp = WrapPwdToPowershell();
	strcat(res, tmp);
	delete tmp;

	strcat(res, " ");
	if (Commands) {
		strcat(res, Commands);
	}
	return res;
}

char* CommandLine::WrapCmdParms() {
	char* res = new char[MAX_PATH];
	if (!res) return nullptr;
	ZeroMemory(res, MAX_PATH);
	char* tmp;
	strcat(res, " /c start /d ");
	tmp = WrapPwdToCmd();
	strcat(res, tmp);
	delete tmp;
	strcat(res, " ");
	if (Commands) {
		strcat(res, Commands);
	}
	return res;
}

char* CommandLine::WrapPwshParms() {
	char* res = new char[MAX_PATH];
	if (!res) return nullptr;
	ZeroMemory(res, MAX_PATH);

	char* tmp;
	strcat(res, " -WorkingDirectory ");
	tmp = WrapPwdToCmd();
	strcat(res, tmp);
	delete tmp;

	if (Commands) {
		strcat(res, "  -Command ");
		tmp = WrapCommand();
		strcat(res, tmp);
		delete tmp;
	}
	return res;
}

char* CommandLine::WrapPowershellParms() {
	char* res = new char[MAX_PATH];
	if (!res) return nullptr;
	char* tmp;
	ZeroMemory(res, MAX_PATH);
	strcat(res, " Start-progress powershell -Verb runAs -WorkingDirectory ");
	tmp = WrapPwdToPowershell();
	strcat(res, tmp);
	delete tmp;

	if (Commands) {
		strcat(res, " -ArgumentList  \" -NoExit - Command ");
		strcat(res, Commands);
	}
	strcat(res, "\"");
	return res;
}


char* CommandLine::WrapCommand() {
	char* res = new char[MAX_PATH];
	if (!res) return nullptr;
	ZeroMemory(res, MAX_PATH);
	strcat(res, "\"");
	strcat(res, Commands);
	strcat(res, "\"");
	return res;
}

char* CommandLine::WrapPwdToWt() {
	char* res = new char[MAX_PATH];
	if (!res) return nullptr;
	ZeroMemory(res, MAX_PATH);
	if (ConsoleExec[strlen(PWD) - 1] == '\\') {
		strcpy(res, PWD);
	}
	else {
		strcat(res, "\"");
		strcat(res, PWD);
		strcat(res, "\"");
	}

	return res;
}
char* CommandLine::WrapPwdToCmd() {
	char* res = new char[MAX_PATH];
	if (!res) return nullptr;
	ZeroMemory(res, MAX_PATH);
	strcat(res, "\"");
	strcat(res, PWD);
	strcat(res, "\"");
	return res;
}


CommandLine::CommandLine(int command, char* parms[]) {
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


char* CommandLine::WrapPwdToPwsh() {
	char* res = new char[MAX_PATH];
	if (!res) return nullptr;
	ZeroMemory(res, MAX_PATH);
	if (ConsoleExec[strlen(PWD) - 1] == '\\') {
		strcpy(res, PWD);
	}
	else {
		strcat(res, "\"");
		strcat(res, PWD);
		strcat(res, "\"");
	}
	//std::cout <<"Powershell " << res << std::endl;
	return res;
}
char* CommandLine::WrapPwdToPowershell() {
	char* res = new char[MAX_PATH];
	if (!res) return nullptr;
	ZeroMemory(res, MAX_PATH);
	if (ConsoleExec[strlen(PWD) - 1] == '\\') {
		strcpy(res, PWD);
	}
	else {
		strcat(res, "\"");
		strcat(res, PWD);
		strcat(res, "\"");
	}
	//std::cout <<"Powershell " << res << std::endl;
	return res;
}


