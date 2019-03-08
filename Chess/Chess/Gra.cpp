#include <string>
#include <iostream>
#include "Gra.h"
#include <windows.h>

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

cTworz_figury stwarzacz;
cPlansza plansza;

void plansza_poczatkowa(cFigura* plansza[8][8]) {
	SYMBOL symbole[] = {wieza, skoczek, goniec, hetman, krol, goniec, skoczek, wieza};
	for (int i = 0; i < 8; ++i) {
		plansza[0][i] = stwarzacz.stworz_figure(symbole[i], czarny);
		plansza[1][i] = stwarzacz.stworz_figure(pionek, czarny);
		plansza[2][i] = stwarzacz.stworz_puste_pole();
		plansza[3][i] = stwarzacz.stworz_puste_pole();
		plansza[4][i] = stwarzacz.stworz_puste_pole();
		plansza[5][i] = stwarzacz.stworz_puste_pole();
		plansza[6][i] = stwarzacz.stworz_figure(pionek, bialy);
		plansza[7][i] = stwarzacz.stworz_figure(symbole[i], bialy);
	}
}

cPlansza::cPlansza()
{
	plansza_poczatkowa(pole);
}

cPlansza::~cPlansza()
{
	for (short i = 0; i < 8; i++)
	{
		for (short j = 0; j < 8; j++)
		{
			delete pole[i][j];
		}
	}
}

void cPlansza::rysuj_plansze()
{
	short licznik_tla = 0;

	std::cout << "  - - - - - - - - " << std::endl;
	for (short i = 0; i < 8; i++)
	{
		std::cout << "| ";
		for (short j = 0; j < 8; j++)
		{
			if (licznik_tla == 0)
			{
				if (plansza.pole[i][j]->kolor == czarny)
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED);
					std::cout << static_cast<char>(plansza.pole[i][j]->symbol) << " ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << static_cast<char>(plansza.pole[i][j]->symbol) << " ";
				}

				licznik_tla++;
			}
			else
			{
				if (plansza.pole[i][j]->kolor == czarny)
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
					std::cout << static_cast<char>(plansza.pole[i][j]->symbol) << " ";
				}
				else
				{
					SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << static_cast<char>(plansza.pole[i][j]->symbol) << " ";
				}

				licznik_tla--;
			}	
		}
		if (licznik_tla == 1) licznik_tla = 0;
		else licznik_tla = 1;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		std::cout << " |\n";
	}
	std::cout << "  - - - - - - - - " << std::endl;
}

cFigura* cTworz_figury::stworz_figure(SYMBOL symbol, KOLOR kolor) const {
	switch (symbol) {
		case goniec:
			return new cGoniec(kolor);
		case hetman:
			return new cHetman(kolor);
		case krol:
			return new cKrol(kolor);
		case pionek:
			return new cPionek(kolor);
		case skoczek:
			return new cSkoczek(kolor);
		case wieza:
			return new cWieza(kolor);
	}
}

cFigura* cTworz_figury::stworz_puste_pole() const {
	return new cPuste();
}

cPionek::cPionek(KOLOR podany_kolor)
{
	symbol = pionek;
	kolor = podany_kolor;
	ruszyl_sie = false;
	jest_na_koncu = false;
}

void cPionek::ruch()
{
}

void cPionek::bicie()
{
}

void cPionek::bicie_w_przelocie()
{
}

void cPionek::zamiana()
{
}

cWieza::cWieza(KOLOR podany_kolor)
{
	symbol = wieza;
	kolor = podany_kolor;
	ruszyl_sie = false;
}

void cWieza::ruch()
{
}

cSkoczek::cSkoczek(KOLOR podany_kolor)
{
	symbol = skoczek;
	kolor = podany_kolor;
}

void cSkoczek::ruch()
{
}

cGoniec::cGoniec(KOLOR podany_kolor)
{
	symbol = goniec;
	kolor = podany_kolor;
}

void cGoniec::ruch()
{
}

cHetman::cHetman(KOLOR podany_kolor)
{
	symbol = hetman;
	kolor = podany_kolor;
}

void cHetman::ruch()
{
}

cKrol::cKrol(KOLOR podany_kolor)
{
	symbol = krol;
	kolor = podany_kolor;
	ruszyl_sie = false;
	szachowany = false;
}

void cKrol::ruch()
{
}

void cKrol::roszada()
{
}

cPuste::cPuste()
{
	symbol = pusty;
	kolor = zaden;
}

void cPuste::ruch()
{
}
