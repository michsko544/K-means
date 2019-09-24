#pragma once
#include "Object.h"
#include <sstream>
#include <vector>

class Owca;

/** 
* Klasa reprezentuj¹ca element wg którego dzieli siê dane, zwany pasterzem czy te¿ centroidem. Jest klas¹ pochodn¹ po klasie Object, wiêc posiada jej sk³adowe oraz metody.
*/
class Pasterz : public Object
{
	std::vector<Owca*> stadko; /**< Wektor zawieraj¹cy wskaŸniki na owieczki których pasterz jest w³aœcicielem.*/
	int liczba_stadka; /**< Iloœæ owiec w stadzie.*/
	friend class Owca; /**< Deklaracja przyjaŸni klasy Pasterz z klas¹ Owca. Aby owca przy znalezieniu bli¿szego pasterza, u¿ywaj¹c wskaŸnika na w³aœciciela mog³a usun¹æ siebie ze stadka i zmniejszyæ jego liczbê.*/
public:
	/** Konstruktor inicjalizuj¹cy domyœlne sk³adowe obiektu klasy Pasterz.
	*
	*/
	Pasterz();
	
	/** Konstruktor tworz¹cy g³êbok¹ kopiê tablicy wspó³rzêdnych oraz inicjalizuj¹cy nazwê dla klasy Pasterz.
	* @param name Nazwa obiektu klasy Pasterz.
	* @param other Tablica wspó³rzêdnych z której ma zostaæ stworzona g³eboka kopia.
	*/
	Pasterz(const std::string& name, double* other);

	/** Metoda wirtualna (polimorfizm) s³u¿¹ca do reprezentacji sk³adowych klasy Pasterz w postaci tekstu. Oprócz sk³adowych podanych w klasie bazowej wyœwietla równie¿ stadko i jego liczbê.
	* @return Tekst opisuj¹cy pasterza.
	*/
	std::string toString() override;

	/** Metoda ustawiaj¹ca pasterza na œrodkowej pozycji wyliczonej ze œredniej arytmetycznej wspó³rzêdnych ka¿dej owieczki z jego stadka.
	*
	*/
	void FindMiddle();

	/** Metoda przedstawiaj¹ca owieczkê ze stadka w postaci stringa u³atwiaj¹cego wrzucenie danych do bitmapy. 
	* @param i Numer owieczki w stadku.
	* @return Tekst ze wspó³rzêdnymi oddzielony spacjami. 
	*/
	std::string showElementStadka(int i);

	/** Metoda przedstawiaj¹ca ca³e stadko w postaci stringa u³atwiaj¹cego wrzucenie danych do pliku tekstowego.
	* @return Tekst ze wspó³rzêdnymi oddzielony spacjami i owieczkami oddzielonymi enterami.
	*/
	std::string showStadko();

	/** Setter ustawiaj¹cy liczbê stadka.
	* @param liczba_stadka Wartoœæ jak¹ chce siê ustawiæ jako liczbê stadka.
	*/
	void setliczba_stadka(int liczba_stadka);

	/** Getter umo¿liwiaj¹cy podgl¹d liczby stadka.
	* @return Liczba stadka.
	*/
	int getliczbastadka() const;

	/** Metoda czyszcz¹ca wektor stadka. Potrzebna przy symulacji, bo pasterz przy ka¿dej iteracji sprawdza jak wygl¹da jego stadko na nowo, gdy¿ siê przesun¹³.
	*
	*/
	void deleteStadko();
};

/** Funkcja zaokr¹glaj¹ca liczbê do drugiego miejsca po przecinku.
* @param value Liczba która ma byæ zaokr¹glona.
* @return Wynik zaokr¹glenia.
*/
double zaokraglij(double value);