#pragma once
#include"DxLib.h"

class Vec2
{
public:
	double x;
	double y;

	Vec2()
		:x(0), y(0)
	{}

	Vec2(double x, double y)
		:x(x), y(y)
	{}

	//�֐�
	float GetLength() const;
	void  Normalized();
	Vec2  GetNormalized()const;//
	float Cross(const Vec2& other)const;//
	float Dot(const Vec2& other)const;//

	Vec2  operator -(const Vec2& other)const;//vec���m�̈����Z
	Vec2& operator -=(const Vec2& other);//�������Z�q(-)
	
	Vec2  operator +(const Vec2& other)const;
	Vec2& operator +=(const Vec2& other);//�������Z�q(+)
	
	Vec2  operator *(const float& other)const;
	Vec2& operator *=(const float& other);//�������Z�q(*)
	
	Vec2  operator /(const float& other)const;
	Vec2& operator /=(const float& other);//�������Z�q(/)
};

//�ϐ�
const float pi = 3.1415f;

//�֐�
double lerp(double a, double b, double t);//���`�⊮

double EaseIn(double t);

double EaseOut(double t);

double MitoPl(const double& num);

double AngletoRadi(const double& angle);

double CollisionCircle2Circle(double x, double y, double r, double X, double Y, double R);