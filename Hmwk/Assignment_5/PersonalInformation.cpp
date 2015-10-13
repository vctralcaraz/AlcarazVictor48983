/* 
 * File:   PersonalInformation.cpp
 * Author: Victor Alcaraz
 * Created on October 13, 2015, 9:38 AM
 */

#include <bits/stdc++.h>
using namespace std;

#include "PersonalInformation.h"

void PersonalInformation::setName(string n) {
    name=n;
}

void PersonalInformation::setAdd(string a){
    address=a;
}

void PersonalInformation::setAge(int ag){
    while(ag<1){
        cout<<"Invalid age! Re-enter age: ";
        cin>>ag;
        cin.ignore();
    }
    age=ag;
}

void PersonalInformation::setPhne(long long p){
    while(p<1000000000 || p>9999999999){
        cout<<"Invalid phone number! Re-enter phone number: ";
        cin>>p;
        cin.ignore();
    }
    phone=p;
}

void PersonalInformation::print(){
    cout<<"Personal Data: "<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Phone: "<<phone<<endl;
}