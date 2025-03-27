//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#ifndef STANDARD_CAR_H_
#define STANDARD_CAR_H_

#include "Car.h"
#include <iostream>
#include <string>
using namespace std;

class StandardCar: public Car{
public:

	//constructors and destructor
	StandardCar();
	StandardCar(int, string);
	virtual ~StandardCar();

	//member functions
	virtual void printCarInfo() const;
};

#endif
