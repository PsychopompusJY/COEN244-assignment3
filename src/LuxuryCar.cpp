//Benjamin Gutman 40315265
//Jiyong Jeon 40314593


#include <iostream>
#include <string>
#include "LuxuryCar.h"
using namespace std;

LuxuryCar:: LuxuryCar(): Car(){
	//does nothing
}

LuxuryCar::LuxuryCar(int id, string type1): Car(id, type1){
	//does nothing
}

virtual LuxuryCar:: ~LuxuryCar(){
	//does nothing
}

virtual void LuxuryCar:: printCarInfo() const{
	cout << "Luxury Car Information: " << endl;
	Car:: printCarInfo();
}
