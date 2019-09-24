#pragma once
#include "Object.h"
#include "Pasterz.h"
#include <sstream>

class ZoorganizowanaGrupaPasterzy;

/**
* Klasa reprezentuj¹ca element zestawu danych, zwany owc¹ czy te¿ owieczk¹. Jest klas¹ pochodn¹ po klasie Object, wiêc posiada jej sk³adowe oraz metody.
*/
class Owca : public Object
{
	Pasterz* wlasciciel; /**< WskaŸnik informuj¹cy, który pasterz jest w³aœcicielem.*/
public:
	/** Konstruktor inicjalizuj¹cy domyœlne sk³adowe obiektu klasy Owca.
	*
	*/
	Owca();

	/** Konstruktor tworz¹cy g³êbok¹ kopiê tablicy wspó³rzêdnych oraz inicjalizuj¹cy nazwê dla klasy Owca.
	* @param name Nazwa obiektu klasy Owca.
	* @param other Tablica wspó³rzêdnych z której ma zostaæ stworzona g³eboka kopia.
	*/
	Owca(const std::string& name, double* other);

	/** Metoda wirtualna (polimorfizm) s³u¿¹ca do reprezentacji sk³adowych klasy Owca w postaci tekstu. Oprócz sk³adowych podanych w klasie bazowej wyœwietla równie¿ w³aœciciela.
	* @return Tekst opisuj¹cy owcê.
	*/
	std::string toString() override;

	/** Metoda szukaj¹ca najbli¿szego pasterza. Jeœli owca znajdzie bli¿szego ni¿ poprzednio to ustawia go jako w³aœciciela i informuje o tym zwrotem z funkcji.
	* @param pasterze Klasa reprezentuj¹ca listê unikalnych wskaŸników na obiekty klasy Pasterz.
	* @return Zwraca prawdê jeœli owieczka zmieni³a swojego poprzedniego w³aœciciela lub fa³sz jeœli nie.
	*/
	bool FindNearestPasterz(const ZoorganizowanaGrupaPasterzy& pasterze);
};

/** Funkcja licz¹ca odleg³oœæ euklidesow¹ dla dowolnego wymiaru miêdzy owc¹ a pasterzem.
* @param potencjalnyPan WskaŸnik na pasterza miêdzy którym jest liczona odleg³oœæ.
* @param owca WskaŸnik na owcê miêdzy któr¹ jest liczona odleg³oœæ.
* @return Odleg³oœæ miêdzy oba obiektami podanymi w parametrach.
*/
double distance(Pasterz* potencjalnyPan, Owca* owca);