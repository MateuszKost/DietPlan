#include "ListaDan.h"
#include "Dania.h"

ListaDan::ListaDan()
{
	Dhead = nullptr;
}

void ListaDan::DodajDoListyDan(Dania Danie)
{
	if (Dhead == nullptr)
	{
		Dhead = new Dania(Danie);
		Dhead->next = nullptr;
	}
	else
	{
		Dania* another = new Dania(Danie);
		Dania* tmp = Dhead;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = another;
		another->next = nullptr;
	}
}

void ListaDan::PokazListeDan()
{
	if (this->Dhead)
	{
		Dania* R = Dhead;
		while (R)
		{
			R->PokazDanie();
			std::cout << std::endl;
			R = R->next;
		}
	}
	else
	{
		std::cout << " Niestety zaden przepis nie zostal dodany !" << std::endl;
	}
}

void ListaDan::PokazListeDanTylko()
{
	if (this->Dhead)
	{
		Dania* R = Dhead;
		while (R)
		{
			std::cout << "\n Nr." << R->numer_dania << " Nazwa: " << R->nazwa_dania << " kalorie: " << R->kalorie << std::endl;
			R = R->next;
		}
	}
	else
	{
		std::cout << " Niestety zaden przepis nie zostal dodany !" << std::endl;
	}
}

void ListaDan::UsunListeDan()
{
	Dania* x;
	while (Dhead)
	{
		x = Dhead->next;
		Dhead->UsunListeSkladnikow();
		delete Dhead;
		Dhead = x;
	}
	Dhead = NULL;
}

/*ListaDan ListaDan::PorownajZPosiadanymi(Skladnik* head, ListaDan list)
{
	bool did = false;
	Dania* TMP = list.Dhead;
	Dania recipe;
	ListaDan listofF;
	Skladnik* Ftmp = head;

	while (TMP)
	{
		recipe = *TMP;
		Skladnik* tmpING = TMP->Shead;
		while (TMP->Shead)
		{
			if ((tmpING->skladnik_nazwa == head->skladnik_nazwa) && (tmpING->ilosc <= head->ilosc) && (tmpING != nullptr))
			{
				did = true;
				if ((!tmpING->Next) && (did == true))
				{
					listofF.DodajDoListyDan(recipe);
					goto end;
				}
				if (tmpING->Next)
				{
					tmpING = tmpING->Next;
				}//przechodzimy na nastepny skladnik przepisu
				if (head->Next)
				{
					head = head->Next;
				}
				else
				{
					head = Ftmp;
				}
			}
			else
			{
				head = head->Next;
			}
			if ((!head) && (did == true))
			{
				did = false;
				head = Ftmp;
			}
			else if ((!head) && (did == false))
			{
				head = Ftmp;
				goto end;
			}
		}
	end:
		TMP = TMP->next;
	}
	return listofF;
}*/

ListaDan ListaDan::PorownajZPosiadanymi(Skladnik* head, ListaDan list)
{
	bool did = false;
	Dania* TMP = list.Dhead;
	ListaDan listofF;
	Skladnik* Ftmp = head;
	int numer = 0; double kalorie = 0; std::string nazwa;  // do dania
	std::string nazwa_skladnika; int ilosc = 0; std::string jednostka;

	while (TMP)
	{
		Skladnik* tmpING = TMP->Shead;
		while (TMP->Shead)
		{
			if ((tmpING->skladnik_nazwa == Ftmp->skladnik_nazwa) && (tmpING->ilosc <= Ftmp->ilosc) && (tmpING != nullptr))
			{
				did = true;
				if ((!tmpING->Next) && (did == true))
				{
					kalorie = TMP->kalorie;
					numer = TMP->numer_dania;
					nazwa = TMP->nazwa_dania;

					Skladnik *kopia = TMP->Shead;

					nazwa_skladnika = kopia->skladnik_nazwa;
					ilosc = kopia->ilosc;
					jednostka = kopia->jednostka;

					Skladnik glowa(nazwa_skladnika, ilosc, jednostka);
					Dania recipe(nazwa, numer, kalorie, glowa);

					listofF.DodajDoListyDan(recipe);
					
					kopia = kopia->Next;

					while (kopia)
					{
						nazwa_skladnika = kopia->skladnik_nazwa;
						ilosc = kopia->ilosc;
						jednostka = kopia->jednostka;

						Skladnik nast;
						nast.zapisz(nazwa_skladnika, ilosc, jednostka);
						recipe.DodajSkladnik(nast);
						kopia = kopia->Next;
					}
					goto end;
				}
				if (tmpING->Next)
				{
					tmpING = tmpING->Next;
				}//przechodzimy na nastepny skladnik przepisu
				if (Ftmp->Next)
				{
					Ftmp = Ftmp->Next;
				}
				else
				{
					Ftmp = head;
				}
			}
			else
			{
				Ftmp = Ftmp->Next;
			}
			if ((!Ftmp) && (did == true))
			{
				did = false;
				Ftmp = head;
			}
			else if ((!Ftmp) && (did == false))
			{
				Ftmp = head;
				goto end;
			}
		}
	end:
		TMP = TMP->next;
	}
	return listofF;
}

ListaDan::~ListaDan() {};