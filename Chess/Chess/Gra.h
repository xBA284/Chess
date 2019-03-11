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
	cFigura* stworz_figure(SYMBOL symbol, KOLOR kolor) const;
	cFigura* stworz_puste_pole() const;
};

extern cTworz_figury stwarzacz;

class cPlansza
{
public:
	cFigura* pole[8][8];
	cPlansza();
	~cPlansza();
	void rysuj_plansze();
};

extern cPlansza plansza;

void ruch(cFigura* skad, cFigura* dokad);