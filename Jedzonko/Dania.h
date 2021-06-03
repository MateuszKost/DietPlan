#pragma once
#include <iostream>
#include "Skladnik.h"

class Dania 
{
public:
	std::string nazwa_dania;
	int numer_dania = 0;
	double kalorie = 0;
	Skladnik* Shead = nullptr;


	Dania(std::string, int, double, Skladnik);
	Dania() {};
	void DodajSkladnik(Skladnik);
	void UsunListeSkladnikow();
	void PokazDanie();
	void PokazListeSkladnikow();
	void PokazCoPotrzeba(Dania *head, int numer);
	void UsunDuplikaty(Skladnik* head);
	void Sortuj(Skladnik* head);
	Skladnik* SzukajSzukanego(Skladnik* head, std::string);
	~Dania();
	Dania* next = nullptr;
};
