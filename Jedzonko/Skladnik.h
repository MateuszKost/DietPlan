#pragma once
#include<iostream>
class Skladnik
{
public:
	std::string skladnik_nazwa;
	int ilosc = 0;
	std::string jednostka;

	Skladnik();
	Skladnik(std::string, int);
	Skladnik(std::string, int, std::string);
	void zapisz(std::string, int, std::string); 
	void zapisz(std::string, int);
	void pokaz_skladnik();
	Skladnik* Next = nullptr;
	~Skladnik();
};