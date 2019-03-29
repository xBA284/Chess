
#include <iostream>
#include <string>
#include "Gra.h"
#include <conio.h>

int main()
{
	plansza.rysuj_plansze();
	ruch(7,0,0,3);
	_getch();
	plansza.rysuj_plansze();

	_getch();
    return 0;
}