#include "Simulation.h"
#include "Bitmap.h"


Simulation::Simulation() : x(0) { std::make_pair(nullptr, nullptr); }
Simulation::Simulation(std::pair<StadoOwiec*, ZoorganizowanaGrupaPasterzy*> para) : para(para), x(0) {}

void Simulation::Go()
{
	bool licznikZmian = 1;
	while(licznikZmian)
	{
		//Wyczyszczenie stadka
		licznikZmian = 0;
		for (auto& tmp : para.second->lista) 
		{
			tmp->deleteStadko();
			tmp->setliczba_stadka(0);
		}
		

		//I ETAP ³¹czenie owieczek z pasterzami

		//owieczka szuka najbli¿szego pasterza, zapamiêtuje
		//pasterz zapamietuje swoje wszystkie owiczki i je zlicza
		for (auto it = para.first->lista.begin(); it != para.first->lista.end(); ++it)
		{
			licznikZmian|=(**it).FindNearestPasterz(*para.second);
		}
		//II ETAP pasterze szukaj¹ pozycji œrodkowej ze œredniej

		//pasterz liczy srodek na podstawie pozycji swoich owieczek
		//pasterz przesuwa sie na pozycje srodkowa	//dlatego zoorganizowani :D
		for (auto& tmp : para.second->lista)
		{
			(*tmp).FindMiddle();
		}

		//III ETAP powtarzanie poprzednich etapów dopóki ¿adna owieczka nie zmieni wlasciciela
	}
}

void Simulation::CreateFile(const std::string& output, bool c)
{
	std::ofstream result(output);
	if (!result.is_open())
		std::cout << "Nieuda³o siê otworzyc pliku z wynikami\n";
	else
	{
		int const margines = 12;
		int const skalowanie = 16;
		bmp::Bitmap bitmap(344,344);
		int d = 1;
		double first,second;
		int aa, bb, cc;
		
		std::default_random_engine gen{ 0 };
		std::uniform_int_distribution<int> dist(1, 255);
		for (auto tmp = para.second->lista.begin(); tmp != para.second->lista.end(); ++tmp)
		{
			std::cout << (*tmp)->toString();
			if ((*tmp)->getn() == 2)
			{
				
				aa = dist(gen);
				bb = dist(gen);
				cc = dist(gen);
				
				for (int i = 0; i < (*tmp)->getliczbastadka(); ++i)
				{
					std::istringstream iss((*tmp)->showElementStadka(i));
					iss >> first;
					iss >> second;
					if(c)
						bitmap.circle((first + 10)*skalowanie + margines, (second + 10)*skalowanie + margines, aa, bb, cc);
					else
						bitmap.owieczka((first+10)*skalowanie+margines, (second+10)*skalowanie+margines, aa,bb,cc);
					
				}
				first = (*tmp)->getx()[0];
				second = (*tmp)->getx()[1];
				bitmap.Pcircle((first + 10)*skalowanie + margines, (second + 10)*skalowanie + margines, aa, bb, cc);
			}
			result << "Grupa " << d << "\n";
			result<<(*tmp)->showStadko();
			d++;
		}
		
		bitmap.write("bitmapa.bmp");
		result.close();
	}
}

void Simulation :: CreateContainers(UserArguments& arg)
{
	std::vector<Object*> data=arg.VectorDanych(arg.file);
	std::vector<Object*>centroids=arg.VectorCentoridowZData(data);
	if (centroids.size() == 0)
	{
		arg.CreateData(2);
		centroids = arg.VectorDanych("pasterzeplik.txt");

	}
	if (data.size() == 0)
	{
		arg.CreateData(1);
		data = arg.VectorDanych("owceplik.txt");
	}
	
	*this=Simulation(std::make_pair(new StadoOwiec(&data),new ZoorganizowanaGrupaPasterzy(&centroids)));
}

void Simulation::pozwolenieDestruktor(bool x) { this->x = x; }

Simulation::~Simulation()
{
	if (x)
	{
		delete this->para.first;
		delete this->para.second;
	}
	x = 0;
}