/* 
 * File:   Budget.h
 * Author: Victor Alcaraz
 * Created on November 4, 2015, 2:11 PM
 * Purpose: classification of Budget
 */

#ifndef BUDGET_H
#define	BUDGET_H

class Budget{
private:
    static float corpBudget;   //static member
    float divisionBudget;      //instance member
public:
    Budget(){divisionBudget=0;}                  //constructor
    void addBudget(float b){divisionBudget+=b; corpBudget+=b;}
    float getDivisionBudget() const{return divisionBudget;}
    float getCorpBudget() const{return corpBudget;}
};

float Budget::corpBudget=0;
#endif	/* BUDGET_H */

