#pragma once

#include "eGrassType.h"
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, public IFenceable
	{
	public:
		EquilateralTriangleLawn(unsigned int length);
		virtual ~EquilateralTriangleLawn();
		unsigned int GetArea() const;
		unsigned int GetPerimeter() const;

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mLength;
	};
}