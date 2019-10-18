#include "stdafx.h"
#include "ShapeCircle.h"

ShapeCircle::ShapeCircle(double cx, double cy, double cz, double r)
	: CenterX(cx)
	, CenterY(cy)
	, CenterZ(cz)
	, Radius(r)
{
}

ShapeType ShapeCircle::GetType()
{
	return TypeCircle;
}
