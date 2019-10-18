#pragma once
#include "Shapes.h"
class ShapePoint :
	public Shapes
{
public:
	ShapePoint();
	ShapePoint(double x, double y, double z);
	~ShapePoint();

	virtual ShapeType GetType();

	double X;
	double Y;
	double Z;
};

