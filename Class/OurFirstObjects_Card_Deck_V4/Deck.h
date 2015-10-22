/* 
 * File:   Deck.h
 * Author: Victor Alcaraz
 * Created on October 22, 2015, 11:51 AM
 * Purpose: Specification for the Deck Class
 */

#ifndef DECK_H
#define	DECK_H

#include "card.h"

class Deck{
    private:
        int nCards;
        Card **card;
        char *indx;
        char dltCard;
    public:
        Deck();
        ~Deck();
        void shuffle();
        char deal();
        int getNCrd();
};

#endif	/* DECK_H */