#include "StadoOwiec.h"
#include <algorithm>
#include <functional>

StadoOwiec::StadoOwiec(std::vector<Object*>* sheeps)
{
		for(auto& it : *sheeps)
		{
			lista.emplace_back(dynamic_cast<Owca*>(it));
		}
		sheeps->clear();
}

