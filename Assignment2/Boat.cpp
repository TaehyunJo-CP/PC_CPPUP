#include "Boat.h"


namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
	: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		
		Boatplane bp(this->GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		for (unsigned int i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp.AddPassenger(plane.GetPassenger(i));
		}

		plane.TakeOffAllPassengers();

		for (unsigned int i = 0; i < this->GetPassengersCount(); i++)
		{
			bp.AddPassenger(this->GetPassenger(i));
		}

		this->TakeOffAllPassengers();

		return bp;
	}
	unsigned int Boat::GetSailSpeed() const
	{
		double first = round(800 - 10 * this->GetTotalPassengersWeight());
		double second = 20;

		return static_cast<unsigned int>(std::max(first, second));
	}
	unsigned int Boat::GetMaxSpeed() const
	{
		return this->GetSailSpeed();
	}
	unsigned int Boat::GetMoveInterval() const
	{
		return 2;
	}
	unsigned int Boat::GetRestInterval() const
	{
		return 1;
	}
}