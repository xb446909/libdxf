#pragma once
#include <vector>
#include "Shapes.h"

using namespace std;

class ShapeManager
{
public:
	ShapeManager() {}
	~ShapeManager() { Clear(); }
	static ShapeManager* Instance();
public:
	void AddShape(Shapes* pShape);
	void Clear();

	Shapes* Shape(int idx);
	int Count();

	static ShapeManager* m_pInst;
private:
	vector<Shapes*> m_vecShapes;
};

