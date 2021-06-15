/** @file */
#pragma once
#include <iostream>
#include "StrukturyDanych.h"
#include "RodzajeStatkow.h"
#include <fstream>
using namespace std;


/** Klasa mapy gry */
class Mapa
{
protected:
	string symbol;  ///< symbol wyswietlania pola mapy  
	int rozmiar;	///< rozmiar mapy (4,6,10)
	wygladMap* mapaStatkow; ///< mapa statkow gracza
	wygladMap* mapaTrafien; ///< mapa trafien gracza
	Lodka lodka; ///< lodka
	Statek statek; ///< statek
	Prom prom; ///< prom
	Transportowiec trans; ///< transportowiec

public:
	wygladMap* operator[](int i)
	{
		return i ? mapaStatkow : mapaTrafien;
	}


	/** Lista inicjalizacyjna mapy */
	Mapa(string s, int r, wygladMap*& mS, wygladMap*& mT, Lodka l, Statek sta, Prom p, Transportowiec t) :symbol(s), rozmiar(r), mapaStatkow(mS), mapaTrafien(mT), lodka(l), statek(sta), prom(p), trans(t) {};//konstruktor wieloargumentowy
	
	/**destruktor*/
	~Mapa(); 
	
	/** Metoda zwraca symbol mapy
	@return symbol mapy
	*/

	string zworcSymbolMapy();
	/** Metoda zwraca rozmiar mapy
	@return rozmiar mapy
	*/

	int zwrocrozmiar();
	/** Metoda zwraca mape statkow
	@return mapa statkow
	*/

	wygladMap*& zwrocMapeStatkow();
	/** Metoda zwraca mape trafien
	@return mapa trafien
	*/

	wygladMap*& zwrocMapeTrafien();
	/** Metoda zapisuje statki gracza
	@param stat mapa statkow
	*/

	void zapiszMape(wygladMap*& stat);
	/** Metoda wypisuje statki lub trafienia gracza
	@param statLUBtraf mapa statkow lub mapa trafien
	*/

	void wypiszMape(wygladMap* statLUBtraf);
	/** Metoda zapisuje trafienia gracza
	@param traf trafienia gracza
	*/

	void zapiszMapeStrzalow(wygladMap*& traf);
	/** Metoda odpowiedzialna za strzal gracza
	@param statkiPrzeciwnika statki przeciwnika
	@param mapaStrzalowGracza statki gracza
	@return punkty za trafienie
	*/

	int strzal(wygladMap*& statkiPrzeciwnika, wygladMap*& mapaStrzalowGracza);
	/** Metoda odpowiada za przejscie do nastepnego ruchu 
	*/
	void przejdzDalej();

	/** Metoda zapisuje statki oraz trafienia gracza do pliku tekstowego
	@param plik plik do zapisu
	@param mS statki gracza
	@param mT trafienia gracza
	*/
	void wypiszDoPliku(fstream& plik, wygladMap* mS, wygladMap* mT);

	/** Metoda odpowiada za usuniecie list statkow oraz trafien
	@param pHead poczatek listy statkow lub trafien
	*/
	void zwalnianiePamieci(wygladMap*& pHead);
};