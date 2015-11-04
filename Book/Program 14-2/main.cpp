/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on November 4, 2015, 2:10 PM
 * Purpose: book Program 14-2
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "Budget.h"

int main(int argc, char** argv) {
    int count;                 //loop counter
    const int NDIVISI=4;       //number of divisions
    Budget divisions[NDIVISI]; //array of Budget objects
    float budgetAmount;
    
    //get the budget requests for each division.
    for(count=0;count<NDIVISI;count++){
        budgetAmount=0;
        cout<<"Enter the budget request for division "<<(count+1)<<": ";
        cin>>budgetAmount;
        cin.ignore();
        divisions[count].addBudget(budgetAmount);
    }
    
    //display the budget requests and the corporate budget.
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<endl<<"Here are the division budget requests:"<<endl;
    for(count=0;count<NDIVISI;count++){
        cout<<"\tDivision "<<(count+1)<<"\t$ ";
        cout<<divisions[count].getDivisionBudget()<<endl;
    }
    
    cout<<"\tTotal Budget Requests:\t$ ";
    cout<<divisions[0].getCorpBudget()<<endl;
    return 0;
}