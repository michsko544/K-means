#pragma once
#include <list>
#include <memory>
#include <iostream>
#include "Object.h"
#include "Simulation.h"
#include <vector>

/**
* Klasa reprezentuj�ca kontener obiekt�w klasy Pasterz.
*/
class ZoorganizowanaGrupaPasterzy
{
public:
	std::list<std::unique_ptr<Pasterz>> lista; /**< Lista pasterzy.*/
	
	/** Konstruktor listy pasterzy. Zamienia wektor w list�.
	* @param pastors Wektor pasterzy.
	*/
	ZoorganizowanaGrupaPasterzy(std::vector<Object*>* pastors);
};