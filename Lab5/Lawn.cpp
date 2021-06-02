#include "Lawn.h"
#include <cmath>;

namespace lab5
{
	const double Lawn::PI = 3.14;
	const double Lawn::ROLL_GRASS_AREA = 0.3;
	const double Lawn::FENCE_WIDTH = 0.25;

	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		unsigned int area = this->GetArea();
		double pricePerArea = 0.0;
		if (grassType == BERMUDA)
		{
			pricePerArea = 800;
		}
		else if (grassType == BAHIA)
		{
			pricePerArea = 500;
		}
		else if (grassType == BENTGRASS)
		{
			pricePerArea = 300;
		}
		else if (grassType == PERENNIAL_RYEGRASS)
		{
			pricePerArea = 250;
		}
		else if (grassType == ST_AUGUSTINE)
		{
			pricePerArea = 450;
		}

		double totalPrice = round(area * pricePerArea / 100.0);

		return static_cast<unsigned int>(totalPrice);
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		unsigned int area = this->GetArea();

		double areaD = static_cast<double>(area);
		double count = ceil(areaD / Lawn::ROLL_GRASS_AREA);

		return static_cast<unsigned int>(count);
	}
}
