#include <cassert>
#include <iostream>
#include <iomanip>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "UBoat.h"
#include "Trailer.h"
#include "DeusExMachina.h"
#include "Person.h"


#define STR(name) #name

using namespace assignment2;
using namespace std;

int main()
{
	Sedan* s = new Sedan();

	s->AddPassenger(new Person("t", 1));
	s->AddPassenger(new Person("t", 2));
	s->AddPassenger(new Person("t", 3));
	s->AddPassenger(new Person("t", 4));

	s->AddTrailer(new Trailer(40));
	delete s;

	Airplane* a = new Airplane(20);

	a->AddPassenger(new Person("a", 1));
	a->AddPassenger(new Person("a", 2));
	a->AddPassenger(new Person("a", 3));
	a->AddPassenger(new Person("a", 4));
	a->AddPassenger(new Person("a", 5));

	Boat* b = new Boat(10);

	b->AddPassenger(new Person("b", 1));
	b->AddPassenger(new Person("b", 2));
	b->AddPassenger(new Person("b", 3));
	b->AddPassenger(new Person("b", 4));

	Boatplane* c = new Boatplane(50);
	c->AddPassenger(new Person("c", 1));
	c->AddPassenger(new Person("c", 2));
	c->AddPassenger(new Person("c", 3));
	c->AddPassenger(new Person("c", 4));

	*c = *a + *b;

	delete a;
	delete b;
	delete c;


	std::cout << "Done" << std::endl;
}