// AmaPerishable.h
// Version 1.0
// Date 2016-03-27       
/////////////////////////////////////////////////////////////////
#ifndef SICT_AMAPERISHABLE_H__
#define SICT_AMAPERISHABLE_H__
#include <iostream>
#include <fstream>
#include "AmaProduct.h"
#include "general.h"
#include "ErrorMessage.h"
#include "Date.h"
using namespace std;

namespace sict{
  class AmaPerishable: public AmaProduct{
  private:
  	Date expiry_;
  public:
  	AmaPerishable();
  	const Date& expiry()const;
  	void expiry(const Date &value);
  	std::fstream& store(std::fstream& file, bool addNewLine = true)const;
  	std::fstream& load(std::fstream& file);
  	std::ostream& write(std::ostream& ostr, bool linear)const;
  	std::istream& read(std:: istream& istr);
  };
}
#endif
