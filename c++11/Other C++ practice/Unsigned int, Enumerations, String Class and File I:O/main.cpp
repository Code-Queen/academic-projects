// Unsigned int, Enumerations, String Class and File I/O 
// File	main.cpp
// Date	2016/09/18

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include "stations.h"
#include "station.h"
using namespace w2;

 int main(int argc, char* argv[]) {
     std::cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         std::cout << argv[i] << ' ';
     }
     std::cout << std::endl;
     if (argc != 2) {
         std::cerr << "\nIncorrect number of arguments\n";
         return 1;
     }
     w2::Stations stations(argv[1]);
     stations.update();
     stations.restock();
     stations.report();
     return 0;
 }