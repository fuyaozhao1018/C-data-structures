/*
 * Name: Fuyao Zhao
 * Email: fuyaozhao1018@gmail.com
 *
 * This file provides the 
 * implementations for linked list set.
 */
#include "Set.h"

/**
 * Return number of elements in LLset
 *
 * @return number of elements in LLset
 */
unsigned int LinkedListSet::size() {
    //get and store the size
    int sLinked = linked.size();
    return sLinked;
}

/**
 * Insert s into this Set. If the element is 
 * already in this Set, do not
 * make any changes to linked list Set.
 *
 * @param s string to be inserted into LLset
 */
void LinkedListSet::insert(string s) {
    // when the element is in the set 
    if(contains(s)==true){
        return;}
    // when the element is not in the set 
    else{
        //insert the element 
        linked.push_back(s);
    }
}

/**
 * Remove s from this Set. If the element does 
 * not exist in this Set, do
 * not make any changes to Linked list Set.
 *
 * @param s string to be removed from LLset
 */
void LinkedListSet::erase(const string & s) {
    // when the element is not in the set 
    if(contains(s)==false){
        return;}
    // when the element is in the set 
    else{
        //delete the element 
        linked.remove(s);
    }
}

/**
 * Check to see if a string exists in Linked list  
 * set or not.
 *
 * @param s string to look for in LLset
 * @return true if s exists in LLSet, 
 *         otherwise false
 */
bool LinkedListSet::contains(const string & s) {
    //iterate through the set 
    for (auto i= linked.begin(); i!= linked.end(); ++i){
        //when found the element 
        if(s == *i ){
            return true;}
    }
    //when not found the element 
    return false;
}