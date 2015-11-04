/* 
 * File:   Budget.h
 * Author: Victor Alcaraz
 * Created on November 4, 2015, 2:51 PM
 * Purpose: classification of budget class
 */

#ifndef BUDGET_H
#define	BUDGET_H

class Budget {
private:
    static float corpBudget;   //static member variable
    float divisionBudget;       //instance member variable
public:
    Budget(){divisionBudget=0;}
    void addBudget(float b){divisionBudget+=b;corpBudget+=b;}
    float getDivisionBudget() const{return divisionBudget;}
    float getCorpBudget() const{return corpBudget;}
    static void mainOffice(float);  //static member function
};

#endif	/* BUDGET_H */

