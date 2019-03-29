#include <string>
#include <iostream>
#include "Gra.h"
#include <windows.h>
#include <conio.h>

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

cTworz_figury stwarzacz;
cPlansza plansza;
KOLOR kogo_kolej;

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

short cPionek::ruch(short ob_x, short ob_y, short do_x, short do_y)
{
	short dlugosc_ruchu;
	short dlugosc_1ruchu;

	if (kogo_kolej == bialy)
	{
		dlugosc_ruchu = -1;
		dlugosc_1ruchu = -2;
	}
	else
	{
		dlugosc_ruchu = 1;
		dlugosc_1ruchu = 2;
	}

	if (((plansza.pole[do_x][do_y] == plansza.pole[ob_x + dlugosc_1ruchu][ob_y] && this->ruszyl_sie == false && plansza.pole[ob_x + dlugosc_1ruchu][ob_y]->symbol == pusty) || plansza.pole[do_x][do_y] == plansza.pole[ob_x + dlugosc_ruchu][ob_y]) && plansza.pole[ob_x + dlugosc_ruchu][ob_y]->symbol == pusty)
	{
		wyk_ruch(ob_x, ob_y, do_x, do_y);
		this->ruszyl_sie = true;
		return 0;
	}
	else return 1;
}

short cPionek::bicie(short ob_x, short ob_y, short do_x, short do_y)
{
	return 0;
}

short cPionek::bicie_w_przelocie(short ob_x, short ob_y, short do_x, short do_y)
{
	return 0;
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

short cWieza::ruch(short ob_x, short ob_y, short do_x, short do_y)
{
	return 0;
}

cSkoczek::cSkoczek(KOLOR podany_kolor)
{
	symbol = skoczek;
	kolor = podany_kolor;
}

short cSkoczek::ruch(short ob_x, short ob_y, short do_x, short do_y)
{
	return 0;
}

cGoniec::cGoniec(KOLOR podany_kolor)
{
	symbol = goniec;
	kolor = podany_kolor;
}

short cGoniec::ruch(short ob_x, short ob_y, short do_x, short do_y)
{
	return 0;
}

cHetman::cHetman(KOLOR podany_kolor)
{
	symbol = hetman;
	kolor = podany_kolor;
}

short cHetman::ruch(short ob_x, short ob_y, short do_x, short do_y)
{
	return 0;
}

cKrol::cKrol(KOLOR podany_kolor)
{
	symbol = krol;
	kolor = podany_kolor;
	ruszyl_sie = false;
	szachowany = false;
}

short cKrol::ruch(short ob_x, short ob_y, short do_x, short do_y)
{
	return 0;
}

void cKrol::roszada()
{
}

cPuste::cPuste()
{
	symbol = pusty;
	kolor = zaden;
}

short cPuste::ruch(short ob_x, short ob_y, short do_x, short do_y)
{
	return 0;
}

void wyk_ruch(short ob_x, short ob_y, short do_x, short do_y)
{
	delete plansza.pole[do_x][do_y];
	plansza.pole[do_x][do_y] = plansza.pole[ob_x][ob_y];
	plansza.pole[ob_x][ob_y] = stwarzacz.stworz_puste_pole();
}
