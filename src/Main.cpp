//PROJEKT K-Œrednich Majkel Skorus

#include <iostream>
#include "Object.h"
#include "Simulation.h"
#include "UserArguments.h"
#include "DetectMemoryLeaks.h"

using namespace std;

int main(int argc, char** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	UserArguments arg;
	if (!arg.LoadArguments(argc, argv)) //jesli nie zwrocil arg to zakoncz
		return 111;

	if(arg.getw()) //jesli bez pliku to stworz dane
		arg.CreateData(3);
	else //jesli z plikiem to rozpoznaj wymiar
		arg.RecognizeDimension();

	Simulation sim;
	
	sim.CreateContainers(arg);
	sim.Go();
	sim.CreateFile("wynik.txt",arg.getn());

	sim.pozwolenieDestruktor(1);
	if(Object::getn()==2)
		system("bitmapa.bmp");
	//system("wynik.txt");
	
	return 111;
}