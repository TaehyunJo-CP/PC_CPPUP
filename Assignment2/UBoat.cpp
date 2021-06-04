#include "UBoat.h"
#include <cmath>


namespace assignment2
{
	UBoat::UBoat()
	: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}
	unsigned int UBoat::GetMaxSpeed() const
	{
		return std::max(this->GetDiveSpeed(), this->GetSailSpeed());
	}

	unsigned int UBoat::GetMoveInterval() const
	{
		return 2;
	}

	unsigned int UBoat::GetRestInterval() const
	{
		return 4;
	}
	
	unsigned int UBoat::GetSailSpeed() const
	{
		double x = this->GetTotalPassengersWeight();
		double r = round(500 * log((x + 150) / 150) + 30);

		return static_cast<unsigned int>(r);
	}
	unsigned int UBoat::GetDiveSpeed() const
	{
		double x = this->GetTotalPassengersWeight();
		double first = round((550 - x / 10));
		double second = 200;

		return static_cast<unsigned int>(std::max(first, second));
	}
}