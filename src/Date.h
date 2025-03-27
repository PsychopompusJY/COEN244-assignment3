//Benjamin Gutman 40315265
//Jiyong Jeon 40314593


//Modified version of Date class posted on moodle

#ifndef DATE_H_
#define DATE_H_

// Class composition: Class Date uses an object of class Time.

#include <iostream>
using namespace std;

class Date {
   public:
      Date(int, int, int);   // sets day, month, year, hours, minutes, seconds

      void printDate() const;   	    // print date to the screen



      //Setters for
      void setDay(int);
      void setMonth(int);
      void setYear(int);

      int getDay();
      int getMonth();
      int getYear();

   private:
      int day, month, year;
};


#endif /* DATE_H_ */
