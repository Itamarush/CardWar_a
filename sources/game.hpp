#pragma once

#include "player.hpp"
#include <string>

namespace ariel {
    class Game {
        private:
        Player player1;
        Player player2;

        public:
            Game(Player player1, Player player2){this->player1 = player1; this->player2 = player2;}
            Game(){}

            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
    };
}