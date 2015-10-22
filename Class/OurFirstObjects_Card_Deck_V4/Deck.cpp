/* 
 * File:   Deck.h
 * Author: Victor Alcaraz
 * Created on October 22, 2015, 11:51 AM
 * Purpose: Implementation for the Deck Class
 */

#include <cstdlib>
#include "Deck.h"
#include "card.h"

Deck::Deck(){
    //Start constructing the deck by initializing the properties
    card=new Card *[nCards];
    indx=new char[nCards];
    dltCard=0;
    nCards=52;
    //loop and create cards and index
    for(int i=0;i<nCards;i++){
        card[i]=new Card(i+1);
        indx[i]=i;
    }
}
Deck::~Deck(){
    //Deallocate memory
    for(int i=0;i<nCards;i++){
        delete card[i];
    }
    delete []card;
    delete []indx;
}
void Deck::shuffle(){
    for(int nShuffles=1;nShuffles<=7;nShuffles++){
        for(int i=0;i<nCards;i++){
            int rnd=rand()%nCards;
            int temp=indx[i];
            indx[i]=indx[rnd];
            indx[rnd]=temp;
        }
    }
}
char Deck::deal(){
    if(dltCard>.9*nCards){
        shuffle();
        dltCard=0;
    }
    return indx[dltCard++];
}
int Deck::getNCrd(){
    return nCards;
}