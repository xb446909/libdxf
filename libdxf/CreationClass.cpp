#include "stdafx.h"
#include "CreationClass.h"
#include "ShapeManager.h"
#include "ShapeLine.h"


CreationClass::CreationClass()
{
}

CreationClass::~CreationClass()
{
}

void CreationClass::addLayer(const DL_LayerData& data)
{
}

void CreationClass::addPoint(const DL_PointData& data)
{
}

void CreationClass::addLine(const DL_LineData& data)
{
	ShapeLine* pLine = new ShapeLine(
		data.x1,
		data.y1,
		data.z1,
		data.x2,
		data.y2,
		data.z2);
	ShapeManager::Instance()->AddShape(pLine);
}

void CreationClass::addArc(const DL_ArcData& data)
{
}

void CreationClass::addCircle(const DL_CircleData& data)
{
}

void CreationClass::addPolyline(const DL_PolylineData& data)
{
}

void CreationClass::addVertex(const DL_VertexData& data)
{
}

void CreationClass::add3dFace(const DL_3dFaceData& data)
{
}
