//Benjamin Gutman 40315265
//Jiyong Jeon 40314593


#include <vector>
#include <iostream>
#include "Customer.h"


Customer::Customer(){
	fName = "";
	lName = "";
	address = "";
	numCarsRented = 0;

}

Customer::Customer(string firstName, string lastName, string Address){
	fName = firstName;
	lName = lastName;
	address = Address;
	numCarsRented = 0;
}

Customer :: ~Customer(){
	//does nothing
	cout << "Customer Deleted";
}


string Customer::getFName(){
	return fName;
}

string Customer:: getLName(){
	return lName;
}

string Customer::getAddress(){
	return address;
}



void Customer::printCustomerInfo(){
	cout << fName << endl;
	cout << lName << endl;
	cout << address << endl;
	for (int i = 0; i < numCarsRented; i++){
		carsRented[i]->printCarInfo();
	}
}

