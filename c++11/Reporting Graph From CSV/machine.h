// factory.cpp
#pragma once
#include "t.h"
#include "Job.h"
#include <queue>

using namespace std;
class Machine: public Task{
	int inComingEdges;
	bool bInstaller;
	bool bRemover;
	queue<Job> inputQ; // input queue for jobs
public:
	Machine():inComingEdges(0){};
	Machine(Task* t): Task(*t), inComingEdges(0){
		
		//if(t.getTaskName()){

		//}
	};
	bool isInstaller(){
		return bInstaller;
	}
	bool isSink(){
		return getTaskPass().empty();
	};
	void incIncoming(){
		inComingEdges++;
	};
	bool isSource(){
		return inComingEdges == 0;
	}
	bool isSingleton(){
		return isSource() && isSink();
	};
	void push_back(Job&& j){
		inputQ.push(move(j));
	};
	void dumpInputQ(){
		cout << "size = " << inputQ.size() << "\n";
		while (not inputQ.empty()){
			cout << inputQ.front().getOrderCustomer() << "/" << inputQ.front().getOrderProduct() << "\n";
			inputQ.pop();
		};
	};
	const size_t inputQSize(){
		return inputQ.size();
	}
	Job getJob(){
		Job job = move (inputQ.front());
		inputQ.pop();
		return job;
	}
	void AddJob(Job job){
		inputQ.push(move(job));
	}
	/*Job* moveJob(Job* job){
		job = new Job(std::move(inputQ.front()));
		inputQ.pop();
		return job;
	}*/
	void Classify(ItemManager& im){
		bInstaller = false;
		bRemover = false;

		for (size_t i = 0; i<im.size(); i++){
			if(getTaskName() == im.getItem(i)-> getItemInstaller()){
				bInstaller = true;
			}
			if(getTaskName() == im.getItem(i)-> getItemRemover()){
				bRemover = true;
			}
		}
		if(bInstaller) cout << getTaskName() << " is an installer\n";
		if(bRemover)   cout << getTaskName() << " is a remover\n";
	}
	bool getInstaller() {return bInstaller;}
	bool getRemover() {return bRemover;}
};