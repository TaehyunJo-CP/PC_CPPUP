#pragma once

#include "eGrassType.h"

namespace lab5
{
	class Lawn
	{

	public:
		Lawn();
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

	protected:
		static const double ROLL_GRASS_AREA;
		static const double PI;
		static const double FENCE_WIDTH;

	};
}
