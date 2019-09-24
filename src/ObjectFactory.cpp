#include "ObjectFactory.h"

Object* ObjectFactory:: create(const std::string& s)
{
	std::istringstream iss(s);
	std::string name="owca";
	double v;
	iss >> name;
	bool x = 0;
	double tmphelper= -100;		//mowi czy tmp sie zmienilo czy dostal pusty argument
	

	if (name == "pasterz" || name=="centroid" || name =="centrum" ||name=="pastor"|| name=="Pasterz" || name=="PASTERZ" || name== "Centroid" || name == "CENTROID" || name=="Pastor" || name=="DobryPasterz" || name=="WladcaOwiec" || name=="KrolOwiec" || name=="owczarz" ||name =="pastuszek")
	{
		int w = Object::getn();
		double* tmp = new double[w];
		for (int i = 0; i < w; ++i)
		{
			iss >> v;
			tmp[i] = v;
			if (tmp[i] == tmphelper)
			{
				if (x == 0)
				{
					double*tmp2 = new double[w];
					tmp2[0] = std::stod(name);
					std::copy(tmp, tmp + w-1, tmp2 + 1);
					std::copy(tmp2, tmp2 + w, tmp);
					delete tmp2;
					name = "pasterz";
					x |= 1;
				}
				else
					return 0;
			}
			v = tmphelper;
		}
		for (int i = 0; i < w; ++i)
		{
			if (tmp[i] < -10 || tmp[i]>10)
				return 0;
		}
		return new Pasterz(name, tmp);
	}
	else
	{
		int w = Object::getn();
		double* tmp = new double[w];
		for (int i = 0; i < w; ++i)
		{
			iss >> v;
			tmp[i] = v;
			if (tmp[i] == tmphelper)
			{
				if (x == 0)
				{
					double*tmp2 = new double[w];
					tmp2[0] = std::stod(name);
					std::copy(tmp, tmp + w - 1, tmp2 + 1);
					std::copy(tmp2, tmp2 + w, tmp);
					delete tmp2;
					name = "owca";
					x |= 1;
				}
				else
					return 0;
			}
			v = tmphelper;
		}
		for (int i = 0; i < w; ++i)
		{
			if (tmp[i] < -10 || tmp[i]>10)
				return 0;
		}
			return new Owca(name, tmp);
	}
}