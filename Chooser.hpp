    
#pragma once
using namespace std;
#include <string>
namespace bullpgia{
class Chooser{
string number;
    public:
    Chooser(string);
virtual std::string choose(uint length)=0;



};
}
