#include "Date.h"


Date::Date(int d, int m, int y) {
    cout << "Constructor Date(...) is called" << endl;
    day = d;
    month = m;
    year = y ;
}



void Date::setDay(int Day){
	day = Day;
}

void Date::setMonth(int Month){
	month = Month;
}

void Date::setYear(int Year){
	year = Year;
}

int Date::getDay(){
	return day;
}

int Date::getMonth(){
	return month;
}

int Date::getYear(){
	return year;
}


void Date::printDate() const {
   cout << month << "/" << day << "/" << year << " ";
}

