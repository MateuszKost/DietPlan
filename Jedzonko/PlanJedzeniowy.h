#pragma once
#include "ListaDan.h"

class Plan
{
public:
	//void StworzPlan3Daniowy(ListaDan, ListaDan, ListaDan, int); //moim zdaniem bez sensu jest jedzenie tylko 3 posilkow, przy poprawnym rozplanowaniu, aczkolwiek nie usuwam tylko zakomentowuje
	void StworzPlan4Daniowy(ListaDan, ListaDan, ListaDan, ListaDan, double);
	void StworzPlan5Daniowy(ListaDan, ListaDan, ListaDan, ListaDan, ListaDan, double);
	Dania DodajDoListyZakupow(Skladnik* head, Dania ListaZakupow);
	Dania* ZwrocDanie(Dania* zwracane, Dania* head, double kalorie, double mnoznik);
};