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

	virtual short ruch(short ob_y, short ob_x, short do_y, short do_x) = 0;
};

class cPuste : public cFigura
{
public:
	cPuste();
	~cPuste();
	short ruch(short ob_y, short ob_x, short do_y, short do_x);
};

class cPionek : public cFigura
{
public:
	bool ruszyl_sie;
	bool jest_na_koncu;

	cPionek(KOLOR podany_kolor);
	~cPionek();
	short ruch(short ob_y, short ob_x, short do_y, short do_x);
	short bicie(short ob_y, short ob_x, short do_y, short do_x);
	short bicie_w_przelocie(short ob_y, short ob_x, short do_y, short do_x);
	void zamiana();
};

class cWieza : public cFigura
{
public:
	bool ruszyl_sie;

	cWieza(KOLOR podany_kolor);
	~cWieza();
	short ruch(short ob_y, short ob_x, short do_y, short do_x);
};

class cSkoczek : public cFigura
{
public:
	cSkoczek(KOLOR podany_kolor);
	~cSkoczek();
	short ruch(short ob_y, short ob_x, short do_y, short do_x);
};

class cGoniec : public cFigura
{
public:
	cGoniec(KOLOR podany_kolor);
	~cGoniec();
	short ruch(short ob_y, short ob_x, short do_y, short do_x);
};

class cHetman : public cFigura
{
public:
	cHetman(KOLOR podany_kolor);
	~cHetman();
	short ruch(short ob_y, short ob_x, short do_y, short do_x);
};

class cKrol : public cFigura
{
public:
	bool ruszyl_sie;
	bool szachowany;

	cKrol(KOLOR podany_kolor);
	~cKrol();
	short ruch(short ob_y, short ob_x, short do_y, short do_x);
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
extern KOLOR kogo_kolej;

void wyk_ruch(short ob_y, short ob_x, short do_y, short do_x);