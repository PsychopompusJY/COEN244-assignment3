//Benjamin Gutman 40315265
//Jiyong Jeon 40314593

#ifndef CAR_H_
#define CAR_H_

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Car{
private:
	int carIdentificationNumber;
	string type;
	bool available;
	Date dateRented;
	Date expectedReturnDate;


public:
	Car();
	Car(int, string);
	Car(Car&);
	virtual ~Car();

	//Getters
	int getCarIdentificationNumber() const;
	string getType() const;
	bool getAvailable() const;

	//setters
	void setCarIdentificationNumber(int);
	void setType(string);
	void setDates(Date);

	//Member Functions
	void changeAvailability();
	virtual void printCarInfo() const;


};



#endif /* CAR_H_ */
