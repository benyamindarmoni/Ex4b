#include <string>
#include "calculate.hpp"
#include <iostream>

using namespace std;


 string bullpgia::  calculateBullAndPgia( string a, string b){
  int bul=0;
  int pgia=0;
  for(int i=0;i<a.length();i++){
     
          if(a[i]==b[i]){
              bul++;
              b[i]=a[i]='x';
      }
   
}
if(bul!=a.length()){
  for(int i=0;i<a.length();i++){
      for(int j=0;j<a.length();j++){
          if(a[i]!='x'&&a[i]==b[j]){
              pgia++; 
         b[j]='x';
         continue;
      }
}
}
}
string ans=to_string(bul);
   ans+=",";
   ans+=to_string(pgia);
return ans;
     
 }
