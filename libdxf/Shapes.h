#pragma once

#include <string>

using namespace std;

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
	virtual string GetLayer() { return m_szLayer; }
	virtual void SetLayer(string layer) { m_szLayer = layer; }

protected:
	string m_szLayer;
};

