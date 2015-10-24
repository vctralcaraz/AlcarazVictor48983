/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on October 22, 2015, 5:41 PM
 * Purpose: to learn writing to binary files
 */

#include <iostream>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const int SIZE=4;
    char data[SIZE]={'A','B','C','D'};
    char nData[SIZE];
    fstream file;
    
    //open the file for output in binary mode.
    file.open("test.txt", ios::out | ios::binary);
    
    //write the contents of the array to the file.
    cout<<"Writing the characters to the file.\n";
    file.write(data, sizeof(data));
    
    //close the file
    file.close();
    
    //open the file for input in binary mode.
    file.open("test.txt", ios::in | ios::binary);
    
    //read the contents of the file into the array.
    cout<<"Now reading the data back into memory.\n";
    file.read(nData,sizeof(nData));
    
    //display the contents of the array.
    for(int count=0;count<SIZE;count++){
        cout<<nData[count]<<" ";
    }
    cout<<endl;
    
    //close the file.
    file.close();
    return 0;
}

