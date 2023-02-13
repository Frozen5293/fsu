#pragma once
#include "include.hpp"
void Config();
std::string  wcharToString(LPCWSTR s);
size_t  wchars2char(char* s, wchar_t* w);
size_t  chars2wchars(wchar_t* w, char* s);