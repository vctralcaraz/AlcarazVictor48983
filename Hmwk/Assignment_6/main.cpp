/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on November 6, 2015, 1:39 PM
 * Purpose: Chapter 14 Homework (Assignment 6)
 */

//system libraries
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Numbers.h"
using namespace std;

//user libraries

//global constants

//function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();

//execution begins here
int main(int argc, char** argv) {
    //declare user input for menu
    int choice;
    
    bool again=true;
    
    do{
        //menu
        cout<<"1. Chapter 14.1\n2. Chapter 14.2\n3. Chapter 14.3\n4. Chapter 14.4\n"
                "5. Chapter 14.5\n6. Exit\nYour Choice: ";
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
    cout<<"Gaddis Chapter 14 Problem 1"<<endl<<endl;
    
    //declare variables
    string number;
    
    cout<<"Enter a number between 0 and 9999 (inclusive): ";
    cin>>number;
    cin.ignore();
    
    Numbers numbers(number);
    numbers.print();
}

void problem2(){
    cout<<"Problem 2:"<<endl;
    cout<<"Gaddis Chapter 14 Problem 2"<<endl<<endl;
    
}

void problem3(){
    cout<<"Problem 1:"<<endl;
    cout<<"Gaddis Chapter 14 Problem 3"<<endl<<endl;
    
}

void problem4(){
    cout<<"Problem 1:"<<endl;
    cout<<"Gaddis Chapter 14 Problem 4"<<endl<<endl;
    
}

void problem5(){
    cout<<"Problem 1:"<<endl;
    cout<<"Gaddis Chapter 14 Problem 5"<<endl<<endl;
    
}