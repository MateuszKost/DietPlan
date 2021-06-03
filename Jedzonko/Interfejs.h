#pragma once
#include <iostream>
#include "WyborPlanu.h"

using namespace std;

class Interfejs
{
	string wyjatek = " BLAD ! NIE MA TAKIEJ OPCJI, BADZ WPROWADZILES COS INNEGO NIZ LICZBE !";

public:
	//zmienna odpowiedzialna za dzia³anie metod
	shared_ptr<WyborPlanu> rodzaj;

	void Dokonaj_Wyboru(); // uzytkownik wybiera opcje
}; 
