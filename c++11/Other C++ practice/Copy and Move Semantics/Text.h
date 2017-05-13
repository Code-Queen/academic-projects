// Copy and Move Semantics
// File Text.h
// Date 2016/09/23

#include <fstream>
#include <iostream>
#include <string>

using namespace std;



namespace w3{

class Text{
	size_t count;
	string* lineTable;
public:
	// ---Destractors --------------------------------------------
	~Text();

	// ---Constractors -------------------------------------------
	Text();
	Text(char* filename);

	Text(const Text& rhs);


	Text(Text&& rhs);

	//---Functions --------------------------------------------------------
	size_t size() const;
	void print();
	//---- Operators ------------------------------------------------------
	Text& operator= (const Text& rhs);
	Text&& operator= (Text&& rhs);

};

} //namespace w3