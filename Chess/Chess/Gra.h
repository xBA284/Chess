#pragma once

enum STAN_GRY { stop = 0, start = 1, koniec = 2 };
//enum FIGURY { pionek = 'p', wieza = 'w', kon = 'k', goniec = 'g', hetman = 'h', krol = 'k' };
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
	//FIGURY typ_figury;
	KOLOR kolor;
	bool zbity;

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
	~cPionek();
	void ruch();
	void bicie();
};

class cWieza : public cFigura
{
public:
	bool ruszyl_sie;

	cWieza();
	~cWieza();
	void ruch();
};

class cKon
{
public:
	cKon();
	~cKon();
};

class cGoniec
{
public:
	cGoniec();
	~cGoniec();
};

class cHetman
{
public:
	cHetman();
	~cHetman();
};

class cKrol
{
public:
	bool ruszyl_sie;

	cKrol();
	~cKrol();
};

cFigura* const plansza_poczatkowa[8][8]{
	{&bialy1},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
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

	cTworz_figury();
	~cTworz_figury();
	void tworz_figury_startowe();
};

class cPlansza
{
public:
	cFigura* pole[8][8];
	cPlansza();
	~cPlansza();
};

cPlansza* plansza = new cPlansza();
delete plansza;