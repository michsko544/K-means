#include "Object.h"
#include <iostream>
#include <ctime>

Object::Object()
{ 
	x = new double[n]; 
	for (int i = 0; i < n; ++i)
	{
		x[i]= rand() % 20001 / 100.0f - 100.0f;
	}
}

Object::Object(const std::string& name, double* other) : name(name)
{
	x = new double[n];
	for (int i = 0; i < n; ++i)
	{
		x[i] = other[i];
	}
	delete[] other;
}

void Object::setn(int a) { n = a; }
int Object::getn() { return n; }
std::string Object::getname() { return name; }
double* Object::getx() const { return x; }

Object::~Object() { delete[] x; }

int Object::n = 2;
