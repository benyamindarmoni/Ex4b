
#pragma once
using namespace std;
#include <string>

class Guesser{
string number;
public:
virtual std::string choose(uint length)=0;
}
