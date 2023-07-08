/*
 * Name: Fuyao Zhao
 * Email: fuyaozhao1018@umail.com

 * This file provides the main function
 * to compress a file
 */

#include <fstream>  
#include <iostream>
#include "HCTree.hpp"
#include "Helper.hpp"

using namespace std;

//the number of edge of vectors
int EDGE = 256;

int main(int argc, char* argv[]){
   if(argc != 3){
    cerr << "Entered wrong argument.\n";
    return 0;
  } 
  //create the number to store ths size
  int size = 0;
  //initialize the tree
  HCTree CompTree;
  //initialize the frequency vector
  vector<int> Frequency(EDGE, 0);	
  //initialize the streams
  FancyInputStream input(argv[1]);
  FancyOutputStream output(argv[2]);
  //if the input stream is not good
  if(!input.good()) {
    //send the error message
    cout << "Failure" << endl;
    return 0;
  }
  //create a unused symbol
  unsigned char symbol = '=';
  //when the input is good
  while(input.good()) {
    //add the frequency
    Frequency[symbol]++;
    //read the symbol
    symbol = input.read<unsigned char>();
    //increase the char size
    size++;
  }
  //write the size first 
  output.write<int>(size);	
  //create the header
  for (int i = 0; i <EDGE; i++) {
    //write the header
    output.write<unsigned short>(Frequency[i]);
  }
  //build the tree
  CompTree.build(Frequency); 
  //go to the start 
  input.reset();
  //while not at the end
  while(input.good()) {
    //if input is good
    if(input.good()){
    //read the symbol
    symbol = input.read<unsigned char>();
    //encode the symbol
    CompTree.encode(symbol, output);}
  }
  //flush the stream
  output.flush();
  //exit
  return 0;
}