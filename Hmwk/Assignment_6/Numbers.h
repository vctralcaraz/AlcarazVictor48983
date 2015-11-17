/* 
 * File:   Numbers.h
 * Author: Victor Alcaraz
 * Created on November 6, 2015, 1:57 PM
 * Purpose: Implementation of Numbers class
 */

#ifndef NUMBERS_H
#define	NUMBERS_H

#include <string>
using namespace std;

class Numbers {
private:
    int numbers;
    int ones;
    int tens;
    int hundrds;
    int thsnds;
    void setNum(string);
public:
    Numbers(string);
    void print();
};

#endif	/* NUMBERS_H */

