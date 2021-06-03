#pragma once
#include <fstream>
#include "Dania.h"
#include "Skladnik.h"

class Kalkulator 
{
	std::fstream plik;

public:
	Kalkulator();
	Dania PobierzDane(std::string);
	Skladnik ZwrocWyszukane(Skladnik*);
	void ObliczCoPodane(Skladnik*);
	Dania DodajDoObliczen(Skladnik*);

	~Kalkulator();
};