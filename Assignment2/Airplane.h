#pragma once

#include "Vehicle.h"
#include "IDrivable.h"
#include "IFlyable.h"

#include "Boatplane.h"
#include "Boat.h"


namespace assignment2
{
	class Boat;

	class Airplane: public Vehicle, public IDrivable, public IFlyable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		virtual ~Airplane();

		Boatplane operator+(Boat& boat);

		// IDrivable��(��) ���� ��ӵ�
		unsigned int GetDriveSpeed() const;

		// IFlyable��(��) ���� ��ӵ�
		unsigned int GetFlySpeed() const;

		// Vehicle��(��) ���� ��ӵ�
		unsigned int GetMaxSpeed() const;
		unsigned int GetMoveInterval() const;
		unsigned int GetRestInterval() const;

	};
}