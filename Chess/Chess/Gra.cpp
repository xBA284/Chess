#include <string>
#include "Gra.h"

cPlansza::cPlansza()
{
	for (short i = 0; i < 8; i++)
	{
		for (short j = 0; j < 8; j++)
		{
			pole[i][j] = plansza_poczatkowa[i][j];
		}
	}
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

cTworz_figury::cTworz_figury()
{
	tworz_figury_startowe();
}

cTworz_figury::~cTworz_figury()
{
}

void cTworz_figury::tworz_figury_startowe()
{
	for (short i = 0; i < 8; i++)
	{
		biale_pionki[i] = new cPionek(bialy);
		czarne_pionki[i] = new cPionek(czarny);
	}
	for (short i = 0; i < 2; i++)
	{
		biale_wieze[i] = new cWieza(bialy);
		czarne_wieze[i] = new cWieza(czarny);
	}
	for (short i = 0; i < 2; i++)
	{
		biale_skoczki[i] = new cSkoczek(bialy);
		czarne_skoczki[i] = new cSkoczek(czarny);
	}
	for (short i = 0; i < 2; i++)
	{
		biale_gonce[i] = new cGoniec(bialy);
		czarne_gonce[i] = new cGoniec(czarny);
	}
	
	biale_hetmany[0] = new cHetman(bialy);
	czarne_hetmany[0] = new cHetman(czarny);

	bialy_krol = new cKrol(bialy);
	czarny_krol = new cKrol(czarny);
	
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

cTworz_figury stwarzacz;