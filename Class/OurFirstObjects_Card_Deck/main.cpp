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
    const int nCards=52;
    Card **card=new Card *[nCards];
    char *indx=new char[nCards];
    
    //loop on all potential 52 cards
    cout<<endl<<"Class Check"<<endl;
    for(int i=0;i<nCards;i++){
        card[i]=new Card(i+1);
        indx[i]=i;
        cout<<"Card Number = "<<static_cast<int>(card[i]->getNumb());
        cout<<" Suit = "<<card[i]->suit();
        cout<<" Numerical Value = "<<static_cast<int>(card[i]->numVal());
        cout<<" Face Value = "<<card[i]->faceVal()<<endl;
    }
    
    //how to shuffle the deck
    srand(static_cast<unsigned int>(time(0)));
    for(int nShuffles=1;nShuffles<=7;nShuffles++){
        for(int i=0;i<nCards;i++){
            int rnd=rand()%nCards;
            int temp=indx[i];
            indx[i]=indx[rnd];
            indx[rnd]=temp;
        }
    }
    
    //output the array
    cout<<endl<<"After Shuffle"<<endl;
    for(int i=0;i<nCards;i++){
        cout<<"Card Number = "<<static_cast<int>(card[indx[i]]->getNumb());
        cout<<" Suit = "<<card[indx[i]]->suit();
        cout<<" Numerical Value = "<<static_cast<int>(card[indx[i]]->numVal());
        cout<<" Face Value = "<<card[indx[i]]->faceVal()<<endl;
    }
    
    //exit stage right
    for(int i=0;i<nCards;i++){
        delete card[i];
    }
    delete []card;
    delete []indx;
    return 0;
}