//Benjamin Gutman 40315265
//Jiyong Jeon 40314593


#ifndef COMPANY_H_
#define COMPANY_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Car.h"
#include "LuxuryCar.h"
#include "StandardCar.h"
#include "Customer.h"

class Company {

private:
	Car **cars; // Array of car pointers
	int Carcount;
	Customer** customers;
	int numCustomers;

public:
	Company(); // Constructor
	~Company(); // Destructor

	//Member Functions

	void newCustomer(Customer*);
	void addCar(Car*); // Adds a new car to the company
	void displayCars() const; // Displays all cars
	void displayCustomers() const;
	Car *getCarById(int id); // Returns a car pointer if available
	Customer* getCustomerByFirstName(string);

	//Define Friend functions
	void friend rentCar(string, int, Company*, Date);
	void friend returnCar(string, int, Company*);





};



#endif /* COMPANY_H_ */
