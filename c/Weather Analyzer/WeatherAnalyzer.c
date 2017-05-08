//Assignment 3
//Weather Analyzer
//by Dariia Mietlova

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*V 1.1:
Changes:

1) declared i outside of loop, you don't need -std=c99 to compile anymore
2) added a check for existence of historicaldata.csv
*/

/*an instance of this struct holds the weather data for a single day*/
struct DailyData{
    int day;
    int month;
    int year;
    float high;
    float low;
    float precipitation;
    char condition;
};

/*an instance of this struct holds summary information for the weather
for a given month*/
struct MonthlyStatistic{
    float minTemperature;
    float maxTemperature;
    float averageTemperature;
    float totalPrecipitation;
};
int readDailyData(FILE* fp, struct DailyData allData[]);

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[],
                    int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[],int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw( char c, int num );


int main(void){
    FILE* fp = fopen("historicaldata.csv","r");
    if(!fp){
        printf("you need to put historicaldata.csv into this directory\n");
        exit(0);
    }
    struct DailyData  allData[3000];
    struct DailyData yearData[366];
    int numTotalRecords;

    numTotalRecords = readDailyData(fp, allData);
    int year;
    int reportType;
    int i;
    struct MonthlyStatistic monthly[12];
    printf("Please enter the year for the report: ");
    scanf("%d",&year);
    printf("Please enter the type of report you wish to generate:\n");
    printf("1) summary\n");
    printf("2) detailed\n");
    scanf("%d",&reportType);
    int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);
    sortYearData(yearData,numDays);

    for(i=0;i<12;i++){
        getStats(i+1,yearData,numDays,&monthly[i]);
    }

    printf("Weather summary for %d\n",year);
    printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
    printf("|-----------|-------|-------|-------|---------|\n");
    for(i=0;i<12;i++){
        printMonthlyStatistic(i+1,&monthly[i]);
    }
    printf("\n\n");
    printf("Precipitation Graph\n\n");
    for (i=0;i<12;i++){
        graphLine(i+1,&monthly[i]);
    }
    if(reportType == 2){
        printf("\n\n");
        printf("Detailed report:\n");
        printVerbose(yearData,numDays);
    }
    return 0;
}

// This function reads the data from the file pointed to by fp and stores the 
// information in the array allData. It returns the number of records read. 
int readDailyData(FILE* fp, struct DailyData allData[]){
    int i=0;
    while(fscanf(fp,"%d,%d,%d,%f,%f,%f,%c\n",
        &allData[i].year,&allData[i].month,&allData[i].day,
        &allData[i].high,&allData[i].low,&allData[i].precipitation,
        &allData[i].condition) == 7){
        i++;
    }
    return i;
}


// This function is passed:
//     a year (yearWanted)
//     an array of DailyData(allData) - which contains every record found in the file
//     size of the allData array (sz)
//     another array of DailyData(yearData) - which has 366 elements.
// This function must copy over all records from allData to yearData that matches 
// yearWanted. Function returns number of records copied. Note, do not assume there
// are 365 days in a year. Some years will have 366 days because they are leap years.
// Some years might have missing data, so the function must return what is there. 
int getRelevantRecords(int yearWanted, const struct DailyData allData[], 
                                    int sz,  struct DailyData yearData[]){
 int i,         // loop counter
     j = 0;     // counter total records copied

    for( i = 0; i < sz; i++){

        // copy over all records from allData to yearData that matches 
        // yearWanted
        if (allData[i].year == yearWanted){

            yearData[j].year = allData[i].year;
            yearData[j].month = allData[i].month;
            yearData[j].day = allData[i].day;
            yearData[j].high = allData[i].high;
            yearData[j].low = allData[i].low;
            yearData[j].precipitation = allData[i].precipitation;
            yearData[j].condition = allData[i].condition;

            j++;    // count records
        }
    }

    return j;
}



// This function is passed:
//     array of DailyData (yearData)
//     the size of the array (sz)
// This function sorts the records in the yearData array. The sorting is done so that 
// the earliest date is the first record. Thus, if yearData had a record for every day 
// of the year, this function would put the data for January 1 into yearData[0], 
// January 2 into yearData[1] and so on. You may assume that the year is the same for 
// every record in the yearData array
void sortYearData(struct DailyData yearData[], int sz){
     int i, j, m;                     // sorting counters
     int tempMonth, tempDay;          //temporary variable to store days / months
     float tempHigh, tempLow, tempPr; //temporary variable to store high/low temperature or precipitation
     char tempCon;                    //temporary variable to store condition

    for (i = 0; i < sz; i++) {
         m = i;
         for (j = i + 1; j < sz; j++)
             if (yearData[j].month < yearData[m].month) {
                 m = j;
             } else if ((yearData[m].month == yearData[j].month) 
                         && yearData[m].day > yearData[j].day){
                 m = j;
             }
         if (m != i) {   
             tempMonth = yearData[i].month;
             yearData[i].month = yearData[m].month;
             yearData[m].month = tempMonth;

             tempDay = yearData[i].day;
             yearData[i].day = yearData[m].day;
             yearData[m].day = tempDay;

             tempHigh = yearData[i].high;
             yearData[i].high = yearData[m].high;
             yearData[m].high = tempHigh;

             tempLow = yearData[i].low;
             yearData[i].low = yearData[m].low;
             yearData[m].low = tempLow;

             tempPr = yearData[i].precipitation;
             yearData[i].precipitation = yearData[m].precipitation;
             yearData[m].precipitation = tempPr;

             tempCon = yearData[i].condition;
             yearData[i].condition = yearData[m].condition;
             yearData[m].condition = tempCon;
         }
    }
    return;
}


//  This function is passed
//     a month as an integer (month)- 1 is January, 2 is February, ... etc.
//     an array of DailyData (yearData)- array contains daily weather data for one year.
//        You may assume the array is sorted.
//     the size of the DailyData arrray (sz)
//     a pointer to a MonthlyStatistics struct (monthStats) - used to pass back the 
//        gathered statisted
// Your function must find minimum temperature, the maximum temperature, the average 
// temperature and total precipitation for a given month using the data in the array 
// with a matching month. The results are passed back to the calling function by storing 
// them into the appropriate data members of monthStats 
void getStats(int month, const struct DailyData yearData[],
                    int sz,struct MonthlyStatistic* monthly){
int   i,            //loop counter
      k=0,          // counter for records for particulat month
      g=0;          // a variable to set initial min and max values to the first element in a found month mached

float min,        // a variable to store monthly min
      max,        // a variable to store monthly max
      avgT=0,     // a variable to store monthly average temperature
      sumP=0;     // a variable to store monthly total precipitation

for( i = 0; i <= sz; i++){

    // find the needed month

    if (yearData[i].month == month){

        // set initial values of min and max to the first elements of a month found
        if (g==0){
        min = yearData[i].low;
        max = yearData[i].high;
        }
        g=1;


        k++;   // count records in a month


            // find min and max
            if (min > yearData[i].low){
             min = yearData[i].low;
            }
            if (max < yearData[i].high){
             max = yearData[i].high;
            }

            // count avetage temperature and total precipitation
            avgT = avgT + average(yearData[i].low, yearData[i].high);
            sumP = sumP + yearData[i].precipitation;

    }

}
        // store values into the appropriate data members of monthStats 
        monthly->minTemperature = min;
        monthly->maxTemperature = max;
        monthly->averageTemperature = avgT / k;
        monthly->totalPrecipitation = sumP;

    return;
}


// This function is passed:
//     a month as an integer (month)- 1 is January, 2 is February, ... etc.
//     a pointer to MonthlyStatistic struct
// This function will print out one single row of the summary table. Each row of the table
// consists of text and values separated by the vertical bar symbol ('|'). Your output 
// must line up the |'s in the header printed by main The values are as follows:
//     name of month, right justified, with at least one space after the left | 
//         and one space before the right |
//     highest temperature, left justified, printed with one space after left bar 
//         and at least one space before right bar
//     lowest temperature, left justified, printed with one space after left bar 
//         and at least one space before right bar
//     average temperature, left justified, printed with one space after left bar
//         and at least one space before right bar
//     total precipitation, left justified, printed with one space after left bar 
//         and at least one space before right bar
void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly){
    
// an array to store text values of a name of a month
char monthChar[12][11] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

    // print out one single row of the summary table
    printf("| %9s | %-5.1f | %-5.1f | %-4.1f  |  %-5.1f  |\n", monthChar[month -1], monthly->maxTemperature, 
                                                        monthly->minTemperature, monthly->averageTemperature,
                                                         monthly->totalPrecipitation);
    return;
}


// This function is passed:
//     a month as an integer (month)- 1 is January, 2 is February, ... etc.
//     a pointer to MonthlyStatistic struct
// It will print out one single row of the precipitation bar graph 
void graphLine(int month,const struct MonthlyStatistic* monthly){
    char c = '*';         // a character to store 'star'
    int q;                // an integer to store quantity of stars to print out

    // an array to store text values of a name of a month
    char monthChar[12][11] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
        

     // find quantity of stars to print out
     q = round(monthly->totalPrecipitation / 10);

     //print out one single row of the precipitation bar graph 
     printf(" %11s | ", monthChar[month -1]);
     draw(c,q);

return;
}


// This function is passed:
//     array of DailyData (yearData) - this array holds data for a full year. You may 
//        assume it is already sorted
//     size of array (sz)
// This function print the details of the weather data for each of the records in yearData.
// The output of this function is sz lines, where each line shows the detailed weather i
// nformation for a specific date. This information includes the date as well as the 
// average temperature and 20 symbols based on the condition of the day. For each day, 
// the format is as follows (in order of appearance on line):
//     name of month, right justified, the ending characters of each month must line up
//     a space
//     The day of the month (2 digits, right aligned)
//     a space
//     year
//     a colon character(:)
//     average temperature of the day right justified
//     20 symbols based on condition of daay
void printVerbose(const struct DailyData allData[],int sz){
    char c;            // a character to store appropriate symbol
    
    int i,             // loop counter
        q = 20;        // an integer for quantity if characters to print out
    
    float avg;         // a float value to store average temperature for a day

    // an array to store text values of a name of a month
    char monthChar[12][11] = { "January","February","March","April","May","June","July","August","September","October","November","December" };

    for( i = 0; i < sz; i++){
    
        // calculate average temperature for a day
        avg = average(allData[i].low, allData[i].high);

        // find appropriate symbol to draw
        c = symbolToDraw(allData[i].condition, avg);   

        //print out the details of the weather data for each of the records in yearData
        printf("%9s %2d %4d:", monthChar[allData[i].month -1], allData[i].day, allData[i].year);
        printf(" %5.1f ", avg);
        draw(c,q);
    }

    return;
}


//     character representing the condition (condition) - 'c', 's' , or 'p'
//     average Temperature (avgTemp)
// This function returns the correct character ('@', '~', '*', ';') given the current 
// condition and the average temperature. Function returns '@' for condition 's', '~' 
// for condition 'c', '*' for condition 'p' if average temperature is below 0, ; for 
// condition 'p' othewise. 
char symbolToDraw(char condition, float avgTemp){
    char c;     //char to store one of the characters (@, ~, *, ;) indicating 
                //weather conditions for a day

    if (condition == 's'){
        c = '@'; 
    } else if (condition == 'c'){
        c = '~';
    } else if (condition == 'p' && avgTemp <= 0){
        c = '*';
    } else if (condition == 'p' && avgTemp > 0){
        c = ';';
    }

    return c;
}


// This function returns the average of the first and second floating point number.
float average(float first, float second){
    return (first + second)/2;
}


// This function is passed:
//     a symbol to print (c)
//     a number (num)
// This function prints the symbol passed in num times.
void draw( char c, int num ){
    int n;     //counter

    for (n = 0; n < num; n++){
        printf("%c", c);
    }

    printf("\n");
    return;
}





/*
I declare that the attached assignment is wholly my
own work in accordance with Seneca Academic Policy.  No part of this
assignment has been copied manually or electronically from any
other source (including web sites) or distributed to other students.

Name   Dariia Mietlova   Student ID  113923155
*/