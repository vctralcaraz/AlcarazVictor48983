/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on October 4, 2015, 8:18 AM
 * Purpose: Chapter 10 and Chapter 12 Homework
 */

//system libraries
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
using namespace std;

//user libraries
struct Divison{
    string name[4]={"East","West","North","South"};
};
struct Quarter{
    int quart=4;
};
struct Sales{
    int sale[4];
};

//global constants

//function prototypes
void problem1();
int wrdCnt(string,int,float &);
void problem2();
int cntVwls(string);
int cntCnst(string);
int cntBoth(string);
void problem3();
void problem4();
void arryToF(ofstream &,int *,int);
void fileToA(ifstream &,int *,int);
void problem5();

//execution begins here
int main(int argc, char** argv) {
    //declare user input for menu
    int choice;
    
    bool again=true;
    
    do{
        //menu
        cout<<"1. Chapter 10-4\n2. Chapter 10-6\n3. Chapter 12-7\n4. Chapter 12-8\n"
                "5. Chapter 12-11\n6. Exit\nYour Choice: ";
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
    cout<<"Gaddis Chapter 10 Problem 4: "<<endl<<endl;
    
    //declare strings and pointer
    string *stptr;
    string text;
    
    //declare variable
    float ave=0;
    int sum=0;
    
    cout<<"Enter a phrase: ";
    getline(cin,text);
    
    stptr= &text;
    cout<<endl;
    cout<<"You have "<<wrdCnt(*stptr,sum,ave)<<" words in your phrase."<<endl;
    cout<<"Average letter per word is "<<ave<<endl;
    cout<<endl;
}

int wrdCnt(string words,int sum,float &avrg){
    
    int count=0;
    string temp;
    words+=' ';
    for(int i=0;i<words.size();i++){
        if(words[i]==' '){
            if(temp.empty()){
                
            }else{
                count++;
                temp="";
            }
        }else temp+=words[i];
        if(words[i]!=' ') sum++;
    }
    avrg=static_cast<float>(sum)/count;
    return count;
}

void problem2(){
    cout<<"Gaddis Chapter 10 Problem 6: "<<endl<<endl;
    
    //declare strings and pointer
    string *stptr;
    string text;
    
    //declare variables
    char choice;
    bool again=true;
    
    
    
    
    
    do{
        //input
        cout<<"Enter a string: ";
        getline(cin,text);
        //pointer equals variable
        stptr= &text;
        do{
            do{
                //menu
                cout<<"A) Count the number of vowels in the string"<<endl;
                cout<<"B) Count the number of consonants in the string"<<endl;
                cout<<"C) Count both the vowels and consonants in the string"<<endl;
                cout<<"D) Enter another string"<<endl;
                cout<<"E) Exit the program"<<endl;
                cout<<"Please enter a selection: ";
                cin>>choice;
                cin.ignore();
                cout<<endl;
                
                //validation
                if(choice<'A' && choice>'E' || choice<'a' && choice>'e'){
                    cout<<"You did not enter an appropriate selection. Please try again."<<endl;
                }
            }while(choice<'A' && choice>'E' || choice<'a' && choice>'e');

            if(choice=='A' || choice=='a'){
                cout<<"Your string has "<<cntVwls(*stptr)<<" vowels"<<endl;
            }else if(choice=='B' || choice=='b'){
                cout<<"Your string has "<<cntCnst(*stptr)<<" consonants"<<endl;
            }else if(choice=='C' || choice=='c'){
                cout<<"Your string has "<<cntBoth(*stptr)<<" letters"<<endl;
            }else if(choice=='D' || choice=='d'){

            }else{
                again=false;
            }
            
            cout<<endl;
        }while(choice!='D' && choice!='d' && choice!='E' && choice!='e');
    }while(again);
}
int cntVwls(string words){
    int count=0;
    for(int i=0;i<words.size();i++){
        //check for vowel
        if(words[i]=='a' || words[i]=='A' || words[i]=='e' || words[i]=='E' ||
           words[i]=='i' || words[i]=='I' || words[i]=='o' || words[i]=='O' ||
           words[i]=='u' || words[i]=='U'){
            //add to count if vowel
            count++;
        }
    }
    
    return count;
}

int cntCnst(string words){
    int count=0;
    for(int i=0;i<words.size();i++){
        //check if letter
        if(words[i]>='A' && words[i]<='Z' || words[i]>='a' && words[i]<='z'){
            //check for vowel
            if(words[i]!='a' && words[i]!='A' && words[i]!='e' && words[i]!='E' &&
               words[i]!='i' && words[i]!='I' && words[i]!='o' && words[i]!='O' &&
               words[i]!='u' && words[i]!='U' && words[i]!=' '){
            
                //add to count if consonant
                count++;
            }
        }
    }
    
    return count;
}

int cntBoth(string words){
    int count=0;
    for(int i=0;i<words.size();i++){
        //check for letter
        if(words[i]>='A' && words[i]<='Z' || words[i]>='a' && words[i]<='z'){
            count++;
        }
    }
    
    return count;
}

void problem3(){
    cout<<"Gaddis Chapter 12 Problem 7: "<<endl;
    
    //file streams
    ifstream fin;
    ofstream fout;
    
    //declare variables
    string temp;
    bool isFrst=true;
    
    //opening files
    cout<<"opening 'sentences.txt' ..."<<endl;
    fin.open("sentences.txt");
    cout<<"opening 'outfile.txt' ..."<<endl;
    fout.open("outfile.txt");
    
    cout<<"Grabbing from 'sentences.txt' and converting upper case and lower case "
            "characters in each sentence ..."<<endl;
    while(getline(fin,temp)){
        for(int i=0;i<temp.size()-1;i++){
            //check if temp[i] is the first letter of the sentence
            if(!isFrst){
                //check for a period
                if(temp[i]=='.'){
                    isFrst=true;   //if there is a period set first letter of sentence to true
                }
                //if temp[i] is uppercase and not first letter, change to lowercase
                if(temp[i]!=' ' && temp[i]>='A' && temp[i]<='Z'){
                    temp[i]=temp[i]+32;
                }
            }
            if(isFrst){
                if(temp[i]!=' ' && temp[i]>='a' && temp[i]<='z'){
                    temp[i]=temp[i]-32;
                    isFrst=false;
                }else if(temp[i]!=' ' && temp[i]>='A' && temp[i]<='Z'){
                    isFrst=false;
                }
            }
        }
        fout<<temp;
    }
    
    cout<<"Your file has completed the process and finished writing to 'outfile.txt'"<<endl;
    cout<<"Both files have closed"<<endl;
    fin.close();
    fout.close();
    cout<<endl;
}

void problem4(){
    cout<<"Gaddis Chapter 12 Problem 8: "<<endl<<endl;
    
    //declare pointer and dynamic array
    int *intptr;
    int size=5;
    intptr=new int [size];
    
    int mult;
    cout<<"What multiple of a number do you want store in the array? ";
    cin>>mult;
    for(int i=0;i<size;i++){
        intptr[i]=mult*(i+1);
    }
    
    //fstream variables
    ifstream fin;
    ofstream fout;
    
    cout<<"Writing the array to file 'array.txt' ..."<<endl;
    arryToF(fout,intptr,size);
    cout<<"Finished writing array to file."<<endl;
    cout<<endl;
    
    cout<<"Getting array from file 'array2.txt'"<<endl;
    fileToA(fin,intptr,size);
    cout<<"Finished grabbing array from file"<<endl;
    
    cout<<"Go check your files"<<endl;
    fin.close();
    fout.close();
    cout<<endl;
}

void arryToF(ofstream &fout,int a[],int s){
    fout.open("array.txt", ios::out | ios::binary);
    
    for(int i=0;i<s;i++){
        fout<<a[i];
        fout<<' ';
    }
}

void fileToA(ifstream &fin,int a[],int s){
    fin.open("array2.txt", ios::in | ios::binary);
    
    int i=0;
    while(fin){
        fin>>a[i];
        i++;
    }
    
    cout<<"The array from file 'array2.txt': "<<endl;
    for(int i=0;i<s;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl<<endl;
}

void problem5(){
    cout<<"Gaddis Chapter 12 Problem 11: "<<endl;
    
    //Declare Variables
    Divison div;
    Quarter quart;
    Sales amount;
    ofstream fout;
    
    //Open file
    cout<<"Opening 'sales.txt' ..."<<endl;
    fout.open("sales.txt");
    cout<<"'sales.txt' has been opened"<<endl;
    
    //loop to enter sales
    for(int i=0;i<quart.quart;i++){
        for(int j=0;j<quart.quart;j++){
        cout<<"Input the sales for the "<<div.name[i]<<" division, quarter "<<j+1<<": $";
        cin>>amount.sale[j];
        //Inputs into the file
        fout<<div.name[i]<<" division, quarter "<<j+1<<" sales: $"<<amount.sale[j]<<endl;
        }   
        cout<<endl;
        fout<<endl;
    }
    
    //Close file
    cout<<"Finished writing to 'sales.txt'"<<endl;
    fout.close();
    cout<<endl;
}