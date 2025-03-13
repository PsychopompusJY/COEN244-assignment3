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
	StandardCar();
	StandardCar(int, string);
	virtual ~StandardCar();

	virtual void printCarInfo() const;
};

#endif STANDARD_CAR_H_
