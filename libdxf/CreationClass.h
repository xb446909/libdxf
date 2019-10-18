#pragma once
#include "dl_creationadapter.h"


class CreationClass : public DL_CreationAdapter
{
public:
	CreationClass();
	~CreationClass();

public:
	virtual void addLayer(const DL_LayerData& data);
	virtual void addBlock(const DL_BlockData& data);
	virtual void endBlock();
	virtual void endEntity();
	virtual void addPoint(const DL_PointData& data);
	virtual void addLine(const DL_LineData& data);
	virtual void addArc(const DL_ArcData& data);
	virtual void addCircle(const DL_CircleData& data);
	virtual void addPolyline(const DL_PolylineData& data);
	virtual void addVertex(const DL_VertexData& data);
	virtual void add3dFace(const DL_3dFaceData& data);

private:
	bool IsBlock;
};

