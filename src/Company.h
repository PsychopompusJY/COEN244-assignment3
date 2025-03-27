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

	void newCustomer(Customer*);
	void addCar(Car*); // Adds a new car to the company
	void displayCars() const; // Displays all cars
	void displayCustomers() const;
	Car *getCarById(int id); // Returns a car pointer if available
	Customer* getCustomerByFirstName(string);
	void friend rentCar(string, int, Company*, Date);
	void friend returnCar(string, int, Company*);





};



#endif /* COMPANY_H_ */
