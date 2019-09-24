#include "Pasterz.h"
#include "Owca.h"

Pasterz::Pasterz() : Object(), liczba_stadka(0) {};
Pasterz::Pasterz(const std::string& name, double* other) : Object(name, other), liczba_stadka(0) {}

std::string Pasterz::toString()
{
	std::ostringstream d;
	d << "Pasterz zawany "<<name<<"\n" << "Wymiar = " << n << "\n";
	for (int i = 0; i < n; ++i)
	{
		d << x[i]<<"\t";
	}
	d << "\n";
	d << "Liczba stadka: " << liczba_stadka<<"\n";
	return d.str();
}

void Pasterz::FindMiddle()
{
	for (int i = 0; i < n; ++i)
	{
		double suma = 0;
		for (auto it=stadko.begin();it!=stadko.end();++it)
		{
			suma += (*it)->x[i];
		}
		if (liczba_stadka != 0)
		{
			suma = suma / liczba_stadka;
			x[i] = zaokraglij(suma);
		}
	}
}


double zaokraglij(double value)
{
	double precision = 0.01;
	return round(value / precision)*precision;
}

std::string Pasterz::showElementStadka(int i)
{
	std::ostringstream d;
		for (int j = 0; j < n; ++j)
			d << stadko[i]->x[j] << " ";
		d << "\n";
	
	return d.str();
}

std::string Pasterz::showStadko()
{
	std::ostringstream d;
	for (int i = 0; i < liczba_stadka; ++i)
	{
		for(int j=0; j<n; ++j)
			d << stadko[i]->x[j] << " ";
		d << "\n";
	}
	return d.str();
}

void Pasterz::setliczba_stadka(int liczba_stadka) { this->liczba_stadka = liczba_stadka; }
int Pasterz::getliczbastadka() const { return liczba_stadka; }

void Pasterz::deleteStadko()
{
	this->stadko.clear();
}