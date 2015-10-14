/* 
 * File:   Inventory.h
 * Author: Victor Alcaraz
 * Created on October 14, 2015, 2:18 PM
 */

#ifndef INVENTORY_H
#define	INVENTORY_H

using namespace std;

class Inventory {
private:
    int iNumber;
    int quantty;
    float cost;
    float tCost;
public:
    Inventory();
    Inventory(int,int,float);
    void setNumb(int);
    void setQuan(int);
    void setCost(float);
    void setTCst();
    void print();
};

#endif	/* INVENTORY_H */

