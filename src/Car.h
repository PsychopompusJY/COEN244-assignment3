//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include <string>
using namespace std;

class Car{
private:
	int carIdentificationNumber;
	string type;
	bool available;

public:
	Car();
	Car(int, string);
	virtual ~Car();

	//Getters
	int getCarId() const;
	string getType() const;
	bool getAvailable() const;

	//Member Functions
	void changeAvailability();
	virtual void printCarInfo();


};



#endif /* CAR_H_ */
