#pragma once

#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle: public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		virtual ~Motorcycle();

		Motorcycle& operator=(const Motorcycle& motorcycle);

		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetMaxSpeed() const override;
		unsigned int GetMoveInterval() const;
		unsigned int GetRestInterval() const;

		// IDrivable을(를) 통해 상속됨
		virtual unsigned int GetDriveSpeed() const override;
	};
}