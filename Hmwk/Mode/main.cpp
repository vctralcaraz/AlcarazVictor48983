/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on September 17, 2015, 12:42 PM
 * Purpose: Find the number of modes and frequencies
 */

//system libraries
#include <iostream>
#include <vector>
using namespace std;

//user libraries

//global constants

//function prototypes
void fillAry(int[],int,int);
void prntAry(int[],int);
void prntVec(vector<int>&);
void sortAry(int[],int);

//execution begins here
int main(int argc, char** argv) {

    //declare variables
    int fcount=0,   //frequency
        mod=20,     //mod number for array
        mode=0,     //mode count
        size=50;    //size of array
    vector<int> freq;    //frequency of numbers
    char choice;    //user choice
    
    do{
        cout<<"Do you want to change the mod and SIZE of the array? [y]/[n]"<<endl;
        cout<<"Default mod is "<<mod<<" and default SIZE is "<<size<<endl;
        cin>>choice;
        if(choice!='Y' && choice!='y' && choice!='N' && choice!='n'){
            cout<<"You did not enter a [Y] or [N]"<<endl;
        }
    }while(choice!='Y' && choice!='y' && choice!='N' && choice!='n');
    
    if(choice=='Y' || choice=='y'){
        cout<<"What number do you want for the mod?"<<endl;
        cin>>mod;
        
        cout<<"What size do you want the array to be?"<<endl;
        cin>>size;
    }
    
    int numbers[size]={}; //initialize the array.
    
    cout<<"Initial Array: "<<endl;
    fillAry(numbers,size,mod);
    prntAry(numbers,size);
    
    cout<<"Sorted Array: "<<endl;
    sortAry(numbers,size);
    prntAry(numbers,size);
    
    for(int i=0;i<size;i++){
        
        //if the current number equals the next number, add to frequency
        if(numbers[i]==numbers[i+1]){
            fcount++;
        }else {
            freq.push_back(fcount);
            fcount=0;
        }
    }
    
    prntVec(freq);
    
    int max=0;
    for(int i=0;i<freq.size();i++){
        if(freq[i]>max){
            max=freq[i];
        }
    }
    
    for(int i=0;i<freq.size();i++){
        if(max==freq[i]){
            mode++;
        }
    }
    
    cout<<"Number of Modes is "<<mode<<endl;
    
    return 0;
}

void prntVec(vector<int>& v){
    cout<<"Frequency of numbers: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

void sortAry(int x[],int size){
    for(int i=0;i<size;i++){
        int temp=0;
        for(int j=0;j<size-1;j++){
            if(x[j]>x[j+1]){
                temp=x[j+1];
                x[j+1]=x[j];
                x[j]=temp; 
            }
        }
    }
}

void prntAry(int x[],int size){
    for(int i=0;i<size;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void fillAry(int x[],int size,int j){
    for(int i=0;i<size;i++){
        x[i]=i%j;
    }
}