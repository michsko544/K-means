#pragma once
#include <string>

namespace bmp
{
	/**
	* Klasa reprezentuj¹ca Bitmapê. Okreœla siê w niej jej wymiary, stawia siê dziêki niej piksele w konkretnych punktach oraz pozwala na zapisanie do pliku o rozszerzeniu ".bmp" ustawionych pikseli.
	*/
	class Bitmap
	{
		int m_width; /**< Szerokoœæ bitmapy. Specyfikujê ile pixeli ma byæ w poziomie.*/
		int m_height; /**< Wysokoœæ bitmapy. Specyfikujê ile pixeli ma byæ w pionie.*/
		std::unique_ptr<uint8_t[]> m_pPixel; /**< Unikalny wskaŸnik na tablicê wszystkich pikseli. Pozwala na ustawienie na konkretnej pozycji(pikselu) danego koloru. Kolor sk³ada siê z trzech uint8_t(red, green, blue (RGB)). Zmieniaj¹c wartoœci RGB w zakresie od 0 do 255 mo¿na korygowaæ kolor.*/

	public:
		/** Konstruktor inicjalizuj¹cy domyœlne sk³adowe bitmapy.
		*
		*/
		Bitmap();

		/** Konstruktor inicjalizuj¹cy sk³adowe bitmapy.
		* @param width Szerokoœæ bitmapy.
		* @param height Wysokoœæ bitmapy.
		*/
		Bitmap(int width, int height);

		/** Metoda ustawiaj¹ca piksel na danej pozycji.
		* @param x Wspó³rzêdna osi odciêtych na której ma zostac postawiony piksel.
		* @param y Wspó³rzêdna osi rzêdnych na której ma zostac postawiony piksel.
		* @param red Wartoœæ koloru czerwonego zapisana na 8 bitach.
		* @param green Wartoœæ koloru zielonego zapisana na 8 bitach.
		* @param blue Wartoœæ koloru niebieskiego zapisana na 8 bitach.
		*/
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

		/** Metoda rysuj¹ca okr¹g wokó³ danej pozycji, reprezentuj¹cy owieczkê .
		* @param x Wspó³rzêdna osi odciêtych okreœlaj¹ca œrodkowy piksel.
		* @param y Wspó³rzêdna osi rzêdnych okreœlaj¹ca œrodkowy piksel.
		* @param red Wartoœæ koloru czerwonego zapisana na 8 bitach.
		* @param green Wartoœæ koloru zielonego zapisana na 8 bitach.
		* @param blue Wartoœæ koloru niebieskiego zapisana na 8 bitach.
		*/
		void circle(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

		/** Metoda rysuj¹ca okr¹g wokó³ danej pozycji, reprezentuj¹cy pasterza. Okr¹g przypomina lekko order.
		* @param x Wspó³rzêdna osi odciêtych okreœlaj¹ca œrodkowy piksel.
		* @param y Wspó³rzêdna osi rzêdnych okreœlaj¹ca œrodkowy piksel.
		* @param red Wartoœæ koloru czerwonego zapisana na 8 bitach.
		* @param green Wartoœæ koloru zielonego zapisana na 8 bitach.
		* @param blue Wartoœæ koloru niebieskiego zapisana na 8 bitach.
		*/
		void Pcircle(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

		/** Metoda rysuj¹ca owieczkê której œrodek jest na danej pozycji.
		* @param x Wspó³rzêdna osi odciêtych okreœlaj¹ca œrodkowy piksel.
		* @param y Wspó³rzêdna osi rzêdnych okreœlaj¹ca œrodkowy piksel.
		* @param red Wartoœæ koloru czerwonego zapisana na 8 bitach.
		* @param green Wartoœæ koloru zielonego zapisana na 8 bitach.
		* @param blue Wartoœæ koloru niebieskiego zapisana na 8 bitach.
		*/
		void owieczka(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

		/** Metoda tworz¹ca plik z tablicy wszystkich pikseli. Tworzy równie¿ obiekty BitmapInfo i BitmapFile oraz definiuje ich wartoœci, potrzebne do utworzenia pliku. 
		* @param filename Nazwa pliku do której ma byæ zapisana bitmapa.
		* @return Prawdê jeœli uda³o siê utworzyæ plik lub fa³sz jeœli nie.
		*/
		bool write(const std::string& filename);

		/** Domyœlny destruktor bitmapy.
		*
		*/
		~Bitmap();
	};
}
