#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Player
    {   
        public:
            string name;

        public:
            Player(string name1) { this->name = name1;};
            Player(){};

        int stacksize();
        int cardesTaken();
    };
}



