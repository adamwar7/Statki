/** @file */
#pragma once
#include <iostream>

using namespace std;


	 ///< napis przechowawany w liscie (nazwa pliku)
	 ///< adres nastepnego elementu listy

/** struktura listy jednokierunkowej */
struct wygladMap
{
	string symbol;	///< symbol wyswietlania pola mapy
	int rozmiar; ///< rozmiar mapy
	bool statek; ///< czy statek jest na danym miejscu czy go nie ma
	string nazwaStatku; ///< nazwa statku
	int y; /// <wspolrzedna y
	char x; ///< wspolrzedna x
	wygladMap* next;	///< adres nastepnego elementu listy
};
