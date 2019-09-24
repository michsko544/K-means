#pragma once

#include <cstdint>

#pragma pack(2)

namespace bmp
{
	/**
	* Klasa reprezentuj¹ca dane pliku bitmapy takie jak np. rozmiar, rozmiar bez tablicy pikseli czy sygnatura.
	*/
	class BitmapFile
	{
	public:
		char header[2]{ 'B','M' }; /**< Sygnatura pliku okreœlaj¹ca, ¿e bêdzie to bitmapa.*/
		int32_t fileSize; /**< Ca³kowity rozmiar pliku.*/
		int32_t reserved{0}; /**< Sk³adowa rezerwuj¹ca potrzebna do utworzenia pliku.*/
		int32_t dataOffset; /**< Rozmiar pliku bez tablicy pikseli.*/
	};

}