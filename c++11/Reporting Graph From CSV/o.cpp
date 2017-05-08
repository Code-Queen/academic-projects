// o.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
#include "o.h"

using namespace std;

	Order::Order() {

	}
	Order::Order(vector<string>& row){

		if(row.size() <3){
			throw string("Expected 3 or more , found: >")+ to_string(row.size()) + "<";
		}
	
		if (customerNameValid(row[0])){
			orderCustomer  = row[0];
		} else {
			throw string("Expected a customer name, found: >")+ row[0] + "<";
		}	

		if (productNameValid(row[1])){
			orderProduct  = row[1];
		} else {
			throw string("Expected an order name, found: >")+ row[1] + "<";
		}	
		
		for (size_t i = 2; i < row.size(); i++){
			if (itemNameValid(row[i])){
				itemsOrdered.push_back(move(row[i]));
			} else {
				throw string("Expected an item name, found: >")+ row[i] + "<";
			}
		}
	}
	void Order::print(){
		cout << "["<< orderCustomer << "]" 
			 << "["<< orderProduct << "]";
		for (auto e : itemsOrdered){
			cout << "["<< e << "]";			 
		}
		cout << "\n";	 
	}

	void Order::graph(fstream& os){
		if (not itemsOrdered.empty()){
			for(auto e : itemsOrdered){
			os << '"' << orderCustomer << '"' << "->" << '"' << e << '"' << "[color=blue];\n";
			}			
		}
	}
	size_t Order::size(){
		return itemsOrdered.size();
	}
	const string& Order::item(size_t i){
		return itemsOrdered[i];
	}
	const string& Order::getOrderCustomer() const{
		return orderCustomer;
	}
	const string& Order::getOrderProduct() const{
		return orderProduct;
	}



	OrderManager::OrderManager(){

	}
	OrderManager::OrderManager(vector< vector< string > >& csvOrder){
		int lineNumber = 0;
		for (auto &row : csvOrder)
		{
			try{
				lineNumber++;
				orderList.push_back(move(Order(row)));
			} catch (const string& e){
				cerr << "Error: on line "<< lineNumber << ": " << e << "\n";
			}
		}
	}
	void OrderManager::print(){
		for(auto t : orderList){
			t.print();
		}
	}
	void OrderManager::graph(string filename){
		fstream os(filename,ios::out | ios::trunc);
		if (os.is_open())
		{
			os << "Digraph tas {\n";
			for(auto t : orderList){
				t.graph(os);
			}
			os << "}\n";
			os.close();
		}
		// to convert to png
		//string cmd = "dot -Tpng " + filename + " > " + filename + ".png";
		//system(cmd.c_str());
	}
	bool OrderManager::checkIntefrity(ItemManager& im){
		bool ret = true;
		for(auto o: orderList){ // for each order check that item in the order exists in the item data
			for (size_t i=0; i< o.size(); i++){
				if(im.find(o.item(i)) == nullptr){
					cerr << "Order " << o.getOrderCustomer() << " / " << o.getOrderProduct() << " references item " << o.item(i) << " but it does not exist\n";
					ret = false;
				}
			}
		};
		return ret;
	}
	size_t OrderManager::size(){
		return orderList.size();
	}
	Order* OrderManager::getOrder(size_t t){
		return &orderList[t];
	}
