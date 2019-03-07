#include "Gra.h"

cFigura::cFigura()
{
}

cFigura::~cFigura()
{
}

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
		biale_pionki[i] = new cPionek();
		czarne_pionki[i] = new cPionek();
	}
	for (short i = 0; i < 2; i++)
	{
		biale_wieze[i] = new cWieza();
		czarne_wieze[i] = new cWieza();
	}
	for (short i = 0; i < 2; i++)
	{
		biale_konie[i] = new cKon();
		czarne_konie[i] = new cKon();
	}
	for (short i = 0; i < 2; i++)
	{
		biale_gonce[i] = new cGoniec();
		czarne_gonce[i] = new cGoniec();
	}
	
	biale_hetmany[0] = new cHetman();
	czarne_hetmany[0] = new cHetman();

	bialy_krol = new cKrol();
	czarny_krol = new cKrol();
	
}

cPionek::cPionek(KOLOR podany_kolor)
{
	symbol = pionek;
	kolor = podany_kolor;
	ruszyl_sie = false;
	jest_na_koncu = false;
}

cKrol::cKrol(KOLOR podany_kolor)
{
	symbol = krol;
	kolor = podany_kolor;
	ruszyl_sie = false;
	szachowany = false;
}
