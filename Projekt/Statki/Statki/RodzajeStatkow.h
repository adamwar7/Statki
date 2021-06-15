/** @file */
#pragma once
#include <iostream>
using namespace std;

/** Wirtualna klasa do sprawdzania poprawnosci i zapisu danych do objektow typu Lodka*/
class SprawdzPoprawnosc
{
public:
	/** Wirtualna metoda, ktora sprawdza poprawnosc danych
	@param roz rozmiar mapy
	@param int wspolrzedna y statku
	@param char wspolrzedna x statku
	@return bool informacja o poprawnosci danych wejsciowych
	*/
	virtual bool poprawnosc(int roz, int i1, char c1) = 0;

	/** Wirtualna metoda, ktora zapisuje dane do objektu typu Lodka
	@param roz rozmiar mapy
	@param int wspolrzedna y statku
	@param char wspolrzedna x statku
	@param poprawnosc informacja o poprawnosci danych wejsciowych
	*/
	virtual void zapisz(int roz, int i1, char s1, bool poprawnosc) = 0;
};

/** Klasa reprezentujaca objekty typu Lodka, dziedziczy z klasy SprawdzPoprawnosc*/
class Lodka :public SprawdzPoprawnosc
{
	string symbol;   ///< symbol lodki
	int rozmiar;  ///< rozmiar mapy
protected:
	int icoo1;			 ///< piewsza wspolrzedna x
	char ccoo1;			 ///< pierwsza wspolrzednia y
public:

	/** Konstruktor wieloargumentowy klasy Lodka
	@param sym symbol lodki
	@param roz rozmiar mapy
	@param int wspolrzedna x statku
	@param char wspolrzedna y statku
	*/
	Lodka(string sym, int roz, int i1, char c1);

	/** Destruktor  */
	~Lodka();

	/** Wirtualna metoda, ktora sprawdza poprawnosc danych
	@param roz rozmiar mapy
	@param int wspolrzedna y statku
	@param char wspolrzedna x statku
	@return bool informacja o poprawnosci danych wejsciowych
	*/
	virtual bool poprawnosc(int roz, int i1, char c1);


	/** Wirtualna metoda, ktora zapisuje dane do objektu typu Lodka
	@param roz rozmiar mapy
	@param int wspolrzedna y statku
	@param char wspolrzedna x statku
	@param poprawnosc informacja o poprawnosci danych wejsciowych
	*/
	virtual void zapisz(int roz, int i1, char s1, bool poprawnosc);


	/**  Metoda zwraca wspolrzedna X
	@return wspolrzedna X
	*/
	int zwrocX();

	/**  Metoda zwraca wspolrzedna Y
	@return wspolrzedna Y
	*/
	char zwrocY();

	/**  Metoda zwraca wspolrzedna Y
	@return symbol
	*/
	string zwrocSymbol();

	/**  Metoda zwraca objekt typu Lodka
	@param roz rozmiar mapy
	@return lodka
	*/
	Lodka zworcLodke(char roz);
};


/** Klasa reprezentujaca objekty typu Statek, dziedziczy z klasy Lodka*/
class Statek :public Lodka
{
protected:
	int icoo2;		 ///< druga wspolrzedna x
	char ccoo2;		 ///< druga wspolrzednia y
public:

	/** Konstruktor wieloargumentowy klasy Statek, podczas wywolania tego kostruktora,
	wywoluje sie konstruktor klasy Lodka
	@param sym symbol statku
	@param roz rozmiar mapy
	@param i1 pierwsza wspolrzedna x statku
	@param c1 pierwsza wspolrzedna y statku
	@param i2 druga wspolrzedna x statku
	@param c2 druga wspolrzednia y statku
	@param l objekt typu Lodka
	*/
	Statek(string sym, int roz, int i1, char c1, int i2, char c2, Lodka l);

	/** Destruktor  */
	~Statek();

	/** Wirtualna metoda, ktora sprawdza poprawnosc danych
	@param roz rozmiar mapy
	@param i2 druga wspolrzedna y statku
	@param c2 druga wspolrzedna x statku
	@param l objekt typu Lodka
	@return bool informacja o poprawnosci danych wejsciowych
	*/
	virtual bool poprawnosc(int roz, int i2, char c2, Lodka l);

	/** Wirtualna metoda, ktora zapisuje dane do objektu typu Statek
	@param roz rozmiar mapy
	@param i2 druga wspolrzedna y statku
	@param c2 druga wspolrzedna x statku
	@param poprawnosc informacja o poprawnosci danych wejsciowych
	*/
	virtual void zapisz(int i2, char c2, bool poprawnosc);

	/**  Metoda zwraca druga wspolrzedna X
	@return druga wspolrzedna X
	*/
	int zwrocX2();

	/**  Metoda zwraca druga wspolrzedna Y
	@return wspolrzedna druga Y
	*/
	char zwrocY2();

	/**  Metoda zwraca objekt typu Statek
	@param roz rozmiar mapy
	@param lodka objekt typu Lodka
	@return statek
	*/
	Statek zworcStatek(char roz, Lodka lodka);
};

/** Klasa reprezentujaca objekty typu Prom, dziedziczy z klasy Statek*/
class Prom :public Statek
{
protected:
	int icoo3;		///< trzecia wspolrzedna x
		
	char ccoo3;		///< trzecia wspolrzedna y
public:

	/** Konstruktor wieloargumentowy klasy Statek, podczas wywolania tego kostruktora,
	wywoluja sie konstruktory klasy Statek oraz klasy Lodka
	@param sym symbol promu
	@param roz rozmiar mapy
	@param i1 pierwsza wspolrzedna x statku
	@param c1 pierwsza wspolrzedna y statku
	@param i2 druga wspolrzedna x statku
	@param c2 druga wspolrzednia y statku
	@param i3 trzecia wspolrzedna x statku
	@param c3 trzecia wspolrzednia y statku
	@param l objekt typu Lodka
	@param l objekt typu Statek
	*/
	Prom(string sym, int roz, int i1, char c1, int i2, char c2, int i3, char c3, Lodka l, Statek s);
	
	/** Destruktor */
	~Prom();

	/** Wirtualna metoda, ktora sprawdza poprawnosc danych
	@param roz rozmiar mapy
	@param i3 druga wspolrzedna y statku
	@param c3 druga wspolrzedna x statku
	@param s objekt typu statek
	@return bool informacja o poprawnosci danych wejsciowych
	*/
	virtual bool poprawnosc(int roz, int i3, char c3, Statek s);

	/** Wirtualna metoda, ktora zapisuje dane do objektu typu Prom
	@param roz rozmiar mapy
	@param i3 druga wspolrzedna y statku
	@param c3 druga wspolrzedna x statku
	@param poprawnosc informacja o poprawnosci danych wejsciowych
	*/
	virtual void zapisz(int roz, int i3, char c3, bool poprawnosc);

	/**  Metoda zwraca trzecia wspolrzedna X
	@return druga wspolrzedna X
	*/
	int zwrocX3();

	/**  Metoda zwraca trzecia wspolrzedna Y
	@return wspolrzedna druga Y
	*/
	char zwrocY3();

	/**  Metoda zwraca objekt typu Prom
	@param roz rozmiar mapy
	@param lodka objekt typu Lodka
	@param statek objekt typu Statek
	@return Prom
	*/
	Prom zworcProm(char roz, Lodka lodka, Statek statek);
};


/** Klasa reprezentujaca objekty typu Transportowiec, dziedziczy z klasy Prom*/
class Transportowiec :public Prom
{
protected:
	int icoo4;	///< czwarta wspolrzedna x
	char ccoo4;	///< czwarta wspolrzedna y
public:

	/** Konstruktor wieloargumentowy klasy Statek, podczas wywolania tego kostruktora,
	wywoluja sie konstruktory klasy Statek oraz klasy Lodka
	@param sym symbol transportowca
	@param roz rozmiar mapy
	@param i1 pierwsza wspolrzedna x statku
	@param c1 pierwsza wspolrzedna y statku
	@param i2 druga wspolrzedna x statku
	@param c2 druga wspolrzednia y statku
	@param i3 trzecia wspolrzedna x statku
	@param c3 trzecia wspolrzednia y statku
	@param i4 czwarta wspolrzedna x statku
	@param c4 czwarta wspolrzednia y statku
	@param l objekt typu Lodka
	@param l objekt typu Statek
	@param p objekt typu Prom
	*/
	Transportowiec(string sym, int roz, int i1, char c1, int i2, char c2, int i3, char c3, int i4, char c4, Lodka l, Statek s, Prom p);

	/** Destruktor */
	~Transportowiec();

	/** Wirtualna metoda, ktora sprawdza poprawnosc danych
	@param roz rozmiar mapy
	@param i3 druga wspolrzedna y statku
	@param c3 druga wspolrzedna x statku
	@param s objekt typu Prom
	@return bool informacja o poprawnosci danych wejsciowych
	*/
	virtual bool poprawnosc(int roz, int i4, char c4, Prom s);

	/** Wirtualna metoda, ktora zapisuje dane do objektu typu Transportowiec
	@param roz rozmiar mapy
	@param i4 czwarta wspolrzedna y statku
	@param c4 czwarta wspolrzedna x statku
	@param poprawnosc informacja o poprawnosci danych wejsciowych
	*/
	virtual void zapisz(int roz, int i4, char c4, bool poprawnosc);

	/**  Metoda zwraca czwarta wspolrzedna X
	@return  czwarta wspolrzedna X
	*/
	int zwrocX4();

	/**  Metoda zwraca  czwarta wspolrzedna Y
	@return wspolrzedna  czwarta Y
	*/
	char zwrocY4();

	/**  Metoda zwraca objekt typu Transportowiec
	@param roz rozmiar mapy
	@param lodka objekt typu Lodka
	@param statek objekt typu Statek
	@param prom objekt typu Prom
	@return transportowiec
	*/
	Transportowiec zworcTransportowiec(char roz, Lodka lodka, Statek statek, Prom prom);
};