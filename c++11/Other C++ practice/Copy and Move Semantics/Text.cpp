// Copy and Move Semantics
// File Text.cpp
// Date 2016/09/23

#include <fstream>
#include <iostream>
#include <string>

#include "Text.h"

using namespace std;



namespace w3{


	// ---Destractors --------------------------------------------
	Text::~Text(){
		cout << "~Text \n";
		delete [] lineTable;
	}

	// ---Constractors -------------------------------------------
	Text::Text():count(0), lineTable(nullptr){
		cout << "Text() \n";
	
	}
	Text::Text(char* filename):count(0), lineTable(nullptr){
		cout << "Text(filename) \n";
		fstream is(filename);
		if (is.is_open()){

			string line;

			//count number of lines in the file
			while(getline(is,line)){
				count++;

			}
			cout << "File "<< filename << " has " << count << " lines. \n";

			lineTable = new string[count];

			//getline hit END-OF-FILE
			//file is in error state. cannot read or seekg while in error state
			is.clear(); // reset error state

			is.seekg(0);				 // go to start of file
			is.seekg(0, ios_base::beg); // same thing

			//read the file storing each line
			for (size_t i = 0; i < count; i++)
			{
				getline(is,lineTable[i]);

				auto cr= lineTable[i].find('\r'); //
				if(cr != string::npos){           // return value match
					lineTable[i].erase( cr );     // will erace the charage return (cr - \r) at the end
				}                                 //
			}
			is.close();

			print();
		} else {
			cerr << "Cannot open file " << filename << "\n";
		}
	}

	Text::Text(const Text& rhs){   //rhs -right hand side
		cout << "copy constractor \n"; 
#if 0
		count = rhs.count;
		lineTable = new string[count];

		//deep copy
			for (size_t i = 0; i < count; i++)
			{
				lineTable[i] = rhs.lineTable[i];
			}
#else
	count = 0;
	lineTable = nullptr;
	*this = rhs; // use copy assignment operator
#endif
	}


	Text::Text(Text&& rhs){ 
		cout << "move constractor \n"; 

		//steal 'brains'
		count = rhs.count;
		lineTable = rhs.lineTable;

		//make rhs a 'zombie'
		rhs.count = 0;
		rhs.lineTable = nullptr;
	}

	//---Functions --------------------------------------------------------
	size_t Text::size() const{
		return count;
	}
	void Text::print(){
		for (size_t i = 0; i < count; i++)
		{
			cout << "Line " << i+1 << " --- >" << lineTable[i] << " <--- \n";
		}
	}

	//---- Operators ------------------------------------------------------
	Text& Text::operator= (const Text& rhs){  // copy assignment operator
		cout << "copy operator= \n";
		if (this != &rhs){
			count = rhs.count;
			delete [] lineTable;

			lineTable = new string[count];

			//deep copy
			for (size_t i = 0; i < count; i++)
			{
				lineTable[i] = rhs.lineTable[i];
			}
		}
		return *this;
	}
	Text&& Text::operator= (Text&& rhs){    //move assignment operator
		cout << "move operator= \n";
		if (this != &rhs){
			delete [] lineTable;

			//steal 'brains'
			count     = rhs.count;
			lineTable = rhs.lineTable;

			// turn rhs into a 'zombie'
			rhs.count     = 0;
			rhs.lineTable = nullptr;


		}
		return move(*this);
	}








	} //namspace w3