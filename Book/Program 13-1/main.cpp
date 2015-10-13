/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on October 12, 2015, 1:43 PM
 * Purpose: Gaddis Book Program Example 13-1
 */

//system libraries
#include <iostream>
using namespace std;

//user libraries
#include "Rectangle.h"

//global functions

//Function Prototypes

//execution
int main(int argc, char** argv) {
    Rectangle box;    //Define an instance of the Rectangle class
    int rectWidth;    //local variable for width
    int rectLength;   //local variable for length
    
    //get the rectangle's width and length from the user
    cout<<"This program will calculate the area of a\n";
    cout<<"rectangle. What is the width? ";
    cin>>rectWidth;
    cin.ignore();
    cout<<"What is the length? ";
    cin>>rectLength;
    cin.ignore();
    
    //stores the width and length of the rectangle
    //in the box object.
    box.setWidth(rectWidth);
    box.setLength(rectLength);
    
    //Display the rectangle's data.
    cout<<"Here is the rectangle's data:\n";
    cout<<"Width: "<<box.getWidth()<<endl;
    cout<<"Length: "<<box.getLength()<<endl;
    cout<<"Area: "<<box.getArea()<<endl;
    return 0;
}