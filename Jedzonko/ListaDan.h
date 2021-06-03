#pragma once
#include "Dania.h"

class ListaDan // list of recipes
{
public:
	Dania* Dhead = nullptr;

	ListaDan();
	void DodajDoListyDan(Dania);
	void PokazListeDan();
	void PokazListeDanTylko();
	void UsunListeDan();
	ListaDan PorownajZPosiadanymi(Skladnik* head, ListaDan list);

	~ListaDan();
};