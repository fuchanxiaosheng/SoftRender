#pragma once
#include "Vertex.h"
#include "Triangle.h"

#include <vector>

class MeshLoader
{
public:
	//only process triangle primitive
	bool Load(const char* filename);
	std::vector<Vertex>& GetVertices();
	std::vector<Triangle>& GetTriangles();

private:
	std::vector<Vertex> vertices;
	std::vector<Vector3D> positions;
	std::vector<Vector2D> texcoords;
	std::vector<Vector3D> normals;
	std::vector<Triangle> triangles;
};
