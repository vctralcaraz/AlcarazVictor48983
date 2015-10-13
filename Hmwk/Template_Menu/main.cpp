/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on October 8, 2015, 12:43 PM
 * Purpose: menu template
 */

//system libraries
#include <iostream>
using namespace std;

//user libraries

//global constants

//function prototypes
void problem1();
void problem2();
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
        cout<<"1. Chapter \n2. Chapter \n3. Chapter \n4. Chapter \n"
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
    cout<<""<<endl;
}

void problem2(){
    cout<<"Problem 2:"<<endl;
    cout<<""<<endl;
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