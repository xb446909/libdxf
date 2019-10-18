#pragma once
#include <string>

using namespace std;

class CharConverter
{
public:
	wchar_t* ANSIToUnicode(const char* str);
	char* UnicodeToANSI(const wchar_t* str);
	wchar_t* UTF8ToUnicode(const char* str);
	char* UnicodeToUTF8(const wchar_t* str);
	string ANSIToUTF8(const char* strSrc);
	string UTF8ToANSI(const char* strSrc);
};

