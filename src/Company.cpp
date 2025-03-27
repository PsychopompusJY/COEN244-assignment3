//Benjamin Gutman 40315265
//Jiyong Jeon 40314593
//
//The company rents two types of cars: standard and
//luxury cars. A car is identified by a car identification number (int), a type (string), and a flag that
//indicates whether the car is currently available or not. The company distinguishes between two
//types of customers: regular customers and corporate customers.
//
//Create the class Company. A company has many cars. You can assume that the maximum
//number of cars the company can have is 1000. You should create all member functions
//including functions that update the cars array. Create a driver to test the Company class.

#include "Company.h"
#include <iostream>

using namespace std;

Company::Company() : Carcount(0){
	cars = new Car*[1000];
}

Company::~Company() {
	delete[] cars;
}

void Company::addCar(Car* car){
	if (Carcount<1000){
		cars[Carcount++]=car;
	}

	else{
		cout<<"company car storage is full"<<endl;
	}
}

void Company::displayCars() const{
	cout<<"Company cars list: "<<endl;
	for (int i=0; i<Carcount; i++){
		cars[i]->printCarInfo();
	}
}

Car *Company::getCarById(int id){
	for (int i = 0; i<Carcount; i++){
		if (cars[i] -> getCarIdentificationNumber() == id && cars[i] -> getAvailable()){
			return cars[i];
		}
	}
	return nullptr; //Car not found or not available
}
