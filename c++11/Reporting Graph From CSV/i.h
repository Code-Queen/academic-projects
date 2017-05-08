#pragma once
// i.h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
#include "t.h"

using namespace std;

class Item{
	string itemName, itemInstaller, itemRemover, itemSequence, itemDescription;
public:
	Item();
	Item(vector<string>& row);
	void print();
	void graph(fstream& os);

	const string& getItemName() const;
	const string& getItemInstaller() const;
	const string& getItemRemover() const;
};

class ItemManager{
	vector<Item> itemList;
public:
	ItemManager();
	ItemManager(vector< vector< string > >& csvItem);
	void print();
	void graph(string filename);

	bool checkIntefrity(TaskManager& tm);
	Item* find(const string& n);
	size_t size(){
		return itemList.size();
	};
	Item* getItem(size_t i){
		return &itemList[i];
	};
};
