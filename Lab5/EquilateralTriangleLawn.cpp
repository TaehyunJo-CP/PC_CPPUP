#include "EquilateralTriangleLawn.h"
#include <cmath>

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int length)
	{
		this->length = length;
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		double l = static_cast<double>(this->length);
		double area = round(sqrt(3) / 4.0 * (l * l));
		return static_cast<unsigned int>(area);
	}
	unsigned int EquilateralTriangleLawn::GetPerimeter() const
	{
		return this->length * 3;
	}
	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		double perimeter = static_cast<double>(this->GetPerimeter());
		double count = ceil(perimeter / Lawn::FENCE_WIDTH);

		return static_cast<unsigned int>(count);
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		double perimeter = static_cast<double>(this->GetPerimeter());

		double fencePricePerMeter = 0.0;
		if (fenceType == RED_CEDAR)
		{
			fencePricePerMeter = 600;
		} else if (fenceType == SPRUCE)
		{
			fencePricePerMeter = 700;
		}
		return static_cast<unsigned int>(perimeter * fencePricePerMeter / 100);
	}
}