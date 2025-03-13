//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#include <iostream>
#include <string>
#include "Car.h"
using namespace std;

Car::Car(){
	carIdentificationNumber = 0;
	type = "";
	available = 0;
}

Car::Car(int number, string type1){
	carIdentificationNumber = number;
	type = type1;
	available = 1;
}

Car::~Car(){
	//Does nothing
}

int Car :: getCarId() const{
	return carIdentificationNumber;
}

string Car:: getType() const{
	return type;
}

bool Car:: getAvailable() const{
	return available;
}

void Car :: changeAvailability(){
	if (available == 0){
		available =1;
	}
	else {
		available =0;
	}
}

void Car :: printCarInfo() const{
	cout << "Car Identification Number: " << carIdentificationNumber << endl;
	cout << "Type : " << type << endl;
	cout << "Availability: ";
	if (available){
		cout << "Is Available" << endl;
	}
	else {
		cout << "Is Not Available" << endl;
	}
}
