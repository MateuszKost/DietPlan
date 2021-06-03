#include "Interfejs.h"
#include "Pytania.h"
#include "Dania_z_pliku.h"
#include "PlanJedzeniowy.h"
#include "WyborPlanu.h"
#include "Kuchnia.h"
#include "KalkulatorKalorii.h"

void Interfejs::Dokonaj_Wyboru()
{
	string wybor;
	int Wybor = 0; 
	Pytania Zadaj;	WyborDiety Wybrana; // dla wyboru 1
	Dania_z_pliku Otworz;
	ListaDan Lista; Dania CoPotrzeba; int numer = 0;// dla wyboru 3
	Kuchnia kuchnia; ListaDan ToMozesz; // dla wyboru 2
	Kalkulator kalkulator; Dania ZPliku, ListaDoObliczen; Skladnik DlaObliczen; // dla wyboru 4

	try {
		ZPliku = kalkulator.PobierzDane("Dane.txt");
		Lista = Otworz.pobierz_z_pliku("Dania.txt"); // plik, który bêdzie u¿ywany dla 2 i 3 wyboru, w przeciwieñstwie do plików dla 1 wyboru, posiada prawdziwe dane
	}
	catch (string wyjatek)
	{
		cout << endl << wyjatek << endl; // wyrzuca nam wyjatek z odpowiednia informacja
	}

	cout << " Witaj w moim programie, postaram sie sprawic, bys trzymal sie okreslonej ilosci kalorii, jak i cieszyl sie z tego co jesz." << endl
		<< " Za chwile dostaniesz wybor, co chcesz robic dalej:" << endl;

	do {
		cout << " 1. Stworz plan jedzeniowy B)" << endl
			<< " 2. Co moge ugotowac" << endl
			<< " 3. Co potrzebuje by to zrobic" << endl
			<< " 4. Kalkulator kalorii" << endl
			<< " 5. Wyjdz z programu." << endl;

		cout << "\n Wybor: "; cin >> wybor;
		Wybor = atoi(wybor.c_str()); // zapobiega zapetlaniu sie wyboru przy wprowadzenia czegos innego niz liczba 

		switch (Wybor)
		{
		case 1:
			//cout << "\n wprowadziles: " << wybor;
			Wybrana = Zadaj.ZadajPytania();

			//Wybor strategii

			if (Wybrana.rodzaj_diety == "mieso")
			{
				rodzaj = Miesny::wybierz_miesny();
				rodzaj -> WybierzPlan(Wybrana.kalorie, Wybrana.ilosc_posilkow);
			}
			else if (Wybrana.rodzaj_diety == "wege")
			{

				rodzaj = Wege::wybierz_wege();
				rodzaj->WybierzPlan(Wybrana.kalorie, Wybrana.ilosc_posilkow);
			}
			break;
		case 2:
			kuchnia = kuchnia.DodajDoKuchni();
			if (kuchnia.Shead == nullptr)
			{
				cout << "\n Nic nie dodales !\n";
			}
			else
			{
				ToMozesz = ToMozesz.PorownajZPosiadanymi(kuchnia.Shead, Lista);
				ToMozesz.PokazListeDan();
				kuchnia.UsunListeSkladnikow();
				ToMozesz.UsunListeDan();
			}
			break;
		case 3:
			Lista.PokazListeDanTylko();
			cout << "\n Ktore danie wybierasz ? " << endl;
			cout << " Wybor: ";
			cin >> numer;
			try {
				CoPotrzeba.PokazCoPotrzeba(Lista.Dhead, numer);
			}
			catch (string wyjatek)
			{
				cout << endl << wyjatek << endl; // wyrzuca nam wyjatek z odpowiednia informacja
			}
			break;
		case 4:
			ListaDoObliczen = kalkulator.DodajDoObliczen(ZPliku.Shead);
			if (ListaDoObliczen.Shead != nullptr) {
				kalkulator.ObliczCoPodane(ListaDoObliczen.Shead);
				ListaDoObliczen.UsunListeSkladnikow();
			}
			else
				break;
			break;
		case 5:
			cout << "\n\n Dziekuje za skorzystanie z programu, mam nadzieje, ze kiedys do mnie jeszcze wrocisz" << endl;
			break;
		default:
			throw wyjatek;
		}
		cout << endl << " Automatyczny powrot do menu wyboru." << endl << endl;
	} while (Wybor != 5);
	Lista.UsunListeDan();
}