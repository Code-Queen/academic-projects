// Containers
// Notifications.cpp
// Date 2016/10/09

 #include <iostream>
 #include <fstream>

#include "Notifications.h"

using namespace std;



namespace w5{

//destructor
Notifications::~Notifications() {
		delete [] messageTable;
}
// default constructor – empty
Notifications::Notifications(): messageCount(0), messageTable(nullptr){
}
// copy constructor
Notifications::Notifications(const Notifications& rhs) : messageCount(0), messageTable(nullptr){ 
		if(rhs.messageCount !=0){ // only need to do something if rhs has brains
			messageTable = new Message::Message[MAX_MESSAGE];
			messageCount = rhs.messageCount;
			for(size_t i = 0 ;i< messageCount; i++){
				messageTable[i] = rhs.messageTable[i];
			}
		}
}
//copy assignment operator
	Notifications& Notifications::operator=(const Notifications& rhs) { 
		if(this !=&rhs){
			//case: zombie, rhs is a zombie – nothing to do
			if(messageCount == 0 && rhs.messageCount == 0){
			} else
			//case: zombie, rhs has brains
			if(messageCount == 0 && rhs.messageCount != 0){
				messageTable = new Message::Message[MAX_MESSAGE]; // allocate space for brains
				messageCount = rhs.messageCount; // deep copy
				for(size_t i = 0 ;i< messageCount; i++){
					messageTable[i] = rhs.messageTable[i];
				}
			} else
			//case: have brains, rhs is a zombie
			if(messageCount != 0 && rhs.messageCount == 0){
				delete [] messageTable;
				messageTable = nullptr;
				messageCount = 0;
			} else
			//case: have brains, rhs has brains
			//We can reuse our messageTable. No need to delete then reallocate a table of the same size.
			if(messageCount != 0 && rhs.messageCount != 0){
				messageCount = rhs.messageCount;
				for(size_t i = 0 ;i< messageCount; i++){ //deep copy
					messageTable[i] = rhs.messageTable[i];
				}
			}
		}
		return *this;
}
//move constructor
Notifications::Notifications(Notifications&& rhs) : messageCount(rhs.messageCount) , messageTable(rhs.messageTable) {
		rhs.messageCount = 0; //zombie
		rhs.messageTable = nullptr;
	}
//move assignment operator
	Notifications&& Notifications::operator=(Notifications&& rhs) {
		if(this !=&rhs){
			delete [] messageTable;
			messageCount = rhs.messageCount; // steal brains
			messageTable = rhs.messageTable;
			rhs.messageCount = 0; //zombie
			rhs.messageTable = nullptr;
		}
		return std::move(*this);
	}

	// adds msg to the set
	void Notifications::operator+=(const Message& msg) {
		if(messageCount ==0){
			messageTable = new Message::Message[MAX_MESSAGE];
		}
		if(messageCount < MAX_MESSAGE){
			messageTable[messageCount] = msg;
			messageCount++;
		}
	}

	//inserts the Message objects to the os output stream
	void Notifications::display(std::ostream& os) const {
		for(size_t i = 0; i < messageCount; i++){
			os << "\n";
			messageTable[i].display(os);
		}
	}

} //w5 namespace close