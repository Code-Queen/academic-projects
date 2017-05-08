// File: Date.h
// Version 1.0
// Date	07 March 03 2016
// Description
// This file declares prototypes of the Date class
/////////////////////////////////////////////////////////////////
#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#define NO_ERROR 0     // -- No error the date is valid
#define CIN_FAILED 1   // -- istream failed when entering information
#define YEAR_ERROR 2   // -- Year value is invalid
#define MON_ERROR 3    // -- Month value is invalid
#define DAY_ERROR 4    // -- Day value is invalid
#include <iostream>
namespace sict{


  class Date{
  	int year_;          // Holds the year; a four digit integer between MIN_YEAR and MAX_YEAR, defined in “general.h”
  	int mon_;	        // Month of the year, between 1 to 12
  	int day_;	        // Day of the month, note that in a leap year February is 29 days, (see mday() member function)
  	int readErrorCode_; // This variable holds an error code with which the caller program can find out if the date value is valid or not, and which part is erroneous if so.
  private:
    int value()const;
    void errCode(int errorCode);
  public:
  	Date();
  	Date(int year, int month, int day);

  bool operator==(const Date& D)const;
	bool operator!=(const Date& D)const;
	bool operator<(const Date& D)const;
	bool operator>(const Date& D)const;
	bool operator<=(const Date& D)const;
	bool operator>=(const Date& D)const;

    int mdays()const;

    int errCode()const;
    bool bad()const;

    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr)const;
  };

  std::ostream& operator<<(std::ostream& ostr, const Date& Date);
  std::istream& operator>>(std::istream& istr, Date& Date);

}
#endif