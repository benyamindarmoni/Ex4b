#include "SmartGuesser.hpp"
#include <stdlib.h>
#include <string>
#include "calculate.hpp"
#include <cmath>
using namespace std;
namespace bullpgia{
 
 void SmartGuesser::startNewGame(uint a) {
  number_len=a;
  array_len=pow(10, a);
     arr=new bool[array_len];
     for(int i=0;i<array_len;i++){
      arr[i]=true;
     }
  
 }
 string SmartGuesser::guess() {
   for(int i=0;i<array_len;i++){
    if(arr[i]==true){
     curr_guess=to_string(i);
    break;
   }
   }
   while(curr_guess.length()<number_len){
    curr_guess="0"+curr_guess;
   }
     return curr_guess;
 }

 void SmartGuesser::learn(string a) {
  string index="";
     for(int i=0;i<array_len;i++){
      if(arr[i]==false)continue;
      index=to_string(i);
      while(index.length()<number_len){
    index="0"+index;
   }
      if(calculateBullAndPgia(index,curr_guess).compare(a)!=0){
       arr[i]=false;
      
     }
}

}}
