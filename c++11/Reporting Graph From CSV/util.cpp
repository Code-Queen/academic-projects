// util.cpp
// Desc: This file reads a delimitor separeted file and
//       prints its records by 3 methods(indexes,iterators,range)

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;

void trim(string& s){
	while(s.size() > 0 && s[0] == ' '){ // kill leading spaces
		s.erase(0,1);
	}
	while(s.size() > 0 && s[s.size()-1] == ' '){ // kill spaces at the end
		s.erase(s.size()-1,1);
	}
}

void csvprint(vector< vector< string > >  & csvData){ 

	cout << "with indexes\n";	//with indexes
	for(size_t row = 0; row < csvData.size(); row++){
	
		cout << "row " << row << " ";
		cout << "(" << csvData[row].size() << " fields)";
		for(size_t column = 0; column < csvData[row].size(); column++){
			cout << "[" << csvData[row][column] << "]";
		}
		cout << "\n";
	}

	cout << "with iterators\n";
	for(auto rowIt = csvData.begin(); rowIt != csvData.end(); rowIt++){ //with iterators
		cout << "row" << rowIt - csvData.begin() << " ";
		cout << "(" << rowIt->size() << " fields)";
		for(auto columnIt = rowIt->begin(); columnIt != rowIt->end(); columnIt++){
			cout << "{" << *columnIt << "}";
		}
		cout << "\n";
	}

	cout << "with range\n";
	for(auto row : csvData){ //with range (though no row number)
		cout << "(" << row.size() << " fields)";
		for(auto column : row){
			cout << "<" << column << ">";
		}
		cout << "\n";
	}
}


void csvread(string& filename, char delimiter, vector< vector< string > >  & csvData){

	fstream is(filename, ios::in);

	if (not is.is_open()){ 
		throw string("Cannot open file ") + filename;
	}

	string line;
	while(getline(is, line)){

		auto cr= line.find('\r');
		if(cr != string::npos){
			line.erase(cr);
		}

	//	cout << "line -->" << line << "<--\n";
		vector <string> fields;
		string field;
		size_t i=0;

		while(i < line.size()){
			if (line[i] != delimiter){
				field += line[i];
			}else{
				trim(field);
				fields.push_back(move(field));
			}
			i++;		
		}
		//what if the last entry was not a delimiter character?
		if (not field.empty()){
			trim(field);
			fields.push_back(move(field));

			csvData.push_back(move(fields));
		}
	}

	is.close();
}
bool itemNameValid(string& t){
	bool result= true;
	if (t.empty())
	{
		result = false; // reject empty names
	}
	for(auto ch : t){
		if (isspace(ch) || isalnum(ch) || ch == '_')
		{
			continue;
		}
		result = false;
	}
	return result;
}
bool validSequence(string& t){
	bool result= true;
	if (t.empty())
	{
		result = false; // reject empty names
	}
	for(auto ch : t){
		if (isdigit(ch))
		{
			continue;
		}
		result = false;
	}
	return result;
}


bool taskNameValid(string& t){
	bool result= true;
	if (t.empty())
	{
		result = false; // reject empty names
	}
	for(auto ch : t){
		if (isspace(ch) || isalnum(ch) || ch == '_')
		{
			continue;
		}
		result = false;
	}
	return result;
}
bool taskSlotsValid(string& t){
	bool result= true;
	if (t.empty())
	{
		result = false; // reject empty names
	}
	for(auto ch : t){
		if (isdigit(ch))
		{
			continue;
		}
		result = false;
	}
	return result;
}

bool customerNameValid(string& t){
	bool result= true;
	if (t.empty())
	{
		result = false; // reject empty names
	}
	for(auto ch : t){
		if (isspace(ch) || isalnum(ch) || ch == '\'')
		{
			continue;
		}
		result = false;
	}
	return result;
}
bool productNameValid(string& t){
	bool result= true;
	if (t.empty())
	{
		result = false; // reject empty names
	}
	for(auto ch : t){
		if (isspace(ch) || isalnum(ch) || ch == '\'' || ch == '#' || ch == '$')
		{
			continue;
		}
		result = false;
	}
	return result;
}
