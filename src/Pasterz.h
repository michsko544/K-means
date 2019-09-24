#pragma once
#include "Object.h"
#include <sstream>
#include <vector>

class Owca;

/** 
* Klasa reprezentuj�ca element wg kt�rego dzieli si� dane, zwany pasterzem czy te� centroidem. Jest klas� pochodn� po klasie Object, wi�c posiada jej sk�adowe oraz metody.
*/
class Pasterz : public Object
{
	std::vector<Owca*> stadko; /**< Wektor zawieraj�cy wska�niki na owieczki kt�rych pasterz jest w�a�cicielem.*/
	int liczba_stadka; /**< Ilo�� owiec w stadzie.*/
	friend class Owca; /**< Deklaracja przyja�ni klasy Pasterz z klas� Owca. Aby owca przy znalezieniu bli�szego pasterza, u�ywaj�c wska�nika na w�a�ciciela mog�a usun�� siebie ze stadka i zmniejszy� jego liczb�.*/
public:
	/** Konstruktor inicjalizuj�cy domy�lne sk�adowe obiektu klasy Pasterz.
	*
	*/
	Pasterz();
	
	/** Konstruktor tworz�cy g��bok� kopi� tablicy wsp�rz�dnych oraz inicjalizuj�cy nazw� dla klasy Pasterz.
	* @param name Nazwa obiektu klasy Pasterz.
	* @param other Tablica wsp�rz�dnych z kt�rej ma zosta� stworzona g�eboka kopia.
	*/
	Pasterz(const std::string& name, double* other);

	/** Metoda wirtualna (polimorfizm) s�u��ca do reprezentacji sk�adowych klasy Pasterz w postaci tekstu. Opr�cz sk�adowych podanych w klasie bazowej wy�wietla r�wnie� stadko i jego liczb�.
	* @return Tekst opisuj�cy pasterza.
	*/
	std::string toString() override;

	/** Metoda ustawiaj�ca pasterza na �rodkowej pozycji wyliczonej ze �redniej arytmetycznej wsp�rz�dnych ka�dej owieczki z jego stadka.
	*
	*/
	void FindMiddle();

	/** Metoda przedstawiaj�ca owieczk� ze stadka w postaci stringa u�atwiaj�cego wrzucenie danych do bitmapy. 
	* @param i Numer owieczki w stadku.
	* @return Tekst ze wsp�rz�dnymi oddzielony spacjami. 
	*/
	std::string showElementStadka(int i);

	/** Metoda przedstawiaj�ca ca�e stadko w postaci stringa u�atwiaj�cego wrzucenie danych do pliku tekstowego.
	* @return Tekst ze wsp�rz�dnymi oddzielony spacjami i owieczkami oddzielonymi enterami.
	*/
	std::string showStadko();

	/** Setter ustawiaj�cy liczb� stadka.
	* @param liczba_stadka Warto�� jak� chce si� ustawi� jako liczb� stadka.
	*/
	void setliczba_stadka(int liczba_stadka);

	/** Getter umo�liwiaj�cy podgl�d liczby stadka.
	* @return Liczba stadka.
	*/
	int getliczbastadka() const;

	/** Metoda czyszcz�ca wektor stadka. Potrzebna przy symulacji, bo pasterz przy ka�dej iteracji sprawdza jak wygl�da jego stadko na nowo, gdy� si� przesun��.
	*
	*/
	void deleteStadko();
};

/** Funkcja zaokr�glaj�ca liczb� do drugiego miejsca po przecinku.
* @param value Liczba kt�ra ma by� zaokr�glona.
* @return Wynik zaokr�glenia.
*/
double zaokraglij(double value);