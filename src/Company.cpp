//Benjamin Gutman 40315265
//Jiyong Jeon 40314593


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
//destructor must individually delete each element then the array itself
Company::~Company() {
	cout << "Company Destructor Called";
	for (int i =0; i<Carcount; i++){
		delete cars[i];
	}
	delete[] cars;
	for (int i = 0; i<numCustomers;i++){
		delete customers[i];
	}
	delete[] customers;
}


void Company::newCustomer(Customer* customer){
	numCustomers++;
	//makes a new array for the increased size, deletes the old one and reallocates the new array to the old one
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

//Adds a new car object to the cars array, since there is a limit to the cars there is no need to reform a new array on each addition
void Company::addCar(Car* car){
	if (Carcount<1000){
		cars[Carcount++]= car;
	}

	else{
		cout<<"company car storage is full"<<endl;
	}
}

//prints out all car information, will decide if the juxury or standard car function will be called at runtime
void Company::displayCars() const{
	cout<<"Company cars list: "<<endl;
	for (int i=0; i<Carcount; i++){
		cars[i]->printCarInfo();
	}
}

//prints out all customers
void Company::displayCustomers() const{
	cout << "Customers: " << endl;
	for (int i = 0; i < numCustomers; i++){
		customers[i] -> printCustomerInfo();
	}
}

//Looks for a car by the id number, returns nullptr if it does not exist
Car *Company::getCarById(int id){
	for (int i = 0; i<Carcount; i++){
		if (cars[i] -> getCarIdentificationNumber() == id){
			return cars[i];
		}
	}
	return nullptr;
}

//finds a customer in the customers array by the first name
Customer *Company::getCustomerByFirstName(string fName){
	for (int i = 0; i<numCustomers; i++){
		if (customers[i] -> getFName() == fName){
			return customers[i];
		}
	}
	return nullptr; //Car not found or not available
}
