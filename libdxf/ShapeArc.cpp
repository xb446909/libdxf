#include "stdafx.h"
#include "ShapeArc.h"

ShapeArc::ShapeArc(double cx, double cy, double cz, double r, double angle1, double angle2)
	: CenterX(cx)
	, CenterY(cy)
	, CenterZ(cz)
	, Radius(r)
	, StartAngle(angle1)
	, EndAngle(angle2)
{
}

ShapeType ShapeArc::GetType()
{
	return TypeArc;
}
