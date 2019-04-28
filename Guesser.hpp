
#pragma once
using namespace std;
#include <string>
namespace bullpgia{ 
class Guesser{
  public:
  uint length;
public:
virtual string guess()=0;
 void startNewGame(uint);
 void learn(string);
};
}
