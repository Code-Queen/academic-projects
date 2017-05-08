// factory.cpp
#pragma once
#include "o.h"


class Job : public Order{
	std::vector<bool> installed;
public:
	Job(){};
	Job(Order* o): Order(*o){ //installed(o->size(), false)
		installed.resize(size()); // allocate space
		for (size_t i =0; i <size(); i++){
			installed[i] = false;         //initialize to false (not installed)
		}
	};
	bool installedJob(size_t i) const {return installed[i];};
	void installedJob(size_t i, bool value) { installed[i] = value;};
};