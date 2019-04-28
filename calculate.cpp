#include <string>
#include "calculate.hpp"
using namespace bullpgia;

string calculateBullAndPgia(string a,string b){
  string ans="";
  int bul=0;
  int pgia=0;
  for(int i=0;i<a.length();i++){
      for(int j=0;j<a.length();i++){
          if(a[i]==b[j]&&i!=j)pgia++; 
          if(a[i]==b[j]&&i==j)bul++;
      }
   
}
ans=bul+","+pgia;
return ans;
}
