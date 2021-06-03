#include "Kuchnia.h"

Kuchnia Kuchnia::DodajDoKuchni()
{
	int Wybor; std::string wybor;
	bool dobrze = false;
	Kuchnia kuchnia;
	Skladnik skladnik;

	std::cout << " Co chcesz zrobic ?" << std::endl;
	do {
	std::cout << " opcja 1: Dodaj skladnik." << std::endl
		<< " opcja 2: Skoncz dodawanie." << std::endl;

		std::cout << "\n Wybor: "; std::cin >> wybor;
		Wybor = atoi(wybor.c_str()); // zapobiega zapetlaniu sie wyboru przy wprowadzenia czegos innego niz liczba 

		switch (Wybor)
		{
		case 1:
			std::cout << "\n Prosze o podanie 3 informacji\n 1. Nazwa: ";
			std::cin >> skladnik_nazwa;
			std::cout << " 2. Ilosc: ";
			std::cin >> ilosc;
			std::cout << " 3. Jednostka (gramy(g), mililitry(ml), sztuki(szt)): ";
			std::cin >> jednostka;

			skladnik.zapisz(skladnik_nazwa, ilosc, jednostka);
			kuchnia.DodajSkladnik(skladnik);

			std::cout << std::endl << std::endl;

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

	//kuchnia.PokazListeSkladnikow();

	return kuchnia;
}