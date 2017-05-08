// factory.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
#include "t.h"
#include "o.h"
#include "i.h"
#include "Machine.h"
#include "Job.h"


using namespace std;
class Factory{
	std::vector<Machine> machineList;
public:
	Factory(){};
	Factory(ItemManager& im, OrderManager& om, TaskManager& tm){
		srand(time(0)); // initialize the random number generator with the time of day clock
		//Step 1 : load factory  with machines
		for (size_t t = 0; t < tm.size(); t++){
			machineList.push_back(move(Machine(tm.getTask(t))));
		}
		for(auto m : machineList){
			cout << m.getTaskName() << "\n";
		}
		//Step 2 : figure out source node
		auto inc = [&](const string& want){
			for(auto& m : machineList){
				if(m.getTaskName() == want){
					m.incIncoming();
					break;
				};
			};
		};
		// increment incoming edges 
		for(auto& m : machineList){
			if(not m.getTaskPass().empty()){
				inc(m.getTaskPass());
			};
			if(not m.getTaskFail().empty()){
				inc(m.getTaskFail());
			};
		};
		int source = -1;
		for (size_t m = 0; m < machineList.size(); m++){
			cout << machineList[m].getTaskName();
			if(machineList[m].isSingleton()){
				cout << "SINGLETON";
			} else {
				if(machineList[m].isSource()){
					if(source == -1){
						source = m;
					} else{
						cout << "Alresdy founf source machine " << source << "\n";
						cout << "machine " << m << " is also a source machine\n";
						throw string("multiple source machines ") + to_string(source) + " and " + to_string(m);
					}
					cout << " SOURCE";
				};
				if(machineList[m].isSink())   cout << " SINK";
				cout << "\n";
			};
		};
		cout << "source node =" << source << "\n";
	
		//Step 3: load jobs into the machine' input queue
		for(size_t o = 0; o < om.size(); o++){
			machineList[source].push_back(move(Job(om.getOrder(o))));
		};

		//Debug only
		//print out jobs o source machine's input queue
		//machineList[source].dumpInputQ();

		//print machine's input queue size
		for (size_t m = 0; m < machineList.size(); m++){
			cout << "Input queue size= " << machineList[m].inputQSize() << "\n";
		};


		for(auto &m : machineList){
				m.Classify(im);
		}


		//Step 4: time loop

		int time = 0;
		
		while(true){
			cout << "TIME = " << time << "\n";		
			//Are there machines with work to do?
			bool AllDone = true;
			for(auto m : machineList){
				if(m.inputQSize()){
					AllDone = false;
					break;
				}
			}
			if(AllDone){
				cout << "All Done\n";
				break; // break out of time loop
			}
			for(auto &m : machineList){
				if(m.inputQSize() == 0){
					continue; // nothing for this machine to do
				}
				Job job = m.getJob();
				cout << "'" << m.getTaskName() << "' is looking at job "
				     << job.getOrderCustomer() << "/"
				     << job.getOrderProduct()  << "\n";
				if(m.isSink()){
					cout << "Job arrived at " << m.getTaskName() << " a sink - nothing to do\n";
					cout << "Job exiting system\n";
					continue; // machine loop over for this machine
				}
				bool didSomething = false;
				//is it installer?
				if(m.getInstaller()){
					//does it need installer?
					cout << m.getTaskName() << " is an installer\n";
					//for each item in the order, if it's not installed
					//if the installer name is same - install the item - call installer(i,true)
					for(size_t i=0; i < job.size(); i++){
						if(job.installedJob(i)){
							continue; // already installed
						}
						string itemName = job.item(i);
						Item* itemPtr = im.find(itemName);
						if(m.getTaskName() == itemPtr->getItemInstaller()){
							job.installedJob(i,true); // flag the item as installed
							didSomething = true;
							time++;
							cout << m.getTaskName() << " installed " << itemName << "\n";
							break; // all done installing 1 item
						}
					}
				}
				//is it remover?
				if(m.getRemover()){
					//does it need remover?
					cout << m.getTaskName() << " is a remover\n";
					//for each item in the order, if it's not installed
					//if the installer name is same - remove the item - call installer(i,false)
					for(int i= job.size() -1; i >= 0; i--){
						if(not job.installedJob(i)){
							continue; // not installed
						}
						string itemName = job.item(i);
						Item* itemPtr = im.find(itemName);
						if(m.getTaskName() == itemPtr->getItemRemover()){
							job.installedJob(i,false); // flag the item as removed
							didSomething = true;
							time++;
							cout << m.getTaskName() << " removed " << itemName << "\n";
							break; // all done removing 1 item
						}
					}
				}
				auto MovePass = [&]{
					string pass = m.getTaskPass();
					cout << "moving job to pass machine " << pass << "\n";
					for(auto &m2 : machineList){
						if(m2.getTaskName() == pass){
							m2.AddJob(job);
							break;
						}
					}
				};
				auto MoveFail = [&]{
					string fail = m.getTaskFail();
					cout << "moving job to fail machine " << fail << "\n";
					for(auto &m2 : machineList){
						if(m2.getTaskName() == fail){
							m2.AddJob(job);
							break;
						}
					}
				};
				if(not didSomething){
					//move job to passed inputQ
					MovePass();
					continue; // end of this machine
				}
				if(m.getTaskFail().empty()){ // if there is only a Pass task
					//move job to passed inputQ
					MovePass();
					continue; // end of this machine
				}
				//flip a coin (rand()&1 - test if odd)
				if(rand() & 1){
					//pass
					//move job to Pass machine inputQ
					MovePass();
					continue; // end of this machine
				} else{
					//fail
					//move job to Fail machine inputQ
					MoveFail();
					continue; // end of this machine
				}
			} // machine loop end
		} // time loop end
		cout << "Simulation over\n";
		cout << "TIME = " << time << "\n";
	};
};

int main(int argc, char* argv[]){
	try {
	 if (argc !=5){ //check if 2 parameters
		throw string("Usage ") + argv[0] + string(" item.csv order.csv task.csv delimiter-char");
		}
		
		string filenameItem = argv[1];     //1st arg is Item file name
		string filenameOrder = argv[2];    //2st arg is Order file name
		string filenameTask = argv[3];     //3st arg is Task file name
		char delimiter  = argv[4][0];      //4nd arg, 1st char

		vector< vector< string > > csvItemData;
		csvread(filenameItem, delimiter, csvItemData);

		vector< vector< string > > csvOrderData;
		csvread(filenameOrder, delimiter, csvOrderData);

		vector< vector< string > > csvTaskData;
		csvread(filenameTask, delimiter, csvTaskData);

	//	csvprint(csvData);

		ItemManager im(csvItemData);
		im.print();
		string graphItemFile = filenameItem + ".gv";
		im.graph(graphItemFile);


		OrderManager om(csvOrderData);
		om.print();
		string graphOrderFile = filenameOrder + ".gv";
		om.graph(graphOrderFile);

		TaskManager tm(csvTaskData);
		tm.print();
		string graphTaskFile = filenameTask + ".gv";
		tm.graph(graphTaskFile);

		bool GoodToGo = true;
		if(tm.checkIntefrity()){
			GoodToGo = false;
		};
		if(im.checkIntefrity(tm)){
			GoodToGo = false;
		};
		if(om.checkIntefrity(im)){
			GoodToGo = false;
		};
		if (not GoodToGo){
			cerr << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			cerr << "! errors in data files. Fix errors and re-run !\n";
			cerr << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
		//	exit(1);
		}
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "+Data files passef the integrity check.\n             +\n";
		cout << "+We are good to go for running the factory simulation.+\n";
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

		Factory factory(im, om, tm);

	} catch (const string& e){
		cerr << e << "\n";
	}
}