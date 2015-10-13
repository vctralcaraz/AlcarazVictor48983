/* 
 * File:   Property.cpp
 * Author: rcc
 * 
 * Created on October 13, 2015, 1:43 PM
 */

#include "Property.h"
using namespace std;
void Property::setName(string n){
    name=n;
}
void Property::setCost(int c){
    cost=c;
}
void Property::setRent(int r){
    rent=r;
}
void Property::setHouse(int h){
    house=h;
}
string Property::getName(){
    return name;
}
int Property::getCost(){
    return cost;
}
int Property::getRent(){
    return rent;
}
int Property::getHouse(){
    return house;
}