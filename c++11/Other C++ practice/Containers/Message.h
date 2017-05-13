// Containers
// Message.h
// Date 2016/10/09

#pragma once
#include <istream>
#include <string>
#include <iostream>

namespace w5{

class Message{
	std::string user, reply, tweet;
public:
	Message();

	//constructor retrieves a record from the in file object, parses the record 
	//(as described above) and stores its components in the Message object.  
	//c is the character that delimits each record
	Message(std::ifstream& in, char c);

	// returns true if the object is in a safe empty state
	bool empty() const; 

	//displays the Message objects within the container
	void display(std::ostream& os) const; 
	
};
}; //namespace w5
