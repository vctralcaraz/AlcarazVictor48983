/* 
 * File:   Inventory.cpp
 * Author: Victor Alcaraz
 * Created on October 14, 2015, 2:18 PM
 */

#include <iostream>
#include <iomanip>
#include "Inventory.h"
using namespace std;

Inventory::Inventory(int i,int q,float c){
    setNumb(i);
    setQuan(q);
    setCost(c);
    setTCst();
}
void Inventory::setNumb(int i){
    while(i<1){
        cout<<"Invalid Item Number. Please Re-enter: ";
        cin>>i;
    }
    iNumber=i;
}
void Inventory::setQuan(int q){
    while(q<1){
        cout<<"Invalid Quantity. Please Re-enter: ";
        cin>>q;
    }
    quantty=q;
}
void Inventory::setCost(float c){
    while(c<1){
        cout<<"Invalid cost. Please Re-enter: ";
        cin>>c;
    }
    cost=c;
}
void Inventory::setTCst(){
    tCost=quantty*cost;
}
void Inventory::print(){
    cout<<fixed<<setprecision(2);
    cout<<endl<<"Here is your item information"<<endl;
    cout<<"Item Number: "<<iNumber<<endl;
    cout<<"Quantity:    "<<quantty<<endl;
    cout<<"Cost:       $"<<cost<<endl;
    cout<<"Total Cost: $"<<tCost<<endl;
}