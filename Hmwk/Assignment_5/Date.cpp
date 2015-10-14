/* 
 * File:   Date.cpp
 * Author: rcc
 * 
 * Created on October 13, 2015, 9:34 AM
 */

#include <iostream>
using namespace std;

#include "Date.h"

void Date::print(){
    int c;  //user choice
    
    cout<<"What format do you want to print your date?\n1. mm/dd/yyyy\n2. "
            "Month Day, Year\n3. Day Month Year\n";
    cout<<"Your choice: ";
    cin>>c;
    cin.ignore();
    
    switch(c){
        case 1:{
            cout<<"Your date: "<<month<<'/'<<day<<'/'<<year;
            break;
        }
        case 2:{
            cout<<"Your date: ";
            switch(month){
                case 1: cout<<"January "; break;
                case 2: cout<<"February "; break;
                case 3: cout<<"March "; break;
                case 4: cout<<"April "; break;
                case 5: cout<<"May "; break;
                case 6: cout<<"June "; break;
                case 7: cout<<"July "; break;
                case 8: cout<<"August "; break;
                case 9: cout<<"September "; break;
                case 10: cout<<"October "; break;
                case 11: cout<<"November "; break;
                case 12: cout<<"December "; break;
            }
            cout<<day<<", "<<year;
            break;
        }
        case 3:{
            cout<<"Your date: "<<day<<' ';
            switch(month){
                case 1: cout<<"January "; break;
                case 2: cout<<"February "; break;
                case 3: cout<<"March "; break;
                case 4: cout<<"April "; break;
                case 5: cout<<"May "; break;
                case 6: cout<<"June "; break;
                case 7: cout<<"July "; break;
                case 8: cout<<"August "; break;
                case 9: cout<<"September "; break;
                case 10: cout<<"October "; break;
                case 11: cout<<"November "; break;
                case 12: cout<<"December "; break;
            }
            cout<<year;
            break;
        }
    }
}
void Date::setMonth(int m){
    while(m<0 || m>12){
        cout<<"Invalid Month! Re-enter Month: ";
        cin>>m;
    }
    month=m;
}
void Date::setDay(int d){
    while(d<0 || d>31){
        cout<<"Invalid Day! Re-enter Day: ";
        cin>>d;
    }
    day=d;
}
void Date::setYear(int y){
    year=y;
}