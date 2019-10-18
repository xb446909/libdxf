#pragma once

bool __stdcall ReadDxf(const char* szFile);
void __stdcall Release();
int __stdcall GetShapeCount();
int __stdcall GetShapeType(int idx);
bool __stdcall GetLine(int idx, double* pX1, double* pY1, double* pZ1, double* pX2, double* pY2, double* pZ2);
bool __stdcall GetArc(int idx, double* pCenterX, double* pCenterY, double* pCenterZ, double* pRadius, double* pStartAngle, double* pEndAngle);
