#include "UserArguments.h"
#include "Object.h"
#include "ObjectFactory.h"

UserArguments::UserArguments() : file("owceplik.txt"), d(2), m(500), k(20), w(false), n(false) {}

bool UserArguments::getw() const { return w; }

bool UserArguments::getn() const { return n; }

void UserArguments::Help()
{
	std::cout << "\n======\n HELP\n======\nUzyj przelacznika -i przed sciezka do pliku, ktory chcesz wczytac\nlub innych przelacznikow:\n";
	std::cout << "\n-d a nastepnie podaj liczbe aby ustawic jaki wymiar ma byc wygenerowany jesli nie ma\npliku wejsciowego (jesli ustawisz na 2 zostanie rowniez wygenerowana bitmapa z\nwynikami)\n";
	std::cout << "\n-k a nastepnie podaj liczbe aby ustawic na ile grup ma podzielic dane jesli nie ma w\npliku wejsciowym centroidow (pasterzy)\n";
	std::cout << "\n-m a nastepnie podaj liczbe aby ustawic ile danych ma zostac wygenerowanych jesli nie\nma w pliku wejsciowym danych (owieczek)\n";
	std::cout << "\n-w aby uruchomic program bez pliku wejsciowego (pliki z danymi wygeneruja sie losowo\nw domyslnych ilosciach lub w ilosciach jakie sie ustawi przelacznikami)\n";
	std::cout << "\n-n aby na bitmapie wyswietlic kropki zamiast owieczek\n";
	std::cout << "\n-h aby wyswietlic pomoc\n";
	std::cout << "\n*Wszystkie parametry mozna podac w dowolnej kolejnosci natomiast musza poprzedzac je\nprzelaczniki aby mialo to logiczny sens\n";
}
bool UserArguments::LoadArguments(int argc, char ** argv)
{
	const std::string INPUT("-i");
	const std::string WYMIAR("-d");
	const std::string K("-k");
	const std::string DATA("-m");
	const std::string HELP("-h");
	const std::string WITHOUT("-w");
	const std::string NORMAL("-n");
	const int InputFlag = 1;
	std::string tmp;
	const int w = 500;

	const int correct = InputFlag;
	int result = 0;

	if (argc == 1)
	{
		Help();
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		if (arg == INPUT && argv[i + 1])
		{
			this->file = argv[i + 1];
			result |= InputFlag;
		}
		if (arg == WYMIAR && argv[i + 1])
		{

			tmp = argv[i + 1];
			if (tmp[0] == '1' || tmp[0] == '2' || tmp[0] == '3' || tmp[0] == '4' || tmp[0] == '5' || tmp[0] == '6' || tmp[0] == '7' || tmp[0] == '8' || tmp[0] == '9')
				this->d = stoi(tmp);
			else
			{
				std::cout << "Nieprawidlowy parametr po -d\n";
				return false;
			}
			if (d < 500 && d>0)
			{
				Object::setn(this->d);
				result |= InputFlag;
			}
			else
			{
				std::cout << "Wymiar wykracza poza przedzial [1;499]\n";
				return false;
			}
		}
		if (arg == K && argv[i + 1])
		{
			tmp = argv[i + 1];
			if (tmp[0] == '1' || tmp[0] == '2' || tmp[0] == '3' || tmp[0] == '4' || tmp[0] == '5' || tmp[0] == '6' || tmp[0] == '7' || tmp[0] == '8' || tmp[0] == '9')
				this->k = stoi(tmp);
			else
			{
				std::cout << "Nieprawidlowy parametr po -k\n";
				return false;
			}
			
			if (k <= 10000 && k>0)
			{
				result |= InputFlag;
			}
			else
			{
				std::cout << "Ilosc podzialu na grupy wykracza poza przedzial [1;10000]\n";
				return false;
			}
		}
		if (arg == DATA && argv[i + 1])
		{
			
			tmp = argv[i + 1];
			if (tmp[0] == '1' || tmp[0] == '2' || tmp[0] == '3' || tmp[0] == '4' || tmp[0] == '5' || tmp[0] == '6' || tmp[0] == '7' || tmp[0] == '8' || tmp[0] == '9')
				this->m = stoi(tmp);
			else
			{
				std::cout << "Nieprawidlowy parametr po -m\n";
				return false;
			}
			if (m < 50000 && m>0)
			{
				result |= InputFlag;
			}
			else
			{
				std::cout << "Ilosc danych wykracza poza przedzial [1;50000]\n";
				return false;
			}
		}

		if (arg == HELP)
		{
			Help();
		}
		if (arg == WITHOUT)
		{
			this->w |= InputFlag;
			result |= InputFlag;
		}
		if (arg == NORMAL)
		{
			this->n |= InputFlag;
			result |= InputFlag;
		}
	}

	if (result == correct)
		return true;
	else
		return false;
}

void UserArguments::RecognizeDimension()
{
	std::ifstream input(file);
	if (!input.is_open())
		std::cout << "Nie udalo sie otowrzyc pliku\n";
	else
	{
		std::string linia;
		int y = 0;
		bool emptyfile=0;
		getline(input, linia);
		while ((linia.empty()||CheckEmptyLine(linia))&&!emptyfile)
		{
			getline(input, linia);
			emptyfile = input.eof();
		}
		if (!emptyfile)
		{
			int l = linia.length();
			if ((linia[0] == '0' || linia[0] == '1' || linia[0] == '2' || linia[0] == '3' || linia[0] == '4' || linia[0] == '5' || linia[0] == '6' || linia[0] == '7' || linia[0] == '8' || linia[0] == '9') || (linia[0] == '-' || (linia[1] == '-' && linia[0] == ' ')))
				y++;
			for (int i = 2; i < l; i++)
			{
				if ((linia[i - 1] == ' ' || (linia[i - 1] == '-' && linia[i - 2] == ' ')))
					if (((linia[i] == '0') || (linia[i] == '1') || (linia[i] == '2') || (linia[i] == '3') || (linia[i] == '4') || (linia[i] == '5') || (linia[i] == '6') || (linia[i] == '7') || (linia[i] == '8') || (linia[i] == '9')))
						y++;
			}
			Object::setn(y);
		}
	}
	input.close();
}
void UserArguments::CreateData(int mode)
{
	std::default_random_engine gen{ 0 };
	std::uniform_int_distribution<int> dist(-1000, 1000);

	if (mode == 1 || mode == 3)
	{
		std::ofstream owceplik("owceplik.txt");
		if (!owceplik.is_open())
			std::cout << "Nieuda³o siê otworzyc pliku owce\n";
		else
		{
			for (int i = 0; i < m; ++i)
			{
				owceplik << "owca ";
				for (int j = 0; j < d; ++j)
				{
					owceplik << (double)dist(gen) / 100.0f << " ";
				}
				owceplik << "\n";
			}
			owceplik.close();
		}
	}
	if (mode == 2 || mode == 3)
	{
		std::ofstream pasterzeplik("pasterzeplik.txt");
		if (!pasterzeplik.is_open())
			std::cout << "Nieuda³o siê otworzyc pliku pasterze\n";
		else
		{
			for (int i = 0; i < k; ++i)
			{
				pasterzeplik << "pasterz ";
				for (int j = 0; j < d; ++j)
				{
					pasterzeplik << (double)dist(gen) / 100.0f << " ";
				}
				pasterzeplik << "\n";
			}
			pasterzeplik.close();
		}
	}
	if (mode > 3)
		std::cout << "Z³y tryb generacji danych\n";
}
std::vector<Object*> UserArguments::VectorDanych(const std::string& vfile)
{
	std::vector<Object*> data;
	std::ifstream input(vfile);
	if (!input.is_open())
		std::cout << "Nie udalo sie otowrzyc pliku\n";
	else
	{
		std::string linia;
		int puste_linie = 0;
		int niepowodzenia = 0;
		while (getline(input, linia))				//dodanie linijek do kontenera
		{
			if (linia.empty()||CheckEmptyLine(linia))
			{
				++puste_linie;
				continue;
			}
			Object* tmp = ObjectFactory::create(linia);
			if (tmp != NULL)
				data.emplace_back(tmp);
			else
			{
				std::cout << "Nie umiem stworzyc takiego obiektu - linia <" << data.size() + puste_linie + niepowodzenia + 1 << "> w pliku " << vfile << "\n";
				++niepowodzenia;
			}
		}
	}
	input.close();
	return data;
}
std::vector<Object*> UserArguments::VectorCentoridowZData(std::vector<Object*>& data)
{
	std::vector<Object*> centroids;
	for (auto i = 0; i < data.size(); ++i)
	{
		std::string name = data[i]->getname();
		if (name == "pasterz" || name=="centroid" || name =="centrum" ||name=="pastor"|| name=="Pasterz" || name=="PASTERZ" || name== "Centroid" || name == "CENTROID" || name=="Pastor" || name=="DobryPasterz" || name=="WladcaOwiec" || name=="KrolOwiec" || name=="owczarz" ||name =="pastuszek")
		{

			centroids.emplace_back(data[i]);
			data.erase(data.begin() + i);
			--i;
		}
	}
	return centroids;
}

bool CheckEmptyLine(std::string line)
{
	for (int i = 0; i < line.size(); ++i)
	{
		if (line[i] != 32 && line[i] != '\t')
			return false;
		else
			continue;
	}
	return true;
}