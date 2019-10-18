#include "stdafx.h"
#include "ShapeManager.h"

ShapeManager* ShapeManager::m_pInst = nullptr;
extern bool g_bRelease;

ShapeManager* ShapeManager::Instance()
{
	if (m_pInst == nullptr)
	{
		m_pInst = new ShapeManager();
	}
	g_bRelease = false;
	return m_pInst;
}

void ShapeManager::AddShape(Shapes* pShape)
{
	m_vecShapes.push_back(pShape);
}

void ShapeManager::Clear()
{
	for (size_t i = 0; i < m_vecShapes.size(); i++)
	{
		delete m_vecShapes[i];
	}
	m_vecShapes.clear();
}

Shapes* ShapeManager::Shape(int idx)
{
	return m_vecShapes[idx];
}

int ShapeManager::Count()
{
	return m_vecShapes.size();
}



