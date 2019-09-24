#pragma once
#include <iostream>

class Pasterz;

/**
* Klasa abstrakcyjna reprezentuj¹ca obiekt posiadaj¹cy wspó³rzêdne o danym wymiarze i nazwê. Klasami pochodnymi jest klasa Pasterz oraz klasa Owca.
*/
class Object
{
protected:
	double* x; /**< Tablica liczb zmiennoprzecinkowych podwójnej precyzji reperezentuj¹ca wspó³rzêdne obiektów.*/
	std::string name; /**< Nazwa obiektu.*/
	static int n; /**< Wymiar w jakim bedzie realizowany program.*/
	friend class Pasterz; /**< Deklaracja przyjaŸni klasy Object z klas¹ Pasterz. Potrzebna aby obiekt klasy Pasterz móg³ zagl¹daæ do sk³adowych klasy Owca.*/
public:
	/** Konstruktor inicjalizuj¹cy domyœlne sk³adowe obiektu klasy Object.
	*
	*/
	Object();

	/** Konstruktor tworz¹cy g³êbok¹ kopiê tablicy wspó³rzêdnych oraz inicjalizuj¹cy nazwê.
	* @param name Nazwa obiektu dziedzicz¹cego po Object.
	* @param other Tablica wspó³rzêdnych z której ma zostaæ stworzona g³eboka kopia.
	*/
	Object(const std::string& name, double* other);

	/** Domyœlny destruktor klasy Object.
	*
	*/
	~Object();

	/** Metoda czysto wirtualna s³u¿¹ca do reprezentacji sk³adowych danej klasy dziedzicz¹cej (Owca lub Pasterz) w postaci tekstu.
	* @return Obliguje metody dziedzicz¹ce do zwrócenia ³añcucha znaków.
	*/
	virtual std::string toString() = 0;

	/** Statyczny setter s³u¿¹cy ustawiania sk³adowej okreœlaj¹cej wymiar w jakim program bêdzie realizowany.
	* @param a Wartoœæ na jak¹ seter ma ustawiæ wymiar.
	*/
	static void setn(int a);

	/** Statyczny getter s³u¿¹cy zajrzenia w jakim wymiarze program bêdzie realizowany.
	* @return Wymiar realizowania programu.
	*/
	static int getn();

	/** Getter s³u¿¹cy do podejrzenia wspó³rzêdnych danego obiektu.
	* @return WskaŸnik na tablicê wspó³rzêdnych typu double.
	*/
	double* getx() const;

	/** Getter s³u¿¹cy do podejrzenia nazwy danego obiektu.
	* @return Nazwa obiektu.
	*/
	std::string getname();
};

