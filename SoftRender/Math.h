#pragma once

class Color
{
public:
	int r;
	int g;
	int b;
	int a;
	Color(int _r = 0, int _g = 0, int _b = 0, int _a = 0) : r(_r), g(_g), b(_b), a(_a) {}
};

class Vector2D
{
public:
	float x;
	float y;

	Vector2D(float _x = 0, float _y = 0) : x(_x), y(_y) {}
	Vector2D& operator+=(const Vector2D& v);
	Vector2D& operator-=(const Vector2D& v);
	Vector2D& operator*=(const Vector2D& v);
	Vector2D& operator/=(const Vector2D& v);

	Vector2D operator+() const;
	Vector2D operator-() const;

	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator-(const Vector2D& v) const;
	Vector2D operator*(float k) const;
	Vector2D operator/(float k) const;

	bool operator==(const Vector2D& v) const;
	bool operator!=(const Vector2D& v) const;

	Vector2D Normalize();
	float Length();

 };

Vector2D operator*(float k, const Vector2D& v);
float Dot(Vector2D& v1, Vector2D& v2);
Vector2D Lerp(Vector2D& v1, Vector2D& v2, float s);

class Vector3D
{
public:
	float x;
	float y;
	float z;

	Vector3D(float _x = 0, float _y = 0, float _z = 0) : x(_x), y(_y), z(_z) {}

	Vector3D& operator+=(const Vector3D& v);
	Vector3D& operator-=(const Vector3D& v);
	Vector3D& operator*=(float k);
	Vector3D& operator/=(float k);

	Vector3D operator+() const;
	Vector3D operator-() const;

	Vector3D operator-(const Vector3D& v) const;
	Vector3D operator+(const Vector3D& v) const;
	Vector3D operator*(float k) const;
	Vector3D operator/(float k) const;

	bool operator ==(const Vector3D& v) const;
	bool operator !=(const Vector3D& v) const;

	double Length() const;

	Vector3D Normalize() const;
};

Vector3D operator*(float k,const Vector3D& v);
double Dot(const Vector3D& v1, const Vector3D& v2);
Vector3D Cross(const Vector3D& v1, const Vector3D& v2);
Vector3D Lerp(Vector3D& v1, Vector3D& v2, float s);

class Vector4D
{
public:
	float x;
	float y;
	float z;
	float w;

	Vector4D(const Vector3D& xyz, float w);
	Vector4D(float _x = 0, float _y = 0, float _z = 0, float _w = 0) : x(_x), y(_y), z(_z), w(_w) {}

	Vector4D& operator += (const Vector4D& v);
	Vector4D& operator -= (const Vector4D& v);
	Vector4D& operator *= (float k);
	Vector4D& operator /= (float k);
	
	Vector4D operator+() const;
	Vector4D operator-() const;

	Vector4D operator-(const Vector4D& v) const;
	Vector4D operator+(const Vector4D& v) const;
	Vector4D operator* (float k) const;
	Vector4D operator/ (float k) const;

	double Length() const;

	bool operator ==(const Vector4D& v) const;
	bool operator !=(const Vector4D& v) const;

	Vector4D Normalize() const;
};

Vector4D operator*(float k, const Vector4D& v);
double Dot(const Vector4D& v1, const Vector4D& v2);
Vector4D Lerp(Vector4D& v1, Vector4D& v2, float s);

class VectorInt2D
{
public:
	int x;
	int y;

	VectorInt2D(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	VectorInt2D(const Vector4D& v);
	VectorInt2D& operator=(const VectorInt2D& v);
	VectorInt2D& operator=(const Vector4D& v);

	bool operator==(const VectorInt2D& v) const;

	VectorInt2D operator-(const VectorInt2D& v) const;
	float Length();
};

class Matrix4x4
{
public:
	float m[4][4];

	Matrix4x4() {}
	Matrix4x4(const float* data);
	Matrix4x4(Vector4D r0, Vector4D r1, Vector4D r2, Vector4D r3);
	Matrix4x4(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33
	);

	float& operator() (unsigned row, unsigned col);
	float operator() (unsigned row, unsigned col) const;

	Matrix4x4& operator*=(const Matrix4x4& rm);
	Matrix4x4& operator+=(const Matrix4x4& rm);
	Matrix4x4& operator/=(const Matrix4x4& rm);
	Matrix4x4& operator*=(float k);
	Matrix4x4& operator/=(float k);

	Matrix4x4 operator+() const;
	Matrix4x4 operator-() const;

	Matrix4x4 operator*(const Matrix4x4& rm) const;
	Matrix4x4 operator+(const Matrix4x4& rm) const;
	Matrix4x4 operator-(const Matrix4x4& rm) const;
	Matrix4x4 operator*(float k) const;
	Matrix4x4 operator/(float k) const;
	Vector4D operator*(const Vector4D& v) const;

	bool operator==(const Matrix4x4& rm) const;
	bool operator!=(const Matrix4x4& rm) const;
	bool IsIdentity();

	double Determinant();
	Matrix4x4 Transpose();

	Matrix4x4 Inverse();
};

Matrix4x4 operator*(float k, const Matrix4x4& rm);
Matrix4x4 MatrixIdentity();

Vector4D Vec2Transform(const Vector2D& v, const Matrix4x4& m);
Vector2D Vec2TransformCoord(const Vector2D& v, const Matrix4x4& m);

Vector2D Vec2TransformNormal(const Vector2D& v, const Matrix4x4& m);

Vector4D Vec3Transform(const Vector3D& v, const Matrix4x4& m);
Vector3D Vec3TransformCoord(const Vector3D& v, const Matrix4x4& m);
Vector3D Vec3TransformNormal(const Vector3D& v, const Matrix4x4& m);

Vector4D Vec4Transform(const Vector4D& v, const Matrix4x4& m);

Matrix4x4 MatrixLookAtLH(const Vector3D& EyePosition, const Vector3D& FocusPosition, const Vector3D& UpDirection);
Matrix4x4 MatrixLookToLH(const Vector3D& EyePosition, const Vector3D& EyeDirection, const Vector3D& UpDirection);

Matrix4x4 MatrixPerspectiveFovLH(float FovAngleY, float AspectRatio, float NearZ, float FarZ);

Matrix4x4 MatrixTransformation(const Vector3D& position, const Vector3D& rotation, const Vector3D& scale);
Matrix4x4 MatrixTranslation(const Vector3D& offset);
Matrix4x4 MatrixScaling(const Vector3D& scale);
Matrix4x4 MatrixRotationX(float Angle);
Matrix4x4 MatrixRotationY(float Angle);
Matrix4x4 MatrixRotationZ(float Angle);

