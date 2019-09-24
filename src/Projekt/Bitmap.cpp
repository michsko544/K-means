#include "Bitmap.h"
#include "BitmapInfo.h"
#include "BitmapFile.h"
#include <fstream>

using namespace bmp;

Bitmap::Bitmap() : m_width(0), m_height(0), m_pPixel(nullptr){}

Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixel(new uint8_t[width*height*3]()) {}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t* pPixel = m_pPixel.get();

	pPixel += (y*3) * m_width + (x*3);

	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

void Bitmap::circle(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	this->setPixel(x+2, y+1, red, green, blue);
	this->setPixel(x+2, y-1, red, green, blue);
	this->setPixel(x+2, y, red, green, blue);
	this->setPixel(x-2, y+1, red, green, blue);
	this->setPixel(x-2, y-1, red, green, blue);
	this->setPixel(x-2, y, red, green, blue);
	this->setPixel(x+1, y+2, red, green, blue);
	this->setPixel(x-1, y+2, red, green, blue);
	this->setPixel(x, y+2, red, green, blue);
	this->setPixel(x+1, y-2, red, green, blue);
	this->setPixel(x-1, y-2, red, green, blue);
	this->setPixel(x, y-2, red, green, blue);

}

void Bitmap::Pcircle(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	this->setPixel(x + 2, y + 1, red, green, blue);
	this->setPixel(x + 2, y - 1, red, green, blue);
	this->setPixel(x + 2, y, red, green, blue);
	this->setPixel(x - 2, y + 1, red, green, blue);
	this->setPixel(x - 2, y - 1, red, green, blue);
	this->setPixel(x - 2, y, red, green, blue);
	this->setPixel(x + 1, y + 2, red, green, blue);
	this->setPixel(x - 1, y + 2, red, green, blue);
	this->setPixel(x, y + 2, red, green, blue);
	this->setPixel(x + 1, y - 2, red, green, blue);
	this->setPixel(x - 1, y - 2, red, green, blue);
	this->setPixel(x, y - 2, red, green, blue);
	this->setPixel(x+1, y-1, red, green, blue);
	this->setPixel(x-1, y+1, red, green, blue);
	this->setPixel(x-1, y-1, red, green, blue);
	this->setPixel(x+1, y+1, red, green, blue);
	this->setPixel(x, y, 255, 255, 255);
	this->setPixel(x + 1, y, red, green, blue);
	this->setPixel(x - 1, y, red, green, blue);
	this->setPixel(x, y - 1, red, green, blue);
	this->setPixel(x, y + 1, red, green, blue);
	this->setPixel(x, y+3, 255, 255, 255);
	this->setPixel(x-1, y + 3, 255, 255, 255);
	this->setPixel(x+1, y + 3, 255, 255, 255);
	this->setPixel(x, y - 3, 255, 255, 255);
	this->setPixel(x - 1, y - 3, 255, 255, 255);
	this->setPixel(x + 1, y - 3, 255, 255, 255);
	this->setPixel(x - 3, y, 255, 255, 255);
	this->setPixel(x - 3, y-1, 255, 255, 255);
	this->setPixel(x - 3, y + 1, 255, 255, 255);
	this->setPixel(x + 3, y, 255, 255, 255);
	this->setPixel(x + 3, y - 1, 255, 255, 255);
	this->setPixel(x + 3, y + 1, 255, 255, 255);

}

void Bitmap::owieczka(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	//prawo
	this->setPixel(x + 7, y, 0,0,0);
	this->setPixel(x + 7, y - 1, 0,0,0);
	this->setPixel(x + 7, y - 2, 0,0,0);
	this->setPixel(x + 7, y + 1, 0,0,0);
	this->setPixel(x + 7, y + 2, 0,0,0);
	this->setPixel(x + 7, y + 3, 0,0,0);
	//lewo
	this->setPixel(x - 7, y, 0,0,0);
	this->setPixel(x - 7, y - 1, 0,0,0);
	this->setPixel(x - 7, y - 2, 0,0,0);
	this->setPixel(x - 7, y + 1, 0,0,0);
	this->setPixel(x - 7, y + 2, 0,0,0);
	this->setPixel(x - 7, y + 3, 0,0,0);
	//gorny skos prawy
	this->setPixel(x + 6, y + 4, 0,0,0);
	this->setPixel(x + 5, y + 5, 0,0,0);
	this->setPixel(x+4, y + 6, 0,0,0);
	this->setPixel(x + 3, y +7, 0,0,0);
	//dolny skos lewy
	this->setPixel(x - 6, y + 4, 0,0,0);
	this->setPixel(x - 5, y + 5, 0,0,0);
	this->setPixel(x - 4, y + 6, 0,0,0);
	this->setPixel(x - 3, y + 7, 0,0,0);
	//gora
	this->setPixel(x + 2, y +7, 0,0,0);
	this->setPixel(x+1, y + 7, 0,0,0);
	this->setPixel(x - 2, y + 7, 0,0,0);
	this->setPixel(x - 1, y + 7, 0,0,0);
	this->setPixel(x , y + 7, 0,0,0);
	//g³owa
	this->setPixel(x + 1, y - 1, 0,0,0);
	this->setPixel(x, y - 1, 0,0,0);
	this->setPixel(x - 1, y - 1, 0,0,0);
	this->setPixel(x + 2, y, 0,0,0);
	this->setPixel(x + 1, y, 0,0,0);
	this->setPixel(x - 1, y, 0,0,0);
	this->setPixel(x, y, 0,0,0);
	this->setPixel(x-2, y, 0,0,0);
	this->setPixel(x + 2, y+1, 0,0,0);
	this->setPixel(x + 1, y+1, 0,0,0);
	this->setPixel(x - 1, y+1, 0,0,0);
	this->setPixel(x, y+1, 0,0,0);
	this->setPixel(x - 2, y+1, 0,0,0);
	this->setPixel(x + 2, y + 2, 0,0,0);
	this->setPixel(x + 1, y + 2, 0,0,0);
	this->setPixel(x - 1, y + 2, 0,0,0);
	this->setPixel(x, y + 2, 0,0,0);
	this->setPixel(x - 2, y + 2, 0,0,0);

	this->setPixel(x + 2, y + 3, 0,0,0);
	this->setPixel(x + 3, y + 3, 0,0,0);
	this->setPixel(x - 3, y + 3, 0,0,0);
	this->setPixel(x, y + 3, 0,0,0);
	this->setPixel(x - 2, y + 3, 0,0,0);
	this->setPixel(x + 4, y + 3, 0,0,0);
	this->setPixel(x - 4, y + 3, 0,0,0);

	this->setPixel(x + 2, y + 4, 0,0,0);
	this->setPixel(x + 1, y + 4, 0,0,0);
	this->setPixel(x - 1, y + 4, 0,0,0);
	this->setPixel(x, y + 4, 0,0,0);
	this->setPixel(x - 2, y + 4, 0,0,0);
	//oczy
	this->setPixel(x+1, y+3, 243, 250, 242);
	this->setPixel(x-1, y+3, 243, 250, 242);
	//nogi
	this->setPixel(x , y - 6, 0,0,0);
	this->setPixel(x , y - 7, 0,0,0);
	this->setPixel(x , y - 8, 0,0,0);
	this->setPixel(x + 1, y - 8, 0,0,0);
	this->setPixel(x -1, y -8, 0,0,0);
	this->setPixel(x + 2, y - 8, 0,0,0);
	this->setPixel(x - 2, y - 8, 0,0,0);
	this->setPixel(x - 2, y - 7, 0,0,0);
	this->setPixel(x + 2, y - 7, 0,0,0);
	this->setPixel(x + 2, y - 6, 0,0,0);
	this->setPixel(x - 2, y - 6, 0,0,0);
	//skos prawy dolny
	this->setPixel(x + 3, y - 6, 0,0,0);
	this->setPixel(x + 4, y - 5, 0,0,0);
	this->setPixel(x + 5, y - 5, 0,0,0);
	this->setPixel(x + 6, y - 4, 0,0,0);
	this->setPixel(x + 6, y - 3, 0,0,0);
	//skos lewy dolny
	this->setPixel(x - 3, y - 6, 0,0,0);
	this->setPixel(x - 4, y - 5, 0,0,0);
	this->setPixel(x - 5, y - 5, 0,0,0);
	this->setPixel(x - 6, y - 4, 0,0,0);
	this->setPixel(x - 6, y - 3, 0,0,0);
	//futerko szare
	int a=red-70, b=green-70, c=blue-70;
	if (a < 0)
		a = 0;
	if (b < 0)
		b = 0;
	if (c < 0)
		c = 0;
	this->setPixel(x + 5 , y, a,b,c);
	this->setPixel(x + 6, y, a, b, c);
	this->setPixel(x + 5, y + 1, a,b,c);
	this->setPixel(x + 6, y + 1, a,b,c);
	this->setPixel(x + 5, y + 2, a,b,c);
	this->setPixel(x + 6, y + 2, a,b,c);
	this->setPixel(x + 5, y + 3, a,b,c);
	this->setPixel(x + 6, y + 3, a,b,c);
	this->setPixel(x + 5, y - 1, a,b,c);
	this->setPixel(x + 6, y - 1, a,b,c);
	this->setPixel(x + 4, y - 1, a,b,c);
	this->setPixel(x + 5, y - 2, a,b,c);
	this->setPixel(x + 6, y - 2, a,b,c);
	this->setPixel(x + 4, y - 2, a,b,c);
	this->setPixel(x + 5, y - 3, a,b,c);
	this->setPixel(x + 3, y - 3, a,b,c);
	this->setPixel(x + 4, y - 3, a,b,c);
	this->setPixel(x + 5, y - 4, a,b,c);
	this->setPixel(x + 3, y - 4, a,b,c);
	this->setPixel(x + 4, y - 4, a,b,c);
	this->setPixel(x + 2, y - 4, a,b,c);
	this->setPixel(x + 1, y - 4, a,b,c);
	this->setPixel(x - 1, y - 4, a,b,c);
	this->setPixel(x - 4, y - 4, a,b,c);
	this->setPixel(x - 5, y - 4, a,b,c);
	this->setPixel(x - 3, y - 5, a,b,c);
	this->setPixel(x - 3, y - 5, a,b,c);
	this->setPixel(x - 2, y - 5, a,b,c);
	this->setPixel(x - 1, y - 5, a,b,c);
	this->setPixel(x, y - 5, a,b,c);
	this->setPixel(x + 1, y - 5, a,b,c);
	this->setPixel(x + 2, y - 5, a,b,c);
	this->setPixel(x + 3, y - 5, a,b,c);
	this->setPixel(x - 1, y - 6, a,b,c);
	this->setPixel(x - 1, y - 7, a,b,c);
	this->setPixel(x + 1, y - 6, a,b,c);
	this->setPixel(x + 1, y - 7, a,b,c);
	this->setPixel(x - 5, y - 3, a,b,c);
	this->setPixel(x - 6, y - 1, a,b,c);
	this->setPixel(x - 6, y - 2, a,b,c);
	this->setPixel(x - 6, y + 3, a,b,c);
	this->setPixel(x - 5, y + 4, a,b,c);
	this->setPixel(x - 3, y + 6, a,b,c);
	this->setPixel(x + 3, y + 6, a,b,c);
	this->setPixel(x + 5, y + 4, a,b,c);

	//biale futerko
	this->setPixel(x-2, y+6, red,green,blue);
	this->setPixel(x - 1, y + 6, red, green, blue);
	this->setPixel(x , y + 6, red, green, blue);
	this->setPixel(x + 1, y + 6, red, green, blue);
	this->setPixel(x + 2, y + 6, red, green, blue);
	this->setPixel(x - 2, y + 5, red, green, blue);
	this->setPixel(x - 1, y + 5, red, green, blue);
	this->setPixel(x, y + 5, red, green, blue);
	this->setPixel(x + 1, y + 5, red, green, blue);
	this->setPixel(x + 2, y + 5, red, green, blue);
	this->setPixel(x + 3, y + 5, red, green, blue);
	this->setPixel(x - 3, y + 5, red, green, blue);
	this->setPixel(x + 4, y + 5, red, green, blue);
	this->setPixel(x - 4, y + 5, red, green, blue);
	this->setPixel(x + 3, y + 4, red, green, blue);
	this->setPixel(x - 3, y + 4, red, green, blue);
	this->setPixel(x + 4, y + 4, red, green, blue);
	this->setPixel(x - 4, y + 4, red, green, blue);
	this->setPixel(x - 5, y + 3, red, green, blue);
	this->setPixel(x - 6, y + 2, red, green, blue);
	this->setPixel(x - 5, y + 2, red, green, blue);
	this->setPixel(x - 4, y + 2, red, green, blue);
	this->setPixel(x - 3, y + 2, red, green, blue);
	this->setPixel(x - 6, y + 1, red, green, blue);
	this->setPixel(x - 5, y + 1, red, green, blue);
	this->setPixel(x - 4, y + 1, red, green, blue);
	this->setPixel(x - 3, y + 1, red, green, blue);
	this->setPixel(x - 6, y , red, green, blue);
	this->setPixel(x - 5, y , red, green, blue);
	this->setPixel(x - 4, y , red, green, blue);
	this->setPixel(x - 3, y , red, green, blue);
	this->setPixel(x - 2, y-1, red, green, blue);
	this->setPixel(x - 5, y-1, red, green, blue);
	this->setPixel(x - 4, y-1, red, green, blue);
	this->setPixel(x - 3, y-1, red, green, blue);
	this->setPixel(x - 2, y - 2, red, green, blue);
	this->setPixel(x - 5, y - 2, red, green, blue);
	this->setPixel(x - 4, y - 2, red, green, blue);
	this->setPixel(x - 3, y - 2, red, green, blue);
	this->setPixel(x - 1, y - 2, red, green, blue);
	this->setPixel(x, y - 2, red, green, blue);
	this->setPixel(x + 1, y - 2, red, green, blue);
	this->setPixel(x + 2, y - 2, red, green, blue);
	this->setPixel(x + 3, y - 2, red, green, blue);
	this->setPixel(x - 2, y - 3, red, green, blue);
	this->setPixel(x - 4, y - 3, red, green, blue);
	this->setPixel(x - 3, y - 3, red, green, blue);
	this->setPixel(x - 1, y - 3, red, green, blue);
	this->setPixel(x, y - 3, red, green, blue);
	this->setPixel(x + 1, y - 3, red, green, blue);
	this->setPixel(x + 2, y - 3, red, green, blue);
	this->setPixel(x, y - 4, red, green, blue);
	this->setPixel(x - 3, y - 4, red, green, blue);
	this->setPixel(x - 2, y - 4, red, green, blue);
	this->setPixel(x +2 , y - 1, red, green, blue);
	this->setPixel(x + 3, y - 1, red, green, blue);
	this->setPixel(x + 4, y , red, green, blue);
	this->setPixel(x + 3, y , red, green, blue);
	this->setPixel(x + 4, y+1, red, green, blue);
	this->setPixel(x + 3, y+1, red, green, blue);
	this->setPixel(x + 4, y+2, red, green, blue);
	this->setPixel(x + 3, y+2, red, green, blue);


}

bool Bitmap::write(const std::string& filename)
{
	BitmapFile fileHeader;
	BitmapInfo infoHeader;

	fileHeader.fileSize = sizeof(BitmapFile) + sizeof(BitmapInfo) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFile) + sizeof(BitmapInfo);
	
	infoHeader.width = m_width;
	infoHeader.height = m_height;
	
	std::ofstream file(filename, std::ios::out | std::ios::binary);
	if (!file.is_open())
		return false;
	
	file.write((char *)&fileHeader, sizeof(fileHeader));
	file.write((char *)&infoHeader, sizeof(infoHeader));
	file.write((char *)m_pPixel.get(), m_width*m_height*3);

	file.close();
	return true;
}

Bitmap::~Bitmap() {}
