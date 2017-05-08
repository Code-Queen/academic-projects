#pragma once
// t.h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;



class Task{
	string taskName, taskSlots, taskPass, taskFail;
public:
	Task();
	Task(vector<string>& row);
	void print();
	void graph(fstream& os);
	const string& getTaskName() const;
	const string& getTaskPass() const;
	const string& getTaskFail() const;
};

class TaskManager{
	vector<Task> TaskList;
public:
	TaskManager();
	TaskManager(vector< vector< string > >& csvTask);
	void print();
	void graph(string filename);
	bool checkIntefrity();
	Task* find(const string& n);
	size_t size();
	Task* getTask(size_t t);
};

