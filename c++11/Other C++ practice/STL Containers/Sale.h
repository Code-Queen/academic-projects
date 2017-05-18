#pragma once
// STL Containers
// Sale.h
// Date 2016/11/06

#ifndef _SALE_H__
#define _SALE_H__
#include <iostream>
#include <fstream>
#include <vector>
#include "iProduct.h"

using namespace std;

namespace w7{

  class Sale{
  private:
  	vector<iProduct*> products;
  public:
  	Sale();
  	~Sale();
    Sale(char* filename);
	void display(std::ostream& os) const;
  };

}

#endif
