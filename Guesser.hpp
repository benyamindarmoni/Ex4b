
#pragma once
using namespace std;
#include <string>
namespace bullpgia{ 
class Guesser{
string number;
  
public:
  Guesser(string s);
virtual std::string Guesser(uint length)=0;
};
}
