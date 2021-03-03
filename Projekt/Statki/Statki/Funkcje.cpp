#include "Funkcje.h"

char podajRozmiar()
{
	char rozmiar = '0';
	while (rozmiar != '1' && rozmiar != '2' && rozmiar != '3')
	{
		cout << "Podaj wielkosc mapy: '1' - mala mapa, '2' srednia mapa, '3' - duza mapa\n";
		cout << "Wprowadz: ";
		cin >> rozmiar;
		system("cls");
	}
	return rozmiar;
}


int zwrocPrawdziwyRozmiar(char fakerozmiar)
{
	if (fakerozmiar == '1')
	{
		return 4;
	}
	else if (fakerozmiar == '2')
	{
		return 6;
	}
	else
		return 10;
}

void instrukcja()
{
	cout << "STATKI\n-------------------------\nInstrukcja obslugi:\n";
	cout << "[1] Aby rozpoczac gre nalezy podac rozmiar mapy: '1'- mapa 4x4, '2'-mapa 6x6, '3'-mapa 10x10\nTaki jaki zostanie wybrany rozmiar mapy tyle bedzie statkow(2,3,4)\n\n";
	cout << "[2] Wspolrzednie statkow nalezy wprowadzac duzymi cyframi. Przykladowa wspolrzednia X=A, Y=1.\nJesli zostana wprowadzone zle wspolrzednie statki nie zapisza sie poprawnie\n\n";
	cout << "[3] Jezeli wspolrzednie statkow beda sie pokrywac lub wychodzic poza zakres mapy,\n nie zostanie zapisania prawidlowa ilosc statkow\n\n";
	cout << "[4] Wygrywa gracz, ktory pierwszy zniszczy wszystkie statki przeciwnika, wyniki sa zapisywanie do plikow tekstowych\n\n";
	char a = '0';
	while (a != '1')
	{
		cout << "Wprowadz '1' aby kontunowac: ";
		cin >> a;
	}
	system("cls");
}