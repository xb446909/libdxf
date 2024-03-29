// libdxf.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "libdxf.h"
#include "dl_dxf.h"
#include "CreationClass.h"
#include "ShapeManager.h"
#include "ShapeLine.h"
#include "ShapeArc.h"
#include "ShapePoint.h"
#include "ShapeCircle.h"

#if 0
void testReading(char* file) {
	// Load DXF file into memory:
	std::cout << "Reading file " << file << "...\n";
	Test_CreationClass* creationClass = new Test_CreationClass();
	DL_Dxf* dxf = new DL_Dxf();
	if (!dxf->in(file, creationClass)) { // if file open failed
		std::cerr << file << " could not be opened.\n";
		return;
	}
	delete dxf;
	delete creationClass;
}



void testWriting() {
	DL_Dxf* dxf = new DL_Dxf();
	DL_Codes::version exportVersion = DL_Codes::AC1015;
	DL_WriterA* dw = dxf->out("myfile.dxf", exportVersion);
	if (dw == NULL) {
		printf("Cannot open file 'myfile.dxf' \
               for writing.");
		// abort function e.g. with return
	}

	dxf->writeHeader(*dw);
	/*
	// int variable:
	dw->dxfString(9, "$INSUNITS");
	dw->dxfInt(70, 4);
	// real (double, float) variable:
	dw->dxfString(9, "$DIMEXE");
	dw->dxfReal(40, 1.25);
	// string variable:
	dw->dxfString(9, "$TEXTSTYLE");
	dw->dxfString(7, "Standard");
	// vector variable:
	dw->dxfString(9, "$LIMMIN");
	dw->dxfReal(10, 0.0);
	dw->dxfReal(20, 0.0);
	*/
	dw->sectionEnd();
	dw->sectionTables();
	dxf->writeVPort(*dw);

	dw->tableLinetypes(3);
	dxf->writeLinetype(*dw, DL_LinetypeData("BYBLOCK", "BYBLOCK", 0, 0, 0.0));
	dxf->writeLinetype(*dw, DL_LinetypeData("BYLAYER", "BYLAYER", 0, 0, 0.0));
	dxf->writeLinetype(*dw, DL_LinetypeData("CONTINUOUS", "Continuous", 0, 0, 0.0));
	dw->tableEnd();

	int numberOfLayers = 3;
	dw->tableLayers(numberOfLayers);

	dxf->writeLayer(*dw,
		DL_LayerData("0", 0),
		DL_Attributes(
			std::string(""),      // leave empty
			DL_Codes::black,        // default color
			100,                  // default width
			"CONTINUOUS", 1.0));       // default line style

	dxf->writeLayer(*dw,
		DL_LayerData("mainlayer", 0),
		DL_Attributes(
			std::string(""),
			DL_Codes::red,
			100,
			"CONTINUOUS", 1.0));

	dxf->writeLayer(*dw,
		DL_LayerData("anotherlayer", 0),
		DL_Attributes(
			std::string(""),
			DL_Codes::black,
			100,
			"CONTINUOUS", 1.0));

	dw->tableEnd();

	dw->tableStyle(1);
	dxf->writeStyle(*dw, DL_StyleData("standard", 0, 2.5, 1.0, 0.0, 0, 2.5, "txt", ""));
	dw->tableEnd();

	dxf->writeView(*dw);
	dxf->writeUcs(*dw);

	dw->tableAppid(1);
	dxf->writeAppid(*dw, "ACAD");
	dw->tableEnd();

	dxf->writeDimStyle(*dw, 1, 1, 1, 1, 1);

	dxf->writeBlockRecord(*dw);
	dxf->writeBlockRecord(*dw, "myblock1");
	dxf->writeBlockRecord(*dw, "myblock2");
	dw->tableEnd();

	dw->sectionEnd();

	dw->sectionBlocks();
	dxf->writeBlock(*dw, DL_BlockData("*Model_Space", 0, 0.0, 0.0, 0.0));
	dxf->writeEndBlock(*dw, "*Model_Space");
	dxf->writeBlock(*dw, DL_BlockData("*Paper_Space", 0, 0.0, 0.0, 0.0));
	dxf->writeEndBlock(*dw, "*Paper_Space");
	dxf->writeBlock(*dw, DL_BlockData("*Paper_Space0", 0, 0.0, 0.0, 0.0));
	dxf->writeEndBlock(*dw, "*Paper_Space0");

	dxf->writeBlock(*dw, DL_BlockData("myblock1", 0, 0.0, 0.0, 0.0));
	// ...
	// write block entities e.g. with dxf->writeLine(), ..
	// ...
	dxf->writeEndBlock(*dw, "myblock1");

	dxf->writeBlock(*dw, DL_BlockData("myblock2", 0, 0.0, 0.0, 0.0));
	// ...
	// write block entities e.g. with dxf->writeLine(), ..
	// ...
	dxf->writeEndBlock(*dw, "myblock2");

	dw->sectionEnd();
	dw->sectionEntities();

	// write all entities in model space:
	dxf->writePoint(
		*dw,
		DL_PointData(10.0,
			45.0,
			0.0),
		DL_Attributes("mainlayer", 256, -1, "BYLAYER", 1.0));

	dxf->writeLine(
		*dw,
		DL_LineData(25.0,   // start point
			30.0,
			0.0,
			100.0,   // end point
			120.0,
			0.0),
		DL_Attributes("mainlayer", 256, -1, "BYLAYER", 1.0));

	dw->sectionEnd();

	dxf->writeObjects(*dw);
	dxf->writeObjectsEnd(*dw);

	dw->dxfEOF();
	dw->close();
	delete dw;
	delete dxf;
}
#endif

bool g_bRelease = false;

bool __stdcall ReadDxf(const char* szFile)
{
	ShapeManager::Instance()->Clear();
	CreationClass* creation_class = new CreationClass();
	DL_Dxf* dxf = new DL_Dxf();
	if (!dxf->in(szFile, creation_class)) 
	{
		return false;
	}
	delete dxf;
	delete creation_class;
	return true;
}

void __stdcall Release()
{
	if (!g_bRelease)
	{
		ShapeManager::Instance()->Clear();
		delete ShapeManager::m_pInst;
		ShapeManager::m_pInst = nullptr;
		g_bRelease = true;
	}
}

int __stdcall GetShapeCount()
{
	return ShapeManager::Instance()->Count();
}

int __stdcall GetShapeType(int idx)
{
	return (int)ShapeManager::Instance()->Shape(idx)->GetType();
}

bool __stdcall GetPoint(int idx, double* pX, double* pY, double* pZ)
{
	if (GetShapeType(idx) != (int)TypePoint) return false;

	ShapePoint* pPoint = (ShapePoint*)ShapeManager::Instance()->Shape(idx);
	*pX = pPoint->X;
	*pY = pPoint->Y;
	*pZ = pPoint->Z;
	return true;
}

bool __stdcall GetLine(int idx, double* pX1, double* pY1, double* pZ1, double* pX2, double* pY2, double* pZ2)
{
	if (GetShapeType(idx) != (int)TypeLine) return false;

	ShapeLine* pLine = (ShapeLine*)ShapeManager::Instance()->Shape(idx);
	*pX1 = pLine->X1;
	*pY1 = pLine->Y1;
	*pZ1 = pLine->Z1;
	*pX2 = pLine->X2;
	*pY2 = pLine->Y2;
	*pZ2 = pLine->Z2;
	return true;
}

bool __stdcall GetArc(int idx, double* pCenterX, double* pCenterY, double* pCenterZ, double* pRadius, double* pStartAngle, double* pEndAngle)
{
	if (GetShapeType(idx) != (int)TypeArc) return false;

	ShapeArc* pArc = (ShapeArc*)ShapeManager::Instance()->Shape(idx);
	*pCenterX = pArc->CenterX;
	*pCenterY = pArc->CenterY;
	*pCenterZ = pArc->CenterZ;
	*pRadius = pArc->Radius;
	*pStartAngle = pArc->StartAngle;
	*pEndAngle = pArc->EndAngle;
	return true;
}

bool __stdcall GetCircle(int idx, double* pCenterX, double* pCenterY, double* pCenterZ, double* pRadius)
{
	if (GetShapeType(idx) != (int)TypeCircle) return false;

	ShapeCircle* pCircle = (ShapeCircle*)ShapeManager::Instance()->Shape(idx);
	*pCenterX = pCircle->CenterX;
	*pCenterY = pCircle->CenterY;
	*pCenterZ = pCircle->CenterZ;
	*pRadius = pCircle->Radius;
	return true;
}
