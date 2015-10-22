/* 
 * File:   card.cpp
 * Author: Victor Alcaraz
 * Created on October 15, 2015, 11:20 AM
 * Purpose: Implementation for the Card Class
 */

//user library for the specification
#include "card.h"

Card::Card(char n){
    setNumb(n);
}
void Card::setNumb(char n){
    if(n<1 || n>52) number=1;
    else number=n;
}
char Card::suit(){
    //declare suit array
    char aSuit[4]={'S','H','C','D'};
    return aSuit[(number-1)/13];
}
char Card::numVal(){
    char numVal;
    numVal=(number-1)%13+1;
    if(numVal>10) numVal=10;
    return numVal;
}
char Card::faceVal(){
    char fValue[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    return fValue[(number-1)%13];
}