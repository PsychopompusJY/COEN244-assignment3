//Benjamin Gutman 40315265
//Jiyong Jeon 40314593


#include "Car.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <vector>



#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Company;

class Customer{
private:
	string fName;
	string lName;
	string address;
	vector<Car*> carsRented;
	int numCarsRented;
public:
	//Constructors and destructor
	Customer();
	Customer(string, string, string);
	~Customer();

	//No setters, users will not change their account information

	//Mutators

	//Getters
	string getFName();
	string getLName();
	string getAddress();


	//Member functions

	void printCustomerInfo();

	//friends of the class, forward declaration
	void friend rentCar(string, int, Company*, Date);
	void friend returnCar(string, int, Company*);


};

#endif
