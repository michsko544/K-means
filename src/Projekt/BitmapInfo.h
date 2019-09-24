#pragma once

#include <cstdint>

#pragma pack(2)

namespace bmp
{
	/**
	* Klasa reprezentuj�ca dane potrzebne do stworzenia bitmapy (bity na piksel, szeroko��, wysoko��). W wi�kszo�ci inicjalizowane domy�lnie �eby m�c okre�li� rozmiar pliku. Jedynie szeroko�� i wysoko�� jest przypisywana potem, aby m�c obliczy� rozmiar z tablic� pikseli i bez tablicy.
	*/
	class BitmapInfo
	{
	public:
		int32_t headerSize{ 40 };
		int32_t width;
		int32_t height;
		int16_t planes{ 1 };
		int16_t bitsPerPixel{24};
		int32_t compression{0};
		int32_t dataSize{0};
		int32_t horizontalResolution{2400};
		int32_t verticalResolution{2400};
		int32_t colors{0};
		int32_t importantColors{0};
	};
}