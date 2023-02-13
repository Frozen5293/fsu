#include "include.hpp"


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
