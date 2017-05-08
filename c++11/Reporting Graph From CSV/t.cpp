// t.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
#include "t.h"
using namespace std;

	Task::Task() : taskSlots("1"){

	}
	Task::Task(vector<string>& row): taskSlots("1"){
		switch(row.size()){
			case 4:
				if (taskNameValid(row[3]))
				{
					taskFail  = row[3];
				} else {
					throw string("Expected a fail task name, found: >")+ row[3] + "<";
				}	
			case 3:
				if (taskNameValid(row[2]))
				{
					taskPass     = row[2];
				} else {
					throw string("Expected a pass task name, found: >")+ row[2] + "<";
				}
			case 2:
				if (taskSlotsValid(row[1]))
				{
					taskSlots  = row[1];
				} else {
					throw string("Expected a slots task name, found: >")+ row[1] + "<";
				}
			case 1:
				if (taskNameValid(row[0]))
				{
					taskName  = row[0];
				} else {
					throw string("Expected a task name, found: >")+ row[0] + "<";
				}
			break;
			default:
			 throw string("expected 1,2,3 or 4 fields, but found ") + to_string(row.size());
		}
	}
	void Task::print(){
		cout << "["<< taskName << "]" 
			 << "["<< taskSlots << "]" 
			 << "["<< taskPass << "]" 
			 << "["<< taskFail << "]" 
			 << "\n";
	}
	void Task::graph(fstream& os){
		if (not taskPass.empty())
		{
			os << '"' << taskName << '"' << " ->" << '"' << taskPass << '"' << "[color=green];\n";
		}
		if (not taskFail.empty())
		{
			os << '"' << taskName << '"' << " ->" << '"' << taskFail << '"' << "[color=red];\n";
		}
		if (not taskPass.empty() and taskFail.empty() )
		{
			os << '"' << taskName << '"' << "\n";
		}
	}
	const string& Task::getTaskName() const{
		return taskName;
	}
	const string& Task::getTaskPass() const{
		return taskPass;
	}
	const string& Task::getTaskFail() const{
		return taskFail;
	}

	TaskManager::TaskManager(){

	}
	TaskManager::TaskManager(vector< vector< string > >& csvTask){
		int lineNumber = 0;
		for (auto &row : csvTask)
		{
			try{
				lineNumber++;
				TaskList.push_back(move(Task(row)));
			} catch (const string& e){
				cerr << "Error: on line "<< lineNumber << ": " << e << "\n";
			}
		}
	}
	void TaskManager::print(){
		for(auto t : TaskList){
			t.print();
		}
	}
	void TaskManager::graph(string filename){
		fstream os(filename,ios::out | ios::trunc);
		if (os.is_open())
		{
			os << "Digraph tas {\n";
			for(auto t : TaskList){
				t.graph(os);
			}
			os << "}\n";
			os.close();
		}
		// to convert to png
		//string cmd = "dot -Tpng " + filename + " > " + filename + ".png";
		//system(cmd.c_str());
	}
	Task* TaskManager::find(const string& n){
			for(size_t t = 0; t < TaskList.size(); t++){
				if(TaskList[t].getTaskName() == n){
					return &TaskList[t];
				};
			};
			return nullptr;
	}
	bool TaskManager::checkIntefrity(){
		bool ret = true;
		for(auto t: TaskList){
			if(not t.getTaskPass().empty() && find(t.getTaskPass()) == nullptr){
				cerr << "Task " << t.getTaskName() << " references pass task " << t.getTaskPass() << " but it does not exist\n";
				ret = false;
			};
			if(not t.getTaskFail().empty() && find(t.getTaskFail()) == nullptr){
				cerr << "Task " << t.getTaskName() << " references fail task " << t.getTaskFail() << " but it does not exist\n";
				ret = false;
			};
		};
		return ret;
	}
	size_t TaskManager::size(){
		return TaskList.size();
	}
	Task* TaskManager::getTask(size_t t){
		return &TaskList[t];
	}
