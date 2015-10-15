/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Creation of first Object Oriented Program
 */

//system libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//user libraries
#include "card.h"

//global constants

//function prototypes

//execution
int main(int argc, char** argv) {
    //declare some variables
    
    
    //loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=1;i<=52;i++){
        Card card(i);
        card.setNumb(i);
        cout<<"Card Number = "<<static_cast<int>(card.getNumb());
        cout<<" Suit = "<<card.suit();
        cout<<" Numerical Value = "<<static_cast<int>(card.numVal());
        cout<<" Face Value = "<<card.faceVal()<<endl;
    }
    
    
    return 0;
}