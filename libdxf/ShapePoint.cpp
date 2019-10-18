#include "stdafx.h"
#include "ShapePoint.h"

ShapePoint::ShapePoint()
	: X(0.0)
	, Y(0.0)
	, Z(0.0)
{
}

ShapePoint::ShapePoint(double x, double y, double z)
	: X(x)
	, Y(y)
	, Z(z)
{
}

ShapePoint::~ShapePoint()
{
}

ShapeType ShapePoint::GetType()
{
	return TypePoint;
}
