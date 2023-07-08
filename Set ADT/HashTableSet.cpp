/*
 * Name: Fuyao Zhao
 * Email: fuyaozhao1018@gmail.com
 *
 * This file provides the 
 * implementations for hash table set.
 */
#include "Set.h"

/**
 * Return number of elements in HTset
 *
 * @return number of elements in HTset
 */
unsigned int HashTableSet::size() {
    //get and store the size
    int sHash = ht.size();
    return sHash;
}
/**
 * Insert s into this Set. If the element is 
 * already in this Set, do not
 * make any changes to Hash table Set.
 *
 * @param s string to be inserted into HTset
 */
void HashTableSet::insert(string s) {
    //when the element is in the set 
    if(contains(s)==true){
        return;
    }
    //when the element is not in the set 
    else{
        //insert the element
        ht.insert(s);}
}

/**
 * Remove s from this Set. If the element does 
 * not exist in this Set, do
 * not make any changes to Hash table Set.
 *
 * @param s string to be removed from HTset
 */
void HashTableSet::erase(const string & s) {
    //when the element is in the set 
    if(contains(s)==true){
        //delete the element 
        ht.erase(s);}
    //when the element is not in the set 
    else{
        return;}
}

/**
 * Check to see if a string exists in Hash table  
 * set or not.
 *
 * @param s string to look for in HTset
 * @return true if s exists in HTSet, 
 *         otherwise false
 */
bool HashTableSet::contains(const string & s) {
    //when found the element 
    if (ht.find(s) != ht.end()) {
        return true;
    }
    //when not found the element
    else {
        return false;
    }
}