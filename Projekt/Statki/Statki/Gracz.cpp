#include "Gracz.h"


Gracz::Gracz(Mapa mapa, int pkt) : rozstawienia(mapa), punktacja(pkt) {};

int Gracz::zwrocPunkty()
{
	return punktacja;
}

void Gracz::edytujPunkty(int pkt)
{
	punktacja += pkt;
}

void Gracz::ZapiszDoPlikuGracza1(fstream& plik)
{
	plik.open("Gracz1.txt", ios::out);
	if (plik.good())
		plik << "Gracz1\n---------------\nPunkty: " << punktacja;
	else
	{
		cout << "Nie udalo sie otworzyc pliku";
	}
}

void Gracz::ZapiszDoPlikuGracza2(fstream& plik)
{
	plik.open("Gracz2.txt", ios::out);
	if (plik.good())
		plik << "Gracz2\n---------------\nPunkty: " << punktacja;
	else
	{
		cout << "Nie udalo sie otworzyc pliku";
	}
}


void  Gracz::zarzadajRozgrywka(Gracz gracz2, fstream& g1, fstream& g2)
{
	this->rozstawienia.zapiszMape(rozstawienia.zwrocMapeStatkow());
	this->rozstawienia.zapiszMapeStrzalow(rozstawienia.zwrocMapeTrafien());
	gracz2.rozstawienia.zapiszMape(gracz2.rozstawienia.zwrocMapeStatkow());
	gracz2.rozstawienia.zapiszMapeStrzalow(gracz2.rozstawienia.zwrocMapeTrafien());
	while (true)
	{

		cout << "Gracz 1:\n\n" << "Punkty: " << this->zwrocPunkty() << endl << endl;
		rozstawienia.wypiszMape(rozstawienia.zwrocMapeStatkow());
		cout << endl << endl;
		rozstawienia.wypiszMape(rozstawienia.zwrocMapeTrafien());
		this->punktacja += rozstawienia.strzal(gracz2.rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
		rozstawienia.przejdzDalej();
		cout << "Gracz 1:\n\n" << "Punkty: " << this->zwrocPunkty() << endl << endl;
		rozstawienia.wypiszMape(rozstawienia.zwrocMapeStatkow());
		cout << endl << endl;
		rozstawienia.wypiszMape(rozstawienia.zwrocMapeTrafien());
		rozstawienia.przejdzDalej();
		if (rozstawienia.zwrocrozmiar() == 4)
		{
			if (this->zwrocPunkty() == 20)
			{
				system("cls");
				cout << "Gracz1 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
			else if (gracz2.zwrocPunkty() == 20)
			{
				system("cls");
				cout << "Gracz2 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
		}
		else if (this->rozstawienia.zwrocrozmiar() == 6)
		{
			if (this->zwrocPunkty() == 29)
			{
				system("cls");
				cout << "Gracz1 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
			else if (gracz2.zwrocPunkty() == 29)
			{
				system("cls");
				cout << "Gracz2 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
		}
		else if (this->rozstawienia.zwrocrozmiar() == 10)
		{
			if (this->zwrocPunkty() == 34)
			{
				system("cls");
				cout << "Gracz1 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
			else if (gracz2.zwrocPunkty() == 34)
			{
				system("cls");
				cout << "Gracz2 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
		}
		cout << "Gracz 2:\n\n" << "Punkty: " << gracz2;;
		gracz2.rozstawienia.wypiszMape(gracz2.rozstawienia.zwrocMapeStatkow());
		cout << endl << endl;
		gracz2.rozstawienia.wypiszMape(gracz2.rozstawienia.zwrocMapeTrafien());
		gracz2+=((gracz2.rozstawienia.strzal(this->rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien())));
		gracz2.rozstawienia.przejdzDalej();
		cout << "Gracz 2:\n\n" << "Punkty: " << gracz2;
		gracz2.rozstawienia.wypiszMape(gracz2.rozstawienia.zwrocMapeStatkow());
		cout << endl << endl;
		gracz2.rozstawienia.wypiszMape(gracz2.rozstawienia.zwrocMapeTrafien());
		gracz2.rozstawienia.przejdzDalej();
		if (rozstawienia.zwrocrozmiar() == 4)
		{
			if (this->zwrocPunkty() == 20)
			{
				system("cls");
				cout << "Gracz1 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
			else if (gracz2.zwrocPunkty() == 20)
			{
				system("cls");
				cout << "Gracz2 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
		}
		else if (this->rozstawienia.zwrocrozmiar() == 6)
		{
			if (this->zwrocPunkty() == 29)
			{
				system("cls");
				cout << "Gracz1 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
			else if (gracz2.zwrocPunkty() == 29)
			{
				system("cls");
				cout << "Gracz2 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
		}
		else if (this->rozstawienia.zwrocrozmiar() == 10)
		{
			if (this->zwrocPunkty() == 34)
			{
				system("cls");
				cout << "Gracz1 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
			else if (gracz2.zwrocPunkty() == 34)
			{
				system("cls");
				cout << "Gracz2 wygrywa!" << endl;
				this->ZapiszDoPlikuGracza1(g1);
				rozstawienia.wypiszDoPliku(g1, rozstawienia.zwrocMapeStatkow(), rozstawienia.zwrocMapeTrafien());
				gracz2.ZapiszDoPlikuGracza2(g2);
				gracz2.rozstawienia.wypiszDoPliku(g2, gracz2.rozstawienia.zwrocMapeStatkow(), gracz2.rozstawienia.zwrocMapeTrafien());
				break;
			}
		}
	}
	this->rozstawienia.zwalnianiePamieci(this->rozstawienia.zwrocMapeStatkow());
	this->rozstawienia.zwalnianiePamieci(this->rozstawienia.zwrocMapeTrafien());
	gracz2.rozstawienia.zwalnianiePamieci(gracz2.rozstawienia.zwrocMapeStatkow());
	gracz2.rozstawienia.zwalnianiePamieci(gracz2.rozstawienia.zwrocMapeTrafien());
}

Gracz& Gracz::operator+=(int pkt)
{
	this->punktacja += pkt;
	return *this;
}

ostream& operator<<(ostream& stream, const Gracz& s)
{
	stream << s.punktacja << endl << endl;
	return stream;
}


Gracz::~Gracz()
{

}

