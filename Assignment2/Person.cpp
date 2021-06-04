#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
	{
		this->mName = new std::string(name);
		this->mWeight = weight;
	}

	Person::~Person()
	{
		delete this->mName;
	}

	const std::string& Person::GetName() const
	{
		return *this->mName;
	}

	unsigned int Person::GetWeight() const
	{
		return this->mWeight;
	}

	Person::Person(const Person& p)
	{
		this->mName = new std::string(*p.mName);
		this->mWeight = p.mWeight;
	}
}