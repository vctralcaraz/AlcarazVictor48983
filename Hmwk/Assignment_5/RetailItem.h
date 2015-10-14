/* 
 * File:   RetailItem.h
 * Author: Victor Alcaraz
 * Created on October 14, 2015, 1:20 PM
 */

#ifndef RETAILITEM_H
#define	RETAILITEM_H

using namespace std;

class RetailItem {
    private:
        string descrbe;
        int units;
        float price;
        void setDesc(string);
        void setUnit(int);
        void setPrce(float);
    public:
        RetailItem(string,int,float);
        void print();
};

#endif	/* RETAILITEM_H */

