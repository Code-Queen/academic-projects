// Lambda Expression
// Grades.h
// Date 2016/10/23

using namespace std;


class Grades{
	size_t count;
	string* studentTable;
public:
	// ---Destractors --------------------------------------------
	~Grades();

	// ---Constractors -------------------------------------------
	Grades();
	Grades(char* filename);

	Grades(const Grades& rhs);
	Grades(Grades&& rhs);

	//---Functions --------------------------------------------------------

	//receives a reference to the output stream object and the expression 
	//to be used in determining the letter grade.  Your function displays 
	//the student number, the student grade, and the letter equivalent as 
	//shown below on the right.
	void displayGrades(std::ostream& os, std::function<const char*(float)>letter) const;

	//---- Operators ------------------------------------------------------
	Grades& operator= (const Grades& rhs);
	Grades&& operator= (Grades&& rhs);
 

};
