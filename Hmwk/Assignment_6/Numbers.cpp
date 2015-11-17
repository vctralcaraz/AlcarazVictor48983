/* 
 * File:   Numbers.cpp
 * Author: Victor Alcaraz
 * Created on November 6, 2015, 1:57 PM
 * Purpose: Implementation of Numbers class
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "Numbers.h"
using namespace std;

Numbers::Numbers(string n){
    setNum(n);
}
void Numbers::setNum(string n){
    bool valid;
    do{
        valid=true;
        if(n.length()>4){
            valid=false;
            cout<<"You can't have a number greater than 9,999"<<endl;
        }
        for(int i=0;i<n.length();i++){
            if(!isdigit(n[i])){
                valid=false;
                cout<<"at least one of your digits is not a number"<<endl;
                break;
            }
        }
        if(!valid){
            cout<<"Please re-enter your number: ";
            cin>>n;
            cin.ignore();
        }
        
    }while(!valid);
    numbers=atoi(n.c_str());
    ones=numbers%10;
    tens=(numbers%100)/10;
    hundrds=(numbers%1000)/100;
    thsnds=numbers/1000;
}
void Numbers::print(){
    string one,ten,hund,thou;
    cout<<"ones = "<<ones<<endl;
    cout<<"tens = "<<tens*10<<endl;
    cout<<"hundreds = "<<hundrds*100<<endl;
    cout<<"thousands = "<<thsnds*1000<<endl;
    
    switch(thsnds){
        case 1:{
            thou="One-Thousand";
            break;
        }
        case 2:{
            thou="Two-Thousand";
            break;
        }
        case 3:{
            thou="Three-Thousand";
            break;
        }
        case 4:{
            thou="Four-Thousand";
            break;
        }
        case 5:{
            thou="Five-Thousand";
            break;
        }
        case 6:{
            thou="Six-Thousand";
            break;
        }
        case 7:{
            thou="Seven-Thousand";
            break;
        }
        case 8:{
            thou="Eight-Thousand";
            break;
        }
        case 9:{
            thou="Nine-Thousand";
            break;
        }
    }
    switch(hundrds){
        case 1:{
            hund="One-Hundred";
            break;
        }
        case 2:{
            hund="Two-Hundred";
            break;
        }
        case 3:{
            hund="Three-Hundred";
            break;
        }
        case 4:{
            hund="Four-Hundred";
            break;
        }
        case 5:{
            hund="Five-Hundred";
            break;
        }
        case 6:{
            hund="Six-Hundred";
            break;
        }
        case 7:{
            hund="Seven-Hundred";
            break;
        }
        case 8:{
            hund="Eight-Hundred";
            break;
        }
        case 9:{
            hund="Nine-Hundred";
            break;
        }
    }
    switch(tens){
        case 0:{
            ten="";
            break;
        }
        case 1:{
            ten="Ten";
            break;
        }
        case 2:{
            ten="Twenty";
            break;
        }
        case 3:{
            ten="Thirty";
            break;
        }
        case 4:{
            ten="Forty";
            break;
        }
        case 5:{
            ten="Fifty";
            break;
        }
        case 6:{
            ten="Sixty";
            break;
        }
        case 7:{
            ten="Seventy";
            break;
        }
        case 8:{
            ten="Eighty";
            break;
        }
        case 9:{
            ten="Ninety";
            break;
        }
    }
    switch(ones){
        case 0:{
            one="";
            break;
        }
        case 1:{
            one="One";
            break;
        }
        case 2:{
            one="Two";
            break;
        }
        case 3:{
            one="Three";
            break;
        }
        case 4:{
            one="Four";
            break;
        }
        case 5:{
            one="Five";
            break;
        }
        case 6:{
            one="Six";
            break;
        }
        case 7:{
            one="Seven";
            break;
        }
        case 8:{
            one="Eight";
            break;
        }
        case 9:{
            one="Nine";
            break;
        }
    }
    if(ten=="Ten" && one!="Zero"){
        switch(ones){
            case 1:{
                ten="Eleven";
                one="";
                break;
            }
            case 2:{
                ten="Twelve";
                one="";
                break;
            }
            case 3:{
                ten="Thirteen";
                one="";
                break;
            }
            case 4:{
                ten="Fourteen";
                one="";
                break;
            }
            case 5:{
                ten="Fifteen";
                one="";
                break;
            }
            case 6:{
                ten="Sixteen";
                one="";
                break;
            }
            case 7:{
                ten="Seventeen";
                one="";
                break;
            }
            case 8:{
                ten="Eighteen";
                one="";
                break;
            }
            case 9:{
                ten="Nineteen";
                one="";
                break;
            }
        }
    }
    
    cout<<numbers<<" = ";
    if(thou!="") cout<<thou<<' ';
    if(hund!="") cout<<hund<<' ';
    if(ten!="") cout<<ten<<' ';
    if(one!="") cout<<one<<' ';
    cout<<endl;
}