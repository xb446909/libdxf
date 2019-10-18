#include "stdafx.h"
#include "CreationClass.h"
#include "ShapeManager.h"
#include "ShapeLine.h"
#include "ShapeArc.h"
#include "CharConverter.h"
#include "ShapePoint.h"
#include "ShapeCircle.h"


CreationClass::CreationClass()
	: IsBlock(false)
{
}

CreationClass::~CreationClass()
{
}

void CreationClass::addLayer(const DL_LayerData& data)
{
}

void CreationClass::addBlock(const DL_BlockData& data)
{
	IsBlock = true;
}

void CreationClass::endBlock()
{
	IsBlock = false;
}

void CreationClass::endEntity()
{
}

void CreationClass::addPoint(const DL_PointData& data)
{
	if (IsBlock)
	{
		return;
	}

	CharConverter converter;
	ShapePoint* pPoint = new ShapePoint(
		data.x,
		data.y,
		data.z
	);
	pPoint->SetLayer(converter.UTF8ToANSI(getAttributes().getLayer().c_str()));
	ShapeManager::Instance()->AddShape(pPoint);
}

void CreationClass::addLine(const DL_LineData& data)
{
	if (IsBlock)
	{
		return;
	}

	CharConverter converter;
	ShapeLine* pLine = new ShapeLine(
		data.x1,
		data.y1,
		data.z1,
		data.x2,
		data.y2,
		data.z2
	);
	pLine->SetLayer(converter.UTF8ToANSI(getAttributes().getLayer().c_str()));
	ShapeManager::Instance()->AddShape(pLine);
}

void CreationClass::addArc(const DL_ArcData& data)
{
	if (IsBlock)
	{
		return;
	}

	CharConverter converter;
	ShapeArc* pArc = new ShapeArc(
		data.cx,
		data.cy,
		data.cz,
		data.radius,
		data.angle1,
		data.angle2
	);
	pArc->SetLayer(converter.UTF8ToANSI(getAttributes().getLayer().c_str()));
	ShapeManager::Instance()->AddShape(pArc);
}

void CreationClass::addCircle(const DL_CircleData& data)
{
	if (IsBlock)
	{
		return;
	}

	CharConverter converter;
	ShapeCircle* pCircle = new ShapeCircle(
		data.cx,
		data.cy,
		data.cz,
		data.radius
	);
	pCircle->SetLayer(converter.UTF8ToANSI(getAttributes().getLayer().c_str()));
	ShapeManager::Instance()->AddShape(pCircle);
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
