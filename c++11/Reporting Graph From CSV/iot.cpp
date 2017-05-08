// iot.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"
#include "t.h"
#include "o.h"
#include "i.h"


using namespace std;

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

		tm.checkIntefrity();
		im.checkIntefrity(tm);
		om.checkIntefrity(im);

	} catch (const string& e){
		cerr << e << "\n";
	}
}