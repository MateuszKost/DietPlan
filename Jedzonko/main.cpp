#include "Interfejs.h"

int main()
{
	Interfejs Interfejs;

	try {
		Interfejs.Dokonaj_Wyboru();
	}
	catch (string wyjatek)
	{
		cout << endl << wyjatek << endl; // wyrzuca nam wyjatek z odpowiednia informacja
	}
}