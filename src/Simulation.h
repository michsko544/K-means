#pragma once
#include "ZoorganizowanaGrupaPasterzy.h"
#include "StadoOwiec.h"
#include <fstream>
#include <random>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include "UserArguments.h"


/**
* Klasa reprezentuj�ca symulacj� programu. Zawiera par� dw�ch g��wnych kontener�w danych (stada owiec i grup� pasterzy), kt�re wype�nia, dzi�ki kt�rym wykonuje najistotniejszy algorytm programu i wed�ug kt�rych tworzy pliki wynikowe.
*/
class Simulation
{
protected:
	bool x; /**< Flaga pozwalaj�ca wykonanie destruktora.*/
public:
	
	std::pair<StadoOwiec*, ZoorganizowanaGrupaPasterzy*> para; /**< Para wka�nik�w na kontenery owiec i pasterzy.*/
	
	/** Konstruktor inicjalizuj�cy domy�lne sk�adowe symulacji.
	*
	*/
	Simulation();

	/** Konstruktor inicjalizuj�cy par� inn� par� podan� w parametrze.
	* @param para Para gotowych kontener�w z owieczkami oraz pasterzami.
	*/
	Simulation(std::pair<StadoOwiec*, ZoorganizowanaGrupaPasterzy*> para);

	/** Metoda rozpoczynaj�ca algorytm grupowania owieczek.
	*
	*/
	void Go();

	/** Metoda tworz�ca plik tekstowy oraz je�eli program realizowany jest dla dw�ch wymiar�w to r�wnie� tworz�ca bitmap�.
	* @param output �cie�ka do kt�rej ma zosta� zapisany plik wyj�ciowy.
	* @param d Je�li jest prawd� zostan� na bitmapie narysowane k�eczka jako dane, je�li jest fa�szem to owieczki.
	*/
	void CreateFile(const std::string& output, bool d);

	/** Metoda wype�niaj�ca kontenery wg ilo�ci podanych w argumentach programu lub wg pliku wejsciowego.
	* @param arg Klasa reprezentuj�ca argumenty podane przez u�ytkownika.
	*/
	void CreateContainers(UserArguments& arg);

	/** Setter s�u��cy do ustawienia flagi x w celu pozwolenia na u�ycie destruktora. 
	* @param x Je�li prawda to pozwala, je�li fa�sz to nie.
	*/
	void pozwolenieDestruktor(bool x);

	/** Destruktor symulacji usuwa dynamicznie zaalokowane kontenery StadoOwiec i ZoorganizowanaGrupaPasterzy w momencie gdy mu si� pozwoli. 
	*
	*/
	~Simulation();
};
