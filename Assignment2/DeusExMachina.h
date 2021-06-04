#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		static DeusExMachina* instance;
		DeusExMachina();
		~DeusExMachina();

		unsigned int mMaxVehicleCount = 10;
		unsigned int mCurVehicleCount = 0;
		Vehicle* mVehicles[10];

	};
}