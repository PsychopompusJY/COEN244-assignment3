//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#include <iostream>
#include <string>
#include "Car.h"
#include "StandardCar.h"
#include "LuxuryCar.h"


void carPrintFunction(Car* car){
	car -> printCarInfo();
}

int main(){

	int Id = 123;
	string Type = "Yaris";
	string TypeLuxury = "GTR";

	StandardCar Car1;
	LuxuryCar Car2;

	Car1.setCarIdentificationNumber(Id);
	if (Car1.getCarIdentificationNumber() == Id){
		cout << "Car Identification Number Test Passed" << endl;
	}
	else {
		cout << "Car Identification Number Test Failed" << endl;
	}

	Car1.setType(Type);
	if (Car1.getType() == Type){
		cout << "Car Type Test Passed" << endl;
	}
	else{
		cout << "Car Type Test Failed" << endl;
	}

	if (!Car1.getAvailable()){
		cout << "Initial Availability Test Passed" << endl;
	}
	else {
		cout << "Initial Availability Test Failed" << endl;
	}

	Car1.changeAvailability();
	if (Car1.getAvailable()){
		cout << "Initial Availability Test Passed" << endl;
	}
	else {
		cout << "Initial Availability Test Failed" << endl;
	}

	Car1.printCarInfo();


	Car2.setCarIdentificationNumber(Id);
	if (Car1.getCarIdentificationNumber() == Id){
		cout << "Car Identification Number Test Passed" << endl;
	}
	else {
		cout << "Car Identification Number Test Failed" << endl;
	}

	Car2.setType(TypeLuxury);
	if (Car2.getType() == TypeLuxury){
		cout << "Car Type Test Passed" << endl;
	}
	else{
		cout << "Car Type Test Failed" << endl;
	}

	if (!Car2.getAvailable()){
		cout << "Initial Availability Test Passed" << endl;
	}
	else {
		cout << "Initial Availability Test Failed" << endl;
	}

	Car2.changeAvailability();
	if (Car2.getAvailable()){
		cout << "Initial Availability Test Passed" << endl;
	}
	else {
		cout << "Initial Availability Test Failed" << endl;
	}

	Car2.printCarInfo();




	StandardCar* Nissan = nullptr;
	Nissan = new StandardCar (123, "Nissan Altima");
	LuxuryCar* Porsche = nullptr;
	Porsche = new LuxuryCar (1123, "Porsche 911");

	carPrintFunction(Nissan);
	carPrintFunction(Porsche);

	delete Nissan;
	delete Porsche;


	return 0;
}
