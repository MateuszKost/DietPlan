#pragma once
#include "Skladnik.h"
#include "Dania.h"

class Kuchnia : public Skladnik, public Dania
{
public:
	Kuchnia() {};
	Kuchnia DodajDoKuchni();
	~Kuchnia() {};
};