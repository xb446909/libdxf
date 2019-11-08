// tester.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "../libdxf/libdxf.h"

#pragma comment(lib, "../Debug/libdxf.lib")

int main()
{
	std::cout << "ReadDxf: " << (ReadDxf("test.dxf") ? "OK" : "NG") << std::endl;
	std::cout << "GetShapeCount: " << GetShapeCount() << std::endl;
	Release();
	std::cout << "ReadDxf: " << (ReadDxf("test.dxf") ? "OK" : "NG") << std::endl;
	std::cout << "GetShapeCount: " << GetShapeCount() << std::endl;
	Release();
}

