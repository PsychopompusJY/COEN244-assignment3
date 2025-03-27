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
#include "Customer.h"

using namespace std;
//Constructor
Company::Company() : Carcount(0), numCustomers(0){
	cars = new Car*[1000];
	customers = new Customer*[1];
}

//Destructor
Company::~Company() {
	cout << 'Company Destructor Called';
	delete[] cars;
	delete[] customers;
}


void Company::newCustomer(Customer* customer){
	numCustomers++;
	if(numCustomers >1){
		Customer** temparray = new Customer* [numCustomers];
		for (int i = 0; i <numCustomers-1; i++){
			temparray[i] = customers[i];
		}
		temparray[numCustomers-1] = customer;
		delete[] customers;
		customers = temparray;
	}
	else{
		customers[numCustomers-1] = customer;
	}
}

void Company::addCar(Car* car){
	if (Carcount<1000){
		cars[Carcount++]= car;
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

void Company::displayCustomers() const{
	cout << "Customers: " << endl;
	for (int i = 0; i < numCustomers; i++){
		customers[i] -> printCustomerInfo();
	}
}

Car *Company::getCarById(int id){
	for (int i = 0; i<Carcount; i++){
		if (cars[i] -> getCarIdentificationNumber() == id){
			return cars[i];
		}
	}
	return nullptr;
}

Customer *Company::getCustomerByFirstName(string fName){
	for (int i = 0; i<numCustomers; i++){
		if (customers[i] -> getFName() == fName){
			return customers[i];
		}
	}
	return nullptr; //Car not found or not available
}
