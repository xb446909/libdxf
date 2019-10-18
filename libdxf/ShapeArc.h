#pragma once
#include "Shapes.h"
class ShapeArc :
	public Shapes
{
public:
	ShapeArc(double cx, double cy, double cz, double r, double angle1, double angle2);

	virtual ShapeType GetType();

	double CenterX;
	double CenterY;
	double CenterZ;

	double Radius;
	double StartAngle;
	double EndAngle;
};

