//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#ifndef LUXURY_CAR_H_
#define LUXURY_CAR_H_

#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

class LuxuryCar: public Car{
public:

	//constructors and destructor
	LuxuryCar();
	LuxuryCar(int, string);
	virtual ~LuxuryCar();

	//member functions
	virtual void printCarInfo() const;
};

#endif
