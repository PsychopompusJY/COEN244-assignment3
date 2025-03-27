//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#include <iostream>
#include <string>
#include "Car.h"
#include "Date.h"
using namespace std;

Car::Car(): dateRented(0,0,0), expectedReturnDate(0,0,0){
	carIdentificationNumber = 0;
	type = "";
	available = 0;
}

Car::Car(int number, string type1): dateRented(0,0,0), expectedReturnDate(0,0,0){
	carIdentificationNumber = number;
	type = type1;
	available = 1;
}

Car::Car(Car& car){
	carIdentificationNumber = car.carIdentificationNumber;
	type = car.type;
	available = car.available;
	dateRented = car.dateRented;
	expectedReturnDate = car.expectedReturnDate;
}

Car::~Car(){
	//Does nothing
}

int Car :: getCarIdentificationNumber() const{
	return carIdentificationNumber;
}

string Car:: getType() const{
	return type;
}

bool Car:: getAvailable() const{
	return available;
}

void Car:: setCarIdentificationNumber(int id){
	carIdentificationNumber = id;
}

void Car:: setType(string type1){
	type = type1;
}

void Car::setDates(Date rentalDate1){
	dateRented.setDay(rentalDate1.getDay());
	dateRented.setMonth(rentalDate1.getMonth());
	dateRented.setYear(rentalDate1.getYear());

	if(rentalDate1.getMonth() <12){
		dateRented.setDay(rentalDate1.getDay());
		dateRented.setMonth(rentalDate1.getMonth()+1);
		dateRented.setYear(rentalDate1.getYear());
	}
	else if(dateRented.getMonth()==1 && dateRented.getDay() >28){
		dateRented.setDay(rentalDate1.getDay() - 28);
		dateRented.setMonth(3);
		dateRented.setYear(rentalDate1.getYear());
	}
	else{
		dateRented.setDay(rentalDate1.getDay());
		dateRented.setMonth(1);
		dateRented.setYear(rentalDate1.getYear()+1);
	}
}

void Car :: changeAvailability(){
	if (available == 0){
		available =1;
	}
	else {
		available =0;
	}
}

void Car :: printCarInfo() const{
	cout << "Car Identification Number: " << carIdentificationNumber << endl;
	cout << "Type : " << type << endl;
	cout << "Availability: ";
	if (available){
		cout << "Is Available" << endl;
	}
	else {
		cout << "Is Not Available" << endl;
	}
}
