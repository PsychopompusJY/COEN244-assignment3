//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

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
	if(tempCar == nullptr){
		cout << "Car does not exist" << endl;
	}
	else if (tempCar -> getAvailable()){
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
	//check for edge case
	if (tempCustomer == nullptr){
		cout << "Customer does not exist" << endl;
		return;
	}
	Car* tempCar = COENCars ->getCarById(carID);
	//check for edgecase
	if (tempCar == nullptr){
		cout << "Car does not exist" << endl;
		return;
	}
	Date resetDate(0,0,0);
	for (int i = 0; i < tempCustomer ->numCarsRented; i++){
		if (tempCustomer ->carsRented[i]->getCarIdentificationNumber() == carID){
			tempCustomer ->carsRented[i]-> setDates(resetDate);
			tempCustomer ->numCarsRented--;
			tempCustomer ->carsRented.erase(tempCustomer ->carsRented.begin()+i);
			tempCar->changeAvailability();
			return; // return to leave function
		}
	}
	//The only way to get here is if the car exists but is not being rented by this person
	cout << "Car is not being rented by " << tempCustomer ->fName << endl;
}

//Create a new standard car and add it to company
void newStandardCar(int Id, string type,Company* COENCars){
	StandardCar* tempCar = new StandardCar(Id, type);
	COENCars -> addCar(tempCar);

}

//Create a new luxury car and add it to company
void newLuxuryCar(int Id, string type,Company* COENCars){
	LuxuryCar* tempCar = new LuxuryCar(Id, type);
	COENCars -> addCar(tempCar);

}

//Create a new customer and add it to company
void newCustomer(string fName, string lName, string address, Company* COENCars){
	Customer* tempCustomer = new Customer(fName, lName, address);
	COENCars-> newCustomer(tempCustomer);
}

//Prints all the cars and customers of the company
void printCompanyInfo(Company* COENCars){
	cout << "Information about company:"<< endl;
	COENCars ->displayCars();
	COENCars -> displayCustomers();
	cout << "\n\n" << endl;
}


int main(){

	Company* COENCars = new Company();

	//Print to view company with no items
	cout << "Initial Company Information: " << endl;
	printCompanyInfo(COENCars);


	//Create customers and cars to be rented out
	newCustomer("Ben", "Gutman", "258 rue Berlioz", COENCars);
	newCustomer("Brianna", "Morrisette", "258 rue Berlioz", COENCars);
	newCustomer("Jiyong", "Jeon", "1950 Rue Claude-Gagne", COENCars);
	newCustomer("Maria", "Jose", "1950 Rue Claude-Gagne", COENCars);

	newStandardCar(213, "Sedan", COENCars);
	newStandardCar(212, "Truck", COENCars);
	newStandardCar(231, "SUV", COENCars);
	newStandardCar(243, "Pickup", COENCars);
	newStandardCar(201, "Hatchback", COENCars);
	newLuxuryCar(202, "convertible", COENCars);
	newLuxuryCar(232, "Sport", COENCars);

	//Three different dates to test edgecases of the change date function
	Date date1(27,3,2025);
	Date date2(31,12,2024);
	Date date3(29,1,2025);

	//Company after creating users and cars
	cout << "Company Info After Creating Cars And Customers: " << endl;
	printCompanyInfo(COENCars);


	//Rent out cars to people

	rentCar("Ben", 213, COENCars, date1);
	rentCar("Ben", 231, COENCars, date1);
	rentCar("Ben", 201, COENCars, date1);
	rentCar("Ben", 213, COENCars, date1);

	rentCar("Brianna", 232, COENCars, date3);
	rentCar("Brianna", 212, COENCars, date3);

	rentCar("Jiyong", 243, COENCars, date2);

	cout << "Company Info After Renting out Cars: " << endl;
	printCompanyInfo(COENCars);

	//test return function
	returnCar("Ben", 231, COENCars);
	returnCar("Ben", 212, COENCars);
	returnCar("Brianna", 212, COENCars);


	//Print of final results
	cout << "Company Info After Returning Some Cars: " << endl;
	printCompanyInfo(COENCars);

	//Delete all objects and reallocate memory
	delete COENCars;
	return 0;


}

