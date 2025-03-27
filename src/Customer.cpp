#include "Customer.h"
#include <vector>
#include <iostream>

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



void Customer::rentCar(int ID, Company* COENCars, Date rentalDay){
	Car* tempCar = COENCars -> getCarById(ID);
	if(tempCar->getAvailable()){
		carsRented.push_back(tempCar);
		carsRented[numCarsRented]->setDates(rentalDay);
		carsRented[numCarsRented]->changeAvailability();
		numCarsRented++;
	}
	else{
		cout << "Car is not available" << endl;
	}

}

void Customer :: returnCar(int ID, Company* COENCars){
	Car* tempCar = COENCars -> getCarById(ID);
	tempCar->changeAvailability();
	for (int i = 0; i < numCarsRented; i++){
		if (carsRented[i]->getCarIdentificationNumber() == ID){
			carsRented.erase(carsRented.begin()+i);
			numCarsRented--;
			return;
		}
	}
	cout << "Car is not being rented by " << fName << endl;
}

void Customer::printCustomerInfo(){
	cout << fName << endl;
	cout << lName << endl;
	cout << address << endl;
	for (int i = 0; i < numCarsRented; i++){
		carsRented[i]->printCarInfo();
	}
}

