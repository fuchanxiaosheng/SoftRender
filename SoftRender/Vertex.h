#pragma once
#include "Math.h"

class Vertex
{
public:
	Vector3D color;
	Vector3D position;
	Vector2D texcoord;
	Vector3D normal;
	Vector4D tangent;

	Vertex() {}
	Vertex(Vector3D _position, Vector3D _normal, Vector3D _color, Vector2D _tex)
		: position(_position), normal(_normal), color(_color), texcoord(_tex) {}
};
