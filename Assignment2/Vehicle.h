#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(const Vehicle& vehicle);

		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;

		void TakeOffAllPassengers();

		void Travel();
		unsigned int GetMoveDistance();
	
	protected:
		virtual double GetTotalPassengersWeight() const;

		unsigned int mMaxPassengerCount = 0;
		unsigned int mCurPassengerCount = 0;

		const Person* mPeople[100];

		unsigned int mMoveTrun = 0;
		unsigned int mMoveDistance = 0;
	};
}