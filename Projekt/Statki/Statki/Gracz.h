/** @file */
#pragma once
#include <iostream>
#include "Mapa.h"
#include <fstream>
/** Klasa repezentujaca gracza */
class Gracz
{
	

public:
	int punktacja;						///< punkty gracza
	Mapa rozstawienia;					///< mapa statkow gracza

public:
	/** Konstrukor dwuarguementowy klasy Gracz
	@param mapa objekt typu Mapa
	@param pkt punktacja gracza
	*/
	Gracz(Mapa mapa, int pkt);

	/** Desturktor */
	~Gracz();						

	/** Metoda zwraca punkty gracza
	@return punkty
	*/
	int zwrocPunkty();

	/** Metoda edytuje punktacje gracza
	@param pkt punkty gracza
	*/
	void edytujPunkty(int pkt);

	/** Metoda zapisu dla gracza pierwszego
	@param plik plik do zapisu
	*/
	void ZapiszDoPlikuGracza1(fstream& plik);

	/** Metoda zapisu dla gracza drugiego
	@param plik plik do zapisu
	*/
	void ZapiszDoPlikuGracza2(fstream& plik);

	/** Operator += do edycji punktacji
	@param pkt punkty do dodania
	@return gracz
	*/
	Gracz& operator+=(int pkt);

	/** Operator << do wypisywania punktacji 
	
	@param stream stream
	@param s objekt typu Gracz
	@return stream
	*/
	friend ostream& operator<<(ostream & stream,const  Gracz & s);


	/** Metoda odpowiedzialna za zarzadanie rozgrywka
	@param gracz2 gracz
	@param g1 plik nr 1
	@param g2 plik nr 2
	*/
	void zarzadajRozgrywka(Gracz gracz2, fstream& g1, fstream& g2);
};

