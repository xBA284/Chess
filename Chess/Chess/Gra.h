#pragma once

enum STAN_GRY { stop = 0, start = 1, koniec = 2 };
enum SYMBOL { pionek = 'P', wieza = 'W', kon = 'K', goniec = 'G', hetman = 'H', krol = 'KR' };
enum KOLOR { bialy = 0, czarny = 1 };

class cGra
{
public:
	STAN_GRY stan_gry;
	KOLOR wygrany;

	cGra();
	~cGra();
};

class cFigura
{
public:
	SYMBOL symbol;
	KOLOR kolor;

	cFigura();
	~cFigura();
	virtual void ruch() = 0;
};

class cPionek : public cFigura
{
public:
	bool ruszyl_sie;
	bool jest_na_koncu;

	cPionek();
	cPionek(KOLOR podany_kolor);
	~cPionek();
	void ruch();
	void bicie();
};

class cWieza : public cFigura
{
public:
	bool ruszyl_sie;

	cWieza();
	cWieza(KOLOR podany_kolor);
	~cWieza();
	void ruch();
};

class cKon : public cFigura
{
public:
	cKon();
	cKon(KOLOR podany_kolor);
	~cKon();
	void ruch();
};

class cGoniec : public cFigura
{
public:
	cGoniec();
	cGoniec(KOLOR podany_kolor);
	~cGoniec();
	void ruch();
};

class cHetman : public cFigura
{
public:
	cHetman();
	cHetman(KOLOR podany_kolor);
	~cHetman();
	void ruch();
};

class cKrol : public cFigura
{
public:
	bool ruszyl_sie;
	bool szachowany;

	cKrol();
	cKrol(KOLOR podany_kolor);
	~cKrol();
	void ruch();
};

class cTworz_figury
{
public:
	cPionek* biale_pionki[8];
	cPionek* czarne_pionki[8];
	cWieza* biale_wieze[10];
	cWieza* czarne_wieze[10];
	cKon* biale_konie[10];
	cKon* czarne_konie[10];
	cGoniec* biale_gonce[10];
	cGoniec* czarne_gonce[10];
	cHetman* biale_hetmany[9];
	cHetman* czarne_hetmany[9];
	cKrol* bialy_krol;
	cKrol* czarny_krol;
	cFigura* pole_puste;

	cTworz_figury();
	~cTworz_figury();
	void tworz_figury_startowe();
};

cTworz_figury stwarzacz;

cFigura* const plansza_poczatkowa[8][8]{
	{stwarzacz.czarne_wieze[0], stwarzacz.czarne_konie[0], stwarzacz.czarne_gonce[0], stwarzacz.czarne_hetmany[0], stwarzacz.czarny_krol, stwarzacz.czarne_gonce[1], stwarzacz.czarne_konie[1], stwarzacz.czarne_wieze[1]},
	{stwarzacz.czarne_pionki[0], stwarzacz.czarne_pionki[1], stwarzacz.czarne_pionki[2], stwarzacz.czarne_pionki[3], stwarzacz.czarne_pionki[4], stwarzacz.czarne_pionki[5], stwarzacz.czarne_pionki[6], stwarzacz.czarne_pionki[7]},
	{stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste},
	{stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste},
	{stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste},
	{stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste},
	{stwarzacz.biale_pionki[0], stwarzacz.biale_pionki[1], stwarzacz.biale_pionki[2], stwarzacz.biale_pionki[3], stwarzacz.biale_pionki[4], stwarzacz.biale_pionki[5], stwarzacz.biale_pionki[6], stwarzacz.biale_pionki[7]},
	{stwarzacz.biale_wieze[0], stwarzacz.biale_konie[0], stwarzacz.biale_gonce[0], stwarzacz.biale_hetmany[0], stwarzacz.bialy_krol, stwarzacz.biale_gonce[1], stwarzacz.biale_konie[1], stwarzacz.biale_wieze[1]}
};

class cPlansza
{
public:
	cFigura* pole[8][8];
	cPlansza();
	~cPlansza();
};

cPlansza plansza;