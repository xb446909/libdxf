#pragma once
enum ShapeType
{
	TypeNone = 0,
	TypePoint,
	TypeLine,
	TypeArc,
	TypeCircle
};

class Shapes
{
public:
	virtual ShapeType GetType();
};

