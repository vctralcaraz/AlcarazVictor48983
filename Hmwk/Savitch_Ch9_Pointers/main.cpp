/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on September 24, 2015, 12:45 PM
 * Purpose: Chapter 9 Savitch: Pointers and Dynamic Arrays
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//user libraries

//global constants

//function prototypes
void problem1();
void problem2();
void problem3();

//execution begins here
int main(int argc, char** argv) {
    int choice;
    do{
        do{
            cout<<"1. Problem 1\n2. Problem 2\n3. Problem 3\n-1 to terminate"<<endl;
            cin>>choice;
            cin.ignore();
            if(choice!=-1 && choice<1 && choice>3){
                cout<<"You didn't choose a number from the list"<<endl;
            }
        }while(choice!=-1 && choice<1 && choice>3);

        switch(choice){
            case 1: problem1(); break;
            case 2: problem2(); break;
            case 3: problem3(); break;
            default: cout<<"See you next time!"<<endl;
        }
    }while(choice!=-1);
    
    return 0;
}

void problem1(){
    cout<<"Problem 1:"<<endl;
    cout<<"Savitch 9th Edition Chapter 9 Problem 5: Computer Lab Logins"<<endl;
    
    
    //declare variables
    int num=4;   
    int com[num]={5,6,4,3};    //number of computers
    int **temp;                //double pointer for 2D dynamic array
    temp = new int *[num];
    
    //initializing 2D dynamic array according to number of computers
    for(int i=0;i<num;i++){
        temp[i] = new int[com[i]];
    }
    
    int stat;   //station number
    int id;     //id number
    int lab;    //lab number
    int choice; //user choice
    bool again=true;  //boolean do again
    
    //do-while for whole program
    do{
        cout<<endl;
        
        //output the dynamic array
        for(int i=0;i<num;i++){
            cout<<"Lab "<<i+1<<' ';
            for(int j=0;j<com[i];j++){
                cout<<j+1<<": ";
                if(temp[i][j]==0) cout<<"empty ";
                else cout<<temp[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
        
        //do-while for validation of input
        do{
            cout<<endl<<"1. Logon\n2. Logoff\n3. Exit"<<endl<<endl;
            cout<<"What would you like to do?: ";
            cin>>choice;
            if(choice<1 && choice>3){
                cout<<"You didn't enter a proper selection"<<endl;
            }
        }while(choice<1 && choice>3);
    
        switch(choice){
            case 1: {
                again=true;
                cout<<"What is your ID number?: ";
                cin>>id;
                cout<<"What computer are you logging on to?: ";
                cin>>stat;
                cout<<"What lab are you in?: ";
                cin>>lab;
                if(stat>com[lab-1]){
                    cout<<endl<<"That computer is not in lab "<<lab<<endl;
                    break;
                }else{
                    //check if someone is already logged in to selected station
                    if(temp[lab-1][stat-1]!=0){
                        cout<<endl<<"!!! Someone is already logged in to that station !!!"<<endl<<endl;
                    }else temp[lab-1][stat-1]=id;  //log ID to station/lab
                    break;
                }
            }
            case 2: {
                again=true;
                cout<<"What computer are you logged in to?: ";
                cin>>stat;
                cout<<"What lab are you in?: ";
                cin>>lab;
                
                //check if someone is logged in to selected station
                if(temp[lab-1][stat-1]!=0){
                    temp[lab-1][stat-1]=0;   //log the ID out
                    cout<<"You have logged out."<<endl;
                }else {
                    cout<<"There is no login account for that computer station."<<endl;
                }
                break;
            }
            case 3: {
                //exit do-while
                again=false;
                break;
            }
            default: cout<<"ERROR: Program terminating"<<endl; again=false;
        }
        
    }while(again);
    
    //delete dynamic array
    for(int i=0;i<num;i++){
        delete [] temp[i];
    }
    delete [] temp;
    
    cout<<endl<<endl;
}

void problem2(){
    bool valid=true;
    cout<<"Problem 2:"<<endl;
    cout<<"Savitch 8th Edition Chapter 9 Problem 3: plane seating with dynamic arrays"<<endl<<endl;
    
    bool again=true;
    string choice;
    const int COLS=7, ROWS=4;
    char plane[COLS][ROWS];
    int temp;
    int count=0;
    
    for(int i=0;i<COLS;i++){
        for(int j=0;j<ROWS;j++){
            if(j%4==0) plane[i][j]='A';
            else if(j%4==1) plane[i][j]='B';
            else if(j%4==2) plane[i][j]='C';
            else if(j%4==3) plane[i][j]='D';
        }
    }
    
    do{
        cout<<endl<<"CSC-17A Airline Seating"<<endl;
        for(int i=0;i<COLS;i++){
            cout<<i+1<<' ';
            for(int j=0;j<ROWS;j++){
                cout<<plane[i][j];
                if(j<ROWS) cout<<' ';
            }
            cout<<endl;
        }
        if(count==(COLS*ROWS)){
            cout<<endl<<"Seats are full. Thank you for choosing CSC-17A Airlines"<<endl;
            again=false;
        }else{
            do{
                valid=true;
                cout<<"What seat do you want? ex. 2B"<<endl;
                cout<<"-1 to exit"<<endl;
                
                getline(cin,choice);
                
                if(choice=="-1") cout<<endl<<"Thank you for choosing CSC-17A Airlines"<<endl;
                else{
                    if(choice.size()!=2){
                        cout<<choice.size()<<endl;
                        cout<<endl<<"size Invalid seat selection"<<endl;
                        valid=false;
                    }
                    else{
                        if(choice[0]<'1' || choice[0]>'7' || choice[1]<'A' || choice[1]>'D'){
                            cout<<"Invalid seat selection"<<endl;
                            valid=false;
                        }
                        else{
                            temp=choice[1]-65;
                            cout<<temp<<endl;
                        }
                        //check if someone is already seated there
                        if(valid){
                            if(plane[(choice[0]-48)-1][temp]=='X'){
                                cout<<endl<<"That seat is already taken"<<endl;
                            }else{
                                plane[(choice[0]-48)-1][temp]='X';  //set seat = taken (X))
                                count++;
                            }
                        }
                    }
                }
            }while(!valid);
        }
    }while(again && choice!="-1");
    cout<<endl;
}

void problem3(){
    cout<<"Problem 3:"<<endl;
    cout<<"Savitch 8th Edition Chapter 9 Problem : "<<endl;
}