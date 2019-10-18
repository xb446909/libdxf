#pragma once

//读取dxf文件，szFile为文件路径，成功返回true，解析失败返回false
bool __stdcall ReadDxf(const char* szFile);

//释放内存(否则会内存泄漏)
void __stdcall Release();

//获取解析到的图形个数，返回图形个数
int __stdcall GetShapeCount();

//获取图形类型，idx为图形索引(从0开始)
//返回值：1:点 2:线段 3:圆弧 4:圆
int __stdcall GetShapeType(int idx);

//获取点数据，idx为索引，pX: X坐标 pY: Y坐标 pZ: Z坐标。成功返回true，否则false
bool __stdcall GetPoint(int idx, double* pX, double* pY, double* pZ);

//获取线数据，idx为索引，pX1: X1坐标 pY1: Y1坐标 pZ1: Z1坐标 pX2: X2坐标 pY2: Y2坐标 pZ2: Z2坐标。成功返回true，否则false
bool __stdcall GetLine(int idx, double* pX1, double* pY1, double* pZ1, double* pX2, double* pY2, double* pZ2);

//获取圆弧数据，idx为索引，pCenterX: 圆心X坐标 pCenterY: 圆心Y坐标 pCenterZ: 圆心Z坐标 pRadius: 半径 pStartAngle: 起始角度 pEndAngle: 终止角度。成功返回true，否则false
bool __stdcall GetArc(int idx, double* pCenterX, double* pCenterY, double* pCenterZ, double* pRadius, double* pStartAngle, double* pEndAngle);

//获取圆数据，idx为索引，pCenterX: 圆心X坐标 pCenterY: 圆心Y坐标 pCenterZ: 圆心Z坐标 pRadius: 半径。成功返回true，否则false
bool __stdcall GetCircle(int idx, double* pCenterX, double* pCenterY, double* pCenterZ, double* pRadius);
