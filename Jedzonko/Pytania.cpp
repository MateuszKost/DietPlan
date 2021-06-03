#include "Pytania.h"

using namespace std;

WyborDiety Pytania::ZadajPytania()
{
	char plec = 0; //visual wymagal ode mnie inicjalizacji
	cout << " Za chwile zostaniesz poproszony o udzielenie kilku odpowiedzi " << endl << endl;

	int Wybor; string wybor;
	bool dobrze = false;
	cout << " Z kim mam do czynienia ?"<< endl
		<< " opcja 1: Kobieta" << endl
		<< " opcja 2: Mezczyzna" << endl;
	do {
		cout << "\n Wybor: "; cin >> wybor;
		Wybor = atoi(wybor.c_str()); // zapobiega zapetlaniu sie wyboru przy wprowadzenia czegos innego niz liczba 

		switch (Wybor)
		{
		case 1:
			cout << "\n Witam Pania !";
			plec = 'k';
			break;
		case 2:
			cout << "\n Witam Pana !";
			plec = 'm';
			break;
		default:
			cout << " Blad wprowadzenia, prosze o ponowne wprowadzenie danych!" << endl;
			break;
		}
		if ((Wybor == 1) || (Wybor == 2))
			dobrze = true;
	} while (!dobrze);

	char wiek = 0; //visual wymagal ode mnie inicjalizacji

	int Wybor2; string wybor2;
	bool dobrze2 = false;
	cout << " Ile masz lat ?" << endl
		<< " opcja 1: 18-40 !" << endl
		<< " opcja 2: wiecej niz 40 !" << endl;
	do {
		cout << "\n Wybor: "; cin >> wybor2;
		Wybor2 = atoi(wybor2.c_str()); // zapobiega zapetlaniu sie wyboru przy wprowadzenia czegos innego niz liczba 

		switch (Wybor2)
		{
		case 1:
			cout << "\n 18-40, zanotowane !";
			wiek = 'm';
			break;
		case 2:
			cout << "\n wiecej niz 40, zanotowane !";
			wiek = 's';
			break;
		default:
			cout << " Blad wprowadzenia, prosze o ponowne wprowadzenie danych!" << endl;
			break;
		}
		if ((Wybor2 == 1) || (Wybor2 == 2))
			dobrze2 = true;
	} while (!dobrze2);

	string rodzaj_diety;

	int Wybor3; string wybor3;
	bool dobrze3 = false;
	cout << " Powiedz mi kim jestes: " << endl
		<< " 1: wegetarian " << endl
		<< " 2: jesz mieso  " << endl;

	do {
		cout << "\n Wybor: "; cin >> wybor3;
		Wybor3 = atoi(wybor3.c_str()); // zapobiega zapetlaniu sie wyboru przy wprowadzenia czegos innego niz liczba 

		switch (Wybor3)
		{
		case 1:
			cout << "\n Wybrales wegetarianskie !";
			rodzaj_diety = "wege";
			break;
		case 2:
			cout << "\n Wybrales z miesem !";
			rodzaj_diety = "mieso";
			break;
		default:
			cout << " Blad wprowadzenia, prosze o ponowne wprowadzenie danych!" << endl;
			break;
		}
		if ((Wybor3 == 1) || (Wybor3 == 2)||(Wybor3 == 3))
			dobrze3 = true;
	} while (!dobrze3);

	int ilosc = 0;

	int Wybor4; string wybor4;
	bool dobrze4 = false;
	cout << " Ile zamierzasz jesc posilkow ?" << endl
		/*<< "opcja 1: 3 posilki" << endl*/
		<< " opcja 1: 4 posilki" << endl
		<< " opcja 2: 5 posilkow" << endl;

	do {
		cout << "\n Wybor: "; cin >> wybor4;
		Wybor4 = atoi(wybor4.c_str()); // zapobiega zapetlaniu sie wyboru przy wprowadzenia czegos innego niz liczba 

		switch (Wybor4)
		{
		/*case 1:
			cout << "\n Wybrales 3 posilki !";
			ilosc = 3;
			break;*/
		case 1:
			cout << "\n Wybrales 4 posilki !";
			ilosc = 4;
			break;
		case 2:
			cout << "\n Wybrales 5 posilkow !";
			ilosc = 5;
			break;
		default:
			cout << " Blad wprowadzenia, prosze o ponowne wprowadzenie danych!" << endl;
			break;
		}
		if ((Wybor4 == 1) || (Wybor4 == 2) || (Wybor4 == 3))
			dobrze4 = true;
	} while (!dobrze4);

	char tryb = 0; //visual wymagal ode mnie inicjalizacji

	int Wybor5; string wybor5;
	bool dobrze5 = false;
	cout << " Jaki masz tryb zycia ?" << endl
		<< " opcja 1: Tryb zycia siedzacy, brak aktywnosci fizycznej" << endl
		<< " opcja 2: Tryb zycia siedzacy, niewielka aktywnosc fizyczna" << endl
		<< " opcja 3: Praca fizyczna lub innego rodzaju istotny wysilek fizyczny" << endl
		<< " opcja 4: Duzy wysilek fizyczny" << endl;

	do {
		cout << "\n Wybor: "; cin >> wybor5;
		Wybor5 = atoi(wybor5.c_str()); // zapobiega zapetlaniu sie wyboru przy wprowadzenia czegos innego niz liczba 

		switch (Wybor5)
		{
		case 1:
			cout << "\n Twoje zycie odzwierciedla tryb 1 !";
			tryb = 'p';
			break;
		case 2:
			cout << "\n Twoje zycie odzwierciedla tryb 2 !";
			tryb = 'd';
			break;
		case 3:
			cout << "\n Twoje zycie odzwierciedla tryb 3 !";
			tryb = 't';
			break;
		case 4:
			cout << "\n Twoje zycie odzwierciedla tryb 4 !";
			tryb = 'c';
			break;
		default:
			cout << " Blad wprowadzenia, prosze o ponowne wprowadzenie danych!" << endl;
			break;
		}
		if ((Wybor5 == 1) || (Wybor5 == 2) || (Wybor5 == 3) || (Wybor5 == 4))
			dobrze5 = true;
	} while (!dobrze5);


	int kalorie = 0;

	if (plec == 'k')
	{
		if (wiek == 'm')
		{
			if (tryb == 'p')
			{
				kalorie = 1900;
			}
			else if (tryb == 'd')
			{
				kalorie = 2200;
			}
			else if (tryb == 't')
			{
				kalorie = 2400;
			}
			else if (tryb == 'c')
			{
				kalorie = 2600;
			}
		}
		else if (wiek == 's')
		{
			if (tryb == 'p')
			{
				kalorie = 1800;
			}
			else if (tryb == 'd')
			{
				kalorie = 2000;
			}
			else if (tryb == 't')
			{
				kalorie = 2300;
			}
			else if (tryb == 'c')
			{
				kalorie = 2400;
			}
		}
	}
	else if (plec == 'm')
	{
		if (wiek == 'm')
		{
			if (tryb == 'p')
			{
				kalorie = 2400;
			}
			else if (tryb == 'd')
			{
				kalorie = 2700;
			}
			else if (tryb == 't')
			{
				kalorie = 3080;
			}
			else if (tryb == 'c')
			{
				kalorie = 3400;
			}
		}
		else if (wiek == 's')
		{
			if (tryb == 'p')
			{
				kalorie = 2250;
			}
			else if (tryb == 'd')
			{
				kalorie = 2500;
			}
			else if (tryb == 't')
			{
				kalorie = 2900;
			}
			else if (tryb == 'c')
			{
				kalorie = 3200;
			}
		}
	}

	cout << endl << " Twoje zapotrzebowanie kaloryczne wynosi: " << kalorie << " kalorii." << endl << endl << endl;

	WyborDiety Wybrano(rodzaj_diety, ilosc, kalorie);

	//zwraca: ilosc posilkow, rodzaj diety, ilosc kalorii string rodzaj_diety, int ilosc, int kalorie

	return Wybrano;
}