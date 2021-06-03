#include "Skladnik.h"
#include "ListaDan.h"
#include "Dania_z_pliku.h"
#include "Dania.h"
#include <string>
#include <fstream>

Dania_z_pliku::Dania_z_pliku()
{}

std::istream& operator>>(std::istream& file, Skladnik& SK)
{
	file >> SK.skladnik_nazwa >> SK.ilosc >> SK.jednostka;
	return file;
}


ListaDan Dania_z_pliku::pobierz_z_pliku(std::string nazwa_pliku)
{
	std::string nazwa_dania; double kal; int numer = 1;//do listy przepisow
	ListaDan LOR;

	file.open(nazwa_pliku);

	if (file.good() == false)
	{
		std::cout << " Plik nie istnieje !!!\n";
	}

	char x, y;

	if (file.good() == true)
	{
		file >> y;
		x = '*';

		if (y == '*')
		{
			while (file >> nazwa_dania >> kal )
			{
				if (x == '*')
				{
					file >> x;
					if (x == '-')
					{
						Skladnik Head;
						file >> Head;
						Dania REC(nazwa_dania, numer,  kal, Head);

						while ((file >> x) && (x == '-'))
						{
							Skladnik NEXT;
							file >> NEXT;
							REC.DodajSkladnik(NEXT);
						}
						LOR.DodajDoListyDan(REC);
						numer++;
					}
				}
				else
				{
					std::string wyjatek = "Blad w kodzie!!";
					throw wyjatek;
				}
			}
		}
		else
		{
			std::string wyjatek = "Blad w kodzie!!";
			throw wyjatek;
		}
	}

	file.close();
	return LOR;
}

Dania_z_pliku::~Dania_z_pliku() {}