#pragma once
#include <string>

namespace bmp
{
	/**
	* Klasa reprezentuj�ca Bitmap�. Okre�la si� w niej jej wymiary, stawia si� dzi�ki niej piksele w konkretnych punktach oraz pozwala na zapisanie do pliku o rozszerzeniu ".bmp" ustawionych pikseli.
	*/
	class Bitmap
	{
		int m_width; /**< Szeroko�� bitmapy. Specyfikuj� ile pixeli ma by� w poziomie.*/
		int m_height; /**< Wysoko�� bitmapy. Specyfikuj� ile pixeli ma by� w pionie.*/
		std::unique_ptr<uint8_t[]> m_pPixel; /**< Unikalny wska�nik na tablic� wszystkich pikseli. Pozwala na ustawienie na konkretnej pozycji(pikselu) danego koloru. Kolor sk�ada si� z trzech uint8_t(red, green, blue (RGB)). Zmieniaj�c warto�ci RGB w zakresie od 0 do 255 mo�na korygowa� kolor.*/

	public:
		/** Konstruktor inicjalizuj�cy domy�lne sk�adowe bitmapy.
		*
		*/
		Bitmap();

		/** Konstruktor inicjalizuj�cy sk�adowe bitmapy.
		* @param width Szeroko�� bitmapy.
		* @param height Wysoko�� bitmapy.
		*/
		Bitmap(int width, int height);

		/** Metoda ustawiaj�ca piksel na danej pozycji.
		* @param x Wsp�rz�dna osi odci�tych na kt�rej ma zostac postawiony piksel.
		* @param y Wsp�rz�dna osi rz�dnych na kt�rej ma zostac postawiony piksel.
		* @param red Warto�� koloru czerwonego zapisana na 8 bitach.
		* @param green Warto�� koloru zielonego zapisana na 8 bitach.
		* @param blue Warto�� koloru niebieskiego zapisana na 8 bitach.
		*/
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

		/** Metoda rysuj�ca okr�g wok� danej pozycji, reprezentuj�cy owieczk� .
		* @param x Wsp�rz�dna osi odci�tych okre�laj�ca �rodkowy piksel.
		* @param y Wsp�rz�dna osi rz�dnych okre�laj�ca �rodkowy piksel.
		* @param red Warto�� koloru czerwonego zapisana na 8 bitach.
		* @param green Warto�� koloru zielonego zapisana na 8 bitach.
		* @param blue Warto�� koloru niebieskiego zapisana na 8 bitach.
		*/
		void circle(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

		/** Metoda rysuj�ca okr�g wok� danej pozycji, reprezentuj�cy pasterza. Okr�g przypomina lekko order.
		* @param x Wsp�rz�dna osi odci�tych okre�laj�ca �rodkowy piksel.
		* @param y Wsp�rz�dna osi rz�dnych okre�laj�ca �rodkowy piksel.
		* @param red Warto�� koloru czerwonego zapisana na 8 bitach.
		* @param green Warto�� koloru zielonego zapisana na 8 bitach.
		* @param blue Warto�� koloru niebieskiego zapisana na 8 bitach.
		*/
		void Pcircle(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

		/** Metoda rysuj�ca owieczk� kt�rej �rodek jest na danej pozycji.
		* @param x Wsp�rz�dna osi odci�tych okre�laj�ca �rodkowy piksel.
		* @param y Wsp�rz�dna osi rz�dnych okre�laj�ca �rodkowy piksel.
		* @param red Warto�� koloru czerwonego zapisana na 8 bitach.
		* @param green Warto�� koloru zielonego zapisana na 8 bitach.
		* @param blue Warto�� koloru niebieskiego zapisana na 8 bitach.
		*/
		void owieczka(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

		/** Metoda tworz�ca plik z tablicy wszystkich pikseli. Tworzy r�wnie� obiekty BitmapInfo i BitmapFile oraz definiuje ich warto�ci, potrzebne do utworzenia pliku. 
		* @param filename Nazwa pliku do kt�rej ma by� zapisana bitmapa.
		* @return Prawd� je�li uda�o si� utworzy� plik lub fa�sz je�li nie.
		*/
		bool write(const std::string& filename);

		/** Domy�lny destruktor bitmapy.
		*
		*/
		~Bitmap();
	};
}
