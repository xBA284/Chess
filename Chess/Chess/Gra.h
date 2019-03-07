#pragma once
#include <string>

enum STAN_GRY { stop = 0, start = 1, koniec = 2 };
enum SYMBOL { pionek = 'P', wieza = 'W', skoczek = 'S', goniec = 'G', hetman = 'H', krol = 'K', pusty = ' '};
enum KOLOR { bialy = 0, czarny = 1, zaden = 2 };

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

	virtual void ruch() = 0;
};

class cPuste : public cFigura
{
public:
	cPuste();
	~cPuste();
	void ruch();
};

class cPionek : public cFigura
{
public:
	bool ruszyl_sie;
	bool jest_na_koncu;

	cPionek(KOLOR podany_kolor);
	~cPionek();
	void ruch();
	void bicie();
	void bicie_w_przelocie();
	void zamiana();
};

class cWieza : public cFigura
{
public:
	bool ruszyl_sie;

	cWieza(KOLOR podany_kolor);
	~cWieza();
	void ruch();
};

class cSkoczek : public cFigura
{
public:
	cSkoczek(KOLOR podany_kolor);
	~cSkoczek();
	void ruch();
};

class cGoniec : public cFigura
{
public:
	cGoniec(KOLOR podany_kolor);
	~cGoniec();
	void ruch();
};

class cHetman : public cFigura
{
public:
	cHetman(KOLOR podany_kolor);
	~cHetman();
	void ruch();
};

class cKrol : public cFigura
{
public:
	bool ruszyl_sie;
	bool szachowany;

	cKrol(KOLOR podany_kolor);
	~cKrol();
	void ruch();
	void roszada();
};

class cTworz_figury
{
public:
	cPionek* biale_pionki[8];
	cPionek* czarne_pionki[8];
	cWieza* biale_wieze[10];
	cWieza* czarne_wieze[10];
	cSkoczek* biale_skoczki[10];
	cSkoczek* czarne_skoczki[10];
	cGoniec* biale_gonce[10];
	cGoniec* czarne_gonce[10];
	cHetman* biale_hetmany[9];
	cHetman* czarne_hetmany[9];
	cKrol* bialy_krol;
	cKrol* czarny_krol;
	cPuste* pole_puste;

	cTworz_figury();
	~cTworz_figury();
	void tworz_figury_startowe();
};

extern cTworz_figury stwarzacz;

cFigura* const plansza_poczatkowa[8][8]{
	{stwarzacz.czarne_wieze[0], stwarzacz.czarne_skoczki[0], stwarzacz.czarne_gonce[0], stwarzacz.czarne_hetmany[0], stwarzacz.czarny_krol, stwarzacz.czarne_gonce[1], stwarzacz.czarne_skoczki[1], stwarzacz.czarne_wieze[1]},
	{stwarzacz.czarne_pionki[0], stwarzacz.czarne_pionki[1], stwarzacz.czarne_pionki[2], stwarzacz.czarne_pionki[3], stwarzacz.czarne_pionki[4], stwarzacz.czarne_pionki[5], stwarzacz.czarne_pionki[6], stwarzacz.czarne_pionki[7]},
	{stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste},
	{stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste},
	{stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste},
	{stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste, stwarzacz.pole_puste},
	{stwarzacz.biale_pionki[0], stwarzacz.biale_pionki[1], stwarzacz.biale_pionki[2], stwarzacz.biale_pionki[3], stwarzacz.biale_pionki[4], stwarzacz.biale_pionki[5], stwarzacz.biale_pionki[6], stwarzacz.biale_pionki[7]},
	{stwarzacz.biale_wieze[0], stwarzacz.biale_skoczki[0], stwarzacz.biale_gonce[0], stwarzacz.biale_hetmany[0], stwarzacz.bialy_krol, stwarzacz.biale_gonce[1], stwarzacz.biale_skoczki[1], stwarzacz.biale_wieze[1]}
};

class cPlansza
{
public:
	cFigura* pole[8][8];
	cPlansza();
	~cPlansza();
	void rysuj_plansze();
};

extern cPlansza plansza;