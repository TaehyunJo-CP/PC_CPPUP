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
		virtual ~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		// Vehicle��(��) ���� ��ӵ�
		virtual unsigned int GetMaxSpeed() const override;
		unsigned int GetMoveInterval() const;
		unsigned int GetRestInterval() const;

		// IDrivable��(��) ���� ��ӵ�
		virtual unsigned int GetDriveSpeed() const override;

	private:
		double GetTotalWeightsWithTrailer() const;

		const Trailer* mTrailer = nullptr;
	};
}