#pragma once
#include "Object.h"
#include "Pasterz.h"
#include <sstream>

class ZoorganizowanaGrupaPasterzy;

/**
* Klasa reprezentuj�ca element zestawu danych, zwany owc� czy te� owieczk�. Jest klas� pochodn� po klasie Object, wi�c posiada jej sk�adowe oraz metody.
*/
class Owca : public Object
{
	Pasterz* wlasciciel; /**< Wska�nik informuj�cy, kt�ry pasterz jest w�a�cicielem.*/
public:
	/** Konstruktor inicjalizuj�cy domy�lne sk�adowe obiektu klasy Owca.
	*
	*/
	Owca();

	/** Konstruktor tworz�cy g��bok� kopi� tablicy wsp�rz�dnych oraz inicjalizuj�cy nazw� dla klasy Owca.
	* @param name Nazwa obiektu klasy Owca.
	* @param other Tablica wsp�rz�dnych z kt�rej ma zosta� stworzona g�eboka kopia.
	*/
	Owca(const std::string& name, double* other);

	/** Metoda wirtualna (polimorfizm) s�u��ca do reprezentacji sk�adowych klasy Owca w postaci tekstu. Opr�cz sk�adowych podanych w klasie bazowej wy�wietla r�wnie� w�a�ciciela.
	* @return Tekst opisuj�cy owc�.
	*/
	std::string toString() override;

	/** Metoda szukaj�ca najbli�szego pasterza. Je�li owca znajdzie bli�szego ni� poprzednio to ustawia go jako w�a�ciciela i informuje o tym zwrotem z funkcji.
	* @param pasterze Klasa reprezentuj�ca list� unikalnych wska�nik�w na obiekty klasy Pasterz.
	* @return Zwraca prawd� je�li owieczka zmieni�a swojego poprzedniego w�a�ciciela lub fa�sz je�li nie.
	*/
	bool FindNearestPasterz(const ZoorganizowanaGrupaPasterzy& pasterze);
};

/** Funkcja licz�ca odleg�o�� euklidesow� dla dowolnego wymiaru mi�dzy owc� a pasterzem.
* @param potencjalnyPan Wska�nik na pasterza mi�dzy kt�rym jest liczona odleg�o��.
* @param owca Wska�nik na owc� mi�dzy kt�r� jest liczona odleg�o��.
* @return Odleg�o�� mi�dzy oba obiektami podanymi w parametrach.
*/
double distance(Pasterz* potencjalnyPan, Owca* owca);