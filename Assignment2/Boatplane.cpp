#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
	: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::Boatplane(const Boatplane& boatplane)
	: Vehicle(boatplane)
	{
	}

	Boatplane::~Boatplane()
	{
	}
	unsigned int Boatplane::GetMaxSpeed() const
	{
		return std::max(this->GetFlySpeed(), this->GetSailSpeed());
	}
	unsigned int Boatplane::GetMoveInterval() const
	{
		return 1;
	}
	unsigned int Boatplane::GetRestInterval() const
	{
		return 3;
	}
	unsigned int Boatplane::GetFlySpeed() const
	{
		return static_cast<unsigned int>(round((150 * exp((-this->GetTotalPassengersWeight() + 500) / 300))));
	}
	unsigned int Boatplane::GetSailSpeed() const
	{
		double first = round(800 - 1.7 * this->GetTotalPassengersWeight());
		double second = 20;
		return static_cast<unsigned int>(std::max(first, second));
	}
}
