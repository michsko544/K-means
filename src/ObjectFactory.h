#pragma once
#include "Object.h"
#include <iostream>
#include <sstream>
#include "Pasterz.h"
#include "Owca.h"
#include <algorithm>

/**
* Klasa reprezentuj¹ca generyczn¹ fabrykê obiektów klasy bazowej (Object)
*/
class ObjectFactory
{
public:
	/** Statyczna metoda tworz¹ca obiekt wg linii jakiej do niej podamy. Wiedz¹c jaki jest wymiar, rozpoznaje czy ma stworzyæ obiekt klasy Pasterz czy Owca oraz ustawia ich sk³adowe.
	* @param s Tekst z którego ma zostaæ stworzony obiekt.
	* @return Czysty wskaŸnik na obiekt typu Object.
	*/
	static Object* create(const std::string& s);
};