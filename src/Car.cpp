//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#include <iostream>
#include <string>
#include "Car.h"
#include "Date.h"
using namespace std;

//Constructors

//Default constructor
Car::Car(): dateRented(0,0,0), expectedReturnDate(0,0,0){
	carIdentificationNumber = 0;
	type = "";
	available = 0;
}

//Regular constructor, car cannot be rented on creation
Car::Car(int number, string type1): dateRented(0,0,0), expectedReturnDate(0,0,0){
	carIdentificationNumber = number;
	type = type1;
	available = 1;
}


//Destructor
Car::~Car(){
	//Does nothing
}

//Getters

int Car :: getCarIdentificationNumber() const{
	return carIdentificationNumber;
}

string Car:: getType() const{
	return type;
}

bool Car:: getAvailable() const{
	return available;
}

//Setters
void Car:: setCarIdentificationNumber(int id){
	carIdentificationNumber = id;
}

void Car:: setType(string type1){
	type = type1;
}


//Sets the dates of rental and returnal with edge cases for end of year and February being 28 days
void Car::setDates(Date rentalDate1){
	dateRented.setDay(rentalDate1.getDay());
	dateRented.setMonth(rentalDate1.getMonth());
	dateRented.setYear(rentalDate1.getYear());

	if(rentalDate1.getDay() == 0 && rentalDate1.getMonth() ==0 && rentalDate1.getYear() == 0){
		expectedReturnDate.setDay(0);
		expectedReturnDate.setMonth(0);
		expectedReturnDate.setYear(0);
	}

	else if(rentalDate1.getMonth() ==12){
		expectedReturnDate.setDay(rentalDate1.getDay());
		expectedReturnDate.setMonth(1);
		expectedReturnDate.setYear(rentalDate1.getYear()+1);
	}
	else if(dateRented.getMonth()==1 && dateRented.getDay() >28){
		expectedReturnDate.setDay(rentalDate1.getDay() - 28);
		expectedReturnDate.setMonth(3);
		expectedReturnDate.setYear(rentalDate1.getYear());
	}
	else{
		expectedReturnDate.setDay(rentalDate1.getDay());
		expectedReturnDate.setMonth(rentalDate1.getMonth()+1);
		expectedReturnDate.setYear(rentalDate1.getYear());
	}
}
//Inverts the availablity status of the boolean available
void Car :: changeAvailability(){
	if (available == 0){
		available =1;
	}
	else {
		available =0;
	}
}

// prints the car information, is a virtual function to be overridden by later classes
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
	dateRented.printDate();
	expectedReturnDate.printDate();
}
