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

		// ISailable��(��) ���� ��ӵ�
		unsigned int GetSailSpeed() const;

		// Vehicle��(��) ���� ��ӵ�
		unsigned int GetMaxSpeed() const;
		unsigned int GetMoveInterval() const;
		unsigned int GetRestInterval() const;
	};
}