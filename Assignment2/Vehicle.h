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

		Vehicle& operator=(const Vehicle& vehicle);

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;

		void TakeOffAllPassengers();

		void Travel();

		virtual unsigned int GetMoveInterval() const = 0;
		virtual unsigned int GetRestInterval() const = 0;
		unsigned int GetMoveDistance() const;
	
	protected:
		virtual double getTotalPassengersWeight() const;

		unsigned int mMaxPassengerCount = 0;
		unsigned int mCurPassengerCount = 0;

		const Person* mPeople[100];

		unsigned int mMoveTurn = 0;
		unsigned int mMoveDistance = 0;
	};
}