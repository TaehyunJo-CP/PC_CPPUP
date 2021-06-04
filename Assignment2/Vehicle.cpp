#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
	{
		this->mMaxPassengerCount = maxPassengersCount;

		for (unsigned int i = 0; i < 100; i++)
		{
			mPeople[i] = nullptr;
		}
	}

	Vehicle::Vehicle(const Vehicle& vehicle)
	{
		this->mMaxPassengerCount = vehicle.mMaxPassengerCount;

		for (unsigned int i = 0; i < 100; i++)
		{
			mPeople[i] = nullptr;
		}

		this->mCurPassengerCount = vehicle.mCurPassengerCount;

		for (unsigned int i = 0; i < this->mCurPassengerCount; i++)
		{
			(this->mPeople)[i] = new Person(*vehicle.mPeople[i]);
		}
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < this->mCurPassengerCount; i++)
		{
			delete (this->mPeople)[i];
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& vehicle)
	{
		if (&vehicle == this)
		{
			return *this;
		}

		for (unsigned int i = 0; i < this->mCurPassengerCount; i++)
		{
			delete (this->mPeople)[i];
			(this->mPeople)[i] = nullptr;
		}
		
		for (unsigned int i = 0; i < vehicle.mCurPassengerCount; i++)
		{
			(this->mPeople)[i] = vehicle.mPeople[i];
		}

		this->mMaxPassengerCount = vehicle.mMaxPassengerCount;
		this->mCurPassengerCount = vehicle.mCurPassengerCount;

		this->mMoveTurn = vehicle.mMoveTurn;
		this->mMoveDistance = vehicle.mMoveDistance;

		return *this;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		for (unsigned int i = 0; i < this->mCurPassengerCount; i++)
		{
			if ((this->mPeople)[i] == person)
			{
				return false;
			}
		}

		if (this->mCurPassengerCount < this->mMaxPassengerCount && person != nullptr)
		{
			this->mPeople[this->mCurPassengerCount] = person;
			this->mCurPassengerCount++;
			return true;
		}
		return false;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i < this->mCurPassengerCount)
		{
			delete this->mPeople[i];

			for (unsigned int j = i; j < this->mCurPassengerCount - 1; j++)
			{
				this->mPeople[j] = this->mPeople[j + 1];
			}
			this->mCurPassengerCount--;

			this->mPeople[this->mCurPassengerCount] = nullptr;

			return true;
		}
		return false;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return this->mCurPassengerCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return this->mMaxPassengerCount;
	}

	double Vehicle::getTotalPassengersWeight() const
	{
		unsigned int sumWeight = 0;
		for (unsigned int i = 0; i < this->mCurPassengerCount; i++)
		{
			sumWeight += (this->mPeople[i])->GetWeight();
		}

		return static_cast<double>(sumWeight);
	}

	void Vehicle::TakeOffAllPassengers()
	{
		for (unsigned int i = 0; i < this->mCurPassengerCount; i++)
		{
			(this->mPeople)[i] = nullptr;
		}

		this->mCurPassengerCount = 0;
	}

	void Vehicle::Travel()
	{
		unsigned int moveInterval = this->GetMoveInterval();
		unsigned int restInvterval = this->GetRestInterval();

		this->mMoveTurn = this->mMoveTurn % (moveInterval + restInvterval);

		if (this->mMoveTurn < moveInterval)
		{
			this->mMoveDistance += this->GetMaxSpeed();
		}
		else if (this->mMoveTurn < (moveInterval + restInvterval))
		{
			this->mMoveDistance += 0;
		}

		this->mMoveTurn++;

	}

	unsigned int Vehicle::GetMoveDistance() const
	{
		return this->mMoveDistance;
	}


	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i < this->mCurPassengerCount)
		{
			return (this->mPeople)[i];
		}
		return NULL;
	}
}