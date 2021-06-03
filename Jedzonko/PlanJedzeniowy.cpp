#include "PlanJedzeniowy.h"

using namespace std;

/*void Plan::StworzPlan3Daniowy(ListaDan Sniadanie, ListaDan Obiad, ListaDan Kolacja, int kalorie)
{
	Plan Plan;

	Dania* tmpS = Sniadanie.Dhead;
	Dania* tmpO = Obiad.Dhead;
	Dania* tmpK = Kolacja.Dhead;
	Dania* twojeSniadanie = nullptr, * twojObiad = nullptr, * twojaKolacja = nullptr;

	twojeSniadanie = Plan.ZwrocDanie(twojeSniadanie, tmpS, kalorie, 0.3);
	twojObiad = Plan.ZwrocDanie(twojObiad, tmpS, kalorie, 0.4);
	twojaKolacja = Plan.ZwrocDanie(twojaKolacja, tmpS, kalorie, 0.3);

	Skladnik* S, * O, * K, skladnik;

	S = twojeSniadanie->Shead;
	O = twojObiad->Shead;
	K = twojaKolacja->Shead;

	Dania Zakupy;

	Zakupy = Plan.DodajDoListyZakupow(S, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(O, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(K, Zakupy);

	Zakupy.UsunDuplikaty(Zakupy.Shead);

	cout << " O to twoj plan \"co zjesz\" dzisiaj !" << endl << endl;
	cout << " Sniadanie: " << twojeSniadanie->nazwa_dania << endl << endl;
	cout << " Obiad: " << twojObiad->nazwa_dania << endl << endl;
	cout << " Kolacja: " << twojaKolacja->nazwa_dania << endl << endl;

	cout << " A o to lista rzeczy, ktore potrzebujesz do ich wykonania:" << endl;
	Zakupy.PokazListeSkladnikow();

	Zakupy.UsunListeSkladnikow();
	delete twojeSniadanie;
	delete twojObiad;
	delete twojaKolacja;
	delete tmpS;
	delete tmpO;
	delete tmpK;
	delete S;
	delete O;
	delete K;
}*/ 

void Plan::StworzPlan4Daniowy(ListaDan Sniadanie, ListaDan DrugieSniadanie, ListaDan Obiad, ListaDan Kolacja, double kalorie)
{
	Plan Plan;

	Dania* tmpS = Sniadanie.Dhead;
	Dania* tmpS2 = DrugieSniadanie.Dhead;
	Dania* tmpO = Obiad.Dhead;
	Dania* tmpK = Kolacja.Dhead;
	Dania* twojeSniadanie = nullptr,* twojeDrugieSniadanie = nullptr, * twojObiad = nullptr, * twojaKolacja = nullptr;

	twojeSniadanie = Plan.ZwrocDanie(twojeSniadanie, tmpS, kalorie, 0.25);
	twojeDrugieSniadanie = Plan.ZwrocDanie(twojeDrugieSniadanie, tmpS2, kalorie, 0.2);
	twojObiad = Plan.ZwrocDanie(twojObiad, tmpO, kalorie, 0.3);
	twojaKolacja = Plan.ZwrocDanie(twojaKolacja, tmpK, kalorie, 0.25);

	Skladnik* S,* S2,* O, * K, skladnik;

	S = twojeSniadanie->Shead;
	S2 = twojeDrugieSniadanie->Shead;
	O = twojObiad->Shead;
	K = twojaKolacja->Shead;

	Dania Zakupy;

	Zakupy = Plan.DodajDoListyZakupow(S, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(S2, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(O, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(K, Zakupy);

	Zakupy.UsunDuplikaty(Zakupy.Shead);

	cout << " O to twoj plan \"co zjesz\" dzisiaj:" << endl << endl;
	cout << " Sniadanie: " << twojeSniadanie->nazwa_dania << endl;
	cout << " Drugie Sniadanie: " << twojeDrugieSniadanie->nazwa_dania << endl;
	cout << " Obiad: " << twojObiad->nazwa_dania << endl;
	cout << " Kolacja: " << twojaKolacja->nazwa_dania << endl << endl;

	cout << " A o to lista rzeczy, ktore potrzebujesz do ich wykonania:" << endl;
	Zakupy.PokazListeSkladnikow();

	Zakupy.UsunListeSkladnikow();
	//delete twojeSniadanie; twojeSniadanie = nullptr;
	//delete twojeDrugieSniadanie; twojeDrugieSniadanie = nullptr;
	//delete twojObiad; twojObiad = nullptr;
	//delete twojaKolacja; twojaKolacja = nullptr;
	//delete tmpS; tmpS = nullptr;
	//delete tmpS2; tmpS2 = nullptr;
	//delete tmpO; tmpO = nullptr;
	//delete tmpK; tmpK = nullptr;
	//delete S; S = nullptr;
	//delete S2; S2 = nullptr;
	//delete O; O = nullptr;
	//delete K; K = nullptr;
}

void Plan::StworzPlan5Daniowy(ListaDan Sniadanie, ListaDan DrugieSniadanie, ListaDan Obiad, ListaDan Podwieczorek, ListaDan Kolacja, double kalorie)
{
	Plan Plan;

	Dania* tmpS = Sniadanie.Dhead;
	Dania* tmpS2 = DrugieSniadanie.Dhead;
	Dania* tmpO = Obiad.Dhead;
	Dania* tmpP = Podwieczorek.Dhead;
	Dania* tmpK = Kolacja.Dhead;
	Dania* twojeSniadanie = nullptr, * twojeDrugieSniadanie = nullptr, * twojObiad = nullptr,* twojPodwieczorek = nullptr, * twojaKolacja = nullptr;

	twojeSniadanie = Plan.ZwrocDanie(twojeSniadanie, tmpS, kalorie, 0.2);
	twojeDrugieSniadanie = Plan.ZwrocDanie(twojeDrugieSniadanie, tmpS2, kalorie, 0.2);
	twojObiad = Plan.ZwrocDanie(twojObiad, tmpO, kalorie, 0.25);
	twojPodwieczorek = Plan.ZwrocDanie(twojPodwieczorek, tmpP, kalorie, 0.15);
	twojaKolacja = Plan.ZwrocDanie(twojaKolacja, tmpK, kalorie, 0.2);

	Skladnik* S, * S2, * O,* P, * K, skladnik;

	S = twojeSniadanie->Shead;
	S2 = twojeDrugieSniadanie->Shead;
	O = twojObiad->Shead;
	P = twojPodwieczorek->Shead;
	K = twojaKolacja->Shead;

	Dania Zakupy;

	Zakupy = Plan.DodajDoListyZakupow(S, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(S2, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(O, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(P, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(K, Zakupy);

	Zakupy.UsunDuplikaty(Zakupy.Shead);

	cout << " O to twoj plan \"co zjesz\" dzisiaj:" << endl << endl;
	cout << " Sniadanie: " << twojeSniadanie->nazwa_dania << endl;
	cout << " Drugie Sniadanie: " << twojeDrugieSniadanie->nazwa_dania << endl;
	cout << " Obiad: " << twojObiad->nazwa_dania << endl;
	cout << " Podwieczorek: " << twojPodwieczorek->nazwa_dania << endl;
	cout << " Kolacja: " << twojaKolacja->nazwa_dania << endl << endl;

	cout << " A o to lista rzeczy, ktore potrzebujesz do ich wykonania:" << endl;
	Zakupy.PokazListeSkladnikow();

	Zakupy.UsunListeSkladnikow();
	/*delete twojeSniadanie;
	delete twojeDrugieSniadanie;
	delete twojObiad;
	delete twojPodwieczorek;
	delete twojaKolacja;
	delete tmpS;
	delete tmpS2;
	delete tmpO;
	delete tmpP;
	delete tmpK;
	delete S;
	delete S2;
	delete O;
	delete P;
	delete K;*/
}

Dania Plan::DodajDoListyZakupow(Skladnik* head, Dania ListaZakupow)
{
	int ilosc = 0;
	Skladnik skladnik;
	string jednostka;
	string nazwaSkladnika;
	Skladnik* S = head;
	while (S)
	{
		ilosc = S->ilosc;
		jednostka = S->jednostka;
		nazwaSkladnika = S->skladnik_nazwa;

		skladnik.zapisz(nazwaSkladnika, ilosc, jednostka);
		ListaZakupow.DodajSkladnik(skladnik);

		S = S->Next;
	}
	return ListaZakupow;
}

Dania* Plan::ZwrocDanie(Dania* zwracane, Dania* head, double kalorie, double mnoznik)
{
	Dania* tmp = head;
	while (tmp)
	{
		if ((tmp->kalorie == (kalorie * mnoznik))) /*&& (tmp->kalorie > ((kalorie * mnoznik) - 50)))*/ // zmienione <= dla celu danych przykladowych
		{
			zwracane = tmp;
			break;
		}
		else
			tmp = tmp->next;
	}
	return zwracane;
}

//smartpointery nie dzilajao

/*#include "PlanJedzeniowy.h"
#include <memory>

using namespace std;

shared_ptr <Dania> tmpS;
shared_ptr <Dania> tmpS2;
shared_ptr <Dania> tmpO;
shared_ptr <Dania> tmpP;
shared_ptr <Dania> tmpK;

shared_ptr <Dania> twojeSniadanie;
shared_ptr <Dania> twojeDrugieSniadanie;
shared_ptr <Dania> twojObiad;
shared_ptr <Dania> twojPodwieczorek;
shared_ptr <Dania> twojaKolacja;

shared_ptr <Skladnik> S;
shared_ptr <Skladnik> S2;
shared_ptr <Skladnik> P;
shared_ptr <Skladnik> O;
shared_ptr <Skladnik> K;


void Plan::StworzPlan3Daniowy(ListaDan Sniadanie, ListaDan Obiad, ListaDan Kolacja, int kalorie)
{
	Plan Plan;

	tmpS = make_shared<Dania>(Sniadanie.Dhead);
	tmpO = make_shared<Dania>(Obiad.Dhead);
	tmpK = make_shared<Dania>(Kolacja.Dhead);

	twojeSniadanie = Plan.ZwrocDanie(twojeSniadanie, tmpS, kalorie, 0.3);
	twojObiad = Plan.ZwrocDanie(twojObiad, tmpS, kalorie, 0.4);
	twojaKolacja = Plan.ZwrocDanie(twojaKolacja, tmpS, kalorie, 0.3);

	S = make_shared<Skladnik>(twojeSniadanie->Shead);
	O = make_shared<Skladnik>(twojObiad->Shead);
	K = make_shared<Skladnik>(twojaKolacja->Shead);

	Dania Zakupy;

	Zakupy = Plan.DodajDoListyZakupow(S, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(O, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(K, Zakupy);

	Zakupy.UsunDuplikaty(Zakupy.Shead);

	cout << " O to twoj plan \"co zjesz\" dzisiaj !" << endl << endl;
	cout << " Sniadanie: " << twojeSniadanie->nazwa_dania << endl << endl;
	cout << " Obiad: " << twojObiad->nazwa_dania << endl << endl;
	cout << " Kolacja: " << twojaKolacja->nazwa_dania << endl << endl;

	cout << " A o to lista rzeczy, ktore potrzebujesz do ich wykonania:" << endl;
	Zakupy.PokazListeSkladnikow();

	Zakupy.UsunListeSkladnikow();
}

void Plan::StworzPlan4Daniowy(ListaDan Sniadanie, ListaDan DrugieSniadanie, ListaDan Obiad, ListaDan Kolacja, int kalorie)
{
	Plan Plan;

	tmpS = make_shared<Dania>(Sniadanie.Dhead);
	tmpS2 = make_shared<Dania>(DrugieSniadanie.Dhead);
	tmpO = make_shared<Dania>(Obiad.Dhead);
	tmpK = make_shared<Dania>(Kolacja.Dhead);

	twojeSniadanie = Plan.ZwrocDanie(twojeSniadanie, tmpS, kalorie, 0.2);
	twojeDrugieSniadanie = Plan.ZwrocDanie(twojeDrugieSniadanie, tmpS, kalorie, 0.2);
	twojObiad = Plan.ZwrocDanie(twojObiad, tmpS, kalorie, 0.4);
	twojaKolacja = Plan.ZwrocDanie(twojaKolacja, tmpS, kalorie, 0.2);

	S = make_shared<Skladnik>(twojeSniadanie->Shead);
	S2 = make_shared<Skladnik>(twojeDrugieSniadanie->Shead);
	O = make_shared<Skladnik>(twojObiad->Shead);
	K = make_shared<Skladnik>(twojaKolacja->Shead);

	Dania Zakupy;

	Zakupy = Plan.DodajDoListyZakupow(S, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(S2, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(O, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(K, Zakupy);

	Zakupy.UsunDuplikaty(Zakupy.Shead);

	cout << " O to twoj plan \"co zjesz\" dzisiaj !" << endl << endl;
	cout << " Sniadanie: " << twojeSniadanie->nazwa_dania << endl << endl;
	cout << " Drugie Sniadanie: " << twojeDrugieSniadanie->nazwa_dania << endl << endl;
	cout << " Obiad: " << twojObiad->nazwa_dania << endl << endl;
	cout << " Kolacja: " << twojaKolacja->nazwa_dania << endl << endl;

	cout << " A o to lista rzeczy, ktore potrzebujesz do ich wykonania:" << endl;
	Zakupy.PokazListeSkladnikow();

	Zakupy.UsunListeSkladnikow();
}

void Plan::StworzPlan5Daniowy(ListaDan Sniadanie, ListaDan DrugieSniadanie, ListaDan Obiad, ListaDan Podwieczorek, ListaDan Kolacja, int kalorie)
{
	Plan Plan;

	tmpS = make_shared<Dania>(Sniadanie.Dhead);
	tmpS2 = make_shared<Dania>(DrugieSniadanie.Dhead);
	tmpO = make_shared<Dania>(Obiad.Dhead);
	tmpP = make_shared<Dania>(Podwieczorek.Dhead);
	tmpK = make_shared<Dania>(Kolacja.Dhead);

	twojeSniadanie = Plan.ZwrocDanie(twojeSniadanie, tmpS, kalorie, 0.2);
	twojeDrugieSniadanie = Plan.ZwrocDanie(twojeDrugieSniadanie, tmpS, kalorie, 0.2);
	twojObiad = Plan.ZwrocDanie(twojObiad, tmpS, kalorie, 0.2);
	twojPodwieczorek = Plan.ZwrocDanie(twojPodwieczorek, tmpS, kalorie, 0.2);
	twojaKolacja = Plan.ZwrocDanie(twojaKolacja, tmpS, kalorie, 0.2);

	S = make_shared<Skladnik>(twojeSniadanie->Shead);
	S2 = make_shared<Skladnik>(twojeDrugieSniadanie->Shead);
	O = make_shared<Skladnik>(twojObiad->Shead);
	P = make_shared<Skladnik>(twojPodwieczorek->Shead);
	K = make_shared<Skladnik>(twojaKolacja->Shead);

	Dania Zakupy;

	Zakupy = Plan.DodajDoListyZakupow(S, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(S2, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(O, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(P, Zakupy);
	Zakupy = Plan.DodajDoListyZakupow(K, Zakupy);

	Zakupy.UsunDuplikaty(Zakupy.Shead);

	cout << " O to twoj plan \"co zjesz\" dzisiaj !" << endl << endl;
	cout << " Sniadanie: " << twojeSniadanie->nazwa_dania << endl << endl;
	cout << " Drugie Sniadanie: " << twojeDrugieSniadanie->nazwa_dania << endl << endl;
	cout << " Obiad: " << twojObiad->nazwa_dania << endl << endl;
	cout << " Podwieczorek: " << twojPodwieczorek->nazwa_dania << endl << endl;
	cout << " Kolacja: " << twojaKolacja->nazwa_dania << endl << endl;

	cout << " A o to lista rzeczy, ktore potrzebujesz do ich wykonania:" << endl;
	Zakupy.PokazListeSkladnikow();

	Zakupy.UsunListeSkladnikow();
}

Dania Plan::DodajDoListyZakupow(shared_ptr<Skladnik> head, Dania ListaZakupow)
{
	int ilosc = 0;
	Skladnik skladnik;
	string jednostka;
	string nazwaSkladnika;
	shared_ptr <Skladnik> S = head;
	while (S)
	{
		ilosc = S->ilosc;
		jednostka = S->jednostka;
		nazwaSkladnika = S->skladnik_nazwa;

		skladnik.zapisz(nazwaSkladnika, ilosc, jednostka);
		ListaZakupow.DodajSkladnik(skladnik);

		S = make_shared<Skladnik>(S->Next);
	}
	return ListaZakupow;
}

shared_ptr<Dania> Plan::ZwrocDanie(shared_ptr<Dania> zwracane, shared_ptr <Dania> head, int kalorie, double mnoznik)
{
	shared_ptr<Dania> tmp = head;
	while (tmp)
	{
		if ((tmp->kalorie <= (kalorie * mnoznik)) && (tmp->kalorie > ((kalorie * mnoznik) - 50)))
		{
			zwracane = tmp;
			break;
		}
		else
			tmp = make_shared<Dania>(tmp->next);
	}
	return zwracane;
}*/ 