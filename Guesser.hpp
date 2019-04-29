
#pragma once
using namespace std;
#include <string>
namespace bullpgia{ 
class Guesser{
  public:
  uint length;
public:
virtual ~Guesser() {}

virtual string guess()=0;
 virtual void startNewGame(uint){};
 virtual void learn(string){};
 
};
}
