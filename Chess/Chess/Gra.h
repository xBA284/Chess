#pragma once

enum STAN_GRY { stop = 0, start = 1, koniec = 2 };
//enum FIGURY { pionek = 'p', wieza = 'w', kon = 'k', goniec = 'g', hetman = 'h', krol = 'k' };
enum KOLOR { bialy = 0, czarny = 1 };

class cGra
{
private:
	STAN_GRY stan_gry;
	KOLOR wygrany;
private:
	cGra();
	~cGra();
};

class cFigura
{
private:
	//FIGURY typ_figury;
	KOLOR kolor;
	bool zbity;
public:
	cFigura();
	~cFigura();
	virtual void ruch() = 0;
	KOLOR pobierz_kolor();
	unsigned short pobierz_liczbe_porzadkowa();
	bool pobierz_czy_zbity();
};

class cPionek : public cFigura
{
private:
	bool ruszyl_sie;
	bool jest_na_koncu;
public:
	cPionek();
	~cPionek();
	void ruch();
	void bicie();
	bool pobierz_czy_ruszyl_sie();
	bool pobierz_czy_jest_na_koncu();
};

cPionek bialy1, bialy2, bialy3, bialy4, bialy5, bialy6, bialy7, bialy8,
czarny1, czarny2, czarny3, czarny4, czarny5, czarny6, czarny7, czarny8;

class cWieza : public cFigura
{
private:
	bool ruszyl_sie;
public:
	cWieza();
	~cWieza();
	void ruch();
	bool pobierz_czy_ruszyl_sie();
};

cWieza bialy_w1, bialy_w2,
czarny_w1, czarny_w2;

class cKon
{
public:
	cKon();
	~cKon();
};

cKon bialy_k1, bialy_k2,
czarny_k1, czarny_k2;

class cGoniec
{
public:
	cGoniec();
	~cGoniec();
};

cGoniec bialy_g1, bialy_g2,
czarny_g1, czarny_g2;

class cHetman
{
public:
	cHetman();
	~cHetman();
};

cHetman bialy_h1,
czarny_h1;

class cKrol
{
private:
	bool ruszyl_sie;
public:
	cKrol();
	~cKrol();
};

cKrol bialy_krol1,
czarny_krol1;

class cPole
{
public:
	cFigura* figura_na_polu;
	cPole();
	~cPole();
};

cPole a8, b8, c8, d8, e8, f8, g8, h8,
a7, b7, c7, d7, e7, f7, g7, h7,
a6, b6, c6, d6, e6, f6, g6, h6,
a5, b5, c5, d5, e5, f5, g5, h5,
a4, b4, c4, d4, e4, f4, g4, h4,
a3, b3, c3, d3, e3, f3, g3, h3,
a2, b2, c2, d2, e2, f2, g2, h2,
a1, b1, c1, d1, e1, f1, g1, h1;

cPole plansza[8][8];

cPole const plansza_startowa[8][8]{
	{a8.figura_na_polu = &czarny_w1, b8.figura_na_polu = &czarny_k1, c8.figura_na_polu = &czarny_g1, d8.figura_na_polu = &czarny_h1, }
}
