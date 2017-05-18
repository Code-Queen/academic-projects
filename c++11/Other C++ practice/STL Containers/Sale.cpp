// STL Containers
// Sale.cpp
// Date 2016/11/06

#include <iostream>
#include <fstream>
#include <vector>
#include "Sale.h"
#include "iProduct.h"

using namespace std;

namespace w7{
 
  	Sale::Sale(){
  		products.erase(products.begin(),products.end());
  	}
  	Sale::~Sale(){
  		products.erase(products.begin(),products.end());
  	}
    Sale::Sale(char* filename){
    	ifstream is(filename, ios::in);
		if (not is.is_open()){ 
			throw string("Cannot open file ") + filename;
		};
	
		while(!is.eof()){
		iProduct* new_product;
		int product_number;
		float price;
		char tax, taxtemp;
			is >> product_number >> price;
			taxtemp = is.get();
			if (taxtemp == ' '){
				tax = is.get();		
			} else{
				tax = ' ';
			};
	      	if (tax == 'P' || tax == 'H'){	        
	        	new_product = new TaxableProduct(product_number,price,tax);
	        } else{
	        	new_product = new Product(product_number,price);
	        };
	      products.push_back(new_product);
    	};
		
		is.close();   
    }
    void Sale::display(std::ostream& os) const{
   		os << "Product No      Cost Taxable\n";
   		float total=0.0;
		for( auto i : products ){

			i->display(os);
			os << "\n";		
			if (i->getTax() == 'H'){
				total = i->getPrice()*1.13 + total;
			} else if(i->getTax() == 'P'){
				total = i->getPrice()*1.08 + total;
			} else{
				total = i->getPrice() + total;
			};
		};
		os << "     Total    " << total << "\n";    
   	}

}

