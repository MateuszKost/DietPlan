#include"Skladnik.h"
#include<iomanip>

Skladnik::Skladnik() {};

Skladnik::Skladnik(std::string nazwa, int kalorie) : skladnik_nazwa(nazwa), ilosc(kalorie) {};

Skladnik::Skladnik(std::string nazwa, int il, std::string jedn)
{
	skladnik_nazwa = nazwa;
	ilosc = il;
	jednostka = jedn;
}

void Skladnik::zapisz(std::string nazwa, int il, std::string jedn)
{
	skladnik_nazwa = nazwa;
	ilosc = il;
	jednostka = jedn;
}

void Skladnik::zapisz(std::string nazwa, int il)
{
	skladnik_nazwa = nazwa;
	ilosc = il;
}

void Skladnik::pokaz_skladnik()
{
	std::cout << this->skladnik_nazwa << " " << this->ilosc << " " << this->jednostka << std::endl;
}

Skladnik::~Skladnik() {};