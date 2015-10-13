/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on October 13, 2015, 1:36 PM
 */

#include <iostream>

using namespace std;

#include "Property.h"
/*
 * 
 */
int main(int argc, char** argv) {

    Property boardS[40];
    string board[40]={"Go","Mediteranian Ave","Community Chest","Baltic Ave","Income Tax",
                      "Reading RailRoad","Oriental Ave","Chance","Vermont Ave","Connecticut Ave",
                      "Jail","St. Charles Place","Electric Company","States Ave","Virginia Ave",
                      "Pennsyvania Railroad","St. James Place","Community Chest","Tennessee Ave",
                      "New York Ave","Free Parking","Kentucky Ave","Chance","Indiana Ave",
                      "Illinois Ave","B & O Railroad","Atlantic Ave","Ventnor Ave","Water Works",
                      "Marvin Gardens","Go to Jail","Pacific Ave","North Carolina","Community Chest",
                      "Pennsylvania Ave","Short Line Railroad","Chance","Park Place","Luxury Tax",
                      "Boardwalk"};
//    int value[40]={200,60,0,60}
    
    for(int i=0;i<40;i++){
        boardS[i].setName(board[i]);
//        boardS[i].setCost(value[i]);
    }
    
    for(int i=0;i<40;i++){
        cout<<boardS[i].getName<<endl;
    }
    return 0;
}

