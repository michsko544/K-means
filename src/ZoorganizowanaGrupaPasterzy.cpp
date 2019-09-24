#include "ZoorganizowanaGrupaPasterzy.h"


ZoorganizowanaGrupaPasterzy::ZoorganizowanaGrupaPasterzy(std::vector<Object*>* pastors)
{
	for(auto& it:*pastors)
	{
		lista.emplace_back(dynamic_cast<Pasterz*>(it));
	}

}

