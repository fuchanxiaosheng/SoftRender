#include "Math.h"

#include <cmath>

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
	return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& v)
{
	return *this;
}
Vector2D& Vector2D::operator*=(const Vector2D& v) 
{
	return *this;
}
Vector2D& Vector2D::operator/=(const Vector2D& v)
{
	return *this;
}

Vector2D Vector2D::operator+() const
{
	return Vector2D();
}
Vector2D Vector2D::operator-() const
{
	return Vector2D();
}

Vector2D Vector2D::operator+(const Vector2D& v) const
{
	return Vector2D();
}
Vector2D Vector2D::operator-(const Vector2D& v) const
{
	return Vector2D();
}
Vector2D Vector2D::operator*(float k) const
{
	return Vector2D();
}
Vector2D Vector2D::operator/(float k) const
{
	return Vector2D();
}

bool Vector2D::operator==(const Vector2D& v) const
{
	return false;
}
bool Vector2D::operator!=(const Vector2D& v) const
{
	return false;
}

Vector2D Vector2D::Normalize()
{
	return Vector2D();
}
float Vector2D::Length()
{
	return 0;
}

Vector2D operator*(float k, const Vector2D& v)
{
	return Vector2D();
}
float Dot(Vector2D& v1, Vector2D& v2)
{
	return 0;
}
Vector2D Lerp(Vector2D& v1, Vector2D& v2, float s)
{
	return Vector2D();
}

Vector3D& Vector3D::operator+=(const Vector3D& v)
{
	return *this;
}
Vector3D& Vector3D::operator-=(const Vector3D& v)
{
	return *this;
}
Vector3D& Vector3D::operator*=(float k)
{
	return *this;
}
Vector3D& Vector3D::operator/=(float k)
{
	return *this;
}

Vector3D Vector3D::operator+() const
{
	return Vector3D();
}
Vector3D Vector3D::operator-() const
{
	return Vector3D();
}

Vector3D Vector3D::operator-(const Vector3D& v) const
{
	return Vector3D();
}
Vector3D Vector3D::operator+(const Vector3D& v) const
{
	return Vector3D();
}
Vector3D Vector3D::operator*(float k)
{
	return Vector3D();
}
Vector3D Vector3D::operator/(float k)
{
	return Vector3D();
}

bool Vector3D::operator ==(const Vector3D& v) const
{
	return false;
}
bool Vector3D::operator !=(const Vector3D& v) const
{
	return false;
}

double Vector3D::Length() const
{
	return 0;
}

Vector3D Vector3D::Normalize() const
{
	return Vector3D();
}

Vector3D operator*(float k, Vector3D& v)
{
	return Vector3D();
}
double Dot(const Vector3D& v1, const Vector3D& v2)
{
	return 0;
}
Vector3D Cross(const Vector3D& v1, const Vector3D& v2)
{
	return Vector3D();
}
Vector3D Lerp(Vector3D& v1, Vector3D& v2, float s)
{
	return Vector3D();
}

Vector4D::Vector4D(const Vector3D& xyz, float w)
{

}

Vector4D& Vector4D::operator += (const Vector4D& v)
{
	return *this;
}
Vector4D& Vector4D::operator -= (const Vector4D& v)
{
	return *this;
}
Vector4D& Vector4D::operator *= (float k)
{
	return *this;
}
Vector4D& Vector4D::operator /= (float k)
{
	return *this;
}

Vector4D Vector4D::operator+() const
{
	return Vector4D();
}
Vector4D Vector4D::operator-() const
{
	return Vector4D();
}

Vector4D Vector4D::operator-(const Vector4D& v) const
{
	return Vector4D();
}
Vector4D Vector4D::operator+(const Vector4D& v) const
{
	return Vector4D();
}
Vector4D Vector4D::operator* (float k) const
{
	return Vector4D();
}
Vector4D Vector4D::operator/ (float k) const
{
	return Vector4D();
}

double Vector4D::Length() const
{
	return 0;
}

bool Vector4D::operator ==(const Vector4D& v) const
{
	return false;
}
bool Vector4D::operator !=(const Vector4D& v) const
{
	return false;
}

Vector4D Vector4D::Normalize() const
{
	return Vector4D();
}

Vector4D operator*(float k, Vector4D& v)
{
	return Vector4D();
}
double Dot(const Vector4D& v1, const Vector4D& v2)
{
	return 0;
}
Vector4D Lerp(Vector4D& v1, Vector4D& v2, float s)
{
	return Vector4D();
}

VectorInt2D::VectorInt2D(const Vector4D& v)
{

}
VectorInt2D& VectorInt2D::operator=(const VectorInt2D& v)
{
	return *this;
}
VectorInt2D& VectorInt2D::operator=(const Vector4D& v)
{
	return *this;
}

bool VectorInt2D::operator==(const VectorInt2D& v) const
{
	return false;
}

VectorInt2D VectorInt2D::operator-(const VectorInt2D& v) const
{
	return VectorInt2D();
}
float VectorInt2D::Length()
{
	return 0;
}

Matrix4x4::Matrix4x4(const float* data)
{

}
Matrix4x4::Matrix4x4(Vector4D r0, Vector4D r1, Vector4D r2, Vector4D r3)
{

}
Matrix4x4::Matrix4x4(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33
)
{

}

float& Matrix4x4::operator() (unsigned row, unsigned col)
{
	return m[row][col];
}
float Matrix4x4::operator() (unsigned row, unsigned col) const
{
	return 0;
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& rm)
{
	return *this;
}
Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& rm)
{
	return *this;
}
Matrix4x4& Matrix4x4::operator/=(const Matrix4x4& rm)
{
	return *this;
}
Matrix4x4& Matrix4x4::operator*=(float k)
{
	return *this;
}
Matrix4x4& Matrix4x4::operator/=(float k)
{
	return *this;
}

Matrix4x4 Matrix4x4::operator+() const
{
	return Matrix4x4();
}
Matrix4x4 Matrix4x4::operator-() const 
{
	return Matrix4x4();
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& rm) const
{
	return Matrix4x4();
}
Matrix4x4 Matrix4x4::operator+(const Matrix4x4& rm) const
{
	return Matrix4x4();
}
Matrix4x4 Matrix4x4::operator-(const Matrix4x4& rm) const
{
	return Matrix4x4();
}
Matrix4x4 Matrix4x4::operator*(float k) const
{
	return Matrix4x4();
}
Matrix4x4 Matrix4x4::operator/(float k) const 
{
	return Matrix4x4();
}
Vector4D Matrix4x4::operator*(const Vector4D& v) const
{
	return Vector4D();
}

bool Matrix4x4::operator==(const Matrix4x4& rm) const
{
	return false;
}
bool Matrix4x4::operator!=(const Matrix4x4& rm) const
{
	return false;
}
bool Matrix4x4::IsIdentity()
{
	return false;
}

double Matrix4x4::Determinant()
{
	return 0;
}
Matrix4x4 Matrix4x4::Transpose()
{
	return Matrix4x4();
}

Matrix4x4 Matrix4x4::Inverse()
{
	return Matrix4x4();
}

Matrix4x4 operator*(float k, const Matrix4x4& rm)
{
	return rm * k;
}
Matrix4x4 MatrixIdentity()
{
	return Matrix4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}

Vector4D Vec2Transform(const Vector2D& v, const Matrix4x4& m)
{
	return Vec4Transform(Vector4D(v.x, v.y, 0, 1), m);
}
Vector2D Vec2TransformCoord(const Vector2D& v, const Matrix4x4& m)
{
	Vector4D v4(v.x, v.y, 0, 1);
	v4 = Vec4Transform(v4, m);
	return Vector2D(v4.x, v4.y);
}

Vector2D Vec2TransformNormal(const Vector2D& v, const Matrix4x4& m)
{
	Vector4D v4(v.x, v.y, 0, 0);
	v4 = Vec4Transform(v4, m);
	return Vector2D(v4.x, v4.y);
}

Vector4D Vec3Transform(const Vector3D& v, const Matrix4x4& m)
{
	return Vec4Transform(Vector4D(v.x, v.y, v.z, 1), m);
}
Vector3D Vec3TransformCoord(const Vector3D& v, const Matrix4x4& m)
{
	Vector4D v4(v.x, v.y, v.z, 1);
	v4 = Vec4Transform(v4, m);
	return Vector3D(v4.x, v4.y, v4.z);
}
Vector3D Vec3TransformNormal(const Vector3D& v, const Matrix4x4& m)
{
	Vector4D v4(v.x, v.y, v.z, 0);
	v4 = Vec4Transform(v4, m);
	return Vector3D(v4.x, v4.y, v4.z);
}

Vector4D Vec4Transform(const Vector4D& v, const Matrix4x4& m)
{
	return Vector4D(
		m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3] * v.w,
		m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3] * v.w,
		m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3] * v.w,
		m.m[3][0] * v.x + m.m[3][1] * v.y + m.m[3][2] * v.z + m.m[3][3] * v.w
	);
}

Matrix4x4 MatrixLookAtLH(const Vector3D& EyePosition, const Vector3D& FocusPosition, const Vector3D& UpDirection)
{
	Vector3D EyeDirection = FocusPosition - EyePosition;

	return MatrixLookToLH(EyePosition, EyeDirection, UpDirection);
}
Matrix4x4 MatrixLookToLH(const Vector3D& EyePosition, const Vector3D& EyeDirection, const Vector3D& UpDirection)
{
	Vector3D zaxis = EyeDirection.Normalize();
	Vector3D xaxis = Cross(UpDirection, zaxis).Normalize();
	Vector3D yaxis = Cross(zaxis, xaxis);
	return Matrix4x4(
		xaxis.x, yaxis.x, zaxis.x, 0,
		xaxis.y, yaxis.y, zaxis.y, 0,
		xaxis.z, yaxis.z, zaxis.z, 0,
		(float)-Dot(xaxis, EyePosition), (float)-Dot(yaxis, EyePosition), (float)-Dot(zaxis, EyePosition), 1
	);
}

Matrix4x4 MatrixPerspectiveFovLH(float FovAngleY, float AspectRatio, float NearZ, float FarZ)
{
	float cosFov = cos(0.5f * FovAngleY);
	float sinFov = sin(0.5f * FovAngleY);
	float h = cosFov / sinFov;
	float w = h / AspectRatio;
	float a = FarZ / (FarZ - NearZ);
	float b = -a * NearZ;
	return Matrix4x4(
		w, 0, 0, 0,
		0, h, 0, 0,
		0, 0, a, 1,
		0, 0, b, 0
	);
}

Matrix4x4 MatrixTransformation(const Vector3D& position, const Vector3D& rotation, const Vector3D& scale)
{
	Matrix4x4 mTranslation = MatrixTranslation(position);
	Matrix4x4 mScaling = MatrixScaling(scale);
	return mTranslation;
}
Matrix4x4 MatrixTranslation(const Vector3D& offset)
{
	return Matrix4x4(
		1.0f, 0, 0, offset.x,
		0, 1.0f, 0, offset.y,
		0, 0, 1.0f, offset.z,
		0, 0, 0, 1.0f
	);
}
Matrix4x4 MatrixScaling(const Vector3D& scale)
{
	return Matrix4x4(
		scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		0, 0, 0, 1
	);
}
Matrix4x4 MatrixRotationX(float Angle)
{
	float cosAng = cosf(Angle);
	float sinAng = sinf(Angle);
	return Matrix4x4(
		1, 0, 0, 0,
		0, cosAng, -sinAng, 0,
		0, sinAng, cosAng, 0,
		0, 0, 0, 1
	);
}
Matrix4x4 MatrixRotationY(float Angle)
{
	float cosAng = cosf(Angle);
	float sinAng = cosf(Angle);
	return Matrix4x4(
		cosAng, 0, sinAng, 0,
		0, 1, 0, 0,
		-sinAng, 0, cosAng, 0,
		0, 0, 0, 1
	);
}
Matrix4x4 MatrixRotationZ(float Angle)
{
	float cosAng = cosf(Angle);
	float sinAng = sinf(Angle);
	return Matrix4x4(
		cosAng, -sinAng, 0, 0,
		sinAng, cosAng, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}