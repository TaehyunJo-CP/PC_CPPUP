#pragma once

#include "Vehicle.h"
#include "ISailable.h"

#include "Airplane.h"
#include "Boatplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		virtual ~Boat();
		Boat& operator=(const Boat& airplane);

		Boatplane operator+(Airplane& plane);

		// ISailable을(를) 통해 상속됨
		unsigned int GetSailSpeed() const;

		// Vehicle을(를) 통해 상속됨
		unsigned int GetMaxSpeed() const;
		unsigned int GetMoveInterval() const;
		unsigned int GetRestInterval() const;
	};
}