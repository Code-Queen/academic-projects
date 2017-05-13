// Unsigned int, Enumerations, String Class and File I/O 
// File	station.cpp
// Date	2016/09/18

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "station.h"
using namespace std;

namespace w2{

	Station::Station(){}

	void Station::set(const std::string n, unsigned s, unsigned a){
		name                 = n;
		passes[STUDENT_PASS] = s;
		passes[ADULT_PASS]   = a;
	}
	void Station::update(PassType pt, int val){ //updates the number of passes - sold if negative, added if positive
		passes[pt] += val;
	}

	unsigned Station::inStock(PassType pt) const{ //returns the number of passes of the requested type
		return passes[pt];
	}

	const std::string& Station::getName() const{ //returns a reference to a string object holding the name of the station
		return name;
	}

	Station::Station(fstream& is){
		string line;
		getline(is, line); // read up until semicolon
		cout << "station line: -->" << line << "<--\n";

		size_t i = 0;
		for ( ; i < line.size(); i++) {
			if (line[i] == ';'){
				break;
			}
			name += line[i];
		}

		cout << "name = ==>" << name << "<--\n";
		if(i == line.size()){
			cout << "Bad file line '" << line << "', missing ';'\n";
			exit(2);
		}
		i++; // skip ';'

		unsigned studentCount = 0;
		for ( ; i < line.size(); i++) {
			if (line[i] == ' '){
				break;
			}
			if (! isdigit(line[i])){
				cout << "Bad file line '" << line << "', non-digit '" << line[i] << "'in student cout field\n";
				exit(3);
			}
			studentCount = 10 * studentCount + (line[i] - '0'); // gives integer equivalent of digit -- in askii table substruction gives value of digit
		}
		cout << "studentCount = " << studentCount << "\n";
		i++; // skip ' '

		unsigned adultCount = 0;
		for ( ; i < line.size(); i++) {
			if (! isdigit(line[i])){
				cout << "Bad file line '" << line << "', non-digit '" << line[i] << "'in adult cout field\n";
				exit(4);
				break;
			}
			adultCount = 10 * adultCount + (line[i] - '0'); // gives integer equivalent of digit -- in askii table substruction gives value of digit
		}
		cout << "adultCount = " << adultCount << "\n";
		set(name,studentCount,adultCount);
	}

	void Station::update(){
		cout<< getName() << "\n";
		int s,a;
		cout <<"Student Passes sold : "; cin >> s;
  		cout <<"Adult   Passes sold : "; cin >> a;
  		update(STUDENT_PASS, s*(-1));
  		update(ADULT_PASS,   a*(-1));
	}
	void Station::restock(){
		cout<< getName() << "\n";
		int s,a;
		cout <<"Student Passes added : "; cin >> s;
  		cout <<"Adult   Passes added: "; cin >> a;
  		update(STUDENT_PASS, s);
  		update(ADULT_PASS,   a);
	}
	void Station::report(){
        cout << std::setw(19)
             << std::left
			 << name
			 << std::setw(6)
			 << std::right
			 << passes[STUDENT_PASS]
			 << std::setw(6)
			 << passes[ADULT_PASS]
			 << "\n";
	}


} // namespace w2