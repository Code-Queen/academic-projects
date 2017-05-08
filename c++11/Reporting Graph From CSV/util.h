// util.h
// Desc: This file reads a delimitor separeted file and
//       prints its records by 3 methods(indexes,iterators,range)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void trim(string& s);

void csvprint(vector< vector< string > >  & csvData);

void csvread(string& filename, char delimiter, vector< vector< string > >  & csvData);

bool itemNameValid(string& t);
bool validSequence(string& t);


bool taskNameValid(string& t);
bool taskSlotsValid(string& t);

bool customerNameValid(string& t);
bool productNameValid(string& t);