#pragma once
#include <iostream>

class Pasterz;

/**
* Klasa abstrakcyjna reprezentuj�ca obiekt posiadaj�cy wsp�rz�dne o danym wymiarze i nazw�. Klasami pochodnymi jest klasa Pasterz oraz klasa Owca.
*/
class Object
{
protected:
	double* x; /**< Tablica liczb zmiennoprzecinkowych podw�jnej precyzji reperezentuj�ca wsp�rz�dne obiekt�w.*/
	std::string name; /**< Nazwa obiektu.*/
	static int n; /**< Wymiar w jakim bedzie realizowany program.*/
	friend class Pasterz; /**< Deklaracja przyja�ni klasy Object z klas� Pasterz. Potrzebna aby obiekt klasy Pasterz m�g� zagl�da� do sk�adowych klasy Owca.*/
public:
	/** Konstruktor inicjalizuj�cy domy�lne sk�adowe obiektu klasy Object.
	*
	*/
	Object();

	/** Konstruktor tworz�cy g��bok� kopi� tablicy wsp�rz�dnych oraz inicjalizuj�cy nazw�.
	* @param name Nazwa obiektu dziedzicz�cego po Object.
	* @param other Tablica wsp�rz�dnych z kt�rej ma zosta� stworzona g�eboka kopia.
	*/
	Object(const std::string& name, double* other);

	/** Domy�lny destruktor klasy Object.
	*
	*/
	~Object();

	/** Metoda czysto wirtualna s�u��ca do reprezentacji sk�adowych danej klasy dziedzicz�cej (Owca lub Pasterz) w postaci tekstu.
	* @return Obliguje metody dziedzicz�ce do zwr�cenia �a�cucha znak�w.
	*/
	virtual std::string toString() = 0;

	/** Statyczny setter s�u��cy ustawiania sk�adowej okre�laj�cej wymiar w jakim program b�dzie realizowany.
	* @param a Warto�� na jak� seter ma ustawi� wymiar.
	*/
	static void setn(int a);

	/** Statyczny getter s�u��cy zajrzenia w jakim wymiarze program b�dzie realizowany.
	* @return Wymiar realizowania programu.
	*/
	static int getn();

	/** Getter s�u��cy do podejrzenia wsp�rz�dnych danego obiektu.
	* @return Wska�nik na tablic� wsp�rz�dnych typu double.
	*/
	double* getx() const;

	/** Getter s�u��cy do podejrzenia nazwy danego obiektu.
	* @return Nazwa obiektu.
	*/
	std::string getname();
};

