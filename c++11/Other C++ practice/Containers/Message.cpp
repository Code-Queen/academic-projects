// Containers
// Message.cpp
// Date 2016/10/09

 #include <iostream>
 #include <fstream>

#include "Message.h"

using namespace std;


namespace w5{

Message::Message(){
	}

//constructor retrieves a record from the in file object, parses the record 
//(as described above) and stores its components in the Message object.  
//c is the character that delimits each record
Message::Message(std::ifstream& in, char c) { 
		std::string line;
		getline(in, line, c);
		auto cr = line.find('\r');
		if (cr != std::string::npos){
			line.erase(cr);
		}
		
		size_t i=0;
		if (line.find(' '))
		{
						while(i<line.size() && line[i] != ' '){
							user += line[i];
							i++;
						}
					
						i++; //skip space
						if(i<line.size() && line[i] == '@'){
						
							if (line[i] == '@')
							{
								i++; //skip '@'
							}
							
							while(i<line.size() && line[i] != ' '){
								reply += line[i];
								i++;
							}
							i++; // skip ' ' after reply
						} 
						
						while(i<line.size()){
							tweet += line[i];
							i++;
						}
					
		}
						

	}

// returns true if the object is in a safe empty state
	bool Message::empty() const { 
		return tweet.empty();
	}

	//displays the Message objects within the container
	void Message::display(std::ostream& os) const { 
		os << "Message\n";
		os << "User  : " << user<< "\n";
		if(!reply.empty()){
			os <<"Reply : " << reply << "\n";
		}
		os << "Tweet : " << tweet << "\n";
	}


} //w5 namespace close