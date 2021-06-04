#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = nullptr;

	DeusExMachina::DeusExMachina()
	{
		for (int i = 0; i < 10; i++)
		{
			(this->mVehicles)[i] = nullptr;
		}
	}

	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int i = 0; i < this->mCurVehicleCount; i++)
		{
			delete (this->mVehicles)[i];
		}

		delete DeusExMachina::mInstance;
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (DeusExMachina::mInstance == nullptr)
		{
			DeusExMachina::mInstance = new DeusExMachina();
		}
		return DeusExMachina::mInstance;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < this->mCurVehicleCount; i++)
		{
			(this->mVehicles)[i]->Travel();
		}
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
		unsigned int maxDistance = 0;
		Vehicle* vehiclePtr = nullptr;

		for (unsigned int i = 0; i < this->mCurVehicleCount; i++)
		{
			unsigned int moveDistance = (this->mVehicles)[i]->GetMoveDistance();

			if (i == 0)
			{
				maxDistance = moveDistance;
				vehiclePtr = (this->mVehicles)[i];
			}
			else
			{
				if (maxDistance < moveDistance)
				{
					maxDistance = moveDistance;
					vehiclePtr = (this->mVehicles)[i];
				}
			}
		}

		return vehiclePtr;
	}


}