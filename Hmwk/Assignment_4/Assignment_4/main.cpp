/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on October 8, 2015, 12:48 PM
 * Purpose: Chapter 11 homework
 */

//system libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//user libraries
#include "SpeakersBureau.h"

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
        cout<<"1. Chapter 11-9\n2. Chapter 11-\n3. Chapter 11-\n4. Chapter 11-\n"
                "5. Chapter 11-\n6. Exit\nYour Choice: ";
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
    cout<<"Gaddis Chapter 11 Problem 9"<<endl<<endl;
    
    int n;             //number of speakers
    bool again=true;
    int choice;        //user choice for menu
    int sChoice;       //speaker choice
    int dChoice;       //data choice
    
    
    cout<<"How many speakers?: "<<endl;
    cin>>n;
    cin.ignore();
    cout<<endl;
    
    Speaker *s=new Speaker[n];

    for(int i=0;i<n;i++){
        cout<<"Speaker Name: ";
        getline(cin,s[i].name);
        cout<<s[i].name<<"'s phone number: ";
        getline(cin,s[i].phone);
        cout<<s[i].name<<"'s topic: ";
        getline(cin,s[i].topic);
        cout<<s[i].name<<"'s fee: ";
        cin>>s[i].fee;
        cin.ignore();
        cout<<endl;
    }
    
    do{
        //output speakers
        cout<<"Speakers:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<". "<<s[i].name<<endl;
        }
        cout<<endl;
        
        do{
            cout<<"1. Change data for a speaker\n2. Display a speakers data\n3. "
                    "Exit"<<endl;
            cin>>choice;
            cin.ignore();
            cout<<endl;
        
            if(choice<1 || choice>3){
                cout<<"Please enter a valid selection"<<endl<<endl;
            }
        }while(choice<1 || choice>3);
        
        switch(choice){
            case 1:{
                do{
                    cout<<"For what speaker do you want to change data for?: ";
                    cin>>sChoice;
                    cin.ignore();
                    if(sChoice<1 || sChoice>n){
                        cout<<"That speaker doesn't exist"<<endl;
                        cout<<endl;
                    }
                }while(sChoice<1 || sChoice>n);
                
                do{
                    cout<<"What data do you want to change?:\n1. Name\n2. Phone"
                            "\n3. Topic\n4. Fee\nChoice: ";
                    cin>>dChoice;
                    cin.ignore();
                }while(dChoice<1 || dChoice>4);
                
                for(int i=0;i<n;i++){
                    if(sChoice==i+1){
                        switch(dChoice){
                            case 1:{
                                cout<<"Enter modified name for "<<s[i].name<<": ";
                                getline(cin,s[i].name);
                                break;
                            }
                            case 2:{
                                cout<<"Enter "<<s[i].name<<"'s new phone: ";
                                getline(cin,s[i].phone);
                                break;
                            }
                            case 3:{
                                cout<<"Enter "<<s[i].name<<"'s new topic: ";
                                getline(cin,s[i].topic);
                                break;
                            }
                            case 4:{
                                cout<<"Enter "<<s[i].name<<"'s fee: ";
                                cin>>s[i].fee;
                                cin.ignore();
                                break;
                            }
                            default: cout<<"Data choice error"<<endl; break;
                        }
                    }
                }
                break;
            }
            case 2:{
                for(int i=0;i<n;i++){
                    cout<<s[i].name<<endl;
                    cout<<"phone number: "<<s[i].phone<<endl;
                    cout<<"topic: "<<s[i].topic<<endl;
                    cout<<"fee: "<<s[i].fee<<endl;
                    cout<<endl;
                }
                break;
            }
            case 3: again=false; cout<<"Exiting Program..."<<endl; break;
        }
    }while(again);
    
    delete []s;
}

void problem2(){
    cout<<"Problem 2:"<<endl;
    cout<<"Gaddis Chapter 11 Problem 9"<<endl<<endl;
}

void problem3(){
    cout<<"Problem 3:"<<endl;
    cout<<"Gaddis Chapter 11 Problem 9"<<endl<<endl;
}

void problem4(){
    cout<<"Problem 4:"<<endl;
    cout<<"Gaddis Chapter 11 Problem 9"<<endl<<endl;
}

void problem5(){
    cout<<"Problem 5:"<<endl;
    cout<<"Gaddis Chapter 11 Problem 9"<<endl<<endl;
}