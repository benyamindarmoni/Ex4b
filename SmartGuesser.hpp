#pragma once

#include "Guesser.hpp"
#include <iostream>
#include "calculate.hpp"
using namespace std;
namespace bullpgia{

    class SmartGuesser : public bullpgia:: Guesser{
    public:
        string curr_guess;
        bool*  arr;
        uint array_len;
        ~SmartGuesser() {
         delete [] arr;
        }

        
        string guess() override;
        void startNewGame(uint)override ;
         void learn(string) override;
    };

}
