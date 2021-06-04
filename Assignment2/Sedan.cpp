#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
	{
		
	}

	Sedan::~Sedan()
	{
		if(this->mTrailer != nullptr)
		{
			delete this->mTrailer;
		}
	}

	Sedan& Sedan::operator=(const Sedan& sedan)
	{
		if (&sedan == this)
		{
			return *this;
		}

		Vehicle::operator=(sedan);

		if (this->mTrailer == nullptr)
		{
			this->mTrailer = sedan.mTrailer;	
		}
		else
		{
			delete this->mTrailer;
			this->mTrailer = sedan.mTrailer;
		}

		return *this;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (this->mTrailer == nullptr)
		{
			this->mTrailer = trailer;
			return true;
		}
		return false;
	}

	bool Sedan::RemoveTrailer()
	{
		if (this->mTrailer != nullptr)
		{
			delete mTrailer;
			this->mTrailer = nullptr;
			return true;
		}
		return false;
	}
	unsigned int Sedan::GetMaxSpeed() const
	{
		return this->GetDriveSpeed();
	}
	unsigned int Sedan::GetMoveInterval() const
	{
		if (this->mTrailer == nullptr)
		{
			return 5;
		}
		else
		{
			return 5;
		}
		
	}
	unsigned int Sedan::GetRestInterval() const
	{
		if (this->mTrailer == nullptr)
		{
			return 1;
		} 		
		else
		{
			return 2;
		}
	}
	unsigned int Sedan::GetDriveSpeed() const
	{
		double x = this->getTotalWeightsWithTrailer();

		if (x > 350)
		{
			return 300;
		}
		else if (x > 260)
		{
			return 380;
		}
		else if (x > 160)
		{
			return 400;
		}
		else if (x > 80)
		{
			return 458;
		}
		else
		{
			return 480;
		}
	}
	double Sedan::getTotalWeightsWithTrailer() const
	{
		if (this->mTrailer == nullptr)
		{
			return this->getTotalPassengersWeight();
		}
		else
		{
			return this->getTotalPassengersWeight() + static_cast<double>((this->mTrailer)->GetWeight());
		}
		
	}
}