/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on November 4, 2015, 2:50 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "Budget.h"

int main(int argc, char** argv) {
    int count;                     //loop counter
    float mainOfficeRequest;       //main office budget request
    const int NDIVISI=4;           //number of divisions
    float budgetAmount;
    
    //get the main office's budget request.
    //note that no instances of the Budget class have been defined.
    cout<<"Enter the main office's budget request: ";
    cin>>mainOfficeRequest;
    cin.ignore();
    Budget::mainOffice(mainOfficeRequest);
    
    Budget divisions[NDIVISI]; //an array of Budget objects
    
    //get the budget requests for each division.
    for(count=0;count<NDIVISI;count++){
        budgetAmount=0;
        cout<<"Enter the budget request for division "<<(count+1)<<": ";
        cin>>budgetAmount;
        cin.ignore();
        divisions[count].addBudget(budgetAmount);
    }
    
    //display the budget request and the corporate budget.
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<endl<<"Here are the division budget requests:"<<endl;
    for(count=0;count<NDIVISI;count++){
        cout<<"\tDivision "<<(count+1)<<"\t$"<<divisions[count].getDivisionBudget()<<endl;
    }
    
    cout<<"\tTotal Budget Requests:\t$"<<divisions[0].getCorpBudget()<<endl;
    return 0;
}

