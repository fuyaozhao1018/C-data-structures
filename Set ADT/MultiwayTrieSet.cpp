/*
 * Name: Fuyao Zhao
 * Email:fuyaozhao1018@gmail.com
 *
 * This file provides the 
 * implementations for multiway trie set.
 */

#include "Set.h"

/**
 * MultiwayTrieSet Constructor, which should 
 * initialize an empty MWT
 */
MultiwayTrieSet::MultiwayTrieSet() {
    //initialize root and numElement
    root = new Node();
    numElements = 0;
}

/**
 * MultiwayTrieSet Destructor, which should
 * deallocate anything dynamic
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    //set numElement to zero
    numElements = 0;
    //when the trie set is not empty
    if(root!=nullptr){
    //call clear to deallocate
    clear(root);}
}

/**
 * Helper method for MultiwayTrieSet 
 * Destructor, which should delete the 
 * whole MWT set and deallocate anything
 * dynamic
 *
 * @param nodeR the node to start with 
 */
void MultiwayTrieSet::clear(Node* nodeR) {
    //if the trie set is already empty
	if (nodeR==nullptr){
        return;}
    //iterate through the set 
	for (auto itrator = nodeR->children.begin(); 
            itrator!=nodeR->children.end();
                                 itrator++){
		clear(itrator->second);
	}
    //deallocate all elements
	delete nodeR;
	nodeR = nullptr;
}

/**
 * Return number of elements in MTWSet
 *
 * @return number of elements in MTWSet
 */
unsigned int MultiwayTrieSet::size() {
    //return the number of elements
    return numElements;
}

/**
 * Insert s into this Set. If the element is 
 * already in this Set, do not
 * make any changes to multiway trie Set.
 *
 * @param s string to be inserted into MWTset
 */
void MultiwayTrieSet::insert(string s) {

    //if the element is already in the set 
    if(contains(s)==true){return;}
    //create a temp node to iterate with 
    Node* temp = root;
    //store the length of the given string 
    int len = s.length();
    //iterate through the set 
	for (int i=0; i<len; i++) {
        if (!temp->children[s[i]]) {
            // create a new node 
            temp->children[s[i]] = new Node();
        }
        // go to the children trie
        temp = temp->children[s[i]];
    }
    // set the current node as a word
    temp->isWord = true;
    //increase numElements by one
    numElements++;
}

/**
 * Remove s from this Set. If the element does 
 * not exist in this Set, do
 * not make any changes to Multiway trie Set.
 *
 * @param s string to be removed from MWTset
 */
void MultiwayTrieSet::erase(const string & s) {
    //when the element is in the set
    if(contains(s)==true){
        //call Helper method to delete the element
        deleteS(root, s, 0);}
    //when the element is not in the set
    else{
        return;}
}

/**
 * Recursively locate the elemet to remove 
 * and Remove s from this Set 
 *
 * @param Ndelete node to iterate with 
 * @param s string to be removed from MWTset
 * @param height the current level of trie 
 */
bool MultiwayTrieSet::deleteS(Node* Ndelete, 
                const string& s,int height) {
    //when the current node is null
	if( Ndelete == nullptr ){
        return false;}
    //when the current height is equal 
    // to the string length
	if( (int)s.length()==height ){
        //when the current node is not word
		if(Ndelete->isWord==false){
            //located but not a word
            return false;}
        //delete the node
		Ndelete->isWord = false;
        //check is the current node has children
		return Ndelete->children.empty();
	}
    //check whether it is ok to delete the node
	bool De = deleteS(Ndelete->children[s[height]],
                                     s, height+1);
    //when it is ok to delete 
	if (De) {
        //delete the node 
		delete Ndelete->children[s[height]];
        //decreaset the numElements
        numElements--;
        //set it to nullptr
		Ndelete->children[s[height]] = nullptr;
        //check if has children and not word
		return Ndelete->children.empty() && 
                        !Ndelete->isWord;
	}
    //deletion failed
    return false;
}

/**
 * Check to see if a string exists in Multiway  
 * trie set or not.
 *
 * @param s string to look for in MWTset
 * @return true if s exists in MWTSet, 
 *         otherwise false
 */
bool MultiwayTrieSet::contains(const string & s){
    //create a node to iterate with 
    Node* containTrie = root;
    //when root is null 
	if (containTrie == nullptr){
         return false;}
    //store the length of the string 
    int len = s.length();
    //iterate through the trie
	for (int i=0; i<len; i++) {
        //when has no children 
		if (!containTrie->children[s[i]]) {
			return false;
		}
        //go next 
		containTrie = containTrie->children[s[i]];
	}
    //check if flond element is word
	return containTrie->isWord;
}