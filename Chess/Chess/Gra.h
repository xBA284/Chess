#pragma once

enum STAN_GRY { stop = 0, start = 1, koniec = 2 };
//enum FIGURY { pionek = 'p', wieza = 'w', kon = 'k', goniec = 'g', hetman = 'h', krol = 'k' };
enum KOLOR { bialy = 0, czarny = 1 };

class cFigura
{
private:
	//FIGURY typ_figury;
	KOLOR kolor;
	unsigned short liczba_porzadkowa;
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

class cWieza : public cFigura
{
private:
	bool ruszyl_sie;
};






class cPole
{
private:
	cFigura* figura_na_polu;
};

cPole plansza[8][8];