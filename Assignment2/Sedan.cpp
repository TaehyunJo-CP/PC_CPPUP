#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
	: Vehicle(4)
	{
		
	}

	Sedan::~Sedan()
	{
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
	unsigned int Sedan::GetDriveSpeed() const
	{
		double x = this->GetTotalWeightsWithTrailer();

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
	double Sedan::GetTotalWeightsWithTrailer() const
	{
		return this->GetTotalPassengersWeight() + static_cast<double>((this->mTrailer)->GetWeight());
	}
}