#pragma once
#include <iostream>
#include <fstream>
#include "ListaDan.h"

class Dania_z_pliku  // recipes from file
{
public:
	std::string nazwa_pliku;
	std::fstream file;

	Dania_z_pliku();
	friend std::istream& operator>>(std::istream&, Skladnik&);
	ListaDan pobierz_z_pliku(std::string);
	~Dania_z_pliku();
};