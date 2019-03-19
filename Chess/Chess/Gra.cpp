#include <string>
#include <iostream>
#include "Gra.h"
#include <windows.h>
#include <conio.h>

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
	system("cls");

	short licznik_tla = 0;

	std::cout << "  A B C D E F G H" << std::endl;
	for (short i = 0; i < 8; i++)
	{
		switch (i)
		{
			case 0: std::cout << "8 ";
				break;
			case 1: std::cout << "7 ";
				break;
			case 2: std::cout << "6 ";
				break;
			case 3: std::cout << "5 ";
				break;
			case 4: std::cout << "4 ";
				break;
			case 5: std::cout << "3 ";
				break;
			case 6: std::cout << "2 ";
				break;
			case 7: std::cout << "1 ";
				break;
		}
		
		for (short j = 0; j < 8; j++)
		{
			if (licznik_tla == 0)
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

				licznik_tla++;
			}
			else
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

				licznik_tla--;
			}	
		}
		if (licznik_tla == 1) licznik_tla = 0;
		else licznik_tla = 1;
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		switch (i)
		{
		case 0: std::cout << " 8\n";
			break;
		case 1: std::cout << " 7\n";
			break;
		case 2: std::cout << " 6\n";
			break;
		case 3: std::cout << " 5\n";
			break;
		case 4: std::cout << " 4\n";
			break;
		case 5: std::cout << " 3\n";
			break;
		case 6: std::cout << " 2\n";
			break;
		case 7: std::cout << " 1\n";
			break;
		}
	}
	std::cout << "  A B C D E F G H" << std::endl;
}

cFigura* cTworz_figury::stworz_figure(SYMBOL symbol, KOLOR kolor) const {
	switch (symbol) {
		case goniec:
			return new cGoniec(kolor);
			break;
		case hetman:
			return new cHetman(kolor);
			break;
		case krol:
			return new cKrol(kolor);
			break;
		case pionek:
			return new cPionek(kolor);
			break;
		case skoczek:
			return new cSkoczek(kolor);
			break;
		case wieza:
			return new cWieza(kolor);
			break;
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

void cPionek::ruch(cFigura*& pole_obecne, cFigura*& pole_docelowe)
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

void cWieza::ruch(cFigura*& pole_obecne, cFigura*& pole_docelowe)
{

}

cSkoczek::cSkoczek(KOLOR podany_kolor)
{
	symbol = skoczek;
	kolor = podany_kolor;
}

void cSkoczek::ruch(cFigura*& pole_obecne, cFigura*& pole_docelowe)
{
}

cGoniec::cGoniec(KOLOR podany_kolor)
{
	symbol = goniec;
	kolor = podany_kolor;
}

void cGoniec::ruch(cFigura*& pole_obecne, cFigura*& pole_docelowe)
{
}

cHetman::cHetman(KOLOR podany_kolor)
{
	symbol = hetman;
	kolor = podany_kolor;
}

void cHetman::ruch(cFigura*& pole_obecne, cFigura*& pole_docelowe)
{
}

cKrol::cKrol(KOLOR podany_kolor)
{
	symbol = krol;
	kolor = podany_kolor;
	ruszyl_sie = false;
	szachowany = false;
}

void cKrol::ruch(cFigura*& pole_obecne, cFigura*& pole_docelowe)
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

void ruch(cFigura*& pole_obecne, cFigura*& pole_docelowe)
{
	delete pole_docelowe;
	pole_docelowe = pole_obecne;
	pole_obecne = stwarzacz.stworz_puste_pole();
}