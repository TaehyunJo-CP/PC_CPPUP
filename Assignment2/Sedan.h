#pragma once

#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan: public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& sedan1);
		virtual ~Sedan();
		Sedan& operator=(const Sedan& sedan);

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();


		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const override;
		unsigned int GetMoveInterval() const;
		unsigned int GetRestInterval() const;

		// IDrivable��(��) ���� ��ӵ�
		virtual unsigned int GetDriveSpeed() const override;

	private:
		double getTotalWeightsWithTrailer() const;

		const Trailer* mTrailer = nullptr;
	};
}