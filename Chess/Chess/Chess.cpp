
#include <iostream>
#include <string>
#include "Gra.h"
#include <conio.h>

int main()
{
	plansza.rysuj_plansze();
	kogo_kolej = bialy;
	short blad = plansza.pole[6][0]->ruch(6, 0, 4, 0);
	std::cout << blad;
	_getch();
	plansza.rysuj_plansze();
	blad = plansza.pole[4][0]->ruch(4, 0, 3, 0);
	std::cout << blad;
	_getch();
	plansza.rysuj_plansze();

	_getch();
    return 0;
}