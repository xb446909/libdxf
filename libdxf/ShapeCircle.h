#pragma once
#include "Shapes.h"
class ShapeCircle :
	public Shapes
{
public:
	ShapeCircle(double cx, double cy, double cz, double r);
	virtual ShapeType GetType();

	double CenterX;
	double CenterY;
	double CenterZ;
	double Radius;
};

