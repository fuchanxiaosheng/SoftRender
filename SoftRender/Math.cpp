#include "Math.h"

#include <cmath>

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& v)
{
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}
Vector2D& Vector2D::operator*=(const Vector2D& v) 
{
	this->x *= v.x;
	this->y *= v.y;
	return *this;
}
Vector2D& Vector2D::operator/=(const Vector2D& v)
{
	this->x /= v.x;
	this->y /= v.y;
	return *this;
}

Vector2D Vector2D::operator+() const
{
	return Vector2D(this->x, this->y);
}
Vector2D Vector2D::operator-() const
{
	return Vector2D(-this->x, -this->y);
}

Vector2D Vector2D::operator+(const Vector2D& v) const
{
	return Vector2D(x + v.x, y + v.y);
}
Vector2D Vector2D::operator-(const Vector2D& v) const
{
	return Vector2D(x - v.x, y - v.y);
}
Vector2D Vector2D::operator*(float k) const
{
	return Vector2D(x * k, y * k);
}
Vector2D Vector2D::operator/(float k) const
{
	return Vector2D(x / k, y / k);
}

bool Vector2D::operator==(const Vector2D& v) const
{
	return x == v.x && y == v.y;
}
bool Vector2D::operator!=(const Vector2D& v) const
{
	return x != v.x || y != v.y;
}

Vector2D Vector2D::Normalize()
{
	return Vector2D(x / Length(), y / Length());
}
float Vector2D::Length()
{
	return sqrt(x * x + y * y);
}

Vector2D operator*(float k, const Vector2D& v)
{
	return v * k;
}
float Dot(Vector2D& v1, Vector2D& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}
Vector2D Lerp(Vector2D& v1, Vector2D& v2, float s)
{
	return v1 + s * (v2 - v1);
}

Vector3D& Vector3D::operator+=(const Vector3D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
Vector3D& Vector3D::operator-=(const Vector3D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
Vector3D& Vector3D::operator*=(float k)
{
	x *= k;
	y *= k;
	z *= k;
	return *this;
}
Vector3D& Vector3D::operator/=(float k)
{
	x /= k;
	y /= k;
	z /= k;
	return *this;
}

Vector3D Vector3D::operator+() const
{
	return *this;
}
Vector3D Vector3D::operator-() const
{
	return Vector3D(-x, -y, -z);
}

Vector3D Vector3D::operator-(const Vector3D& v) const
{
	return Vector3D(x - v.x, y - v.y, z - v.z);
}
Vector3D Vector3D::operator+(const Vector3D& v) const
{
	return Vector3D(x + v.x, y + v.y, z + v.z);
}
Vector3D Vector3D::operator*(float k) const
{
	return Vector3D(x * k, y * k, z * k);
}
Vector3D Vector3D::operator/(float k) const
{
	return Vector3D(x / k, y / k, z / k);
}

bool Vector3D::operator ==(const Vector3D& v) const
{
	return x == v.x && y == v.y && z == v.z;
}
bool Vector3D::operator !=(const Vector3D& v) const
{
	return x != v.x || y != v.y || z != v.z;
}

double Vector3D::Length() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::Normalize() const
{
	return Vector3D(x / Length(), y / Length(), z / Length());
}

Vector3D operator*(float k, const Vector3D& v)
{
	return v * k;
}
double Dot(const Vector3D& v1, const Vector3D& v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
Vector3D Cross(const Vector3D& v1, const Vector3D& v2)
{
	return Vector3D(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}
Vector3D Lerp(Vector3D& v1, Vector3D& v2, float s)
{
	return v1 + s * (v2 - v1);
}

Vector4D::Vector4D(const Vector3D& xyz, float w)
{
	x = xyz.x;
	y = xyz.y;
	z = xyz.z;
	this->w = w;
}

Vector4D& Vector4D::operator += (const Vector4D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}
Vector4D& Vector4D::operator -= (const Vector4D& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}
Vector4D& Vector4D::operator *= (float k)
{
	x *= k;
	y *= k;
	z *= k;
	w *= k;
	return *this;
}
Vector4D& Vector4D::operator /= (float k)
{
	x /= k;
	y /= k;
	z /= k;
	w /= k;
	return *this;
}

Vector4D Vector4D::operator+() const
{
	return *this;
}
Vector4D Vector4D::operator-() const
{
	return Vector4D(-x, -y, -z, -w);
}

Vector4D Vector4D::operator-(const Vector4D& v) const
{
	return Vector4D(x - v.x, y - v.y, z - v.z, w - v.w);
}
Vector4D Vector4D::operator+(const Vector4D& v) const
{
	return Vector4D(x + v.x, y + v.y, z + v.z, w + v.w);
}
Vector4D Vector4D::operator* (float k) const
{
	return Vector4D(x * k, y * k, z * k, w * k);
}
Vector4D Vector4D::operator/ (float k) const
{
	return Vector4D(x / k, y / k, z / k, w / k);
}

double Vector4D::Length() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

bool Vector4D::operator ==(const Vector4D& v) const
{
	return x == v.x && y == v.y && z == v.z && w == v.w;
}
bool Vector4D::operator !=(const Vector4D& v) const
{
	return x != v.x || y != v.y || z != v.z || w != v.w;
}

Vector4D Vector4D::Normalize() const
{
	return Vector4D(x / Length(), y / Length(), z / Length(), w / Length());
}

Vector4D operator*(float k, const Vector4D& v)
{
	return v * k;
}
double Dot(const Vector4D& v1, const Vector4D& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}
Vector4D Lerp(Vector4D& v1, Vector4D& v2, float s)
{
	return v1 + s * (v2 - v1);
}

VectorInt2D::VectorInt2D(const Vector4D& v)
{
	x = v.x;
	y = v.y;
}
VectorInt2D& VectorInt2D::operator=(const VectorInt2D& v)
{
	x = v.x;
	y = v.y;
	return *this;
}
VectorInt2D& VectorInt2D::operator=(const Vector4D& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

bool VectorInt2D::operator==(const VectorInt2D& v) const
{
	return x == v.x && y == v.y;
}

VectorInt2D VectorInt2D::operator-(const VectorInt2D& v) const
{
	return VectorInt2D(-x, -y);
}
float VectorInt2D::Length()
{
	return sqrt(x * x + y * y);
}

Matrix4x4::Matrix4x4(const float* data)
{
	m[0][0] = data[0]; m[0][1] = data[1]; m[0][2] = data[2]; m[0][3] = data[3];
	m[1][0] = data[4]; m[1][1] = data[5]; m[1][2] = data[6]; m[1][3] = data[7];
	m[2][0] = data[8]; m[2][1] = data[9]; m[2][2] = data[10]; m[2][3] = data[11];
	m[3][0] = data[12]; m[3][1] = data[13]; m[3][2] = data[14]; m[3][3] = data[15];
}
Matrix4x4::Matrix4x4(Vector4D r0, Vector4D r1, Vector4D r2, Vector4D r3)
{
	m[0][0] = r0.x; m[0][1] = r0.y; m[0][2] = r0.z; m[0][3] = r0.w;
	m[1][0] = r1.x; m[1][1] = r1.y; m[1][2] = r1.z; m[1][3] = r1.w;
	m[2][0] = r2.x; m[2][1] = r2.y; m[2][2] = r2.z; m[2][3] = r2.w;
	m[3][0] = r3.x; m[3][1] = r3.y; m[3][2] = r3.z; m[3][3] = r3.w;
}
Matrix4x4::Matrix4x4(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33
)
{
	m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
	m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
	m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
	m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
}

float& Matrix4x4::operator() (unsigned row, unsigned col)
{
	return m[row][col];
}
float Matrix4x4::operator() (unsigned row, unsigned col) const
{
	return m[row][col];
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& rm)
{
	m[0][0] *= rm.m[0][0]; m[0][1] *= rm.m[0][1]; m[0][2] *= rm.m[0][2]; m[0][3] *= rm.m[0][3];
	m[1][0] *= rm.m[1][0]; m[1][1] *= rm.m[1][1]; m[1][2] *= rm.m[1][2]; m[1][3] *= rm.m[1][3];
	m[2][0] *= rm.m[2][0]; m[2][1] *= rm.m[2][1]; m[2][2] *= rm.m[2][2]; m[2][3] *= rm.m[2][3];
	m[3][0] *= rm.m[3][0]; m[3][1] *= rm.m[3][1]; m[3][2] *= rm.m[3][2]; m[3][3] *= rm.m[3][3];
	return *this;
}
Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& rm)
{
	m[0][0] += rm.m[0][0]; m[0][1] += rm.m[0][1]; m[0][2] += rm.m[0][2]; m[0][3] += rm.m[0][3];
	m[1][0] += rm.m[1][0]; m[1][1] += rm.m[1][1]; m[1][2] += rm.m[1][2]; m[1][3] += rm.m[1][3];
	m[2][0] += rm.m[2][0]; m[2][1] += rm.m[2][1]; m[2][2] += rm.m[2][2]; m[2][3] += rm.m[2][3];
	m[3][0] += rm.m[3][0]; m[3][1] += rm.m[3][1]; m[3][2] += rm.m[3][2]; m[3][3] += rm.m[3][3];
	return *this;
}
Matrix4x4& Matrix4x4::operator/=(const Matrix4x4& rm)
{
	m[0][0] /= rm.m[0][0]; m[0][1] /= rm.m[0][1]; m[0][2] /= rm.m[0][2]; m[0][3] /= rm.m[0][3];
	m[1][0] /= rm.m[1][0]; m[1][1] /= rm.m[1][1]; m[1][2] /= rm.m[1][2]; m[1][3] /= rm.m[1][3];
	m[2][0] /= rm.m[2][0]; m[2][1] /= rm.m[2][1]; m[2][2] /= rm.m[2][2]; m[2][3] /= rm.m[2][3];
	m[3][0] /= rm.m[3][0]; m[3][1] /= rm.m[3][1]; m[3][2] /= rm.m[3][2]; m[3][3] /= rm.m[3][3];
	return *this;
}
Matrix4x4& Matrix4x4::operator*=(float k)
{
	m[0][0] *= k; m[0][1] *= k; m[0][2] *= k; m[0][3] *= k;
	m[1][0] *= k; m[1][1] *= k; m[1][2] *= k; m[1][3] *= k;
	m[2][0] *= k; m[2][1] *= k; m[2][2] *= k; m[2][3] *= k;
	m[3][0] *= k; m[3][1] *= k; m[3][2] *= k; m[3][3] *= k;
	return *this;
}
Matrix4x4& Matrix4x4::operator/=(float k)
{
	m[0][0] /= k; m[0][1] /= k; m[0][2] /= k; m[0][3] /= k;
	m[1][0] /= k; m[1][1] /= k; m[1][2] /= k; m[1][3] /= k;
	m[2][0] /= k; m[2][1] /= k; m[2][2] /= k; m[2][3] /= k;
	m[3][0] /= k; m[3][1] /= k; m[3][2] /= k; m[3][3] /= k;
	return *this;
}

Matrix4x4 Matrix4x4::operator+() const
{
	return *this;
}
Matrix4x4 Matrix4x4::operator-() const 
{
	return Matrix4x4(
		-m[0][0], -m[0][1], -m[0][2], -m[0][3],
		-m[1][0], -m[1][1], -m[1][2], -m[1][3],
		-m[2][0], -m[2][1], -m[2][2], -m[2][3],
		-m[3][0], -m[3][1], -m[3][2], -m[3][3]
	);
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& rm) const
{
	Matrix4x4 ret;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ret.m[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				ret.m[i][j] += (m[i][k] * rm.m[k][j]);
			}
		}
	}
	return ret;
}
Matrix4x4 Matrix4x4::operator+(const Matrix4x4& rm) const
{
	return Matrix4x4(
		m[0][0] + rm.m[0][0], m[0][1] + rm.m[0][1], m[0][2] + rm.m[0][2], m[0][3] + rm.m[0][3],
		m[1][0] + rm.m[1][0], m[1][1] + rm.m[1][1], m[1][2] + rm.m[1][2], m[1][3] + rm.m[1][3],
		m[2][0] + rm.m[2][0], m[2][1] + rm.m[2][1], m[2][2] + rm.m[2][2], m[2][3] + rm.m[2][3],
		m[3][0] + rm.m[3][0], m[3][1] + rm.m[3][1], m[3][2] + rm.m[3][2], m[3][3] + rm.m[3][3]
	);
}
Matrix4x4 Matrix4x4::operator-(const Matrix4x4& rm) const
{
	return Matrix4x4(
		m[0][0] - rm.m[0][0], m[0][1] - rm.m[0][1], m[0][2] - rm.m[0][2], m[0][3] - rm.m[0][3],
		m[1][0] - rm.m[1][0], m[1][1] - rm.m[1][1], m[1][2] - rm.m[1][2], m[1][3] - rm.m[1][3],
		m[2][0] - rm.m[2][0], m[2][1] - rm.m[2][1], m[2][2] - rm.m[2][2], m[2][3] - rm.m[2][3],
		m[3][0] - rm.m[3][0], m[3][1] - rm.m[3][1], m[3][2] - rm.m[3][2], m[3][3] - rm.m[3][3]
	);
}
Matrix4x4 Matrix4x4::operator*(float k) const
{
	return Matrix4x4(
		m[0][0] * k, m[0][1] * k, m[0][2] * k, m[0][3] * k,
		m[1][0] * k, m[1][1] * k, m[1][2] * k, m[1][3] * k,
		m[2][0] * k, m[2][1] * k, m[2][2] * k, m[2][3] * k,
		m[3][0] * k, m[3][1] * k, m[3][2] * k, m[3][3] * k
	);
}
Matrix4x4 Matrix4x4::operator/(float k) const 
{
	return Matrix4x4(
		m[0][0] / k, m[0][1] / k, m[0][2] / k, m[0][3] / k,
		m[1][0] / k, m[1][1] / k, m[1][2] / k, m[1][3] / k,
		m[2][0] / k, m[2][1] / k, m[2][2] / k, m[2][3] / k,
		m[3][0] / k, m[3][1] / k, m[3][2] / k, m[3][3] / k
	);
}
Vector4D Matrix4x4::operator*(const Vector4D& v) const
{
	return Vector4D(
		m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w,
		m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w,
		m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w,
		m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w
	);
}

bool Matrix4x4::operator==(const Matrix4x4& rm) const
{
	return
		m[0][0] == rm.m[0][0] && m[0][1] == rm.m[0][1] && m[0][2] == rm.m[0][2] && m[0][3] == rm.m[0][3] &&
		m[1][0] == rm.m[1][0] && m[1][1] == rm.m[1][1] && m[1][2] == rm.m[1][2] && m[1][3] == rm.m[1][3] &&
		m[2][0] == rm.m[2][0] && m[2][1] == rm.m[2][1] && m[2][2] == rm.m[2][2] && m[2][3] == rm.m[2][3] &&
		m[3][0] == rm.m[3][0] && m[3][1] == rm.m[3][1] && m[3][2] == rm.m[3][2] && m[3][3] == rm.m[3][3];
}
bool Matrix4x4::operator!=(const Matrix4x4& rm) const
{
	return 
		m[0][0] != rm.m[0][0] || m[0][1] != rm.m[0][1] || m[0][2] != rm.m[0][2] || m[0][3] != rm.m[0][3] ||
		m[1][0] != rm.m[1][0] || m[1][1] != rm.m[1][1] || m[1][2] != rm.m[1][2] || m[1][3] != rm.m[1][3] ||
		m[2][0] != rm.m[2][0] || m[2][1] != rm.m[2][1] || m[2][2] != rm.m[2][2] || m[2][3] != rm.m[2][3] ||
		m[3][0] != rm.m[3][0] || m[3][1] != rm.m[3][1] || m[3][2] != rm.m[3][2] || m[3][3] != rm.m[3][3];
}
bool Matrix4x4::IsIdentity()
{

	return m[0][0] == 1 && 1 == m[1][1] && 1 == m[2][2] && m[3][3] == 1;
}

double Matrix4x4::Determinant()
{
	//00 01 02 03
	//10 11 12 13
	//20 21 22 23
	//30 31 32 33

	double a00 = (double)m[1][1] * m[2][2] * m[3][3] + (double)m[1][2] * m[2][3] * m[3][1] + (double)m[1][3] * m[2][1] * m[3][2]
			   - (double)m[1][3] * m[2][2] * m[3][1] - (double)m[1][1] * m[2][3] * m[3][2] - (double)m[1][2] * m[2][1] * m[3][3];
	double a01 = (double)m[1][0] * m[2][2] * m[3][3] + (double)m[1][2] * m[2][3] * m[3][0] + (double)m[1][3] * m[2][0] * m[3][2]
			   - (double)m[1][3] * m[2][2] * m[3][0] - (double)m[1][0] * m[2][3] * m[3][2] - (double)m[1][2] * m[2][0] * m[3][3];
	double a02 = (double)m[1][0] * m[2][1] * m[3][3] + (double)m[1][1] * m[2][3] * m[3][0] + (double)m[1][3] * m[2][0] * m[3][1]
			   - (double)m[1][3] * m[2][1] * m[3][0] - (double)m[1][0] * m[2][3] * m[3][1] - (double)m[1][1] * m[2][0] * m[3][3];
	double a03 = (double)m[1][0] * m[2][1] * m[3][2] + (double)m[1][1] * m[2][2] * m[3][0] + (double)m[1][2] * m[2][0] * m[3][1]
			   - (double)m[1][2] * m[2][1] * m[3][0] - (double)m[1][0] * m[2][2] * m[3][1] - (double)m[1][1] * m[2][0] * m[3][2];
	return (m[0][0] * a00 - m[0][1] * a01 + m[0][2] * a02 - m[0][3] * a03);
}
Matrix4x4 Matrix4x4::Transpose()
{
	return Matrix4x4(
		m[0][0], m[1][0], m[2][0], m[3][0],
		m[0][1], m[1][1], m[2][1], m[3][1],
		m[0][2], m[1][2], m[2][2], m[3][2],
		m[0][3], m[1][3], m[2][3], m[3][3]
	);
}

Matrix4x4 Matrix4x4::Inverse()
{
	double a00 = (double)m[1][1] * m[2][2] * m[3][3] + (double)m[1][2] * m[2][3] * m[3][1] + (double)m[1][3] * m[2][1] * m[3][2]
		- (double)m[1][3] * m[2][2] * m[3][1] - (double)m[1][1] * m[2][3] * m[3][2] - (double)m[1][2] * m[2][1] * m[3][3];
	double a01 = (double)m[1][0] * m[2][2] * m[3][3] + (double)m[1][2] * m[2][3] * m[3][0] + (double)m[1][3] * m[2][0] * m[3][2]
		- (double)m[1][3] * m[2][2] * m[3][0] - (double)m[1][0] * m[2][3] * m[3][2] - (double)m[1][2] * m[2][0] * m[3][3];
	double a02 = (double)m[1][0] * m[2][1] * m[3][3] + (double)m[1][1] * m[2][3] * m[3][0] + (double)m[1][3] * m[2][0] * m[3][1]
		- (double)m[1][3] * m[2][1] * m[3][0] - (double)m[1][0] * m[2][3] * m[3][1] - (double)m[1][1] * m[2][0] * m[3][3];
	double a03 = (double)m[1][0] * m[2][1] * m[3][2] + (double)m[1][1] * m[2][2] * m[3][0] + (double)m[1][2] * m[2][0] * m[3][1]
		- (double)m[1][2] * m[2][1] * m[3][0] - (double)m[1][0] * m[2][2] * m[3][1] - (double)m[1][1] * m[2][0] * m[3][2];
	double detMat = m[0][0] * a00 - m[0][1] * a01 + m[0][2] * a02 - m[0][3] * a03;
	if (detMat == 0)
	{
		//行列式为0,不存在逆矩阵
		return Matrix4x4();
	}
	double rDetMat = 1.0f / detMat;
	//00 01 02 03
	//10 11 12 13
	//20 21 22 23
	//30 31 32 33
	

	//01 02 03 01 02 03
	//21 22 23 21 22 23
	//31 32 33 31 32 33
	double a10 = (double)m[0][1] * m[2][2] * m[3][3] + (double)m[0][2] * m[2][3] * m[3][1] + (double)m[0][3] * m[2][1] * m[3][2]
			   - (double)m[0][3] * m[2][2] * m[3][1] - (double)m[0][1] * m[2][3] * m[3][2] - (double)m[0][2] * m[2][1] * m[3][3];
	
	double a11 = (double)m[0][0] * m[2][2] * m[3][3] + (double)m[0][2] * m[2][3] * m[3][0] + (double)m[0][3] * m[2][0] * m[3][2]
			   - (double)m[0][3] * m[2][2] * m[3][0] - (double)m[0][0] * m[2][3] * m[3][2] - (double)m[0][2] * m[2][0] * m[3][3];
	double a12 = (double)m[0][0] * m[2][1] * m[3][3] + (double)m[0][1] * m[2][3] * m[3][0] + (double)m[0][3] * m[2][0] * m[3][1]
			   - (double)m[0][3] * m[2][1] * m[3][0] - (double)m[0][0] * m[2][3] * m[3][1] - (double)m[0][1] * m[2][0] * m[3][3];
	double a13 = (double)m[0][0] * m[2][1] * m[3][2] + (double)m[0][1] * m[2][2] * m[3][0] + (double)m[0][2] * m[2][0] * m[3][1]
			   - (double)m[0][2] * m[2][1] * m[3][0] - (double)m[0][0] * m[2][2] * m[3][1] - (double)m[0][1] * m[2][0] * m[3][2];
	double a20 = (double)m[0][1] * m[1][2] * m[3][3] + (double)m[0][2] * m[1][3] * m[3][1] + (double)m[0][3] * m[1][1] * m[3][2]
			   - (double)m[0][3] * m[1][2] * m[3][1] - (double)m[0][1] * m[1][3] * m[3][2] - (double)m[0][2] * m[1][1] * m[3][3];
	double a21 = (double)m[0][0] * m[1][2] * m[3][3] + (double)m[0][2] * m[1][3] * m[3][0] + (double)m[0][3] * m[1][0] * m[3][2]
			   - (double)m[0][3] * m[1][2] * m[3][0] - (double)m[0][0] * m[1][3] * m[3][2] - (double)m[0][2] * m[1][0] * m[3][3];
	double a22 = (double)m[0][0] * m[1][1] * m[3][3] + (double)m[0][1] * m[1][3] * m[3][0] + (double)m[0][3] * m[1][0] * m[3][1]
			   - (double)m[0][3] * m[1][1] * m[3][0] - (double)m[0][0] * m[1][3] * m[3][1] - (double)m[0][1] * m[1][0] * m[3][3];
	double a23 = (double)m[0][0] * m[1][1] * m[3][2] + (double)m[0][1] * m[1][2] * m[3][0] + (double)m[0][2] * m[1][0] * m[3][1]
			   - (double)m[0][2] * m[1][1] * m[3][0] - (double)m[0][0] * m[1][2] * m[3][1] - (double)m[0][1] * m[1][0] * m[3][2];
	double a30 = (double)m[0][1] * m[1][2] * m[2][3] + (double)m[0][2] * m[1][3] * m[2][1] + (double)m[0][3] * m[1][1] * m[2][2]
			   - (double)m[0][3] * m[1][2] * m[2][1] - (double)m[0][1] * m[1][3] * m[2][2] - (double)m[0][2] * m[1][1] * m[2][3];
	double a31 = (double)m[0][0] * m[1][2] * m[2][3] + (double)m[0][2] * m[1][3] * m[2][0] + (double)m[0][3] * m[1][0] * m[2][2]
			   - (double)m[0][3] * m[1][2] * m[2][0] - (double)m[0][0] * m[1][3] * m[2][2] - (double)m[0][2] * m[1][0] * m[2][3];
	double a32 = (double)m[0][0] * m[1][1] * m[2][3] + (double)m[0][1] * m[1][3] * m[2][0] + (double)m[0][3] * m[1][0] * m[2][1]
			   - (double)m[0][3] * m[1][1] * m[2][0] - (double)m[0][0] * m[1][3] * m[2][1] - (double)m[0][1] * m[1][0] * m[2][3];
	double a33 = (double)m[0][0] * m[1][1] * m[2][2] + (double)m[0][1] * m[1][2] * m[2][0] + (double)m[0][2] * m[1][0] * m[2][1]
			   - (double)m[0][2] * m[1][1] * m[2][0] - (double)m[0][0] * m[1][2] * m[2][1] - (double)m[0][1] * m[1][0] * m[2][2];

	return Matrix4x4(
		a00 * rDetMat, -a10 * rDetMat, a20 * rDetMat, -a30 * rDetMat,
		-a01 * rDetMat, a11 * rDetMat, -a21 * rDetMat, a31 * rDetMat,
		a02 * rDetMat, -a12 * rDetMat, a22 * rDetMat, -a32 * rDetMat,
		-a03 * rDetMat, a13 * rDetMat, -a23 * rDetMat, a33 * rDetMat
	);
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
	float sinAng = sinf(Angle);
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