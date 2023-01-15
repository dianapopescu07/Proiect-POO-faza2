#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//clasa abstracta
class Reducere
{
public:
	//metoda virtuala pura
	virtual float realizeazaReducere() = 0;
};