#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <random>
#include <sstream>
#include <algorithm>
#include <functional>


class Object;

/**
* Klasa reprezentuj¹ca argumenty podane przez u¿ytkownika.
*/
class UserArguments
{
	std::string file; /**< Plik wejœciowy podany przez u¿ytkownika. Domyœlnie ustawiony na "owceplik.txt".*/
	int d; /**< Wymiar podany przez u¿ytkownika. Domyœlnie 2.*/
	int m; /**< Iloœæ danych, ile owiec ma siê wygenerowaæ. Domyœlnie 500.*/
	int k; /**< Iloœæ grup (k-œrednich). Domyœlnie 20 grup.*/
	bool w; /**< Flaga okreœlaj¹ca czy uruchomiæ program bez pliku wejœciowego jeœli prawda. Domyœlnie ustawiona na fa³sz.*/
	bool n; /**< Flaga okreœlaj¹ca czy bitmapa ma wyswietlic kropki jeœli prawda, jesli fa³sz to owieczki. Domyœlnie ustawiona na fa³sz.*/
	friend class Simulation; /**< Deklaracja przyjaŸni klasy UserArguments z klas¹ Simulation, aby symulacja wiedzia³a jakie argumenty poda³ u¿ytkownik.*/
public:

	/** Konstruktor inicjalizuj¹cy domyœlne sk³adowe klasy UserArguments.
	*
	*/
	UserArguments(); 

	/** Getter umo¿liwiaj¹cy podgl¹d flagi w, odpowiedzialnej za uruchamianie bez pliku.
	* @return Flagê w.
	*/
	bool getw() const; 

	/** Getter umo¿liwiaj¹cy podgl¹d flagi n, odpowiedzialnej za tworzenie kropek zamiast owieczek w bitmapie.
	* @return Flagê n.
	*/
	bool getn() const;

	/** Metoda wyœwietlaj¹ca instrukcjê w konsoli.
	*
	*/
	void Help(); 

	/** Metoda ustawiaj¹ca sk³adowe klasy na podane przez u¿ytkownika.
	* @param argc Iloœæ argumentów podana przez u¿ytkownika.
	* @param argv Tablica wyrazów jakie podano do konsoli.
	* @return Prawda jeœli uda³o siê ustawiæ oraz fa³sz jeœli wartoœci by³y nie poprawne.
	*/
	bool LoadArguments(int argc, char ** argv); 

	/** Metoda okreœlaj¹ca wymiar w jakim bêdzie realizowany program na podstawie pliku wejœciowego. Ustawia sk³adow¹ d na wymiar jaki rozpozna³.
	*
	*/
	void RecognizeDimension();

	/** Metoda tworz¹ca dane wg sk³adowych obiektu na rzecz którego jest wywo³ywana.
	* @param mode Okreœla co wygenerowaæ ma metoda. Przyjmuje trzy wartoœci 1; 2 lub 3. 1-tworzy tylko owce, 2-tworzy tylko pasterzy, 3-tworzy owce i pasterzy.
	*/
	void CreateData(int mode);

	/** Metoda zamieniaj¹ca plik wejœciowy w wektor danych.
	* @vfile Plik z którego maj¹ zostaæ pobrane dane.
	* @return Wektor obiektów.
	*/
	std::vector<Object*> VectorDanych(const std::string& vfile); 

	/** Metoda wyci¹gaj¹ca z wektora danych pasterzy (centroidów) sugeruj¹c siê nazw¹ obiektu.
	* @param data Wektor z którego maj¹ zostaæ wyci¹gniête obiekty.
	* @return Wektor wyci¹gniêtych centoridów.
	*/
	std::vector<Object*> VectorCentoridowZData(std::vector<Object*>& data); 
};

/** Funkcja sprawdzaj¹ca czy podany tekst sk³ada siê wy³¹cznie ze spacji lub tabulacji.
* @return Prawda jeœli sk³ada siê tylko ze spacji lub tabulacji fa³sz jeœli nie.
*/
bool CheckEmptyLine(std::string line);