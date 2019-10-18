#pragma once
#include "Shapes.h"
class ShapePoint :
	public Shapes
{
public:
	ShapePoint();
	~ShapePoint();

	virtual ShapeType GetType();
};

