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
* Klasa reprezentuj¹ca symulacjê programu. Zawiera parê dwóch g³ównych kontenerów danych (stada owiec i grupê pasterzy), które wype³nia, dziêki którym wykonuje najistotniejszy algorytm programu i wed³ug których tworzy pliki wynikowe.
*/
class Simulation
{
protected:
	bool x; /**< Flaga pozwalaj¹ca wykonanie destruktora.*/
public:
	
	std::pair<StadoOwiec*, ZoorganizowanaGrupaPasterzy*> para; /**< Para wkaŸników na kontenery owiec i pasterzy.*/
	
	/** Konstruktor inicjalizuj¹cy domyœlne sk³adowe symulacji.
	*
	*/
	Simulation();

	/** Konstruktor inicjalizuj¹cy parê inn¹ par¹ podan¹ w parametrze.
	* @param para Para gotowych kontenerów z owieczkami oraz pasterzami.
	*/
	Simulation(std::pair<StadoOwiec*, ZoorganizowanaGrupaPasterzy*> para);

	/** Metoda rozpoczynaj¹ca algorytm grupowania owieczek.
	*
	*/
	void Go();

	/** Metoda tworz¹ca plik tekstowy oraz je¿eli program realizowany jest dla dwóch wymiarów to równie¿ tworz¹ca bitmapê.
	* @param output Œcie¿ka do której ma zostaæ zapisany plik wyjœciowy.
	* @param d Jeœli jest prawd¹ zostan¹ na bitmapie narysowane kó³eczka jako dane, jeœli jest fa³szem to owieczki.
	*/
	void CreateFile(const std::string& output, bool d);

	/** Metoda wype³niaj¹ca kontenery wg iloœci podanych w argumentach programu lub wg pliku wejsciowego.
	* @param arg Klasa reprezentuj¹ca argumenty podane przez u¿ytkownika.
	*/
	void CreateContainers(UserArguments& arg);

	/** Setter s³u¿¹cy do ustawienia flagi x w celu pozwolenia na u¿ycie destruktora. 
	* @param x Jeœli prawda to pozwala, jeœli fa³sz to nie.
	*/
	void pozwolenieDestruktor(bool x);

	/** Destruktor symulacji usuwa dynamicznie zaalokowane kontenery StadoOwiec i ZoorganizowanaGrupaPasterzy w momencie gdy mu siê pozwoli. 
	*
	*/
	~Simulation();
};
