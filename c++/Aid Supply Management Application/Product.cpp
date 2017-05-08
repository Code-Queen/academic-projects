// File: Product.cpp
// Version: 1.0
// Date: 2016/03/19
// This file defines Product Class
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Product.h"
using namespace std;
namespace sict{
	Product::Product(){
		sku_[0] = 0;
		name_ = nullptr;
  		price_ = 0;
  		quantity_ = 0;
  		qtyNeeded_ = 0;
	}
    Product::Product(const char* skuValue, const char* nameValue, bool taxedValue, int priceValue, int quantityNeededValue){
  		std::strncpy(sku_, skuValue, MAX_SKU_LEN);
       delete [] name_; 
  		name_ = new char[std::strlen(nameValue + 1)];
  		std::strcpy(name_, nameValue);
  		quantity_ = 0;
  		price_ = priceValue;
  		qtyNeeded_ = quantityNeededValue;
  		taxed_ = taxedValue;
    }

  	Product::Product(const Product& src) {
		std::strncpy(sku_, src.sku_, MAX_SKU_LEN);
	  	price_ = src.price_;
	  	taxed_ = src.taxed_;
	  	quantity_ = src.quantity_;
	  	qtyNeeded_ = src.qtyNeeded_;
       delete [] name_; 
	    if (src.name_ != nullptr) {
	        name_ = new char[std::strlen(src.name_ + 1)]; 
	        std::strcpy(name_, src.name_);
	    } else{
	        name_ = nullptr;
	    }

  	}

	Product& Product::operator=(const Product& src){
	    if (this != &src) {
	    	std::strncpy(sku_, src.sku_, MAX_SKU_LEN);
	  		price_ = src.price_;
	  		taxed_ = src.taxed_;
	  		quantity_ = src.quantity_;
	  		qtyNeeded_ = src.qtyNeeded_;
	        delete [] name_;
	        if (src.name_ != nullptr) {
	        	name_ = new char[std::strlen(src.name_ + 1)]; 
	        	std::strcpy(name_, src.name_);
	    	} else{
	        	name_ = nullptr;
	    	}
	    }
	    return *this;
	 }
	Product::~Product(){
    	delete[] name_; 
  	}

    void Product::sku(const char* skuValue){
    	std::strncpy(sku_, skuValue, MAX_SKU_LEN);
    }
    void Product::name(const char* nameValue){
      delete[] name_; 
    	name_ = new char[std::strlen(nameValue + 1)];
  		std::strcpy(name_, nameValue);
    }
    void Product::price(double priceValue){
    	price_ = priceValue;
    }
    void Product::taxed(char taxedValue){
      if (taxedValue == 'Y' || taxedValue == 'y' || taxedValue == '1')
      {
       taxed_ = true;
      } else if (taxedValue == 'N' || taxedValue == 'n' || taxedValue == '0')
      {
        taxed_ = false;
      }
    }
    void Product::quantity(int quantityValue){
    	quantity_ = quantityValue;
    }
    void Product::qtyNeeded(int quantityNeededValue){
    	qtyNeeded_ = quantityNeededValue;
    }
    const char* Product::sku()const{
    	return sku_;
    }
    const char* Product::name()const{
    	return name_;
    }
    double Product::price()const{
    	return price_;
    }
    bool Product::taxed()const{
    	return taxed_;
    }
    int Product::quantity()const{
    	return quantity_;
    }
    int Product::qtyNeeded()const{
    	return qtyNeeded_;
    }
    double Product::cost()const{
    	if (taxed() == true)
    	{
    		return price_ * 1.13;
    	} else {
    	  return price_;
    	}
    }
    bool Product::isEmpty()const{
    	return sku_[0] == 0 && name_ == nullptr && price_ == 0 && quantity_ == 0 && qtyNeeded_ == 0;
    }
    bool Product::operator==(const char* value)const{
    	return strcmp(sku_,value) == 0;
    }
	int Product::operator+=(int value){
		return quantity_ = quantity_ + value;
		return quantity_;
	}
	int Product::operator-=(int value){
		return quantity_ = quantity_ - value;
		return quantity_;
	}
	double operator+=(double& value, const Product& src){
		return value = src.cost() * src.quantity() + value;
	}
  bool operator>(const Product& P1, const Product& P2){
    return std::strcmp(P1.name(), P2.name()) >0;
  }
	std::ostream& operator<<(std::ostream& ostr, Product& Product){
    Product.write(ostr, true);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr,  Product& Product){
		Product.read(istr);
		return istr;
	}
}