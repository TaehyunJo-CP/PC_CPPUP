#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
		: mX(x)
		, mY(y)
	{
	}

	Point::Point(const Point& other)
	{
		this->mX = other.GetX();
		this->mY = other.GetY();
	}

	Point::~Point()
	{
	}

	Point& Point::operator=(const Point& other)
	{
		this->mX = other.GetX();
		this->mY = other.GetY();
		return *this;
	}

	Point Point::operator+(const Point& other) const
	{
		return Point(mX + other.mX, mY + other.mY);
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(mX - other.mX, mY - other.mY);
	}

	float Point::Dot(const Point& other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	Point Point::operator*(float operand) const
	{
		return Point(mX * operand, mY * operand);
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}

	Point operator*(const float scalar, const Point& lhs)
	{
		return lhs * scalar;
	}
}