/* 
 * File:   card.h
 * Author: Victor Alcaraz
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Specification for the Card Class
 */

#ifndef CARD_H
#define	CARD_H

class Card{
    private:
        char number;
        void setNumb(char);                //Mutator / utility
    public:
        Card(){number=1;}
        Card(char);                        //Constructor
        char getNumb(){return number;}     //Accessor
        char suit();                       //Suit property
        char numVal();                     //numerical value property
        char faceVal();                    //face value property
};


#endif	/* CARD_H */

