// i.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
#include "i.h"

using namespace std;

	Item::Item() {

	}
	Item::Item(vector<string>& row){
		switch(row.size()){
			case 5:
				itemDescription = row[4];
			case 4:
				if (validSequence(row[3]))
				{
					itemSequence  = row[3];
				} else {
					throw string("Expected a sequence number, found: >")+ row[3] + "<";
				}	
		//	case 3:
				if (itemNameValid(row[2]))
				{
					   itemRemover = row[2];
				} else {
					throw string("Expected remover task name, found: >")+ row[2] + "<";
				}
		//	case 2:
				if (itemNameValid(row[1]))
				{
					itemInstaller  = row[1];
				} else {
					throw string("Expected a installer task name, found: >")+ row[1] + "<";
				}
		//	case 1:
				if (itemNameValid(row[0]))
				{
					itemName  = row[0];
				} else {
					throw string("Expected a item name, found: >")+ row[0] + "<";
				}
			break;
			default:
			 throw string("expected 4 or 5 fields, but found ") + to_string(row.size());
		}
	}
	void Item::print(){
		cout << "["<< itemName << "]" 
			 << "["<< itemInstaller << "]" 
			 << "["<< itemRemover << "]" 
			 << "["<< itemSequence << "]" 
			 << "["<< itemDescription << "]" 
			 << "\n";
	}

	void Item::graph(fstream& os){	
		if (not itemInstaller.empty()){
			os << '"' << "Item Name:" << itemName << '"' << " ->" << '"' << "Installer Name:" << itemInstaller << '"' << "[color=green];\n";	
		}
		if (not itemRemover.empty()){
			os << '"' << "Item Name:" << itemName << '"' << " ->" << '"' << "Remover Name:" << itemRemover << '"' << "[color=red];\n";
		}
	}
	const string& Item::getItemName() const{
		return itemName;
	}
	const string& Item::getItemInstaller() const{
		return itemInstaller;
	}
	const string& Item::getItemRemover() const{
		return itemRemover;
	}


	ItemManager::ItemManager(){

	}
	ItemManager::ItemManager(vector< vector< string > >& csvItem){
		int lineNumber = 0;
		for (auto &row : csvItem)
		{
			try{
				lineNumber++;
				itemList.push_back(move(Item(row)));
			} catch (const string& e){
				cerr << "Error: on line "<< lineNumber << ": " << e << "\n";
			}
		}
	}
	void ItemManager::print(){
		for(auto t : itemList){
			t.print();
		}
	}
	void ItemManager::graph(string filename){
		fstream os(filename,ios::out | ios::trunc);
		if (os.is_open())
		{
			os << "Digraph tas {\n";
			for(auto t : itemList){
				t.graph(os);
			}
			os << "}\n";
			os.close();
		}
		// to convert to png
		//string cmd = "dot -Tpng " + filename + " > " + filename + ".png";
		//system(cmd.c_str());
	}

	Item* ItemManager::find(const string& n){
			for(size_t i = 0; i < itemList.size(); i++){
				if(itemList[i].getItemName() == n){
					return &itemList[i];
				};
			};
			return nullptr;
	}
	bool ItemManager::checkIntefrity(TaskManager& tm){
		bool ret = true;
		for(auto i: itemList){
			if(tm.find(i.getItemInstaller()) == nullptr){
				cerr << "Item " << i.getItemName() << " references installer task " << i.getItemInstaller() << " but it does not exist\n";
				ret = false;
			};
			if(tm.find(i.getItemRemover()) == nullptr){
				cerr << "Item " << i.getItemName() << " references remover task " << i.getItemRemover() << " but it does not exist\n";
				ret = false;
			};
		};
		return ret;
	}