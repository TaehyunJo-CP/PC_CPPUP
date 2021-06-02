#include "CircleLawn.h"
#include <cmath>

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
	{
		this->radius = radius;
	}
	CircleLawn::~CircleLawn()
	{
	}
	unsigned int CircleLawn::GetArea() const
	{
		double r = static_cast<double>(this->radius);
		double area = round(Lawn::PI * r * r);
		return static_cast<unsigned int>(area);
	}
}