    
#pragma once
using namespace std;
#include <string>

class Chooser{
string number;
public:
Chooser(string s){
number=s;
}
virtual std::string choose(uint length)=0;



}
