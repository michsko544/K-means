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
* Klasa reprezentuj�ca argumenty podane przez u�ytkownika.
*/
class UserArguments
{
	std::string file; /**< Plik wej�ciowy podany przez u�ytkownika. Domy�lnie ustawiony na "owceplik.txt".*/
	int d; /**< Wymiar podany przez u�ytkownika. Domy�lnie 2.*/
	int m; /**< Ilo�� danych, ile owiec ma si� wygenerowa�. Domy�lnie 500.*/
	int k; /**< Ilo�� grup (k-�rednich). Domy�lnie 20 grup.*/
	bool w; /**< Flaga okre�laj�ca czy uruchomi� program bez pliku wej�ciowego je�li prawda. Domy�lnie ustawiona na fa�sz.*/
	bool n; /**< Flaga okre�laj�ca czy bitmapa ma wyswietlic kropki je�li prawda, jesli fa�sz to owieczki. Domy�lnie ustawiona na fa�sz.*/
	friend class Simulation; /**< Deklaracja przyja�ni klasy UserArguments z klas� Simulation, aby symulacja wiedzia�a jakie argumenty poda� u�ytkownik.*/
public:

	/** Konstruktor inicjalizuj�cy domy�lne sk�adowe klasy UserArguments.
	*
	*/
	UserArguments(); 

	/** Getter umo�liwiaj�cy podgl�d flagi w, odpowiedzialnej za uruchamianie bez pliku.
	* @return Flag� w.
	*/
	bool getw() const; 

	/** Getter umo�liwiaj�cy podgl�d flagi n, odpowiedzialnej za tworzenie kropek zamiast owieczek w bitmapie.
	* @return Flag� n.
	*/
	bool getn() const;

	/** Metoda wy�wietlaj�ca instrukcj� w konsoli.
	*
	*/
	void Help(); 

	/** Metoda ustawiaj�ca sk�adowe klasy na podane przez u�ytkownika.
	* @param argc Ilo�� argument�w podana przez u�ytkownika.
	* @param argv Tablica wyraz�w jakie podano do konsoli.
	* @return Prawda je�li uda�o si� ustawi� oraz fa�sz je�li warto�ci by�y nie poprawne.
	*/
	bool LoadArguments(int argc, char ** argv); 

	/** Metoda okre�laj�ca wymiar w jakim b�dzie realizowany program na podstawie pliku wej�ciowego. Ustawia sk�adow� d na wymiar jaki rozpozna�.
	*
	*/
	void RecognizeDimension();

	/** Metoda tworz�ca dane wg sk�adowych obiektu na rzecz kt�rego jest wywo�ywana.
	* @param mode Okre�la co wygenerowa� ma metoda. Przyjmuje trzy warto�ci 1; 2 lub 3. 1-tworzy tylko owce, 2-tworzy tylko pasterzy, 3-tworzy owce i pasterzy.
	*/
	void CreateData(int mode);

	/** Metoda zamieniaj�ca plik wej�ciowy w wektor danych.
	* @vfile Plik z kt�rego maj� zosta� pobrane dane.
	* @return Wektor obiekt�w.
	*/
	std::vector<Object*> VectorDanych(const std::string& vfile); 

	/** Metoda wyci�gaj�ca z wektora danych pasterzy (centroid�w) sugeruj�c si� nazw� obiektu.
	* @param data Wektor z kt�rego maj� zosta� wyci�gni�te obiekty.
	* @return Wektor wyci�gni�tych centorid�w.
	*/
	std::vector<Object*> VectorCentoridowZData(std::vector<Object*>& data); 
};

/** Funkcja sprawdzaj�ca czy podany tekst sk�ada si� wy��cznie ze spacji lub tabulacji.
* @return Prawda je�li sk�ada si� tylko ze spacji lub tabulacji fa�sz je�li nie.
*/
bool CheckEmptyLine(std::string line);