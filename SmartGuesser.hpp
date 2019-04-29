#pragma once
#include "calculate.hpp"
#include "Guesser.hpp"
#include <iostream>

using namespace std;
namespace bullpgia{

    class SmartGuesser : public bullpgia:: Guesser{
    public:
        string number;
        uint len;
        
        string guess() override;
        void startNewGame(uint)override ;
         void learn(string) override;
    };

}
