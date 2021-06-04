#include "Airplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	Airplane& Airplane::operator=(const Airplane& airplane)
	{
		Vehicle::operator=(airplane);
		return *this;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(this->GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		for (unsigned int i = 0; i < this->GetPassengersCount(); i++)
		{
			bp.AddPassenger(this->GetPassenger(i));
		}

		this->TakeOffAllPassengers();

		for (unsigned int i = 0; i < boat.GetPassengersCount(); i++)
		{
			bp.AddPassenger(boat.GetPassenger(i));
		}

		boat.TakeOffAllPassengers();

		return bp;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		return static_cast<unsigned int>(round(4 * exp((-this->getTotalPassengersWeight() + 400) / 70)));
		
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		return static_cast<unsigned int>(round(200 * exp((-this->getTotalPassengersWeight() + 800) / 500)));
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		return std::max(this->GetDriveSpeed(), this->GetFlySpeed());
	}

	unsigned int Airplane::GetMoveInterval() const
	{
		return 1;
	}
	unsigned int Airplane::GetRestInterval() const
	{
		return 3;
	}
}