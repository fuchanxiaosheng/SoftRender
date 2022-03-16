#include "PrimitiveConstructor.h"

#include <cmath>
#include <cstdlib>

void PrimitiveConstructor::LineDraw()
{
	for (int i = 0; i < numOfTriangle; i++)
	{
		DrawLine(
			psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.vertexPosition, psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.vertexPosition,
			Color(psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.color.x, psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.color.y, psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.color.z, 1.0f),
			Color(psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.color.x, psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.color.y, psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.color.z, 1.0f)
			);
		DrawLine(
			psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.vertexPosition, psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.vertexPosition,
			Color(psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.color.x, psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.color.y, psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.color.z, 1.0f),
			Color(psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.color.x, psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.color.y, psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.color.z, 1.0f)
		);
		DrawLine(
			psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.vertexPosition, psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.vertexPosition,
			Color(psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.color.x, psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.color.y, psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.color.z, 1.0f),
			Color(psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.color.x, psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.color.y, psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.color.z, 1.0f)
		);
	}
	drawBitmap(0, 0, viewport.wh.x, viewport.wh.y, frameBuffer);
}

void PrimitiveConstructor::DrawLine(Vector4D a, Vector4D b, Color c1, Color c2)
{
	VectorInt2D startPoint(a.x, a.y), endPoint(b.x, b.y);
	int dx = abs(startPoint.x - endPoint.x);
	int dy = abs(startPoint.y - endPoint.y);
	int ix = startPoint.x < endPoint.x ? 1 : -1;
	int iy = startPoint.y < endPoint.y ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2, e2;
	int length = sqrt(dx * dx + dy * dy);
	float rlength = length != 0 ? 1.0f / length : 0;
	PixelColor c;
	c.r = c1.r;
	c.g = c1.g;
	c.b = c1.b;
	Vector3D increment;
	double ir = (c1.r - c2.r) * rlength;
	double ig = (c1.g - c2.g) * rlength;
	double ib = (c1.b - c2.b) * rlength;
	for (; startPoint.y >= 0 && startPoint.y < viewport.wh.y && startPoint.x >= 0 && startPoint.x < viewport.wh.x;)
	{
		frameBuffer[startPoint.y * viewport.wh.x + startPoint.x] = c;
		if (startPoint == endPoint)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			startPoint.x += ix;
			increment.x += ir;
			increment.y += ig;
			increment.z += ib;
			c.r = c1.r + increment.x;
			c.r = c1.g + increment.y;
			c.r = c1.b + increment.z;
		}
		if (e2 < dy)
		{
			err += dx;
			startPoint.y += iy;
			increment.x += ir;
			increment.y += ig;
			increment.z += ib;
			c.r = c1.r + increment.x;
			c.r = c1.g + increment.y;
			c.r = c1.b + increment.z;
		}
	}
}

void PrimitiveConstructor::TriangleDraw()
{
	memset(frameBuffer, 255, sizeof(PixelColor) * viewport.wh.x * viewport.wh.y);
	memcpy(depthBuffer, sdepthBuffer, sizeof(float) * viewport.wh.x * viewport.wh.y);
	VertexToPixel* p;
	VertexToPixel vertex;
	PixelShaderIn edge1Increment, edge2Increment, edge3Increment;
	float t;
	for (int i = 0; i < numOfTriangle; i++)
	{
		if (i == 2)
			i = i;
		float rz = 0;
		VertexToPixel aData = psiVertices[triangles[i].VertexIndex[0]];
		rz = aData.pixelShaderIn.vertexPosition.z != 0 ? 1.0f / aData.pixelShaderIn.vertexPosition.z : 0;
		aData.pixelShaderIn.color = aData.pixelShaderIn.color * rz;
		aData.pixelShaderIn.normal = aData.pixelShaderIn.normal * rz;
		aData.pixelShaderIn.texCoord = aData.pixelShaderIn.texCoord * rz;
		aData.pixelShaderIn.tangent = aData.pixelShaderIn.tangent * rz;

		VertexToPixel bData = psiVertices[triangles[i].VertexIndex[1]];
		rz = bData.pixelShaderIn.vertexPosition.z != 0 ? 1.0f / bData.pixelShaderIn.vertexPosition.z : 0;
		bData.pixelShaderIn.color = bData.pixelShaderIn.color * rz;
		bData.pixelShaderIn.normal = bData.pixelShaderIn.normal * rz;
		bData.pixelShaderIn.texCoord = bData.pixelShaderIn.texCoord * rz;
		bData.pixelShaderIn.tangent = bData.pixelShaderIn.tangent * rz;

		VertexToPixel cData = psiVertices[triangles[i].VertexIndex[2]];
		rz = cData.pixelShaderIn.vertexPosition.z != 0 ? 1.0f / cData.pixelShaderIn.vertexPosition.z : 0;
		cData.pixelShaderIn.color = cData.pixelShaderIn.color * rz;
		cData.pixelShaderIn.normal = cData.pixelShaderIn.normal * rz;
		cData.pixelShaderIn.texCoord = cData.pixelShaderIn.texCoord * rz;
		cData.pixelShaderIn.tangent = cData.pixelShaderIn.tangent * rz;

		edge1Increment.vertexPosition.y = abs(bData.pixelShaderIn.vertexPosition.y - aData.pixelShaderIn.vertexPosition.y);
		edge1Increment.vertexPosition.y = edge1Increment.vertexPosition.y != 0 ? 1.0f / edge1Increment.vertexPosition.y : 0;
		edge1Increment.vertexPosition.x = (bData.pixelShaderIn.vertexPosition.x - aData.pixelShaderIn.vertexPosition.x) * edge1Increment.vertexPosition.y;
		edge1Increment.vertexPosition.z = (bData.pixelShaderIn.vertexPosition.z - aData.pixelShaderIn.vertexPosition.z) * edge1Increment.vertexPosition.y;
		edge1Increment.color = (bData.pixelShaderIn.color - aData.pixelShaderIn.color) * edge1Increment.vertexPosition.y;
		edge1Increment.normal = (bData.pixelShaderIn.normal - aData.pixelShaderIn.normal) * edge1Increment.vertexPosition.y;
		edge1Increment.texCoord = (bData.pixelShaderIn.texCoord - aData.pixelShaderIn.texCoord) * edge1Increment.vertexPosition.y;
		edge1Increment.tangent = (bData.pixelShaderIn.tangent - aData.pixelShaderIn.tangent) * edge1Increment.vertexPosition.y;

		edge2Increment.vertexPosition.y = abs(cData.pixelShaderIn.vertexPosition.y - bData.pixelShaderIn.vertexPosition.y);
		edge2Increment.vertexPosition.y = edge2Increment.vertexPosition.y != 0 ? 1.0f / edge2Increment.vertexPosition.y : 0;
		edge2Increment.vertexPosition.x = (cData.pixelShaderIn.vertexPosition.x - bData.pixelShaderIn.vertexPosition.x) * edge2Increment.vertexPosition.y;
		edge2Increment.vertexPosition.z = (cData.pixelShaderIn.vertexPosition.z - bData.pixelShaderIn.vertexPosition.z) * edge2Increment.vertexPosition.y;
		edge2Increment.color = (cData.pixelShaderIn.color - bData.pixelShaderIn.color) * edge2Increment.vertexPosition.y;
		edge2Increment.normal = (cData.pixelShaderIn.normal - bData.pixelShaderIn.normal) * edge2Increment.vertexPosition.y;
		edge2Increment.texCoord = (cData.pixelShaderIn.texCoord - bData.pixelShaderIn.texCoord) * edge2Increment.vertexPosition.y;
		edge2Increment.tangent = (cData.pixelShaderIn.tangent - bData.pixelShaderIn.tangent) * edge2Increment.vertexPosition.y;

		edge3Increment.vertexPosition.y = abs(aData.pixelShaderIn.vertexPosition.y - cData.pixelShaderIn.vertexPosition.y);
		edge3Increment.vertexPosition.y = edge3Increment.vertexPosition.y != 0 ? 1.0f / edge3Increment.vertexPosition.y : 0;
		edge3Increment.vertexPosition.x = (aData.pixelShaderIn.vertexPosition.x - cData.pixelShaderIn.vertexPosition.x) * edge3Increment.vertexPosition.y;
		edge3Increment.vertexPosition.z = (aData.pixelShaderIn.vertexPosition.z - cData.pixelShaderIn.vertexPosition.z) * edge3Increment.vertexPosition.y;
		edge3Increment.color = (aData.pixelShaderIn.color - cData.pixelShaderIn.color) * edge3Increment.vertexPosition.y;
		edge3Increment.normal = (aData.pixelShaderIn.normal - cData.pixelShaderIn.normal) * edge3Increment.vertexPosition.y;
		edge3Increment.texCoord = (aData.pixelShaderIn.texCoord - cData.pixelShaderIn.texCoord) * edge3Increment.vertexPosition.y;
		edge3Increment.tangent = (aData.pixelShaderIn.tangent - cData.pixelShaderIn.tangent) * edge3Increment.vertexPosition.y;
	

		if ((aData.screenPos.y - bData.screenPos.y) * (bData.screenPos.y - cData.screenPos.y) > 0)
		{
			p = &bData;
			t = aData.screenPos.y - cData.screenPos.y;
			t = t != 0 ? (p->screenPos.y - cData.screenPos.y) / t : 0;
			vertex.pixelShaderIn.vertexPosition.x = cData.pixelShaderIn.vertexPosition.x + (aData.pixelShaderIn.vertexPosition.x - cData.pixelShaderIn.vertexPosition.x) * t;
			vertex.pixelShaderIn.vertexPosition.y = p->screenPos.y;
			vertex.pixelShaderIn.vertexPosition.z = cData.pixelShaderIn.vertexPosition.z + (aData.pixelShaderIn.vertexPosition.z - cData.pixelShaderIn.vertexPosition.z) * t;
			vertex.screenPos.x = vertex.pixelShaderIn.vertexPosition.x;
			vertex.screenPos.y = vertex.pixelShaderIn.vertexPosition.y;
			vertex.pixelShaderIn.color = cData.pixelShaderIn.color + (aData.pixelShaderIn.color - cData.pixelShaderIn.color) * t;
			vertex.pixelShaderIn.texCoord = cData.pixelShaderIn.texCoord + (aData.pixelShaderIn.texCoord - cData.pixelShaderIn.texCoord) * t;
			vertex.pixelShaderIn.normal = cData.pixelShaderIn.normal + (aData.pixelShaderIn.normal - cData.pixelShaderIn.normal) * t;
			vertex.pixelShaderIn.tangent = cData.pixelShaderIn.tangent + (aData.pixelShaderIn.tangent - cData.pixelShaderIn.tangent) * t;

			TriangleSample(aData, *p, vertex, edge1Increment, -edge3Increment);
			TriangleSample(cData, *p, vertex, -edge2Increment, edge3Increment);
		}
		else if ((bData.screenPos.y - aData.screenPos.y) * (aData.screenPos.y - cData.screenPos.y) > 0)
		{
			p = &aData;
			t = bData.screenPos.y - cData.screenPos.y;
			t = t != 0 ? (p->screenPos.y - cData.screenPos.y) / t : 0;
			vertex.pixelShaderIn.vertexPosition.x = cData.pixelShaderIn.vertexPosition.x + (bData.pixelShaderIn.vertexPosition.x - cData.pixelShaderIn.vertexPosition.x) * t;
			vertex.pixelShaderIn.vertexPosition.y = p->screenPos.y;
			vertex.pixelShaderIn.vertexPosition.z = cData.pixelShaderIn.vertexPosition.z + (bData.pixelShaderIn.vertexPosition.z - cData.pixelShaderIn.vertexPosition.z) * t;
			vertex.screenPos.x = vertex.pixelShaderIn.vertexPosition.x;
			vertex.screenPos.y = vertex.pixelShaderIn.vertexPosition.y;
			vertex.pixelShaderIn.color = cData.pixelShaderIn.color + (bData.pixelShaderIn.color - cData.pixelShaderIn.color) * t;
			vertex.pixelShaderIn.texCoord = cData.pixelShaderIn.texCoord + (bData.pixelShaderIn.texCoord - cData.pixelShaderIn.texCoord) * t;
			vertex.pixelShaderIn.normal = cData.pixelShaderIn.normal + (bData.pixelShaderIn.normal - cData.pixelShaderIn.normal) * t;
			vertex.pixelShaderIn.tangent = cData.pixelShaderIn.tangent + (bData.pixelShaderIn.tangent - cData.pixelShaderIn.tangent) * t;

			TriangleSample(bData, *p, vertex, -edge1Increment, edge2Increment);
			TriangleSample(cData, *p, vertex, edge3Increment, -edge2Increment);
		}
		else if ((aData.screenPos.y - cData.screenPos.y) * (cData.screenPos.y - bData.screenPos.y) > 0)
		{
			p = &cData;
			t = bData.screenPos.y - aData.screenPos.y;
			t = t != 0 ? (p->screenPos.y - aData.screenPos.y) / t : 0;
			vertex.pixelShaderIn.vertexPosition.x = aData.pixelShaderIn.vertexPosition.x + (bData.pixelShaderIn.vertexPosition.x - aData.pixelShaderIn.vertexPosition.x) * t;
			vertex.pixelShaderIn.vertexPosition.y = p->screenPos.y;
			vertex.pixelShaderIn.vertexPosition.z = aData.pixelShaderIn.vertexPosition.z + (bData.pixelShaderIn.vertexPosition.z - aData.pixelShaderIn.vertexPosition.z) * t;
			vertex.screenPos.x = vertex.pixelShaderIn.vertexPosition.x;
			vertex.screenPos.y = vertex.pixelShaderIn.vertexPosition.y;
			vertex.pixelShaderIn.color = aData.pixelShaderIn.color + (bData.pixelShaderIn.color - aData.pixelShaderIn.color) * t;
			vertex.pixelShaderIn.texCoord = aData.pixelShaderIn.texCoord + (bData.pixelShaderIn.texCoord - aData.pixelShaderIn.texCoord) * t;
			vertex.pixelShaderIn.normal = aData.pixelShaderIn.normal + (bData.pixelShaderIn.normal - aData.pixelShaderIn.normal) * t;
			vertex.pixelShaderIn.tangent = aData.pixelShaderIn.tangent + (bData.pixelShaderIn.tangent - aData.pixelShaderIn.tangent) * t;

			TriangleSample(aData, *p, vertex, -edge3Increment, edge1Increment);
			TriangleSample(bData, *p, vertex, edge2Increment, -edge1Increment);
		}
		else
		{
			if (aData.screenPos.y == bData.screenPos.y)
			{
				TriangleSample(cData, bData, aData, -edge2Increment, edge3Increment);
			}
			else if (aData.screenPos.y == cData.screenPos.y)
			{
				TriangleSample(bData, aData, cData, -edge1Increment, edge2Increment);
			}
			else if (bData.screenPos.y == cData.screenPos.y)
			{
				TriangleSample(aData, bData, cData, edge1Increment, -edge3Increment);
			}
			else
			{

			}
		}
	}
	drawBitmap(0, 0, viewport.wh.x, viewport.wh.y, frameBuffer);
}

void PrimitiveConstructor::TriangleSample(VertexToPixel& p1, VertexToPixel& p2, VertexToPixel& p3, PixelShaderIn p2Increment, PixelShaderIn p3Increment)
{
	float m1dx, m2dx, m1dz, m2dz;
	VertexToPixel m1, m2, m1increment, m2increment;
	int highY;
	VertexToPixel* left, * right;
	PixelShaderIn* leftIncrement, * rightIncrement;
	VertexToPixel* m1base,* m2base;
	Vector3D offset1;
	Vector3D offset2;
	PixelShaderIn pIn;
	left = p2.screenPos.x > p3.screenPos.x ? &p3 : &p2;
	leftIncrement = p2.screenPos.x > p3.screenPos.x ? &p3Increment : &p2Increment;
	right = p2.screenPos.x > p3.screenPos.x ? &p2 : &p3;
	rightIncrement = p2.screenPos.x > p3.screenPos.x ? &p2Increment : &p3Increment;

	if (p1.screenPos.y <= p2.screenPos.y)
	{
		m1dx = leftIncrement->vertexPosition.x;
		m1dz = leftIncrement->vertexPosition.z;
		m1increment.pixelShaderIn.color = leftIncrement->color;
		m1increment.pixelShaderIn.normal = leftIncrement->normal;
		m1increment.pixelShaderIn.texCoord = leftIncrement->texCoord;
		m1increment.pixelShaderIn.tangent = leftIncrement->tangent;
		offset1.x = m1dx;
		m1 = p1;
		m1base = &p1;

		m2dx = rightIncrement->vertexPosition.x;
		m2dz = rightIncrement->vertexPosition.z;
		m2increment.pixelShaderIn.color = rightIncrement->color;
		m2increment.pixelShaderIn.normal = rightIncrement->normal;
		m2increment.pixelShaderIn.texCoord = rightIncrement->texCoord;
		m2increment.pixelShaderIn.tangent = rightIncrement->tangent;
		offset2.x = m2dx;
		m2 = p1;
		m2base = &p1;

		highY = p2.screenPos.y;
	}
	else
	{

		*leftIncrement = -(*(leftIncrement));
		*rightIncrement = -(*(rightIncrement));

		m1dx = leftIncrement->vertexPosition.x;
		m1dz = leftIncrement->vertexPosition.z;
		m1increment.pixelShaderIn.color = leftIncrement->color;
		m1increment.pixelShaderIn.normal = leftIncrement->normal;
		m1increment.pixelShaderIn.texCoord = leftIncrement->texCoord;
		m1increment.pixelShaderIn.tangent = leftIncrement->tangent;
		offset1.x = m1dx;
		m1 = *left;
		m1base = left;

		m2dx = rightIncrement->vertexPosition.x;
		m2dz = rightIncrement->vertexPosition.z;
		m2increment.pixelShaderIn.color = rightIncrement->color;
		m2increment.pixelShaderIn.normal = rightIncrement->normal;
		m2increment.pixelShaderIn.texCoord = rightIncrement->texCoord;
		m2increment.pixelShaderIn.tangent = rightIncrement->tangent;
		offset2.x = m2dx;
		m2 = *right;
		m2base = right;

		highY = p1.screenPos.y;
	}

	while (m1.screenPos.y < highY)
	{
		long yLine = m1.screenPos.y * viewport.wh.x;
		float rLength = m2.pixelShaderIn.vertexPosition.x - m1.pixelShaderIn.vertexPosition.x;
		rLength = rLength != 0 ? 1.0f / rLength : 0;
		VertexToPixel increment;
		increment.pixelShaderIn.color = (m2.pixelShaderIn.color - m1.pixelShaderIn.color) * rLength;
		increment.pixelShaderIn.texCoord = (m2.pixelShaderIn.texCoord - m1.pixelShaderIn.texCoord) * rLength;
		increment.pixelShaderIn.normal = (m2.pixelShaderIn.normal - m1.pixelShaderIn.normal) * rLength;
		increment.pixelShaderIn.tangent = (m2.pixelShaderIn.tangent - m1.pixelShaderIn.tangent) * rLength;
		increment.pixelShaderIn.vertexPosition.z = (m2.pixelShaderIn.vertexPosition.z - m1.pixelShaderIn.vertexPosition.z) * rLength;

		VertexToPixel current = m1;
		for (int i = m1.screenPos.x; i < m2.screenPos.x; i++)
		{
			if (depthBuffer[yLine + i] > current.pixelShaderIn.vertexPosition.z && current.pixelShaderIn.vertexPosition.z != 0)
			{
				float depth = current.pixelShaderIn.vertexPosition.z;
				pIn.color = current.pixelShaderIn.color * depth;
				pIn.color.w = 1.0f;
				if (PixelShader != nullptr)
				{
					pIn.texCoord = current.pixelShaderIn.texCoord * depth;
					pIn.normal = current.pixelShaderIn.normal * depth;
					pIn.tangent = current.pixelShaderIn.tangent * depth;
					pIn.vertexPosition.x = i;
					pIn.vertexPosition.y = yLine;
					pIn.vertexPosition.z = current.pixelShaderIn.vertexPosition.z;
					frameBuffer[yLine + i] = PixelShader(pIn, this);
				}
				else
				{
					frameBuffer[yLine + i].r = pIn.color.x;
					frameBuffer[yLine + i].g = pIn.color.y;
					frameBuffer[yLine + i].b = pIn.color.z;
					frameBuffer[yLine + i].a = 1;
				}
				depthBuffer[yLine + i] = current.pixelShaderIn.vertexPosition.z;
			}
			current.pixelShaderIn.color += increment.pixelShaderIn.color;
			current.pixelShaderIn.vertexPosition.z += increment.pixelShaderIn.vertexPosition.z;
			if (PixelShader != nullptr)
			{
				current.pixelShaderIn.normal += increment.pixelShaderIn.normal;
				current.pixelShaderIn.texCoord += increment.pixelShaderIn.texCoord;
				current.pixelShaderIn.tangent += increment.pixelShaderIn.tangent;
			}
		}
		m1.screenPos.y++;
		m1.pixelShaderIn.vertexPosition.y = m1.screenPos.y;
		offset1.x += m1dx;
		m1.pixelShaderIn.vertexPosition.x = m1base->pixelShaderIn.vertexPosition.x + offset1.x;
		m1.screenPos.x = m1.pixelShaderIn.vertexPosition.x;
		m1.pixelShaderIn.vertexPosition.z += m1dz;
		m1.pixelShaderIn.color += m1increment.pixelShaderIn.color;
		m1.pixelShaderIn.normal += m1increment.pixelShaderIn.normal;
		m1.pixelShaderIn.texCoord += m1increment.pixelShaderIn.texCoord;
		m1.pixelShaderIn.tangent += m1increment.pixelShaderIn.tangent;

		m2.screenPos.y++;
		m2.pixelShaderIn.vertexPosition.y = m2.screenPos.y;
		offset2.x += m2dx;
		m2.pixelShaderIn.vertexPosition.x = m2base->pixelShaderIn.vertexPosition.x + offset2.x;
		m2.screenPos.x = m2.pixelShaderIn.vertexPosition.x;
		m2.pixelShaderIn.vertexPosition.z += m2dz;
		m2.pixelShaderIn.color += m2increment.pixelShaderIn.color;
		m2.pixelShaderIn.normal += m2increment.pixelShaderIn.normal;
		m2.pixelShaderIn.texCoord += m2increment.pixelShaderIn.texCoord;
		m2.pixelShaderIn.tangent += m2increment.pixelShaderIn.tangent;
	}
}

PrimitiveConstructor::PrimitiveConstructor()
{
	frameBuffer = new PixelColor[1024 * 768];
	sdepthBuffer = new float[1024 * 768];
	for (int i = 0; i < 768; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			sdepthBuffer[i * 1024 + j] = 1000.0f;
		}
	}
	depthBuffer = new float[1024 * 768];
	memcpy(depthBuffer, sdepthBuffer, sizeof(float) * 1024 * 768);
}

PrimitiveConstructor::~PrimitiveConstructor()
{
	delete[] frameBuffer;
	delete[] depthBuffer;
	delete[] sdepthBuffer;

}

void PrimitiveConstructor::Clip()
{
	std::vector<Triangle> newTriangles;
	for (int i = 0; i < numOfTriangle; i++)
	{
		std::vector<ClipPoint> points;
		std::vector<Triangle> outTriangles;
		int numOfPoints;

		if (!IsAllInClipSpace(
			psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.vertexPosition,
			psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.vertexPosition,
			psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.vertexPosition
		))
		{
			SutherlandHodgmanClip(triangles[i], points);

			if (points.size() != 0)
			{
				TriangulatePolygon(points, outTriangles);

				for (int j = 0; j < outTriangles.size(); j++)
				{
					Triangle triangle;
					if (points[outTriangles[j].VertexIndex[0]].index == 0)
					{
						triangle.VertexIndex[0] = psiVertices.size();
						psiVertices.push_back(points[outTriangles[j].VertexIndex[0]].data);
					}
					else
					{
						triangle.VertexIndex[0] = points[outTriangles[j].VertexIndex[0]].index - 1;
					}

					if (points[outTriangles[j].VertexIndex[1]].index == 0)
					{
						triangle.VertexIndex[1] = psiVertices.size();
						psiVertices.push_back(points[outTriangles[j].VertexIndex[1]].data);
					}
					else
					{
						triangle.VertexIndex[1] = points[outTriangles[j].VertexIndex[1]].index - 1;
					}

					if (points[outTriangles[j].VertexIndex[2]].index == 0)
					{
						triangle.VertexIndex[2] = psiVertices.size();
						psiVertices.push_back(points[outTriangles[j].VertexIndex[2]].data);
					}
					else
					{
						triangle.VertexIndex[2] = points[outTriangles[j].VertexIndex[2]].index - 1;
					}
					newTriangles.push_back(triangle);
				}
			}
		}
		else
		{
			newTriangles.push_back(triangles[i]);
		}
	}
	triangles.clear();
	for (int i = 0; i < newTriangles.size(); i++)
	{
		triangles.push_back(newTriangles[i]);
	}
	numOfTriangle = triangles.size();
	numOfVertex = psiVertices.size();
}

void PrimitiveConstructor::TriangulatePolygon(std::vector<ClipPoint>& points, std::vector<Triangle>& triangles)
{
	Triangle triangle;
	for (int i = 0; i < points.size() - 2; i++)
	{
		triangle.VertexIndex[0] = 0;
		triangle.VertexIndex[1] = i + 1;
		triangle.VertexIndex[2] = i + 2;
		triangles.push_back(triangle);
	}
}

bool PrimitiveConstructor::IsAllInClipSpace(Vector4D& p1, Vector4D& p2, Vector4D& p3)
{
	if (p1.x < -p1.w || p2.x < -p2.w || p3.x < -p3.w)
		return false;
	else if (p1.x > p1.w || p2.x > p2.w || p3.x > p3.w)
		return false;
	else if (p1.y < -p1.w || p2.y < -p2.w || p3.x < -p3.w)
		return false;
	else if (p1.y > p1.w || p2.y > p2.w || p3.y > p3.w)
		return false;
	else if (p1.z < 0 || p2.z < 0 || p3.z < 0)
		return false;
	else if (p1.z > p1.w || p2.z > p2.w || p3.z > p3.w)
		return false;
	return true;
	
}

void PrimitiveConstructor::SutherlandHodgmanClip(Triangle& triangle, std::vector<ClipPoint>& points)
{
	Vector3D nearNormal(0, 0, 1), farNormal(0, 0, -1), leftNormal(1, 0, 0), topNormal(0, 1, 0), rightNormal(-1, 0, 0), bottomNormal(0, -1, 0);
	ClipPoint point;
	point.data = psiVertices[triangle.VertexIndex[0]];
	point.index = triangle.VertexIndex[0] + 1;
	points.push_back(point);
	point.data = psiVertices[triangle.VertexIndex[1]];
	point.index = triangle.VertexIndex[1] + 1;
	points.push_back(point);
	point.data = psiVertices[triangle.VertexIndex[2]];
	point.index = triangle.VertexIndex[2] + 1;
	points.push_back(point);

	TriangleClip(ClipPlaneType::Near, nearNormal, points);
	TriangleClip(ClipPlaneType::Far, farNormal, points);
	TriangleClip(ClipPlaneType::Left, leftNormal, points);
	TriangleClip(ClipPlaneType::Top, topNormal, points);
	TriangleClip(ClipPlaneType::Right, rightNormal, points);
	TriangleClip(ClipPlaneType::Bottom, bottomNormal, points);
}

void PrimitiveConstructor::TriangleClip(ClipPlaneType type, Vector3D& normal, std::vector<ClipPoint>& points)
{
	ClipPoint v1, v2;
	std::vector<ClipPoint> tempPoints;
	ClipPoint clipPoint;
	VertexToPixel data;
	for (int i = 0; i < points.size(); i++)
	{
		int next = (i + 1) % points.size();
		v1 = points[i];
		v2 = points[next];

		Vector3D p1;
		p1.x = v1.data.pixelShaderIn.vertexPosition.x;
		p1.y = v1.data.pixelShaderIn.vertexPosition.y;
		p1.z = v1.data.pixelShaderIn.vertexPosition.z;
		Vector3D p2;
		p2.x = v2.data.pixelShaderIn.vertexPosition.x;
		p2.y = v2.data.pixelShaderIn.vertexPosition.y;
		p2.z = v2.data.pixelShaderIn.vertexPosition.z;

		Vector3D planePoint1(0, 0, 0);
		Vector3D planePoint2(0, 0, 0);
		switch (type)
		{
		case ClipPlaneType::Near:
			break;
		case ClipPlaneType::Far:
			planePoint1.z = v1.data.pixelShaderIn.vertexPosition.w;
			planePoint2.z = v2.data.pixelShaderIn.vertexPosition.w;
			break;
		case ClipPlaneType::Left:
			planePoint1.x = -v1.data.pixelShaderIn.vertexPosition.w;
			planePoint2.x = -v2.data.pixelShaderIn.vertexPosition.w;
			break;
		case ClipPlaneType::Right:
			planePoint1.x = v1.data.pixelShaderIn.vertexPosition.w;
			planePoint2.x = v2.data.pixelShaderIn.vertexPosition.w;
			break;
		case ClipPlaneType::Top:
			planePoint1.y = -v1.data.pixelShaderIn.vertexPosition.w;
			planePoint2.y = -v2.data.pixelShaderIn.vertexPosition.w;
			break;
		case ClipPlaneType::Bottom:
			planePoint1.y = v1.data.pixelShaderIn.vertexPosition.w;
			planePoint2.y = v2.data.pixelShaderIn.vertexPosition.w;
			break;
		}

		float startPos = Dot((p1 - planePoint1), normal);
		float endPos = Dot((p2 - planePoint2), normal);
		float t = startPos / (startPos - endPos);

		if (startPos > 0 && endPos > 0)
		{
			tempPoints.push_back(v2);
		}
		else if (startPos <= 0 && endPos > 0)
		{
			clipPoint.data = InsersectionPoint(t, v1.data, v2.data);
			clipPoint.index = 0;
			tempPoints.push_back(clipPoint);
			tempPoints.push_back(v2);
		}
		else if (startPos > 0 && endPos <= 0)
		{
			clipPoint.data = InsersectionPoint(t, v1.data, v2.data);
			clipPoint.index = 0;
			tempPoints.push_back(clipPoint);
		}
		else
		{

		}
	}
	points.clear();
	for (int i = 0; i < tempPoints.size(); i++)
	{
		points.push_back(tempPoints[i]);
	}
}

VertexToPixel PrimitiveConstructor::InsersectionPoint(float t, VertexToPixel& p1, VertexToPixel& p2)
{
	VertexToPixel out;
	out.pixelShaderIn.vertexPosition = p1.pixelShaderIn.vertexPosition + (p2.pixelShaderIn.vertexPosition - p1.pixelShaderIn.vertexPosition) * t;
	float rz = out.pixelShaderIn.vertexPosition.z;
	rz = rz != 0 ? 1.0f / rz : 0;
	out.pixelShaderIn.color = (p1.pixelShaderIn.color * rz + (p2.pixelShaderIn.color * rz - p1.pixelShaderIn.color * rz) * t) * out.pixelShaderIn.vertexPosition.z;
	out.pixelShaderIn.normal = (p1.pixelShaderIn.normal * rz + (p2.pixelShaderIn.normal * rz - p1.pixelShaderIn.normal * rz) * t) * out.pixelShaderIn.vertexPosition.z;
	out.pixelShaderIn.tangent = (p1.pixelShaderIn.tangent * rz + (p2.pixelShaderIn.tangent * rz - p1.pixelShaderIn.tangent * rz) * t) * out.pixelShaderIn.vertexPosition.z;
	out.pixelShaderIn.texCoord = (p1.pixelShaderIn.texCoord * rz + (p2.pixelShaderIn.texCoord * rz - p1.pixelShaderIn.texCoord * rz) * t) * out.pixelShaderIn.vertexPosition.z;
	out.pixelShaderIn.directionLightDirection = p1.pixelShaderIn.directionLightDirection;
	out.pixelShaderIn.viewPosition = p1.pixelShaderIn.viewPosition;
	return out;
}

void PrimitiveConstructor::SetVertexBuffer(int vertexNum, Vertex* v)
{
	numOfVertex = vertexNum;
	backNumOfVertex = vertexNum;
	for (int i = 0; i < numOfVertex; i++)
	{
		Vertex vertex;
		vertex.position = v[i].position;
		vertex.color = v[i].color;
		vertex.normal = v[i].normal;
		vertex.texcoord = v[i].texcoord;
		vertex.tangent = v[i].tangent;
		vertices.push_back(vertex);
	}
}

void PrimitiveConstructor::SetVertexBuffer(std::vector<Vertex> vs)
{
	numOfVertex = vs.size();
	backNumOfVertex = vs.size();
	for (int i = 0; i < numOfVertex; i++)
	{	
		vertices.push_back(vs[i]);
	}
}
void PrimitiveConstructor::SetIndexBuffer(int indexNum, int* indices)
{
	Triangle triangle;
	numOfTriangle = indexNum / 3;
	for (int i = 0; i < numOfTriangle; i++)
	{
		triangle.VertexIndex[0] = indices[i * 3 + 0];
		triangle.VertexIndex[1] = indices[i * 3 + 1];
		triangle.VertexIndex[2] = indices[i * 3 + 2];
		triangles.push_back(triangle);
		backUpTriangles.push_back(triangle);
	}
}

void PrimitiveConstructor::SetIndexBuffer(std::vector<Triangle> ts)
{
	numOfTriangle = ts.size();
	for (int i = 0; i < numOfTriangle; i++)
	{
		triangles.push_back(ts[i]);
		backUpTriangles.push_back(ts[i]);
	}
}

void PrimitiveConstructor::ExecVertexSahder()
{
	psiVertices.clear();
	numOfVertex = backNumOfVertex;
	for (int i = 0; i < numOfVertex; i++)
	{
		VertexShaderIn vIn;
		vIn.position = vertices[i].position;
		vIn.texCoord = vertices[i].texcoord;
		vIn.normal = vertices[i].normal;
		vIn.color = vertices[i].color;
		vIn.tangent = vertices[i].tangent;
		PixelShaderIn vOut = VertexShader(vIn, this);
		VertexToPixel passData;
		passData.pixelShaderIn = vOut;
		psiVertices.push_back(passData);
	}
}

void PrimitiveConstructor::PersDivide()
{
	int halfwidth = viewport.wh.x / 2;
	int halfheight = viewport.wh.y / 2;
	float zfn = viewport.nf.y - viewport.nf.x;
	for (int i = 0; i < numOfVertex; i++)
	{
		PixelShaderIn& v = psiVertices[i].pixelShaderIn;
		psiVertices[i].pixelShaderIn.vertexPosition.x = (int)(halfwidth * (v.vertexPosition.x / v.vertexPosition.w) + halfwidth);
		psiVertices[i].pixelShaderIn.vertexPosition.y = (int)(halfheight * (v.vertexPosition.y / v.vertexPosition.w) + halfheight);
		psiVertices[i].pixelShaderIn.vertexPosition.z = (v.vertexPosition.z / v.vertexPosition.w) * zfn;
		psiVertices[i].pixelShaderIn.vertexPosition.w = 1;
		psiVertices[i].screenPos.x = v.vertexPosition.x;
		psiVertices[i].screenPos.y = v.vertexPosition.y;
	}
}

void PrimitiveConstructor::BackCull()
{
	numOfVertex = psiVertices.size();
	numOfTriangle = backUpTriangles.size();
	triangles.clear();
	for (int i = 0; i < backUpTriangles.size(); i++)
	{
		triangles.push_back(backUpTriangles[i]);
	}

	std::vector<Triangle> newTriangles;
	for (int i = 0; i < numOfTriangle; i++)
	{
		Vector3D v1(
			psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.vertexPosition.x - psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.vertexPosition.x,
			psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.vertexPosition.y - psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.vertexPosition.y,
			psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.vertexPosition.z - psiVertices[triangles[i].VertexIndex[0]].pixelShaderIn.vertexPosition.z
		);
		Vector3D v2(
			psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.vertexPosition.x - psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.vertexPosition.x,
			psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.vertexPosition.y - psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.vertexPosition.y,
			psiVertices[triangles[i].VertexIndex[2]].pixelShaderIn.vertexPosition.z - psiVertices[triangles[i].VertexIndex[1]].pixelShaderIn.vertexPosition.z
		);

		Vector3D normal = Cross(v1, v2).Normalize();
		if (Dot(normal, Vector3D(0, 0, 1)) <= 0)
		{
			newTriangles.push_back(triangles[i]);
		}
	}

	triangles.clear();
	for (int i = 0; i < newTriangles.size(); i++)
	{
		triangles.push_back(newTriangles[i]);
	}
	numOfTriangle = triangles.size();
}