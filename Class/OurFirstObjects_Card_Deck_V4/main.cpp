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
#include "Deck.h"

//global constants

//function prototypes

//execution
int main(int argc, char** argv) {
    //declare some variables
    srand(static_cast<unsigned int>(time(0)));
    Deck *deck=new Deck();
    
    //loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=0;i<deck->getNCrd();i++){
        Card card(deck->deal()+1);
        cout<<"Card Number = "<<static_cast<int>(card.getNumb());
        cout<<" Suit = "<<card.suit();
        cout<<" Numerical Value = "<<static_cast<int>(card.numVal());
        cout<<" Face Value = "<<card.faceVal()<<endl;
    }
    
    //exit stage right
    delete []deck;
    return 0;
}