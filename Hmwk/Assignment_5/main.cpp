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
#include "RetailItem.h"
#include "Inventory.h"

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
        cout<<"1. Chapter 13.1\n2. Chapter 13.4\n3. Chapter 13.5\n4. Chapter 13.6\n"
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
    cout<<"Gaddis Chapter 13 Problem 1"<<endl<<endl;
    
    int month;  //month number
    int day;    //day of the month
    int year;   //year
    Date yDate; //your date
    
    //date input
    cout<<"Enter the month number: ";
    cin>>month;
    cout<<"Enter the day: ";
    cin>>day;
    cout<<"Enter the year (yyyy): ";
    cin>>year;
    
    //set date
    yDate.setMonth(month);
    yDate.setDay(day);
    yDate.setYear(year);
    
    //print date
    yDate.print();
    cout<<endl<<endl;
}

void problem2(){
    cout<<"Problem 2:"<<endl;
    cout<<"Gaddis Chapter 13 Problem 4"<<endl<<endl;
    
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
}

void setData(PersonalInformation *pi){
    //declare variables
    string name;
    string address;
    int age;
    long long phone;
    bool you=true;
    
    cout<<"Input your information along with 2 references"<<endl;
    for(int i=0;i<3;i++){
        if(you){
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
            you=false;
            cout<<endl;
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
            cout<<endl;
        }
    }
}

void problem3(){
    cout<<"Problem 3:"<<endl;
    cout<<"Gaddis Chapter 13 Problem 5"<<endl<<endl;
    
    //declare variables
    string des;
    int unit;
    float pri;
    
    des="Jacket";
    unit=12;
    pri=59.95;
    
    RetailItem jacket(des,unit,pri);
    
    des="Designer Jeans";
    unit=40;
    pri=34.95;
    
    RetailItem jeans(des,unit,pri);
    
    des="Shirt";
    unit=20;
    pri=24.95;
    
    RetailItem shirt(des,unit,pri);
    
    jacket.print();
    jeans.print();
    shirt.print();
}

void problem4(){
    cout<<"Problem 4:"<<endl;
    cout<<"Gaddis Chapter 13 Problem 5"<<endl<<endl;
    
    int number;
    int quant;
    float cost;
    
    cout<<"What is the item number?: ";
    cin>>number;
    cin.ignore();
    cout<<"What is the cost of the item?: $";
    cin>>cost;
    cin.ignore();
    cout<<"How many is being purchased?: ";
    cin>>quant;
    cin.ignore();
    
    Inventory item(number,quant,cost);
    item.print();
    cout<<endl;
}

void problem5(){
    cout<<"Problem 5:"<<endl;
    cout<<""<<endl;
}