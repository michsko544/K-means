#include "Owca.h"
#include "ZoorganizowanaGrupaPasterzy.h"


Owca::Owca() : Object(), wlasciciel(nullptr) {}
Owca::Owca(const std::string& name, double* other) : Object(name, other), wlasciciel(nullptr) {}

std::string Owca::toString()
{
	std::ostringstream d;
	d << "Owca\n" << "Wymiar = " << n<<"\n";
	for (int i = 0; i < n; ++i)
	{
		d << x[i] << "\t";
	}
	d << "\n";
	d << "Najblizszy pasterz:\n"<< wlasciciel->toString()<<"\n";
	return d.str();
}

bool Owca::FindNearestPasterz(const ZoorganizowanaGrupaPasterzy& pasterze)
{
	bool f = 0;
	double min;
	double tmp;
	Pasterz* old_wlasciciel = wlasciciel;
	Pasterz* adoptator=nullptr;
	for (auto it = pasterze.lista.begin(); it != pasterze.lista.end(); ++it)
	{
		if (f == 0)
		{
			adoptator = &**it;
			min = distance(adoptator, this);
			f = !f;
		}
		tmp = distance(&**it, this);
		if (tmp < min)
		{
			adoptator = &**it;
			min = tmp;
		}
	}
	wlasciciel=adoptator;
	wlasciciel->stadko.emplace_back(this);
	wlasciciel->liczba_stadka++;
	if (wlasciciel == old_wlasciciel)
		return 0;
	else
		return 1;
}

double distance(Pasterz* potencjalnyPan, Owca* owca)
{
	double suma = 0;
	for (int i = 0; i < owca->getn(); ++i)
	{
		suma += (potencjalnyPan->getx()[i] - owca->getx()[i])*(potencjalnyPan->getx()[i] - owca->getx()[i]);
	}
	return sqrt(suma);
}