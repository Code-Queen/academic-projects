// Unsigned int, Enumerations, String Class and File I/O 
// File	stations.h
// Date	2016/09/18

#ifndef STATIONS_H_
#define STATIONS_H_

#include "station.h"

using namespace std;

namespace w2{

	class Stations{
		int stationCount;
		Station* stationTable; 
	public:
		~Stations();
		Stations (char *filename);
		void update();
		void restock();
		void report();
	};

} //namespace w2

#endif