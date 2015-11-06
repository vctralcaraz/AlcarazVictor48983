/* 
 * File:   Coin.cpp
 * Author: Victor Alcaraz
 * Created on November 6, 2015, 11:55 AM
 * Purpose: Implementation of Coin class
 */

#include "Coin.h"
using namespace std;

Coin::Coin(){
    headCnt=0;
    tailCnt=0;
}
void Coin::toss(int r){
    if(r==1){
        sideUp="Heads";
        headCnt++;
    }
    if(r==2){
        sideUp="Tails";
        tailCnt++;
    }
}
string Coin::getSide(){
    return sideUp;
}
int Coin::getHCnt() const{
    return headCnt;
}
int Coin::getTCnt() const{
    return tailCnt;
}