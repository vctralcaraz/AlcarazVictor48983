/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on September 17, 2015, 12:42 PM
 * Purpose: Find the mean, median, and number of modes
 */

//system libraries
#include <iostream>
using namespace std;

//user libraries

//global constants

//function prototypes
void fillAry(int[],int,int);
void prntAry(int[],int);
void sortAry(int[],int);
float mean(int [],int);
float median(int [],int);
int *mode(int [],int);

//execution begins here
int main(int argc, char** argv) {

    //declare variables
    int mod=20,     //mod number for array
        size=50;    //size of array
    int *a;
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
    
    cout<<endl;
    cout<<"The mean of the data is "<<mean(numbers,size)<<endl;
    cout<<"The median of the data is "<<median(numbers,size)<<endl;
    cout<<"The number of modes data: "<<endl;
    *mode(numbers,size);
    
    return 0;
}

float mean(int numbers[],int size){
    float ave=0;
    float sum=0.0f;
    
    for(int i=0;i<size;i++){
        sum+=numbers[i];
    }
    ave=sum/size;
    
    return ave;
}

float median(int numbers[],int size){
    int middle;
    float ave;
    if(size%2==0){
        ave=(numbers[(size/2)]+numbers[((size/2)+1)])/2;
        return ave;
    }else if(size%2==1){
        middle=numbers[size/2];
        return static_cast<float>(middle);
    }
}

int *mode(int numbers[],int size){
    
    int count=0;
    int max=0;
    int j=0;
    int nModes=0;
    
    for(int i=0;i<size;i++){
        if(numbers[i]==numbers[i+1]){
            count++;
        }else if(numbers[i]!=numbers[i+1]){
            if(count>=max){
                max=count;
                nModes++;
            }
            count=0;
        }else cout<<"error1"<<endl;
    }
    for(int i=0;i<size;i++){
        if(max==numbers[i]) nModes++;
    }
    int nSize=nModes+2;
    
//    a=new int[nSize];
    int a[nSize];
    a[0]=nModes;
    a[1]=max;
    j=0;
    for(int i=2;i<nSize;i++){
        a[i]=numbers[j];
        j++;
    }
    for(int i=0;i<nSize;i++){
        cout<<a[i]<<", ";
    }
    return a;
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