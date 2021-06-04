#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight)
	{
		this->mWeight = weight;
	}

	Trailer::~Trailer()
	{
	}

	unsigned int Trailer::GetWeight() const
	{
		return this->mWeight;
	}
}