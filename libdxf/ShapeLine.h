#pragma once
#include "Shapes.h"
class ShapeLine :
	public Shapes
{
public:
	ShapeLine();
	ShapeLine(double x1, double y1, double z1,
			  double x2, double y2, double z2);


	virtual ShapeType GetType();

	double X1;
	double Y1;
	double Z1;
	double X2;
	double Y2;
	double Z2;
};

