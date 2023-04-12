#pragma once

#include "player.hpp"
#include <string>

namespace ariel {
    class Game {
        private:
        Player player1;
        Player player2;
        vector<string> gameLog;
        int p1Won, p2Won, drawTimes, numOfTurnsPlayed;
        
        public:
             Game(Player &p1, Player &p2);


            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            void CardsToPlayers(card, Player, Player, int);

    };
}