#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
	: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		double first = round(pow(-(this->GetTotalPassengersWeight() / 15), 3) + 2 * this->GetTotalPassengersWeight() + 400);
		double second = 0;
		return static_cast<unsigned int>(std::max(first, second));
	}

	unsigned int Motorcycle::GetMoveInterval() const
	{
		return 5;
	}

	unsigned int Motorcycle::GetRestInterval() const
	{
		return 1;
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		return this->GetMaxSpeed();
	}
}