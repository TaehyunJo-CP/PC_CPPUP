#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::instance = nullptr;

	DeusExMachina::DeusExMachina()
	{
		for (int i = 0; i < 10; i++)
		{
			(this->mVehicles)[i] = nullptr;
		}
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (DeusExMachina::instance == nullptr)
		{
			DeusExMachina::instance = new DeusExMachina();
		}
		return DeusExMachina::instance;
	}

	void DeusExMachina::Travel() const
	{
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (this->mMaxVehicleCount > this->mCurVehicleCount && vehicle != nullptr)
		{
			(this->mVehicles)[this->mCurVehicleCount] = vehicle;
			this->mCurVehicleCount++;
			return true;
		}
		return false;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i < this->mCurVehicleCount)
		{
			delete this->mVehicles[i];

			for (unsigned int j = i; j < this->mCurVehicleCount - 1; j++)
			{
				this->mVehicles[j] = this->mVehicles[j + 1];
			}
			this->mCurVehicleCount--;

			this->mVehicles[this->mCurVehicleCount] = nullptr;

			return true;
		}
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}


}