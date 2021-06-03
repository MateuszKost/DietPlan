#include "Skladnik.h"
#include "Dania.h"
#include<iomanip>

Dania::Dania(std::string nazwa, int numer, double cal, Skladnik SK)
{
	numer_dania = numer;
	nazwa_dania = nazwa;
	kalorie = cal;
	Shead = new Skladnik(SK);
}

void Dania::DodajSkladnik(Skladnik SK)
{
	if (this->Shead == nullptr)
	{
		Shead = new Skladnik(SK);
		Shead->Next = nullptr;
	}
	else
	{
		Skladnik* another = new Skladnik(SK);
		Skladnik* tmp = Shead;
		while (tmp->Next != nullptr)
		{
			tmp = tmp->Next;
		}
		tmp->Next = another;
		another->Next = nullptr;
	}
}

void Dania::PokazDanie()
{
	std::cout << "\n Nr." << this->numer_dania << " Nazwa: " << this->nazwa_dania << " kalorie: " << this->kalorie << std::endl;
	std::cout << "\nSkladniki:" << std::endl;
	if (this->Shead)
	{
		int nr = 1;
		Skladnik* SK = Shead;
		while (SK)
		{
			std::cout << " " << nr << ". ";
			SK->pokaz_skladnik();
			nr++;
			SK = SK->Next;
		}
	}
}

void Dania::UsunListeSkladnikow()
{
	Skladnik* x;
	while (Shead)
	{
		x = Shead->Next;
		delete Shead;
		Shead = x;
	}
	Shead = NULL;
}

void Dania::PokazListeSkladnikow()
{
	if (this->Shead)
	{
		int nr = 1;
		Skladnik* S = Shead;
		while (S)
		{
			std::cout << " " << nr << ". ";
			S->pokaz_skladnik();
			nr++;
			S = S->Next;
		}
	}
}

void Dania::PokazCoPotrzeba(Dania* head, int numer)
{
	Dania* tmp = nullptr;
	tmp = head;
	std::string wyjatek = " NIE ZNALEZIONO TAKIEGO NUMERU !";

	while (tmp)
	{
		if (tmp->numer_dania == numer)
		{
			std::cout << "\n Wybrales: " << tmp->nazwa_dania << std::endl;
			std::cout << " Ponizsza lista prezentuje to co potrzebujesz do przygotowania tego dania: " << std::endl;
			tmp->PokazListeSkladnikow();
			break;
		}
		if (tmp->next == nullptr)
		{
			throw wyjatek;
		}
		tmp = tmp->next;
	}
}

void Dania::UsunDuplikaty(Skladnik* head)
{
	Skladnik* S2, * S, * tmp;
	S = head;
	while (S)
	{
		S2 = S;
		while (S2->Next)
			if (S2->Next->skladnik_nazwa == S->skladnik_nazwa)
			{
				S->ilosc = S->ilosc + S2->Next->ilosc;
				tmp = S2->Next;
				S2->Next = tmp->Next;
				delete tmp;
			}
			else S2 = S2->Next;
		S = S->Next;
	}
}

void Dania::Sortuj(Skladnik* head) 
{
	Skladnik* temp = NULL;
	Skladnik* help = NULL;

	for (temp = head; temp != NULL; temp = temp->Next)
		for (help = temp; help != NULL; help = help->Next)
			if (help->skladnik_nazwa > temp->skladnik_nazwa) {
				std::string nazwa = help->skladnik_nazwa;
				int kalorie = help->ilosc;
				help->skladnik_nazwa = temp->skladnik_nazwa;
				help->ilosc = temp->ilosc;
				temp->skladnik_nazwa = nazwa;
				temp->ilosc = kalorie;
			}
}

Skladnik* Dania::SzukajSzukanego(Skladnik* head, std::string poszukiwania)
{
	Skladnik* tmp = head;
	Skladnik* DoZwrocenia = nullptr;

	while (tmp)
	{
		if (poszukiwania == tmp->skladnik_nazwa)
		{
			DoZwrocenia = tmp;
			break;
		}
		tmp = tmp->Next;
	}
	return DoZwrocenia;
}

Dania::~Dania() {
	//std::cout << "\n\n jestem XDDD\n\n";
}
