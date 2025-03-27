//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#include <iostream>
#include <string>
#include "StandardCar.h"
using namespace std;

StandardCar::StandardCar(): Car(){
	//Does Nothing
}

StandardCar:: StandardCar(int id, string type1) : Car(id, type1){
	//does nothing
}

StandardCar:: ~StandardCar(){
	//does nothing
}

//overrides the print function from Car.h
void StandardCar:: printCarInfo() const{
	cout << "Standard Car Information: " << endl;
	Car :: printCarInfo();
}
