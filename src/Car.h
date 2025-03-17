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
	int getCarIdentificationNumber() const;
	string getType() const;
	bool getAvailable() const;

	//setters
	void setCarIdentificationNumber(int);
	void setType(string);

	//Member Functions
	void changeAvailability();
	virtual void printCarInfo() const;


};



#endif /* CAR_H_ */
