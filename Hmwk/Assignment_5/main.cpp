/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on October 13, 2015, 9:26 AM
 * Purpose: Chapter 13 Homework Gaddis
 */

//system libraries
#include <iostream>
using namespace std;

//user libraries
#include "Date.h"
#include "PersonalInformation.h"

//global constants

//function prototypes
void problem1();
void problem2();
void setData(PersonalInformation *);
void problem3();
void problem4();
void problem5();

//execution
int main(int argc, char** argv) {

    //declare user input for menu
    int choice;
    
    bool again=true;
    
    do{
        //menu
        cout<<"1. Chapter 13.1\n2. Chapter 13.4\n3. Chapter \n4. Chapter \n"
                "5. Chapter \n6. Exit\nYour Choice: ";
        cin>>choice;
        cin.ignore();
        cout<<endl;
        
        //validation
        if(choice>6 || choice<1){
            cout<<"You have entered an incorrect choice."<<endl;
        }else{
            switch(choice){   //menu choice
                case 1: problem1(); break;
                case 2: problem2(); break;
                case 3: problem3(); break;
                case 4: problem4(); break;
                case 5: problem5(); break;
                case 6: again=false; break;
                default:{
                    cout<<"Something went wrong. Exiting program..."<<endl;
                    return 1;
                }
            }
        }
    }while(again);
    
    return 0;
}

void problem1(){
    cout<<"Problem 1:"<<endl;
    cout<<"Gaddis Chapter 13 Problem 1"<<endl;
    
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
    cout<<endl;
}

void problem2(){
    cout<<"Problem 2:"<<endl;
    cout<<"Gaddis Chapter 13 Problem 4"<<endl;
    
    //dynamic array of class
    PersonalInformation *per=new PersonalInformation[3];
    
    //set all the personal information
    setData(per);
    
    //print all the personal information
    for(int i=0;i<3;i++){
        per[i].print();
        cout<<endl;
    }
    
    delete []per;
    delete per;
}

void setData(PersonalInformation *pi){
    //declare variables
    string name;
    string address;
    int age;
    int phone;
    
    cout<<"Input your information along with 2 references"<<endl;
    for(int i=0;i<3;i++){
        if(i==0){
            cout<<"Your name: ";
            getline(cin,name);
            pi[i].setName(name);
            cout<<"Your address: ";
            getline(cin,address);
            pi[i].setAdd(address);
            cout<<"Your age: ";
            cin>>age;
            cin.ignore();
            pi[i].setAge(age);
            cout<<"Your phone number: ";
            cin>>phone;
            cin.ignore();
            pi[i].setPhne(phone);
        }else {
            cout<<"Reference "<<i<<" name: ";
            getline(cin,name);
            pi[i].setName(name);
            cout<<"Reference "<<i<<" address: ";
            getline(cin,address);
            pi[i].setAdd(address);
            cout<<"Reference "<<i<<" age: ";
            cin>>age;
            cin.ignore();
            pi[i].setAge(age);
            cout<<"Reference "<<i<<" phone number: ";
            cin>>phone;
            cin.ignore();
            pi[i].setPhne(phone);
        }
    }
}

void problem3(){
    cout<<"Problem 3:"<<endl;
    cout<<""<<endl;
}

void problem4(){
    cout<<"Problem 4:"<<endl;
    cout<<""<<endl;
}

void problem5(){
    cout<<"Problem 5:"<<endl;
    cout<<""<<endl;
}