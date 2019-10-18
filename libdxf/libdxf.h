#pragma once

//��ȡdxf�ļ���szFileΪ�ļ�·�����ɹ�����true������ʧ�ܷ���false
bool __stdcall ReadDxf(const char* szFile);

//�ͷ��ڴ�(������ڴ�й©)
void __stdcall Release();

//��ȡ��������ͼ�θ���������ͼ�θ���
int __stdcall GetShapeCount();

//��ȡͼ�����ͣ�idxΪͼ������(��0��ʼ)
//����ֵ��1:�� 2:�߶� 3:Բ�� 4:Բ
int __stdcall GetShapeType(int idx);

//��ȡ�����ݣ�idxΪ������pX: X���� pY: Y���� pZ: Z���ꡣ�ɹ�����true������false
bool __stdcall GetPoint(int idx, double* pX, double* pY, double* pZ);

//��ȡ�����ݣ�idxΪ������pX1: X1���� pY1: Y1���� pZ1: Z1���� pX2: X2���� pY2: Y2���� pZ2: Z2���ꡣ�ɹ�����true������false
bool __stdcall GetLine(int idx, double* pX1, double* pY1, double* pZ1, double* pX2, double* pY2, double* pZ2);

//��ȡԲ�����ݣ�idxΪ������pCenterX: Բ��X���� pCenterY: Բ��Y���� pCenterZ: Բ��Z���� pRadius: �뾶 pStartAngle: ��ʼ�Ƕ� pEndAngle: ��ֹ�Ƕȡ��ɹ�����true������false
bool __stdcall GetArc(int idx, double* pCenterX, double* pCenterY, double* pCenterZ, double* pRadius, double* pStartAngle, double* pEndAngle);

//��ȡԲ���ݣ�idxΪ������pCenterX: Բ��X���� pCenterY: Բ��Y���� pCenterZ: Բ��Z���� pRadius: �뾶���ɹ�����true������false
bool __stdcall GetCircle(int idx, double* pCenterX, double* pCenterY, double* pCenterZ, double* pRadius);
