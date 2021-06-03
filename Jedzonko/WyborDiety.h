#pragma once
#include <iostream>

class WyborDiety
{
public:

	std::string rodzaj_diety;
	int kalorie = 0;
	int ilosc_posilkow = 0;
	WyborDiety() {};
	WyborDiety(std::string, int, int);
	~WyborDiety();
};