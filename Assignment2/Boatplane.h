#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"


namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{

	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(const Boatplane& boatplane);

		Boatplane& operator=(const Boatplane& airplane);

		virtual ~Boatplane();

		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetMaxSpeed() const override;
		unsigned int GetMoveInterval() const;
		unsigned int GetRestInterval() const;


		// IFlyable을(를) 통해 상속됨
		virtual unsigned int GetFlySpeed() const override;


		// ISailable을(를) 통해 상속됨
		virtual unsigned int GetSailSpeed() const override;

	};
}