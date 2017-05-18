// Lambda Expression
// main.cpp
// Date 2016/10/23

 #include <iostream>
 #include <functional>
 #include <string>
 #include "Grades.h"

 template<typename Func>
const char* letter(float i, Func func) { return func(i); }

 int main(int argc, char* argv[]) {
     if (argc != 2) {
         std::cerr << argv[0] <<
          ": incorrect number of arguments\n";
         std::cerr << "Usage: " << argv[0] << " file_name\n"; 
         return 1;
     }


         Grades grades(argv[1]);

         // define the lambda expression for letter
     
         auto letter = [](float grade){

            const char* result;
            if (grade < 100 && grade >=90)
            {
                result = "A+";
            } else if (grade < 90 && grade >=80)
            {
                result = "A";
            } else if (grade < 80 && grade >=75)
            {
                result = "B+";
            } else if (grade < 75 && grade >=70)
            {
                result = "B";
            } else if (grade < 70 && grade >=65)
            {
                result = "C+";
            } else if (grade < 65 && grade >=60)
            {
                result = "C";
            } else if (grade < 60 && grade >=55)
            {
                result = "D+";
            } else if (grade < 55 && grade >=50)
            {
                result = "D";
            } else if (grade < 50)
            {
                result = "F";
            }

            return result;
         };

         grades.displayGrades(std::cout, letter);




     std::cout << "Press any key to continue ... ";
     std::cin.get();
 }