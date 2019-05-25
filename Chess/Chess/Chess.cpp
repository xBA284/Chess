
#include <iostream>
#include <string>
#include "Gra.h"

int main()
{
	plansza.rysuj_plansze();
	kogo_kolej = bialy;
	short blad = plansza.pole[6][0]->ruch(6, 0, 4, 0);
	std::cout << blad;
	getchar();
	plansza.rysuj_plansze();
	blad = plansza.pole[4][0]->ruch(4, 0, 3, 0);
	std::cout << blad;
	getchar();
	plansza.rysuj_plansze();
	blad = plansza.pole[7][0]->ruch(7, 0, 4, 0);
	std::cout << blad;
	getchar();
	plansza.rysuj_plansze();
	blad = plansza.pole[4][0]->ruch(4, 0, 4, 7);
	std::cout << blad;
	getchar();
	plansza.rysuj_plansze();
	blad = plansza.pole[4][7]->ruch(4, 7, 4, 3);
	std::cout << blad;
	getchar();
	plansza.rysuj_plansze();

	getchar();
    return 0;
}