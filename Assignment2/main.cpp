#include <iostream>
#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

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
	s->RemoveTrailer();

	Sedan* s2 = new Sedan(*s);

	Airplane* a = new Airplane(20);
	Airplane* a2 = new Airplane(30);

	a->AddPassenger(new Person("a", 1));
	a->AddPassenger(new Person("a", 2));
	a->AddPassenger(new Person("a", 3));
	a->AddPassenger(new Person("a", 4));
	a->AddPassenger(new Person("a", 5));

	*a2 = *a;
	Airplane* a3 = new Airplane(*a);

	Boat* b = new Boat(10);

	b->AddPassenger(new Person("b", 1));
	b->AddPassenger(new Person("b", 2));
	b->AddPassenger(new Person("b", 3));
	b->AddPassenger(new Person("b", 4));

	Boatplane* c = new Boatplane(100);

	for(int i = 0; i < 100; i++)
	{
		c->AddPassenger(new Person("c", 1));
	}

	for (int i = 0; i < 150; i++)
	{
		c->RemovePassenger(0);
	}

	*c = *a + *b;

	Motorcycle* m = new Motorcycle();
	m->AddPassenger(new Person("d", 1));
	m->AddPassenger(new Person("d", 2));
	m->RemovePassenger(1);
	m->RemovePassenger(0);
	m->RemovePassenger(0);

	UBoat* u = new UBoat();
	u->AddPassenger(new Person("e", 1));
	u->AddPassenger(new Person("e", 2));
	u->AddPassenger(new Person("e", 3));


	

	delete a;
	delete b;
	delete c;
	delete m;
	delete s;
	delete u;
	delete a2;
	delete a3;
	delete s2;


	std::cout << "Done" << std::endl;

	_CrtDumpMemoryLeaks();
}


