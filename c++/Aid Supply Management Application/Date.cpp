// File: Date.cpp
// Version 1.0
// Date	07 March 03 2016
// Description
// This file contains definitions of the Date class
/////////////////////////////////////////////////////////////////
#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"
#include "general.h"
namespace sict{


//int Date::value()const --- This function returns a unique integer number based on the date. 
//  This value is used to compare two dates. (If the value() of date one is 
//  larger than date two, then date one is after date two). 
    int Date::value()const{
      return year_ * 372 + mon_ * 31 + day_;
    }
//void errCode(int errorCode) ---  This function sets the readErrorCode_ member-variable
//  to one of the values difined in header file.    
    void Date::errCode(int errorCode){
    	readErrorCode_ = errorCode;
    }

//Constractors    
    Date::Date(){
    	year_ = 0;
    	mon_ = 0;
    	day_ = 0;
    	readErrorCode_ = NO_ERROR;
    }
  	Date::Date(int year, int month, int day){
  		year_ = year;
  		mon_ = month;
  		day_ = day;
  		readErrorCode_ = NO_ERROR;
  	}

//Operator overloads
  	bool Date::operator==(const Date& D)const{
  		return this->value() == D.value();
  	}
	bool Date::operator!=(const Date& D)const{
		return this->value() != D.value();
	}
	bool Date::operator<(const Date& D)const{
		return this->value() < D.value();
	}
	bool Date::operator>(const Date& D)const{
		return this->value() > D.value();
	}
	bool Date::operator<=(const Date& D)const{
		return this->value() <= D.value();
	}
	bool Date::operator>=(const Date& D)const{
		return this->value() >= D.value();
	}

//int Date::mdays()const --- This function returns the number of days in a month.
	int Date::mdays()const{
	  int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
	  int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
	  mon--;
	  return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}

//Accessor / getter member functions
	int Date::errCode()const{
		return readErrorCode_;
	}
	bool Date::bad()const{
		return (readErrorCode_ != 0); 
	}

//IO member-funtions
	std::istream& Date::read(std::istream& istr){
		char separator;
	
		 istr >> year_;	 
		 istr >> separator;
		 istr >> mon_;
		 istr >> separator;
		 istr >> day_;

	    if (!istr.fail()){
			if (year_ < MIN_YEAR || year_ > MAX_YEAR){
				readErrorCode_ = YEAR_ERROR;
			} else if (mon_ < 1 || mon_ > 12){
				readErrorCode_ = MON_ERROR;
			} else if (day_ < 1 || day_ > mdays()){ 
				readErrorCode_ = DAY_ERROR;
			}
		} else{
			readErrorCode_ = CIN_FAILED; 
		}
	    return istr;
	}
	std::ostream& Date::write(std::ostream& ostr) const{
		char slash('/');
		ostr << year_ ;
		ostr << slash;
		ostr.width(2);
		ostr.fill('0');
		ostr << mon_;
		ostr << slash;
		ostr.width(2);
		ostr.fill('0');
		ostr << day_;
		ostr.fill(' ');
		return ostr;
	}

//Non-member IO operator overloads
	ostream& operator<<(ostream& ostr, const Date& Date){
    	return Date.write(ostr);
  	}

  	istream& operator>>(istream& istr, Date& Date){
    	return Date.read(istr);
  	}
}
