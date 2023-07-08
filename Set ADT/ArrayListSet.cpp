/*
 * Name: Fuyao Zhao
 * Email: fuyaozhao1018@gmail.com
 *

 * This file provides the 
 * implementations for array list set.
 */
#include "Set.h"

/**
 * Return number of elements in ALSet
 *
 * @return number of elements in ALSet
 */
unsigned int ArrayListSet::size() {
    //get and store the size
    int sArrayList = arr.size();
    return sArrayList;
}

/**
 * Insert s into this Set. If the element is 
 * already in this Set, do not
 * make any changes to this Set.
 *
 * @param s string to be inserted into ALset
 */
void ArrayListSet::insert(string s){
    //when the element is in the set 
    if(contains(s)==true){
        return;}
    // when the element is not in the set
    else{
        //insert the element
        arr.push_back(s);
    }
}

/**
 * Remove s from this Set. If the element does 
 * not exist in this Set, do
 * not make any changes to array list Set.
 *
 * @param s string to be removed from ALset
 */
void ArrayListSet::erase(const string & s) {
    //when the element is not in the set 
    if(contains(s)==false){
        return;}
    //when the element is in the set 
    else{
        //iterate through the set 
        for (auto it = arr.begin(); it != arr.end();){
            //when finding the element 
            if (*it == s) {
                //delete the element 
                it = arr.erase(it);
            }
            //when not finding the element 
            else {
                //go next 
                ++it;
            }
        }
    }
}
/**
 * Check to see if a string exists in Array list  
 * set or not.
 *
 * @param s string to look for in ALset
 * @return true if s exists in ALSet, 
 *         otherwise false
 */
bool ArrayListSet::contains(const string & s){
    //iterate through the set 
    for (auto i= arr.begin(); i!= arr.end(); ++i){
        //when found the element
        if(s==*i){
            return true;}
    }
    //when not found
    return false;
}