#include"KalkulatorKalorii.h"
#include <vector>
#include <algorithm>

using namespace std;

Kalkulator::Kalkulator() {};

Dania Kalkulator::PobierzDane(string nazwa_pliku)
{
	plik.open(nazwa_pliku);

	if (plik.good() == false)
	{
		std::cout << " Plik nie istnieje !!!\n";
	}

	char x;
	Dania Dane;
	string nazwa; int kalorie = 0;

	if (plik.good() == true)
	{
		
		while (plik >> x)
		{
			if (x == '-')
			{
				Skladnik skladnik;
				plik >> nazwa >> kalorie;
				skladnik.zapisz(nazwa, kalorie);
				Dane.DodajSkladnik(skladnik);
			}
			else
			{
				std::string wyjatek = "Blad w kodzie!!";
				throw wyjatek;
			}
		}
	}

	plik.close();
	return Dane;
}

Skladnik Kalkulator::ZwrocWyszukane(Skladnik* head)
{
	Skladnik* tmp = head;
	vector<string> DlaPoszukiwan;
	Skladnik* Znaleziona;
	Dania DoPoszukiwan;

	string wyjatek = " Blad !";

	string wprowadzenie;
	cout << " Wprowadz jakiego produktu poszukujesz, aby znalezc jego kalorie" << endl;
	cout << " Chodizlo mi o: ";
	cin >> wprowadzenie;
	int dlugosc_wyrazu = wprowadzenie.length();
	int polowa = dlugosc_wyrazu / 2;

	while (tmp)
	{
		for (int i = 0; i < polowa; i++)
		{
			if (tmp->skladnik_nazwa[i] == wprowadzenie[i])
			{
				if (i == (polowa - 1))
				{
					back_inserter(DlaPoszukiwan) = tmp->skladnik_nazwa;
				}
			}
			else
			{
				break;
			}
		}
		tmp = tmp->Next;
	}

	if (DlaPoszukiwan.size() == 0)
		throw wyjatek;

	cout << " Znalazlem kilka danych, ktore moga odpowiadac danej wprowadzonej przez Ciebie, ktora z nich jest ta, o ktora Ci chodzilo ?" << endl;
	int wielkosc = DlaPoszukiwan.size();

	for (int i = 0; i < wielkosc; i++)
	{
		cout << " " << i+1 << ". " << DlaPoszukiwan[i] << endl;
	}

	cout << " Chodzilo mi o: ";
	string Numer; cin >> Numer;
	int numer = atoi(Numer.c_str());
	if ((numer > wielkosc)||(numer == 0))
		throw wyjatek;

	numer = numer - 1;

	string znaleziona = DlaPoszukiwan[numer];

	Znaleziona = DoPoszukiwan.SzukajSzukanego(head, znaleziona);

	int kal = 0; string nazwa_poszukiwanego;
	kal = Znaleziona->ilosc; 
	nazwa_poszukiwanego = Znaleziona->skladnik_nazwa;

	Skladnik TegoSzukalem(nazwa_poszukiwanego, kal);

	return TegoSzukalem;
}

void Kalkulator::ObliczCoPodane(Skladnik* head)
{
	Skladnik* tmp = head;
	Skladnik* tmp2 = head;
	int i = 1;
	cout << " O to lista produktow, dla ktorych chcesz policzyc sume kalorii: " << endl;
	
	while (tmp)
	{
		cout << " nr." << i << " Nazwa: " << tmp->skladnik_nazwa << endl;
		i++;
		tmp = tmp->Next;
	}

	int suma = 0;

	while (tmp2)
	{
		suma = suma + tmp2->ilosc;
		tmp2 = tmp2->Next;
	}

	cout << "\n A o to suma kalorii dla tych produktow: " << suma;
}

Dania Kalkulator::DodajDoObliczen(Skladnik* head)
{
	string wybor;
	int Wybor;
	bool dobrze = false;
	Dania Dane;
	Skladnik Dodaj;
	Kalkulator K;

	std::cout << " Co chcesz zrobic ?" << std::endl;
	do {
		std::cout << " opcja 1: Dodaj do obliczen." << std::endl
			<< " opcja 2: Skoncz dodawanie." << std::endl;

		std::cout << "\n Wybor: "; std::cin >> wybor;
		Wybor = atoi(wybor.c_str()); // zapobiega zapetlaniu sie wyboru przy wprowadzenia czegos innego niz liczba 

		switch(Wybor)
		{
		case 1:
			try {
				Dodaj = K.ZwrocWyszukane(head);
			}
			catch (string wyjatek)
			{
				cout << endl << wyjatek << endl << endl; // wyrzuca nam wyjatek z odpowiednia informacja
				break;
			}
			Dane.DodajSkladnik(Dodaj);
			break;
		case 2:
			break;
		default:
			std::cout << " Blad wprowadzenia, prosze o ponowne wprowadzenie danych!" << std::endl;
			break;
		}
		if (Wybor == 2)
			dobrze = true;
	} while (!dobrze);

	return Dane;
}

Kalkulator::~Kalkulator() {};