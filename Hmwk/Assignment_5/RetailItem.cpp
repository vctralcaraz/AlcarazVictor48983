/* 
 * File:   RetailItem.cpp
 * Author: Victor Alcaraz
 * Created on October 14, 2015, 1:20 PM
 */

#include <iostream>
using namespace std;
#include "RetailItem.h"

//private
void RetailItem::setDesc(string d){
    descrbe=d;
}
void RetailItem::setUnit(int u){
    units=u;
}
void RetailItem::setPrce(float p){
    price=p;
}
//public
RetailItem::RetailItem(string d,int u, float p){
    setDesc(d);
    setUnit(u);
    setPrce(p);
}
void RetailItem::print(){
    cout<<"Description: "<<descrbe<<endl;
    cout<<"Units:       "<<units<<endl;
    cout<<"Price:       "<<price<<endl<<endl;
}