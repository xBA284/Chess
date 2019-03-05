#include "Gra.h"

cFigura::cFigura()
{
}

cFigura::~cFigura()
{
}

cPlansza::cPlansza()
{
	pole[0][] = ;
}

cPlansza::~cPlansza()
{
	;
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
