#pragma once
// o.h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
#include "i.h"

using namespace std;

class Order{
	string orderCustomer, orderProduct;
	vector<string> itemsOrdered;
public:
	Order();
	Order(vector<string>& row);
	void print();
	void graph(fstream& os);
	size_t size();
	const string& item(size_t i);
	const string& getOrderCustomer() const;
	const string& getOrderProduct() const;
};

class OrderManager{
	vector<Order> orderList;
public:
	OrderManager();
	OrderManager(vector< vector< string > >& csvOrder);
	void print();
	void graph(string filename);
	bool checkIntefrity(ItemManager& im);

	size_t size();
	Order* getOrder(size_t o);
};
