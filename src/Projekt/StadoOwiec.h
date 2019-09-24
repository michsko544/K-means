#pragma once
#include <list>
#include <memory>
#include "Object.h"
#include "Owca.h"
#include <iostream>
#include <vector>

/**
* Klasa reprezentuj�ca kontener obiekt�w klasy Owca.
*/
class StadoOwiec
{
public:
	std::list<std::unique_ptr<Owca>> lista; /**< Lista owiec.*/

	/** Konstruktor listy owiec. Zamienia wektor w list�.
	* @param sheeps Wektor owiec.
	*/
	StadoOwiec(std::vector<Object*>* sheeps);
};

