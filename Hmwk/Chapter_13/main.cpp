/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 12, 2015, 2:45 PM
 */

//system libraries
#include <iostream>
using namespace std;

//user libraries
#include "Date.h"
//global constants

//function prototypes

//execution
int main(int argc, char** argv) {
    int month;  //month number
    int day;    //day of the month
    int year;   //year
    Date yDate; //your date
    
    //date input
    cout<<"Enter the month number: ";
    cin>>month;
    cout<<"Enter the day: ";
    cin>>day;
    cout<<"Enter the year (xxxx): ";
    cin>>year;
    
    //set date
    yDate.setMonth(month);
    yDate.setDay(day);
    yDate.setYear(year);
    
    //print date
    yDate.print();
    
    return 0;
}

