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
	Customer();
	Customer(string, string, string);
	~Customer();

	string getFName();
	string getLName();
	string getAddress();


	void friend rentCar(string, int, Company*, Date);
	void friend returnCar(string, int, Company*);
	void printCustomerInfo();


};

#endif
