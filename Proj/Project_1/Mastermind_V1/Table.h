/* 
 * File:   Table.h
 * Author: Victor Alcaraz
 * Created on December 2, 2015, 2:44 PM
 * Purpose: Implementation of Table Class
 */

#ifndef TABLE_H
#define	TABLE_H

#include <bits/stdc++.h>
using namespace std;

class Table {
protected:
    int holes;
    int tries;
    void setHles(int);
    void setTrys(int);
public:
    Table();
    Table(int,int);
    void print();
};

#endif	/* TABLE_H */

