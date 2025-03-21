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

#ifndef COMPANY_H_
#define COMPANY_H_

#include <iostream>
#include <string>
using namespace std;

#include "Car.h"
#include "LuxuryCar.h"
#include "StandardCar.h"

class Company {

private:
	Car *cars[1000]; // Array of car pointers
	int Carcount;

public:
	Company(); // Constructor
	~Company(); // Destructor

	void addCar(Car *car); // Adds a new car to the company
	void displayCars() const; // Displays all cars
	Car *getCarById(int id); // Returns a car pointer if available




};



#endif /* COMPANY_H_ */
