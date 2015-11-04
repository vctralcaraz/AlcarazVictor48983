/* 
 * File:   Budget.cpp
 * Author: Victor Alcaraz
 * Created on November 4, 2015, 2:51 PM
 * Purpose: specifications for budget class
 */

#include "Budget.h"

//definition of corpBudget static member variable
float Budget::corpBudget=0;

//*********************************************************
// definition of static member function mainOffice.       *
// this function adds the main office's budget request to *
// the corpBudget variable.                               *
//*********************************************************

void Budget::mainOffice(float moffice){
    corpBudget+=moffice;
}