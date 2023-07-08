/*
 * Name: Fuyao Zhao
 * Email: fuyaozhao1018@gmail.com
 *
 * This file provides the 
 * implementations for red black tree.
 */
#include "Set.h"

/**
 * Return number of elements in RBTSet
 *
 * @return number of elements in RBTSet
 */
unsigned int RedBlackTreeSet::size() {
    //get and store the size
    int sRBT = rbt.size();
    return sRBT;
}

/**
 * Insert s into this Set. If the element is 
 * already in this Set, do not
 * make any changes to red black tree Set.
 *
 * @param s string to be inserted into RBTset
 */
void RedBlackTreeSet::insert(string s) {
    //when the element is in the set
    if(contains(s)==true){
        return;
    }
    //when the element is not in the set
    else{
        //insert it in 
        rbt.insert(s);}
}

/**
 * Remove s from this Set. If the element does 
 * not exist in this Set, do not 
 * make any changes to Red and black tree Set.
 *
 * @param s string to be removed from RBTset
 */
void RedBlackTreeSet::erase(const string & s) {
    //when the element is in the set
    if(contains(s)==true){
        //delete the element
        rbt.erase(s);}
    //when the element is not in the set
    else{
        return;}}

/**
 * Check to see if a string exists in Red black  
 * tree set or not.
 *
 * @param s string to look for in RBTset
 * @return true if s exists in RBTSet, 
 *         otherwise false
 */
bool RedBlackTreeSet::contains(const string & s) {
    //when the element is in the set
    if(rbt.count(s)){
        return true;}
    //when the element is not in the set
    else{
        return false;}
}