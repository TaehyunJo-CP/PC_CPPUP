#pragma once

#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat: public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		~UBoat();

		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetMaxSpeed() const override;
		unsigned int GetMoveInterval() const;
		unsigned int GetRestInterval() const;


		// ISailable을(를) 통해 상속됨
		virtual unsigned int GetSailSpeed() const override;

		// IDivable을(를) 통해 상속됨
		virtual unsigned int GetDiveSpeed() const override;
	};
}