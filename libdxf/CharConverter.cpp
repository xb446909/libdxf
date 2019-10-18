#include "stdafx.h"
#include "CharConverter.h"
#include <stdlib.h>
#include <string>

using namespace std;

wchar_t* CharConverter::ANSIToUnicode(const char* str)
{
	int textlen;
	wchar_t* result;
	textlen = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	result = (wchar_t*)malloc((textlen + 1) * sizeof(wchar_t));
	memset(result, 0, (textlen + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, 0, str, -1, (LPWSTR)result, textlen);
	return result;
}

char* CharConverter::UnicodeToANSI(const wchar_t* str)
{
	char* result;
	int textlen;
	textlen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	result = (char*)malloc((textlen + 1) * sizeof(char));
	memset(result, 0, sizeof(char) * (textlen + 1));
	WideCharToMultiByte(CP_ACP, 0, str, -1, result, textlen, NULL, NULL);
	return result;
}

wchar_t* CharConverter::UTF8ToUnicode(const char* str)
{
	int textlen;
	wchar_t* result;
	textlen = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	result = (wchar_t*)malloc((textlen + 1) * sizeof(wchar_t));
	memset(result, 0, (textlen + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_UTF8, 0, str, -1, (LPWSTR)result, textlen);
	return result;
}

char* CharConverter::UnicodeToUTF8(const wchar_t* str)
{
	char* result;
	int textlen;
	textlen = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
	result = (char*)malloc((textlen + 1) * sizeof(char));
	memset(result, 0, sizeof(char) * (textlen + 1));
	WideCharToMultiByte(CP_UTF8, 0, str, -1, result, textlen, NULL, NULL);
	return result;
}

string CharConverter::ANSIToUTF8(const char* strSrc)
{
	char* str = UnicodeToUTF8(ANSIToUnicode(strSrc));
	string dst(str);
	free(str);
	return dst;
}

string CharConverter::UTF8ToANSI(const char* strSrc)
{
	char* str = UnicodeToANSI(UTF8ToUnicode(strSrc));
	string dst(str);
	free(str);
	return dst;
}