/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on October 1, 2015, 11:14 AM
 * Purpose: Chapter 11 Notes & self contained array
 */

//pass all structs by reference
    //can return a structure from a function
    
    /*Unions:
     * 
     * Similar to a struct, but
     *  -all members share a single memory location, and
     *  -only one member of the union can be used at a time
     * Declared using union, otherwise the same as struct
     * Variables defined as for struct variables
     * 
     * A union without a union tag:
     *      union {...};
     * Must use static if declared outside of a function
     * Allocates memory at declaration time
     * Can refer to members directly without dot operator
     * Uses only one memory location, saves space
     * 
     * 
     * Enumerated Data Types:
     * 
     * An enumerated data type is a programmer-defined data type. It
     * consists of values known as enumerators, which represents
     * integer constants.
     * (so you don't have to utilize flags)
     * 
     * Example:
     * (cap the first letter)
     *  enum Day {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};
     * The identifiers MONDAY, TUESDAY, WEDNESDAY, THURSDAY, and FRIDAY,
     * which are listed inside the braces, are enumerators. They represent the 
     * values that belong to the Day data type.
     * 
     * Note that the enumerators are not strings, so they aren't
     * enclosed in quotes. They are identifiers.
     * 
     * Once you have created an enumerated data type in your program, you can define
     * variables of that type. Example:
     *  Day workDay;
     * This statement defines workDay as a variable of the Day type.
     * 
     * We may assign any of the enumerators MONDAY, TUESDAY, WEDNESDAY, THURSDAY, or
     * FRIDAY to a variable of the Day type. Example:
     *  workDay=WEDNESDAY;
     * 
     * So, what is an enumerator?
     * Think of it as an integer named constants
     * Internally, the compiler assigns integer values
     * to the enumerators, beginning at 0.
     * 
     * in memory...
     * 
     * MONDAY=0
     * TUESDAY=1
     * WEDNESDAY=2
     * THURSDAY=3
     * FRIDAY=4
     * 
     * cout<<MONDAY<<endl;
     * output: 0
     * 
     * You cannot directly assign an integer value to an
     * enum variable. This will not work:
     *  workDay=3; //Error!
     * Instead, you must cast the integer:
     *  workDay=static_cast<Day>(3);
     * 
     */

//system libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//user libraries
#include "ARRAY.h"

//global constants

//function prototypes
Array *filAry(int);
void   prntAry(Array *,int);

//execution begins here
int main(int argc, char** argv) {
    //set random number seed and size of array
    srand(static_cast<unsigned int>(time(0)));
    int size=100;
    int perLine=10;
    
    //declare and size ADT
    Array *array=filAry(size);
    
    //print results
    prntAry(array,perLine);
    
    //deallocate memory
    delete []array->data;
    delete array;
    
    //exit stage right        
    return 0;
}

void   prntAry(Array *a,int perLine){
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<' ';
        if(i%perLine==(perLine-1)) cout<<endl;
    }
}

Array *filAry(int n){
    //check n
    if(n<=1) n=2;
    
    //allocate memory
    Array *a=new Array;
    //a->size=n;
    (*a).size=n;
    a->data=new int[a->size];
    
    //loop and fill with random numbers
    for(int i=0;i<a->size;i++){
//        a->data[i]=rand()%90+10;
        (*a).data[i]=rand()%90+10; //?convert array to pointer notation
        
    }
    
    //exit
    return a;
}