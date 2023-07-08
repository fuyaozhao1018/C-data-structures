/*
 * Name: Fuyao Zhao
 * Email: fuyaozhao1018@umail.com
 *
 * This file provides the main function
 * to decompress a file
 */

#include <fstream>   
#include <iostream>
#include "HCTree.hpp"
#include "Helper.hpp"

using namespace std;
//the number of edge of vectors
int EDGE = 256;

int main(int argc,  char* argv[]){
  //check wether the number of argument 
  //is correct
  if(argc != 3){
    cerr << "Entered wrong argument.\n";
    return 0;
  }
  //initialize the tree
  HCTree Tree;		
  //initialize the streams
  FancyInputStream input(argv[1]);
  FancyOutputStream output(argv[2]);
  //read the size integer
  int size = input.read<int>();	
  //if the imput is not good
  if(!input.good()){
      //send the error message
      cout << "Failure" << endl;
      return 0;
  }  
  //create a frequency vector
  vector<int> chars_freq(EDGE, 0);
  //create the header
  for(int i = 0; i < EDGE; i++) {
    chars_freq[i] = input.read<unsigned short>();
  }
  //build the tree
  Tree.build(chars_freq);
  //create the integer to iterate with
  int x=1;
  //while the iteration is with in the size
  //so no garrbage bits
  while( x<size ){
    //write the decoded bits
    output.write(Tree.decode(input));
    //increase x
    x++;
  }
  //exit
  return 0;
}