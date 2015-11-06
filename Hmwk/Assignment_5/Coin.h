/* 
 * File:   Coin.h
 * Author: Victor Alcaraz
 * Created on November 6, 2015, 11:55 AM
 * Purpose: Specification of Coin class
 */

#ifndef COIN_H
#define	COIN_H

#include <string>
using namespace std;

class Coin {
private:
    string sideUp;       //heads or tails
    int headCnt;         //count of number of heads
    int tailCnt;         //count of number of tails
public:
    Coin();              //constructor
    void toss(int);      //mutator
    string getSide();    //accessor of side
    int getHCnt() const; //accessor of head count
    int getTCnt() const; //accessor of tail count
};

#endif	/* COIN_H */