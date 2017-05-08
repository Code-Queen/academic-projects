// File: ErrorMessage.cpp
// Version 1.0
// Date	07 March 11 2016
// Description
// This file contains definitions of the ErrorMessage class
/////////////////////////////////////////////////////////////////
#include "ErrorMessage.h"
#include <cstring>
using namespace std;
namespace sict{

	//Constructors
	ErrorMessage::ErrorMessage(){
		message_ = nullptr;
	}
  	ErrorMessage::ErrorMessage(const char* errorMessage){
  		message_ = nullptr;
  		message(errorMessage);
  	}

	//Operator overload
  	ErrorMessage& ErrorMessage::operator=(const char* errorMessage){
  		message(errorMessage);
  		return *this;
  	}

  	//Destructor
  	ErrorMessage::~ErrorMessage(){
  		delete[] message_;
  	}

  	void ErrorMessage::clear(){
  		delete[] message_;
  		message_ = nullptr;
  	}
  	bool ErrorMessage::isClear()const{
  		return message_ == nullptr;
  	}
  	void ErrorMessage::message(const char* value){
  	//	clear();
  		message_ = new char[std::strlen(value + 1)];
  		std::strcpy(message_, value);
  	}
  	const char* ErrorMessage::message()const{
  		return message_;
  	}

  	//Helper function
	std::ostream& operator<<(std::ostream& ostr,  ErrorMessage& error){
		if(!error.isClear()){
			cout << error.message();
		}
		return ostr;
	}


}