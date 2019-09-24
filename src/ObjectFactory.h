#pragma once
#include "Object.h"
#include <iostream>
#include <sstream>
#include "Pasterz.h"
#include "Owca.h"
#include <algorithm>

/**
* Klasa reprezentuj�ca generyczn� fabryk� obiekt�w klasy bazowej (Object)
*/
class ObjectFactory
{
public:
	/** Statyczna metoda tworz�ca obiekt wg linii jakiej do niej podamy. Wiedz�c jaki jest wymiar, rozpoznaje czy ma stworzy� obiekt klasy Pasterz czy Owca oraz ustawia ich sk�adowe.
	* @param s Tekst z kt�rego ma zosta� stworzony obiekt.
	* @return Czysty wska�nik na obiekt typu Object.
	*/
	static Object* create(const std::string& s);
};