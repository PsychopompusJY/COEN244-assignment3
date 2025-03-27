



#include <iostream>
#include <string>
#include "Date.h"
#include "Car.h"
#include "LuxuryCar.h"
#include "StandardCar.h"
#include "Company.h"
#include "Customer.h"
using namespace std;

//Allows a customer of a certain company to rent a car by Id
void rentCar(string Fname, int carID, Company* COENCars, Date rentalDay){
	Customer* tempCustomer = COENCars->getCustomerByFirstName(Fname);
	if (tempCustomer == nullptr){
		cout << "Customer does not exist" << endl;
		return;
	}
	Car* tempCar = COENCars->getCarById(carID);
	if(tempCar->getAvailable()){
		tempCustomer->carsRented.push_back(tempCar);
		tempCustomer -> carsRented[tempCustomer ->numCarsRented]->setDates(rentalDay);
		tempCustomer ->carsRented[tempCustomer ->numCarsRented]->changeAvailability();
		tempCustomer ->numCarsRented++;
	}
	else{
		cout << "Car is not available" << endl;
	}

}

//Allows a customer to return a car they rented
void returnCar(string Fname, int carID, Company* COENCars){
	Customer* tempCustomer = COENCars->getCustomerByFirstName(Fname);
	if (tempCustomer == nullptr){
		cout << "Customer does not exist" << endl;
		return;
	}
	Car* tempCar = COENCars ->getCarById(carID);
	tempCar->changeAvailability();
	for (int i = 0; i < tempCustomer ->numCarsRented; i++){
		if (tempCustomer ->carsRented[i]->getCarIdentificationNumber() == carID){
			tempCustomer ->carsRented.erase(tempCustomer ->carsRented.begin()+i);
			tempCustomer ->numCarsRented--;
			return;
		}
	}
	cout << "Car is not being rented by " << tempCustomer ->fName << endl;
}

//Create a new car and add it to company
void newCar(int Id, string type,Company* COENCars){
	Car* tempCar = new Car(Id, type);
	COENCars -> addCar(tempCar);

}

//Create a new car and add it to company
void newCustomer(string fName, string lName, string address, Company* COENCars){
	Customer* tempCustomer = new Customer(fName, lName, address);
	COENCars-> newCustomer(tempCustomer);
}

void printCompanyInfo(Company* COENCars){
	cout << "Information about company:"<< endl;
	COENCars ->displayCars();
	COENCars -> displayCustomers();
}


int main(){

	Company* COENCars = new Company();


}

