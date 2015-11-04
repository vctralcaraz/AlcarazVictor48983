/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on November 4, 2015, 1:56 PM
 * Purpose: Book Program 14-1
 */

#include <iostream>
using namespace std;

#include "Tree.h"

int main(int argc, char** argv) {
    //Define three Tree objects.
    Tree oak;
    Tree elm;
    Tree pine;
    
    //display the number of Tree objects we have.
    cout<<"We have "<<pine.getObjectCount()<<" trees in our program!"<<endl;
    return 0;
}

