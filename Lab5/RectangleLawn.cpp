#include "RectangleLawn.h"
#include "eFenceType.h"
#include <cmath>;

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
	{
		this->width = width;
		this->height = height;
	}
	RectangleLawn::~RectangleLawn()
	{
	}
	unsigned int RectangleLawn::GetArea() const
	{
		return this->width * this->height;
	}
	unsigned int RectangleLawn::GetPerimeter() const
	{
		return (this->width + this->height) * 2;
	}
	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		double perimeter = static_cast<double>(this->GetPerimeter());
		double count = ceil(perimeter / Lawn::FENCE_WIDTH);

		return static_cast<unsigned int>(count);
	}
	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		double perimeter = static_cast<double>(this->GetPerimeter());

		double fencePricePerMeter = 0.0;
		if (fenceType == RED_CEDAR)
		{
			fencePricePerMeter = 600;
		}
		else if (fenceType == SPRUCE)
		{
			fencePricePerMeter = 700;
		}
		return static_cast<unsigned int>(perimeter * fencePricePerMeter / 100);
	}
}
