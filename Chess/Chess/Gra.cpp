#include "Gra.h"

cFigura::cFigura()
{
}

cFigura::~cFigura()
{
}

KOLOR cFigura::pobierz_kolor()
{
	return kolor;
}

unsigned short cFigura::pobierz_liczbe_porzadkowa()
{
	return liczba_porzadkowa;
}

bool cFigura::pobierz_czy_zbity()
{
	return zbity;
}
