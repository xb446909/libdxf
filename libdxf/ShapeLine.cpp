#include "stdafx.h"
#include "ShapeLine.h"

ShapeLine::ShapeLine()
	: X1(0.0)
	, Y1(0.0)
	, Z1(0.0)
	, X2(0.0)
	, Y2(0.0)
	, Z2(0.0)
{
}

ShapeLine::ShapeLine(double x1, double y1, double z1, double x2, double y2, double z2)
	: X1(x1)
	, Y1(y1)
	, Z1(z1)
	, X2(x2)
	, Y2(y2)
	, Z2(z2)
{
}

ShapeType ShapeLine::GetType()
{
	return TypeLine;
}
