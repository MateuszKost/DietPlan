#include "WyborPlanu.h"
#include "Dania_z_pliku.h"
#include "PlanJedzeniowy.h"

void Miesny::WybierzPlan(int kalorie, int ilosc_dan)
{
	Dania_z_pliku Otworz;
	ListaDan Sniadanie, DrugieSniadanie, Obiad, Podwieczorek, Kolacja;

	Sniadanie = Otworz.pobierz_z_pliku("sniadania.txt");
	DrugieSniadanie = Otworz.pobierz_z_pliku("drugiesniadania.txt");
	Obiad = Otworz.pobierz_z_pliku("obiady.txt");
	Podwieczorek = Otworz.pobierz_z_pliku("podwieczorki.txt");
	Kolacja = Otworz.pobierz_z_pliku("kolacje.txt");

	Plan P;
	if (ilosc_dan == 4)
	{
		P.StworzPlan4Daniowy(Sniadanie, DrugieSniadanie, Obiad, Kolacja, kalorie);
	}
	else if (ilosc_dan == 5)
	{
		P.StworzPlan5Daniowy(Sniadanie, DrugieSniadanie, Obiad, Podwieczorek, Kolacja, kalorie);
	}

	Sniadanie.UsunListeDan();
	DrugieSniadanie.UsunListeDan(); 
	Obiad.UsunListeDan();
	Podwieczorek.UsunListeDan();
	Kolacja.UsunListeDan();
}

std::shared_ptr<WyborPlanu> Miesny::wybierz_miesny()
{
	std::shared_ptr<WyborPlanu> temp = std::make_shared<Miesny>();
	return temp;
}

void Wege::WybierzPlan(int kalorie, int ilosc_dan)
{
	Dania_z_pliku Otworz;
	Plan P;
	ListaDan WegeSniadanie, WegeDrugieSniadanie, WegeObiad, WegePodwieczorek, WegeKolacja;

	WegeSniadanie = Otworz.pobierz_z_pliku("wegesniadania.txt");
	WegeDrugieSniadanie = Otworz.pobierz_z_pliku("wegedrugiesniadania.txt");
	WegeObiad = Otworz.pobierz_z_pliku("wegeobiady.txt");
	WegePodwieczorek = Otworz.pobierz_z_pliku("wegepodwieczorki.txt");
	WegeKolacja = Otworz.pobierz_z_pliku("wegekolacje.txt");
	if (ilosc_dan == 4)
	{
		P.StworzPlan4Daniowy(WegeSniadanie, WegeDrugieSniadanie, WegeObiad, WegeKolacja, kalorie);
	}
	else if (ilosc_dan == 5)
	{
		P.StworzPlan5Daniowy(WegeSniadanie, WegeDrugieSniadanie, WegeObiad, WegePodwieczorek, WegeKolacja, kalorie);
	}
	WegeSniadanie.UsunListeDan();
	WegeDrugieSniadanie.UsunListeDan();
	WegeObiad.UsunListeDan();
	WegePodwieczorek.UsunListeDan();
	WegeKolacja.UsunListeDan();
}

std::shared_ptr<WyborPlanu>Wege::wybierz_wege()
{
	std::shared_ptr<WyborPlanu> temp = std::make_shared<Wege>();
	return temp;
}