// Unsigned int, Enumerations, String Class and File I/O 
// File	station.h
// Date	2016/09/18

#ifndef STATION_H_
#define STATION_H_


using namespace std;

namespace w2{

	enum PassType {STUDENT_PASS, ADULT_PASS, PASS_COUNT}; // qual to 0, 1, 2 respectively

	class Station{
		string name;
		unsigned passes[PASS_COUNT];

	public:
		Station();
		void set(const std::string n, unsigned s, unsigned a);

		void update(PassType pt, int val); //updates the number of passes - sold if negative, added if positive

		unsigned inStock(PassType pt) const; //returns the number of passes of the requested type

		const std::string& getName() const; //returns a reference to a string object holding the name of the station

		Station(fstream& is);
		void update();
		void restock();
		void report();
	};

} // namespace w2

#endif