// AmaProduct.cpp
// Version 1.0
// Date 2016-03-27      
/////////////////////////////////////////////////////////////////
#include "AmaProduct.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace sict{
	AmaProduct::AmaProduct(char fileTag){
		fileTag_ = fileTag;
	}
  	const char* AmaProduct::unit()const{
  		return unit_;
  	}
  	void AmaProduct::unit(const char* value){
  		int len = std::strlen(unit_);
  		std::strncpy(unit_, value, len);
  		unit_[len]='\0';
  	}
  	std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine)const{ 
      file << fileTag_;
	    file << ",";
	    file << sku();
	    file << ",";
  		file << name();
  		file << ",";
  		file << price();
  		file << ",";
  		file << taxed();
  		file << ",";
  		file << quantity();
  		file << ",";
  		file << unit_;
  		file << ",";
  		file << qtyNeeded();

	    if (addNewLine == true)
	    {
	    	file << '\n';
	    }	
    	return file;
  	}
  	std::fstream& AmaProduct::load(std::fstream& file){
  		char sku[MAX_SKU_LEN];
  		char* name;
  		name = new char[20];
  		double price;
  		char taxed;
  		int quantity;
  		int qtyNeeded; 

  		file.getline(sku,MAX_SKU_LEN, ',');
      if (!file.fail()){
        Product::sku(sku);
      }
  		file.getline(name,20, ',');
      if (!file.fail()){
		    Product::name(name); 
      }	
	  	file >> price;
      if (!file.fail()){
	  	  Product::price(price);
      }
	  	file.ignore(1);
	  	file >> taxed;
      if (!file.fail()){
	  	  Product::taxed(taxed);
      }
	  	file.ignore(1);
		  file >> quantity;
      if (!file.fail()){
	  	  Product::quantity(quantity);
      }
	  	file.ignore(1);
	    file.getline(unit_,11, ',');
	  	file >> qtyNeeded;
      if (!file.fail()){
	  	  Product::qtyNeeded(qtyNeeded);
      }

	    return file;
  	}
  	std::ostream& AmaProduct::write(std::ostream& os, bool linear)const{
  		
      if (!err_.isClear())
  		{
  			os << err_.message();
  		} else{
  			if (linear == false)
  			{
  				os << "Sku: " << Product::sku();
  				os << endl;
  				os << "Name: " << Product::name();
  				os << endl;
  				os << "Price: " <<  Product::price();
  				os << endl;
				os << "Price after tax: ";
				Product::cost() == Product::price() ? os << "N/A" : os << Product::cost() ;
  				os << endl;
  				os << "Quantity On Hand: " << Product::quantity() << " " << unit_;
  				os << endl;
  				os << "Quantity Needed: " << Product::qtyNeeded();				  
			} else {
  				//1234   |Box                 | 139.50|   1|kg        |   5|
  				os.unsetf(ios::right);
  				os.width(MAX_SKU_LEN);
  				os.setf(ios::left);
  				os << Product::sku();
  				os << "|";
  				os.width(20);
				os.setf(ios::left);
  				os<<Product::name();
  				os << "|";
  				os.unsetf(ios::left);
				os.width(7);
  				os.setf(ios::right);
  				os << std::fixed;
  				os.precision(2);
  				os << Product::cost();
  				os << "|";
				os.width(4);
				os << Product::quantity();
				os << "|";
				os.unsetf(ios::right);
				os.width(10);
				os.setf(ios::left);
				os << unit_;
				os << "|";
				os.unsetf(ios::left);
				os.width(4);
				os.setf(ios::right);
				os << Product::qtyNeeded();
				os << "|";
  			}
		}
	    return os;
  	}
  	std::istream& AmaProduct::read(std::istream& istr){
  		char sku[MAX_SKU_LEN];
  		char* name;
  		name = new char[20];
  		double price;
  		char taxed;
  		int quantity;
  		int qtyNeeded; 
  		while(!istr.fail()){
  		cout << "Sku: ";	
  		cin.getline(sku,MAX_SKU_LEN);
  		Product::sku(sku);
  		cout << "Name: ";	
	  	cin.getline(name,20);
	  	Product::name(name);
	  	cout << "Unit: ";	 
	  	istr >> unit_;
	  	istr.clear();
	  	cout << "Taxed? (y/n): ";	
	  	istr >> taxed; 
	  	if (taxed == 'Y' || taxed == 'y' || taxed == 'N' || taxed == 'n')
	  	{
	  		Product::taxed(taxed);
	  		istr.clear();
	  	} else{
	  		err_.message("Only (Y)es or (N)o are acceptable");
	  		istr.setstate(ios::failbit);
	  		break;
	  	}  	
	  	cout << "Price: ";	
	  	istr >> price;
	  	Product::price(price);
	  	if (!Product::price())
  		{
  			err_.message("Invalid Price Entry");
  			break;
  		}
	  	istr.clear();
	  	cout << "Quantity On hand: ";	 
	  	istr >> quantity;
	  	Product::quantity(quantity);
	  	if (!Product::quantity())
  		{
  			err_.message("Invalid Quantity Entry");
  			break;
  		}
	  	istr.clear();
	  	cout << "Quantity Needed: ";	
	  	istr >> qtyNeeded; 
	  	Product::qtyNeeded(qtyNeeded);
	  	if (!Product::qtyNeeded())
  		{
  			err_.message("Invalid Quantity Needed Entry");
  			break;
  		}
	  	istr.clear(); 	
      break;
	     			
  		}

  		
      if(!cin.fail()){
        err_.clear();
      }
    	return istr;
  	}
}