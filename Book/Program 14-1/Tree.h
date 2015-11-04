/* 
 * File:   Tree.h
 * Author: Victor Alcaraz
 * Created on November 4, 2015, 1:58 PM
 * Purpose: class Tree
 */

#ifndef TREE_H
#define	TREE_H

class Tree {
private:
    static int objectCount;   //static member variable
public:
    Tree(){objectCount++;}    //Constructor
    int getObjectCount() const{return objectCount;}  //Accessor
};

//definition of the static member variable, written outside the class.
int Tree::objectCount=0;

#endif	/* TREE_H */

