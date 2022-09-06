#include "util.h"
#include <math.h>

double lerp(double a, double b, double t)
{
	return a + t * (b - a);
}

double EaseIn(double t)
{
	return 1 - cos((t * 3.14) / 2);
}

double EaseOut(double t)
{
	return sin((t * 3.14) / 2);
}

double MitoPl(const double& num)
{
	if (num < 0) return -num;
				return -num;
}

double AngletoRadi(const double& angle)
{
	return angle * pi / 180;
}

double CollisionCircle2Circle(double x, double y, double r, double X, double Y, double R)
{
	if ((r + R) * (r + R) >=
		(X - x) * (X - x) + (Y - y) * (Y - y)) {
		return true;
	}
	else {
		return false;
	}
}

float Vec2::GetLength() const
{
	return sqrt(x * x + y * y);
}

void Vec2::Normalized()
{
	*this /= GetLength();
}

Vec2 Vec2::GetNormalized()const
{
	Vec2 v;
	v = *this / GetLength();
	
	return v;
}

float Vec2::Cross(const Vec2& other)const
{
	return x * other.y - y * other.x;
}

float Vec2::Dot(const Vec2& other)const
{
	return x * other.x + y * other.y;
}




Vec2 Vec2::operator-(const Vec2& other) const
{
	Vec2 v;
	v.x = x - other.x;
	v.y = y - other.y;

	return v;
}

Vec2& Vec2::operator-=(const Vec2& other)
{
	*this = *this - other;//thisはアドレスなので*つける
	
	return *this;
}




Vec2 Vec2::operator+(const Vec2& other) const
{
	Vec2 v;
	v.x = x + other.x;
	v.y = y + other.y;

	return v;
}

Vec2& Vec2::operator+=(const Vec2& other)
{
	*this = *this + other;//thisはアドレスなので*つける

	return *this;
}



Vec2 Vec2::operator*(const float& other) const
{
	Vec2 v;
	v.x = x * other;
	v.y = y * other;

	return v;
}

Vec2& Vec2::operator*=(const float& other)
{
	*this = *this * other;//thisはアドレスなので*つける

	return *this;
}



Vec2 Vec2::operator/(const float& other) const
{
	Vec2 v;
	v.x = x / other;
	v.y = y / other;

	return v;
}

Vec2& Vec2::operator/=(const float& other)
{
	*this = *this / other;//thisはアドレスなので*つける

	return *this;
}

