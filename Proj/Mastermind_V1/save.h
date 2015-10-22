/* 
 * File:   save.h
 * Author: Victor Alcaraz
 * Created on October 20, 2015, 7:42 PM
 * Purpose: user game data
 */

#ifndef SAVE_H
#define	SAVE_H

struct Save{
    int games;     //number of games
    int wins;      //number of wins
    int loses;     //number of loses
    float average; //win percentage
    int lTries;    //least amount of tries in a win
};

#endif	/* SAVE_H */