// Containers
// Notifications.h
// Date 2016/10/09

#pragma once
#include "Message.h"

namespace w5{

const int MAX_MESSAGE = 10;

class Notifications{
	Message* messageTable;
	size_t messageCount;
public:
	//destructor
	~Notifications();
	
	// default constructor – empty
	Notifications();
	
	// copy constructor
	Notifications(const Notifications& rhs); 
	
	//copy assignment operator
	Notifications& operator=(const Notifications& rhs);  

	//move constructor
	Notifications(Notifications&& rhs); 

	//move assignment operator
	Notifications&& operator=(Notifications&& rhs);

	// adds msg to the set
	void operator+=(const Message& msg); 

	//inserts the Message objects to the os output stream
	void display(std::ostream& os) const;

};

}; //namespace 5w