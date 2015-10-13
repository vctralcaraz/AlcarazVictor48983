/* 
 * File:   Property.h
 * Author: rcc
 *
 * Created on October 13, 2015, 1:43 PM
 */

#ifndef PROPERTY_H
#define	PROPERTY_H
#include <iostream>
using namespace std;

class Property {
private:
    string name;
    int cost;
    int rent;
    int house;
public:
    void setName(string);
    void setCost(int);
    void setRent(int);
    void setHouse(int);
    string getName();
    int getCost();
    int getRent();
    int getHouse();
};

#endif	/* PROPERTY_H */

