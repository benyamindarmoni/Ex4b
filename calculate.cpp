#include <string>
#include "calculate.hpp"
#include <iostream>
//using namespace bullpgia;
using namespace std;

string calculateBullAndPgia(string a,string b){

  int bul=0;
  int pgia=0;
  for(int i=0;i<a.length();i++){
      for(int j=0;j<a.length();j++){
          if(a[i]==b[j]&&i!=j)pgia++; 
          if(a[i]==b[j]&&i==j)bul++;
      }
   
}
string ans=to_string(bul);
   ans+=",";
   ans+=to_string(pgia);
return ans;
}
