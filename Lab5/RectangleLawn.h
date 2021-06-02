#pragma once

#include "eGrassType.h"
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn(unsigned int width, unsigned int height);
		virtual ~RectangleLawn();
		unsigned int GetArea() const;
		unsigned int GetPerimeter() const;

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int width;
		unsigned int height;
	};
}