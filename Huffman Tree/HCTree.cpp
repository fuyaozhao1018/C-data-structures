/*
 * Name: Fuyao Zhao
 * Email: fuyaozhao1018@umail.com
 *
 * This file provides a implemented skeleton 
 * for a huffman tree.
 */
#include "HCTree.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
//the edge number of vectors
int EDGETREE = 256;

/**
 * Destructor of a Huffman coding tree.
 * delete the HCTree
 */
HCTree::~HCTree(){
    clear(root);
    root = nullptr;
}

/**
 * Helper method of the destructor
 * delete the every thing in HCTree
 * @param Delete the node to start 
 *               deletation 
 */
void HCTree::clear(HCNode* Delete){
    //if the root is null 
    if(Delete == nullptr) {
        //the deletation is completed
        return;
    }
    //go left 
    if(Delete->c0){
      //recursive call
      clear(Delete->c0);
    }
    //go right 
    if(Delete->c1){
      //recursive call
      clear(Delete->c1);
    }
    //delete the root 
    delete Delete;
    //return function
    return; 
  }
  
/**
 * Use the Huffman algorithm to build a Huffman coding tree.
 * PRECONDITION:  freqs is a vector of ints, such that freqs[i] is the
 *                frequency of occurrence of byte i in the input file.
 * POSTCONDITION: root points to the root of the trie, and leaves[i]
 *                points to the leaf node containing byte i.
 *
 * @param freqs frequency vector
 */
void HCTree::build(const vector<int>& freqs){
    //nodes to store the value
    HCNode* right;
    HCNode* parent;
    HCNode* left; 
    //this queue is the tree structure
    priority_queue<HCNode*, vector<HCNode*> , HCNodePtrComp> HCQueue;
    //initialize the tree
    for(int i = 0; i <EDGETREE; i++){
      //when the frequency is not zero
      if(freqs[i] != 0){
        //set the leaves
	      leaves[i] = new HCNode(freqs[i], i);}
    }
    //store the leaves
    for(int j = 0; j <EDGETREE; j++){
      // if the byte occured
      if(leaves[j]){
        //push the value in 
        HCQueue.push(leaves[j]);}
    }
    //when the queue is empty
    if(HCQueue.size()==0 ){
      //set root to null
      root = nullptr;
      return;
    }
    //start to sort nodes
    if(HCQueue.size()==1){
      //set the root 
      root = HCQueue.top();
    }
    //when the root is set 
    while(HCQueue.size() > 1){
      //set left and pop the used node
      left = HCQueue.top();
      HCQueue.pop(); 
      //set right and pop the used node
      right = HCQueue.top(); 
      HCQueue.pop(); 
      //create a new combined node
      parent= new HCNode(left->count+right->count, left->symbol);
      //set the left and right of top
      parent->c1=right;
      parent->c0=left; 
      //set left and right's parent
      left->p=parent;
      right->p=parent;
      //push the finished node in     
      HCQueue.push(parent);
    }  
    //set the root to the node at the top
    root=HCQueue.top(); 
    //pop the root 
    HCQueue.pop();
}

/**
 * Write to the given FancyOutputStream the sequence of bits coding the
 * given symbol.
 * PRECONDITION: build() has been called, to create the coding tree,
 *               and initialize root pointer and leaves vector.
 *
 * @param symbol symbol to encode
 * @param out output stream for the encoded bits
 */
void HCTree::encode(unsigned char symbol, FancyOutputStream & out) const{
    //create a int vector to store symbols
    vector<int> back; 
    //store the pointer to the leaf
    HCNode* Encode = leaves[symbol]; 
    //while the node is not root and not null
    while(Encode!=root&&Encode){
      //if the parent's left child is itself
        if (Encode->p->c0==Encode){
            //push 9 at the back
            back.push_back(0);
        }
        //else when it is 1 push 1 
        else{ back.push_back(1);}
        //go to its parent
        Encode=Encode->p; 
    }
    //create the vector to sort the order
    vector<int> front; 
    //create the int to store the size 
    int size = back.size();
    //iterate through the vector
    for(int i=0; i<size; i++){
      //push the corresponding value in 
      front.push_back(back[size-i-1]);
    }    
    //write every bit 
    for(int j=0; j<size; j++){
      out.write_bit(front[j]);
    } 
}

/**
 * Return symbol coded in the next sequence of bits from the stream.
 * PRECONDITION: build() has been called, to create the coding tree, and
 *               initialize root pointer and leaves vector.
 *
 * @param in input stream to find encoded bits
 * @return a single char decoded from the input stream
 */
unsigned char HCTree::decode(FancyInputStream & in) const{
    //integer to store the bit read in 
    int bitIn; 	   
    //the node to store root 
    HCNode* Decode = root;
    //iterate through the tree
    while(Decode->c0!= nullptr){
      //read in the bit 
      bitIn=in.read_bit();  
      //if it is 0
      if(bitIn== 0){
        //go left 
        Decode=Decode->c0;}
      //if it is 1
      else if(bitIn== 1){
        //go right
        Decode=Decode->c1;}
      //else it is error
      else{
        return -1;}
    } 
    //return the symbol
    return Decode->symbol;
}

