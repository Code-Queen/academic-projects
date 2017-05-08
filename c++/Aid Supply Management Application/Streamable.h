// File: Steamable.h
// Version: 1.0
// Date: 2016/03/15
// This file declares Steamable Interface
#ifndef SICT__Streamable_H_
#define SICT__Streamable_H_
#include <iostream>
#include <fstream>
using namespace std;
namespace sict{
  class Streamable{
  public:
    
  	virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const = 0;
  	virtual std::fstream& load(std::fstream& file) = 0;
  	virtual std::ostream& write(std::ostream& os, bool linear)const = 0;
  	virtual std::istream& read(std::istream& is) = 0;
  };
}
#endif