
#include <iostream>
#include <string>
#include "Gra.h"
#include <conio.h>

int main()
{
	plansza.rysuj_plansze();
	ruch(plansza.pole[7][0], plansza.pole[0][3]);
	_getch();
	plansza.rysuj_plansze();

	_getch();
    return 0;
}