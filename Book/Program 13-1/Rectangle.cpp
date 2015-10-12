/* 
 * File:   Rectangle.cpp
 * Author: Victor Alcaraz
 * Created on October 12, 2015, 2:00 PM
 * Purpose: class functions
 */

#include "Rectangle.h"

/***************************************************
 * setWidth assigns a value to the width member.   *
 ***************************************************/
void Rectangle::setWidth(int w){
    width=w;
}

/***************************************************
 * setLength assigns a value to the width member.  *
 ***************************************************/
void Rectangle::setLength(int len){
    length=len;
}

/*****************************************************
 * getLength returns the value in the length member. *
 *****************************************************/
int Rectangle::getWidth() const{
    return width;
}

/***************************************************
 * setWidth returns a value in the width member.   *
 ***************************************************/
int Rectangle::getLength() const{
    return length;
}

/******************************************************
 * setArea returns the product of width times length. *
 ******************************************************/
int Rectangle::getArea() const{
    return width*length;
}