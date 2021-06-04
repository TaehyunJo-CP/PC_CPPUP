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

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const override;


		// IFlyable��(��) ���� ��ӵ�
		virtual unsigned int GetFlySpeed() const override;


		// ISailable��(��) ���� ��ӵ�
		virtual unsigned int GetSailSpeed() const override;

	};
}