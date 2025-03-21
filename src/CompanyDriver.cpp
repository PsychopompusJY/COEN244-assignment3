//Benjamin Gutman 40315265
//Jiyong Jeon 40314593


#include <iostream>
#include "Company.h"
#include "StandardCar.h"
#include "LuxuryCar.h"
#include "Car.h"

using namespace std;

void carPrintFunction(Car* car){
	car->printCarInfo();
}

int main() {
	// Create a company object
	Company coenCars;

	// Add cars dynamically
	coenCars.addCar(new StandardCar(101, "Toyota Corolla"));
	coenCars.addCar(new LuxuryCar(202, "Mercedes-Benz S-Class"));
	coenCars.addCar(new StandardCar(303, "Honda Civic"));

	// Display all cars
	cout << "\nDisplaying All Cars in the Company:\n";
	coenCars.displayCars();

	// Search for a car by ID
	int Id = 101;
	Car* car = coenCars.getCarById(Id);
	if (car) {
		cout << "\nCar ID " << Id << " is available for rent.\n";
		carPrintFunction(car);
	} else {
		cout << "\nCar ID " << Id << " is not available.\n";
	}

	// Clean-up handled inside Company destructor
	return 0;
}
