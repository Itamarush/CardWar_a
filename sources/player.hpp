#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {   
        public:
            string name;
            vector<card> cardPack;
            vector<card> cardPackWon;
            int numOfTimeWon;
            bool isActive;


        public:
            Player(string name1) { this->name = name1;};
            Player(){};

            string getName()
            {
                return this->name;
            }

        int stacksize();
        int cardesTaken();
        bool isPlaying();
        void joinedGame();
        void finishedGame();
        void setCardsTaken(int);
        card pullCard();
        void addCard(const std::vector<card>&);
    };
}



