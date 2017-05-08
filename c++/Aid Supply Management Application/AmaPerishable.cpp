// AmaPerishable.cpp
// Version 1.0
// Date 2016-03-27      
/////////////////////////////////////////////////////////////////
#include "AmaPerishable.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

using namespace std;
namespace sict{
	AmaPerishable::AmaPerishable(){
		AmaProduct('P');
	}
	const Date& AmaPerishable::expiry()const{
		return expiry_;
	}
	void AmaPerishable::expiry(const Date &value){
		expiry_ = value;
	}
	std::fstream& AmaPerishable::store(std::fstream& file, bool addNewLine)const{
	
		AmaProduct::store(file,false);
	
	    file << ",";
	    file << expiry_;
	    if (addNewLine == true)
	    {
	    	file << '\n';
	    }
	   
    	return file;
	}
	std::fstream& AmaPerishable::load(std::fstream& file){
		AmaProduct::load(file);
		file.ignore(1);
    if (!file.fail()){
		  expiry_.read(file);
    }
 
  		
		return file;
	}
	std::ostream& AmaPerishable::write(std::ostream& ostr, bool linear)const{
		AmaProduct::write(ostr,linear);
		if (err_.isClear() && !isEmpty())
  		{
  			if (linear == true)
  			{
  				ostr << expiry_;
  			} else{
  				ostr << '\n';
  				ostr << "Expiry date: ";
  				ostr << expiry_;
  			}
  		} 
  		return ostr;
	}
  	std::istream& AmaPerishable::read(std::istream& istr){
  		AmaProduct::read(istr);
  		err_.clear();
  		Date date;

  		if (err_.isClear())
  		{  		
  			cout << "Expiry date (YYYY/MM/DD): ";
  			istr.clear();
  			istr >> date;
  		
  			
  				if(date.errCode() == CIN_FAILED){
  					err_.message("Invalid Date Entry");
  					istr.setstate(ios::failbit);
  					return istr;
  				} else if(date.errCode() == YEAR_ERROR){
  					err_.message("Invalid Year in Date Entry");
  					istr.setstate(ios::failbit);
  					return istr;
  				} else if(date.errCode() == MON_ERROR){
  					err_.message("Invalid Month in Date Entry");
  					istr.setstate(ios::failbit);
  					return istr;
  				} else if(date.errCode() == DAY_ERROR){
  					err_.message("Invalid Day in Date Entry");
  					istr.setstate(ios::failbit);
  					return istr;
  				} else 
            if(!istr.fail()){expiry(date);};        
  		}

  		return istr;
  	}
}
