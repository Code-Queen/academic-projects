// The Aid Management Aplication
// AidApp.cpp
// Version 1.0
// Date 2016-04-10     
/////////////////////////////////////////////////////////////////
#include "AidApp.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace sict{
	AidApp::AidApp(const char* filename){
  		std::strcpy(filename_, filename);
  		for (int i = 0; i < MAX_NO_RECS; i++)
  		{
  			product_[i] = nullptr;
  		}
  		noOfProducts_ = 0;
  		loadRecs();
	}
	void AidApp::pause()const{
		cout << "Press Enter to continue..." << endl;
		std::cin.ignore(1000, '\n');
	}
	int AidApp::menu(const char* name, const char* name2){
		int option;
		cout
	    << "Disaster Aid Supply Management Program" << endl
	    << "1- List products" << endl
	    << "2- Display product" << endl
	    << "3- Add non-perishable product" << endl
	    << "4- Add perishable product"  << endl
	    << "5- Add to quantity of purchased products" << endl
	    << "6- Update product quantity" << endl
	    << "7- Delete "<< name << endl
	    << "8- Sort " << name2 << endl
	    << "0- Exit program" << endl
	    << "> ";
  		cin >> option;
  		if(option < 0 || option > 8){
  			option = -1;
  		}
  		std::cin.clear();
  		std::cin.ignore(1000, '\n');
  		return option;
	}
	void AidApp::loadRecs(){

	
		char ch;
		fstream f;
		Product* temp;
		f.open(filename_, ios::in);
        noOfProducts_ = 0;
		if (!f.fail()){
	        while(!f.eof()) {
	        	ch = ' ';
	        	f >> ch;
		  		f.ignore(1);
		  		temp = nullptr;

				if (ch == 'P'){
					temp = new AmaPerishable(); 
				} else if (ch == 'N'){
					temp = new AmaProduct('N'); 
				} 
				if(temp != nullptr) {			
					temp->load(f);
					delete product_[noOfProducts_];
					product_[noOfProducts_++] = temp;
				}
			}
		} else{
			f.clear();
			f.open(filename_, ios::out);
		}
		
		f.close();






	}
	void AidApp::saveRecs(){
		fstream f;
		f.open(filename_, ios::out);
		for (int i = 0; i < noOfProducts_; i++){
			product_[i]->store(f);

		}
		f.clear();
		f.close();
	}
	void AidApp::listProducts()const{
		double totalCost = 0;
		cout << endl;
		cout <<" Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl
             <<"-----|--------|--------------------|-------|----|----------|----|----------" << endl;
        for (int i = 0; i < noOfProducts_; i++){
        	cout.unsetf(ios::right);
  			cout.width(4);
  			cout.setf(ios::right);
			cout << i+1 ;
			cout.unsetf(ios::right);
			cout << " | ";
			product_[i]->write(cout,true);
			cout << endl;
			totalCost+=product_[i]->cost()*product_[i]->quantity();
			
			if (i == 9){
				pause();
			}
		}
		cout << "---------------------------------------------------------------------------" << endl;
		cout << "Total cost of support: $";
		cout.precision(2);
		cout << totalCost << endl;
	}
	int AidApp::searchProducts(const char* sku)const{

		int result = -1;
		for (int i = 0; i < noOfProducts_; i++){
			if (*product_[i] == sku ){
				result = i;
			} 
		}
		return result;
	}
	void AidApp::addQty(const char* sku){
		int result = searchProducts(sku);
		int qty;
	//	int i;

		if (result == -1){      
			cout << "Not found!" << endl;
		} else {
			product_[result]->write(cout,false);
			cout << endl;
			cout << "\nPlease enter the number of purchased items: ";
			cin >> qty;
			if (cin.fail()){
				cout << "Invalid quantity value! " << endl;
			} else{
				if (qty <= (product_[result]->qtyNeeded() - product_[result]->quantity()))
				{
					*product_[result] += qty;
				} else {
					*product_[result] += (product_[result]->qtyNeeded() - product_[result]->quantity());
					cout << "Too many items; only " << product_[result]->qtyNeeded() - product_[result]->quantity() << " is needed, please return the extra " << qty - (product_[result]->qtyNeeded() - product_[result]->quantity()) << " items." << endl;
				}
			}
			saveRecs();
			cout << endl;
			cout << "Updated!" << endl;
			std::cin.clear();
  			std::cin.ignore(1000,'\n');
		}
	}
	void AidApp::updQty(const char* sku){
		int result = searchProducts(sku);
		int qty;
	

		if (result == -1){      
			cout << "Not found!" << endl;
		} else {
			product_[result]->write(cout,false);
			cout << endl;
			cout << "\nPlease enter the new item quantity: ";
			cin >> qty;
			if (cin.fail()){
				cout << "Invalid Quantity value! " << endl;
			} else{
				if (qty <= product_[result]->quantity())
				{
					product_[result]->quantity(qty);
					cout << "Item quantity is set to " << qty << "." << endl;
				} else {
					cout << "Invalid Quantity value, please enter a value between 0 and " << product_[result]->quantity() << "." << endl;
				}
			}
			saveRecs();
			cout << endl;
		
			std::cin.clear();
  			std::cin.ignore(1000,'\n');
		}
	}
	void AidApp::addProduct(bool isPerishable){
    Product* temp;
		if (isPerishable == true)
		{
			temp = new AmaPerishable();
    }
    else{
      temp = new AmaProduct('N');
    }
		temp->read(cin);
    if (cin.fail())
    {
      cout << *temp;
      delete temp;
    }
    else if (noOfProducts_ + 1<MAX_NO_RECS){
  		product_[noOfProducts_] = temp;
      noOfProducts_ += 1;
      saveRecs();
    }
    else{
      delete temp;
    }
		
	}
	void AidApp::deleteProduct(const char* sku){
		int result = searchProducts(sku);
		int found = 0;
		int i;

		if (result == -1){      
			cout << "Not found!" << endl;
		} else {
			fstream f;
			f.open(filename_, ios::out);
			for (i = 0; i < noOfProducts_; i++){
				if(product_[i]->sku() != product_[result]->sku()){
					product_[i]->store(f);
				} else{
					found = 1;
				}
			}
			if(found !=0){
				noOfProducts_ = i;
			}
			f.clear();
			f.close();
			if(f.fail()){
				cout << "Failed!" << endl;
			} else {
				loadRecs();
				cout << "Deleted!" << endl;
			}
		}
		
	}
	void AidApp::sortProducts(){
		sort(product_, noOfProducts_);	
	}
	int AidApp::run(){
		char sku[MAX_SKU_LEN];
		char name[8] = "product";
		char name2[9] = "products";
		int result, i;

		do{
		result = menu(name, name2);
		std::strncpy(name,"product", 8);
		std::strncpy(name2,"products", 9);

		    switch(result){
			case 1:
					listProducts();
					std::strncpy(name,"droduct", 8);
					std::strncpy(name2,"Products", 9);
					cout << endl;
					pause();
					break;
			case 2:
					cout << "Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN);
					i = searchProducts(sku);
					cout << endl;
					if (i > -1){
						product_[i]->write(cout,false);
						cout << endl;
					} else{
						cout << "Not found!" << endl;
					}
					cout << endl;
					pause();
					break;
			case 3:
				    cout << endl;
					addProduct(false);
					loadRecs();
					cout << endl;
					cout << "Product added" << endl;
					cout << endl;
					
					break;
			case 4:
			        cout << endl;
					addProduct(true);
					loadRecs();
					cout << endl;
					cout << "Product added" << endl;
					cout << endl;
				
					break;
			case 5:
					cout << endl;
					cout << "Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN);
					cout << endl;
					addQty(sku);
					cout << endl;
					pause();
					break;
			case 6:
					cout << endl;
					cout << "Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN);
					cout << endl;
					updQty(sku);
					std::strncpy(name,"droduct", 8);
					std::strncpy(name2,"Products", 9);
			
					break;
			case 7:
					cout << endl;
					cout << "Deleting product, Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN);
					cout << endl;
					deleteProduct(sku);
					std::strncpy(name,"droduct", 8);
					std::strncpy(name2,"Products", 9);
					cout << endl;
				
					break;
			case 8:
					sortProducts();
					saveRecs();
				
					std::strncpy(name,"droduct", 8);
					std::strncpy(name2,"Products", 9);
					cout << endl;
					cout << "Sorted!" << endl;
					cout << endl;
					break;
		    case 0:
		    		break;
			default:
					cout << "===Invalid Selection, try again.===" << endl;
					cout << endl;
					pause();
			}
		} while (result != 0);
		cout << endl;
		cout << "Goodbye!!" << endl;
		return 0;
	}
}