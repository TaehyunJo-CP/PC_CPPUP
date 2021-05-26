#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
	{
		for (unsigned int i = 0 ; i < this->mMaxPointCount; i++)
		{
			(this->mPoints)[i] = nullptr;
		}
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		for (unsigned int i = 0; i < this->mMaxPointCount; i++)
		{
			(this->mPoints)[i] = nullptr;
		}

		this->mPointCount = other.mPointCount;

		for (unsigned int i = 0; i < this->mPointCount; i++)
		{
			Point* tmp = new Point(other.mPoints[i]->GetX(), other.mPoints[i]->GetY());
			(this->mPoints)[i] = tmp;
		}
	}

	PolyLine::~PolyLine()
	{
		for (unsigned int i = 0; i < this->mPointCount; i++)
		{
			delete mPoints[i];
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		for (unsigned int i = 0; i < this->mMaxPointCount; i++)
		{
			(this->mPoints)[i] = nullptr;
		}

		this->mPointCount = other.mPointCount;

		for (unsigned int i = 0; i < this->mPointCount; i++)
		{
			Point* tmp = new Point(other.mPoints[i]->GetX(), other.mPoints[i]->GetY());
			(this->mPoints)[i] = tmp;
		}

		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (this->mPointCount < this->mMaxPointCount)
		{
			mPoints[this->mPointCount] = new Point(x, y);
			this->mPointCount++;

			return true;
		}
		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (this->mPointCount < this->mMaxPointCount && point != nullptr)
		{
			mPoints[this->mPointCount] = point;
			this->mPointCount++;

			return true;
		}
		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (this->mPointCount > i && i >= 0)
		{
			delete mPoints[i];

			for (unsigned int j = i; j < this->mPointCount - 1; j++)
			{
				mPoints[j] = mPoints[j + 1];
			}
			this->mPointCount--;
			mPoints[this->mPointCount] = nullptr;

			return true;
		}

		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (this->mPointCount > 0)
		{
			float minX = 0.0f;
			float minY = 0.0f;
			float maxX = 0.0f;
			float maxY = 0.0f;

			for (unsigned int i = 0; i < this->mPointCount; i++)
			{
				const Point* tmp = mPoints[i];
				float thisX = tmp->GetX();
				float thisY = tmp->GetY();

				if (i == 0)
				{
					minX = thisX;
					maxX = thisX;
					minY = thisY;
					maxY = thisY;
				}
				else
				{
					if (minX > thisX)
					{
						minX = thisX;
					}

					if (maxX < thisX)
					{
						maxX = thisX;
					}

					if (minY > thisY)
					{
						minY = thisY;
					}

					if (maxY < thisY)
					{
						maxY = thisY;
					}
				}
			}

			*outMin = Point(minX, minY);
			*outMax = Point(maxX, maxY);

			return true;
		}

		return false;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i < this->mPointCount && i >= 0)
		{
			return this->mPoints[i];
		}
		else
		{
			return nullptr;
		}
	}
}