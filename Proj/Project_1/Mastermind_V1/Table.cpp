/* 
 * File:   Table.cpp
 * Author: Victor Alcaraz
 * Created on December 2, 2015, 2:44 PM
 * Purpose: Implementation of Table Class
 */

#include "Table.h"

Table::Table(){
    holes=0;
    tries=0;
}
Table::Table(int h,int t){
    setHles(h);
    setTrys(t);
}
void Table::setHles(int h){
    holes=h;
}
void Table::setTrys(int t){
    tries=t;
}
void Table::print(){
    //2D Array board
    for(int i=0;i<tries;i++){
        for(int j=0;j<holes;j++){
            board[i][j]=145;
        }
    }
}