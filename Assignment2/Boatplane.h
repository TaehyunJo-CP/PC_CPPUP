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

		virtual ~Boatplane();

		// Vehicle을(를) 통해 상속됨
		virtual unsigned int GetMaxSpeed() const override;


		// IFlyable을(를) 통해 상속됨
		virtual unsigned int GetFlySpeed() const override;


		// ISailable을(를) 통해 상속됨
		virtual unsigned int GetSailSpeed() const override;

	};
}