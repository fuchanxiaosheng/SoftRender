#include "Math.h"

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
	return Matrix4x4();
}
Matrix4x4 MatrixIdentity()
{
	return Matrix4x4();
}

Vector4D Vec2Transform(const Vector2D& v, const Matrix4x4& m)
{
	return Vector4D();
}
Vector2D Vec2TransformCoord(const Vector2D& v, const Matrix4x4& m)
{
	return Vector2D();
}

Vector2D Vec2TransformNormal(const Vector2D& v, const Matrix4x4& m)
{
	return Vector2D();
}

Vector4D Vec3Transform(const Vector3D& v, const Matrix4x4& m)
{
	return Vector4D();
}
Vector3D Vec3TransformCoord(const Vector3D& v, const Matrix4x4& m)
{
	return Vector3D();
}
Vector3D Vec3TransformNormal(const Vector3D& v, const Matrix4x4& m)
{
	return Vector3D();
}

Vector4D Vec4Transform(const Vector4D& v, const Matrix4x4& m)
{
	return Vector4D();
}

Matrix4x4 MatrixLookAtLH(const Vector3D& EyePosition, const Vector3D& FocusPosition, const Vector3D& UpDirection)
{
	return Matrix4x4();
}
Matrix4x4 MatrixLookToLH(const Vector3D& EyePosition, const Vector3D& EyeDirection, const Vector3D& UpDirection)
{
	return Matrix4x4();
}

Matrix4x4 MatrixPerspectiveFovLH(float FovAngleY, float AspectRatio, float NearZ, float FarZ)
{
	return Matrix4x4();
}

Matrix4x4 MatrixTransformation(const Vector3D& position, const Vector3D& rotation, const Vector3D& scale)
{
	return Matrix4x4();
}
Matrix4x4 MatrixTranslation(const Vector3D& offset)
{
	return Matrix4x4();
}
Matrix4x4 MatrixScaling(const Vector3D& scale)
{
	return Matrix4x4();
}
Matrix4x4 MatrixRotationX(float Angle)
{
	return Matrix4x4();
}
Matrix4x4 MatrixRotationY(float Angle)
{
	return Matrix4x4();
}
Matrix4x4 MatrixRotationZ(float Angle)
{
	return Matrix4x4();
}