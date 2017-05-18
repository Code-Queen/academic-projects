// Lambda Expression
// Grades.cpp
// Date 2016/10/23

#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <iomanip>
#include "Grades.h"
using namespace std;

	// ---Destractors --------------------------------------------

	Grades::~Grades(){};

	// ---Constractors -------------------------------------------

	Grades::Grades():count(0), studentTable(nullptr){}

	Grades::Grades(char* filename):count(0), studentTable(nullptr){	
		fstream is(filename);
		if (is.is_open()){

			string line;

			//count number of lines in the file
			while(getline(is,line)){
				count++;

			}
			

			studentTable = new string[count];

			//getline hit END-OF-FILE
			//file is in error state. cannot read or seekg while in error state
			is.clear(); // reset error state

			is.seekg(0);				 // go to start of file
			is.seekg(0, ios_base::beg); // same thing

			//read the file storing each line
			for (size_t i = 0; i < count; i++)
			{
				getline(is,studentTable[i]);

				auto cr= studentTable[i].find('\r'); //
				if(cr != string::npos){           // return value match
					studentTable[i].erase( cr );     // will erace the charage return (cr - \r) at the end
				}                                 //
			}
			is.close();

	
		} else {
			cerr << "Cannot open file " << filename << "\n";
		}
	}

	Grades::Grades(const Grades& rhs){
	cout << "copy constractor \n"; 
	#if 0
		count = rhs.count;
		studentTable = new string[count];

		//deep copy
			for (size_t i = 0; i < count; i++)
			{
				studentTable[i] = rhs.studentTable[i];
			}
	#else
		count = 0;
		studentTable = nullptr;
		*this = rhs; // use copy assignment operator
	#endif
	}

	Grades::Grades(Grades&& rhs){
		cout << "move constractor \n"; 

		//steal 'brains'
		count = rhs.count;
		studentTable = rhs.studentTable;

		//make rhs a 'zombie'
		rhs.count = 0;
		rhs.studentTable = nullptr;
	}

	//---Functions --------------------------------------------------------

	//receives a reference to the output stream object and the expression 
	//to be used in determining the letter grade.  Your function displays 
	//the student number, the student grade, and the letter equivalent as 
	//shown below on the right.
	void Grades::displayGrades(std::ostream& os, std::function<const char*(float)>letter) const{
		for (size_t i = 0; i < count; i++)
		{
			string line = studentTable[i]; //1022342 67.4
			size_t j=0;
			string number;
			string grade;

			while(j<sizeof(line) && line[j] != ' '){
							number += line[j];
							j++;
						}
						j++; //skip space
						
						while(j<sizeof(line)){
							grade += line[j];
							j++;
						}

			os << number << " " << std::fixed << std::setprecision(2) << std::stof(grade) << " " << letter(std::stof(grade)) << "\n";
		}
	} 

	//---- Operators ------------------------------------------------------

	Grades& Grades::operator= (const Grades& rhs){
		cout << "copy operator= \n";
		if (this != &rhs){
			count = rhs.count;
			delete [] studentTable;

			studentTable = new string[count];

			//deep copy
			for (size_t i = 0; i < count; i++)
			{
				studentTable[i] = rhs.studentTable[i];
			}
		}
		return *this;
	}

	Grades&& Grades::operator= (Grades&& rhs){
		cout << "move operator= \n";
		if (this != &rhs){
			delete [] studentTable;

			//steal 'brains'
			count     = rhs.count;
			studentTable = rhs.studentTable;

			// turn rhs into a 'zombie'
			rhs.count     = 0;
			rhs.studentTable = nullptr;


		}
		return move(*this);
	}

