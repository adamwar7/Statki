/** @file */
#pragma once
#include <iostream>
#include "Gracz.h"
#include "Mapa.h"
#include "RodzajeStatkow.h"
#include "StrukturyDanych.h"


/** Funkcja wypisuje instrukcje dla uzytkownikow.
*/
void instrukcja();

/** Funkcja odpowiada za wprowadzenie uproszczonego rozmiaru podanego przez uzytkownika
@return uproszczony rozmiar
*/
char podajRozmiar();

/** Funkcja zamienia uproszczony rozmiar mapy rozgrywki, na prawdziwy.
@param fakerozmiar uproszczony rozmiar mapy
@return prawdziwy rozmiar mapy
*/
int zwrocPrawdziwyRozmiar(char fakerozmiar);


