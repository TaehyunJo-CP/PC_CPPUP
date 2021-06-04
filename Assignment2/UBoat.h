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

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const override;
		unsigned int GetMoveInterval() const;
		unsigned int GetRestInterval() const;


		// ISailable��(��) ���� ��ӵ�
		virtual unsigned int GetSailSpeed() const override;

		// IDivable��(��) ���� ��ӵ�
		virtual unsigned int GetDiveSpeed() const override;
	};
}