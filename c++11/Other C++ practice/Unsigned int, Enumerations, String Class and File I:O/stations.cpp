// Unsigned int, Enumerations, String Class and File I/O 
// File	stations.cpp
// Date	2016/09/18

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "stations.h"
#include "station.h"
using namespace std;

namespace w2{

	Stations::~Stations(){
		delete [] stationTable;
	}

	Stations::Stations (char *filename)
		: stationCount(0), stationTable(nullptr)
	{
		fstream is = fstream(filename, ios::in);  // is -input stream
		if(is.is_open()){

			string line;
			getline(is, line, ';'); // read up until semicolon
			cout << "first line in file: -->" << line << "<--\n";

			//check data on line is only digits
			bool bOK = true;
			for(size_t i =0; i < line.size(); i++){
				if(isdigit(line[i])) continue;
				bOK = false;
				break;
			}
			if(bOK){

				stationCount = stoi(line);
				getline(is, line); //skip a \n
				cout << "stationCount=" << stationCount << "\n";

				stationTable = new Station[stationCount];

				for (int s = 0; s < stationCount; s++){
					stationTable[s] = Station(is);
				}
			}


			is.close();
		} else{
			cerr << "cannot open file -->" << filename << "<--\n";
			exit(1);
		}
	}

	void Stations::update(){

		cout <<"Passes Sold :\n";
 		cout <<"-------------\n";

		for(int s = 0; s < stationCount; s++){
			stationTable[s].update(); // print out what Staition class knows about table, calls its function
		}
		cout <<"\n";
	}

	void Stations::restock(){

		cout <<"Passes Added :\n";
 		cout <<"-------------\n";

		for(int s = 0; s < stationCount; s++){
			stationTable[s].restock(); // print out what Staition class knows about table, calls its function
		}
		cout <<"\n";
	}

	void Stations::report(){
		cout << "Passes in Stock : Student Adult\n"
             << "-------------------------------\n";
		for(int s = 0; s < stationCount; s++){
			stationTable[s].report(); // print out what Staition class knows about table, calls its function
		}
	}

} // namespace w2