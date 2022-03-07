#pragma once

#include <vector>

#include "Math.h"
#include "Triangle.h"
#include "Vertex.h"
#include "TextureSampler.h"

enum class ClipPlaneType
{
	Top,
	Bottom,
	Left,
	Right,
	Far,
	Near
};

class VertexShaderIn
{
public:
	Vector3D position;
	Vector3D normal;
	Vector2D texCoord;
	Vector4D tangent;
	Vector3D bitTangent;
	Vector3D color;
};

class PixelShaderIn
{
public:
	Vector2D texCoord;
	Vector4D vertexPosition;
	Vector3D normal;
	Vector3D viewPosition;
	Vector3D directionLightDirection;
	Vector4D color;
	Vector3D tangent;

	PixelShaderIn operator-()
	{
		PixelShaderIn ret;
		ret.texCoord = -texCoord;
		ret.vertexPosition = -vertexPosition;
		ret.normal = -normal;
		ret.color = -color;
		ret.tangent = -tangent;
		ret.viewPosition = viewPosition;
		ret.directionLightDirection = directionLightDirection;
		return ret;
	}
};

class VertexToPixel
{
public:
	VectorInt2D screenPos;
	PixelShaderIn pixelShaderIn;
};

class ClipPoint
{
public:
	VertexToPixel data;
	int index;
};

class EndPoint
{
public:
	VectorInt2D position;
	Vector4D position4D;
	Vertex vertex;
};

class ViewPort
{
public:
	VectorInt2D wh;
	Vector2D nf;
};

class PrimitiveConstructor
{
public:
	PrimitiveConstructor();
	~PrimitiveConstructor();

	void LineDraw();
	void TriangleDraw();
	void TriangleSample(VertexToPixel& p1, VertexToPixel& p2, VertexToPixel& p3, PixelShaderIn p2Increment, PixelShaderIn p3Increment);


	PixelColor* frameBuffer;
	float* sdepthBuffer;
	float* depthBuffer;
	std::vector<VertexToPixel> psiVertices;

	PixelShaderIn(*VertexShader)(VertexShaderIn);
	PixelColor(*PixelShader)(PixelShaderIn);

	void(*setPixel)(int, int, PixelColor);
	void(*drawBitmap)(int, int, int, int, const void*);

	ViewPort viewport;
	EndPoint* vertices;

	void SetVertexBuffer(int vertexNum, Vertex* vertices);
	void SetIndexBuffer(int indexNum, int* indices);
	void BackCull();
	void Clip();
	void PersDivide();

private:
	void ExecVertexSahder();
	void DrawLine(Vector4D startPoint, Vector4D endPoint, Color c1, Color c2);

	void SutherlandHodgmanClip(Triangle& triangle, std::vector<ClipPoint>& points);
	void TriangleClip(ClipPlaneType type, Vector3D& normal, std::vector<ClipPoint>& points);
	bool IsAllInClipSpace(Vector4D& p1, Vector4D& p2, Vector4D& p3);
	VertexToPixel InsersectionPoint(float t, VertexToPixel& p1, VertexToPixel& p2);
	void TriangulatePolygon(std::vector<ClipPoint>& points, std::vector<Triangle>& triangles);

private:
	std::vector<Triangle> triangles;
	std::vector<Triangle> backUpTriangles;
	int backNumOfVertex;
	int numOfTriangle;
	int numOfVertex;
	
};
