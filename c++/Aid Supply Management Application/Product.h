// File: Product.h
// Version: 1.0
// Date: 2016/03/19
// This file declares Product Class
#ifndef SICT__PRODUCT_H_
#define SICT__PRODUCT_H_
#include <iostream>
#include <fstream>
#include "general.h"
#include "Streamable.h"

using namespace std;
namespace sict{
  class Product: public Streamable{
  	char sku_[MAX_SKU_LEN];
  	char* name_;
  	double price_;
  	bool taxed_;
  	int quantity_;
  	int qtyNeeded_;
  public:
    Product();
    Product(const char* skuValue, const char* nameValue, bool taxedValue = true, int priceValue =0, int quantityNeededValue=0);
    Product(const Product& src);
    Product& operator=(const Product& src);
    virtual ~Product();
    void sku(const char* skuValue);
    void name(const char* nameValue);
    void price(double priceValue);
    void taxed(char taxedValue);
    void quantity(int quantityValue);
    void qtyNeeded(int quantityNeededValue);
    const char* sku()const;
    const char* name()const;
    double price()const;
    bool taxed()const;
    int quantity()const;
    int qtyNeeded()const;
    double cost()const;
    bool isEmpty()const;
    bool operator==(const char* value)const;
	int operator+=(int value);
	int operator-=(int value);
  };
    bool operator>(const Product& P1, const Product& P2);
  	double operator+=(double& value, const Product& src);
  	std::ostream& operator<<(std::ostream& ostr,  Product& Product);
  	std::istream& operator>>(std::istream& istr,  Product& Product);
}
#endif