#include "game.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
using namespace ariel;
using namespace std;

Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2)
{

    if (player1.isPlaying())
    {
        throw string("Player number 1 is already in a game!");
    }

    if (player2.isPlaying())
    {
        throw logic_error("Player number 2 is already in a game!");
    }
    
    int const sizeOfDeck = 52;
    card deck[sizeOfDeck];
    this->player1 = player1;
    this->player2 = player2;
    player1.joinedGame();
    player2.joinedGame();
    player1.setCardsTaken(0);
    player2.setCardsTaken(0);
    p1Won = p2Won = drawTimes = 0;
    createDeck(deck, sizeOfDeck);
    CardsToPlayers(deck[sizeOfDeck], player1, player2, sizeOfDeck);
}

void createDeck(card deck[], int sizeOfDeck)
{
    int i = 0;
    for (int rank = 1; rank <= 13; rank++)
    {
        for (int suit = 1; suit <= 4; suit++)
        {
            deck[i] = (card(rank, suit));
            i++;
        }
    }
    // Create a random number generator using the current time as a seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);

    // Shuffle the deck using std::shuffle()
    std::shuffle(deck, deck + sizeOfDeck, rng);
}

void CardsToPlayers(card deck[], Player p1, Player p2, int sizeOfDeck)
{
    for (size_t i = 0; i < sizeOfDeck; i++)
    {
        if (i % 2)
        {
            p1.cardPack.push_back(deck[i]);
        }
        else
        {
            p2.cardPack.push_back(deck[i]);
        }
    }
}

void Game::playAll()
{
    for (size_t i = 0; i < 26; i++)
    {
        playTurn();
    }
    
};

void Game::playTurn()
{
        // Check if both players are the same
        if (&this->player1 == &this->player2)
        {
            throw runtime_error("player one player 2 are the same person");
        }

        if (!(player1.stacksize()))
        {
        throw std::string("The game is over!");
        }

        std::string turn = "";
        std::vector<card> p1DrawCards, p2DrawCards;
        this->numOfTurnsPlayed++;
        
         // Draw cards for each player
    card p1c = player1.pullCard();
    card p2c = player2.pullCard();

    // Play the game until one player wins
    while (p1c.getNum() == p2c.getNum()) {
        // Handle a tie
        drawTimes++;
        if (player1.stacksize() < 2) {
            player1.addCard(p1DrawCards);
            player1.addCard(p2DrawCards);
            return;
        }

        // Add cards to the war pile and draw again
        p1DrawCards.push_back(p1c);
        p1DrawCards.push_back(player1.pullCard());
        p2DrawCards.push_back(p2c);
        p2DrawCards.push_back(player2.pullCard());
        turn += player1.getName() + " played " + p1c.toString() + " " + player2.getName() + " played " +
                p2c.toString() + ".";
        turn += "draw. ";
        p1c = player1.pullCard();
        p2c = player2.pullCard();
    }

    // Determine the winner of the turn
    turn += player1.getName() + " played " + p1c.toString() + " " + player2.getName() + " played " +
            p2c.toString() + ".";
    if (p1c.getNum() > p2c.getNum() || (p2c.getNum() == 1 && p1c.getNum() != 2)) {
        p1Won++;
        player1.addCard(p1DrawCards);
        player1.addCard(p2DrawCards);
        turn += " " + player1.getName() + " wins.";
    } else {
        player2.addCard(p1DrawCards);
        player2.addCard(p2DrawCards);
        turn += " " + player2.getName() + " wins.";
    }

    // Update the game log
    gameLog.push_back(turn + "\n");
};

void Game::printLastTurn()
{
    if (gameLog.size() == 0)
    {
        std::cout << "The match hasnt begin yet" << std::endl;
        return;
    }

    std::cout << gameLog[gameLog.size() - 1] << std::endl;
};
        
void Game::printWiner()
{
    int p1_cards = this->player1.cardesTaken();
    int p2_cards = this->player2.cardesTaken();
    if (p1_cards + p2_cards < 52)
    {
        std::cout << "The game is still being played!" << std::endl;
    }
    else if (p1_cards > p2_cards)
    {
        std::cout << "Congratulations, Player 1 is the winner!" << std::endl;
    }
    else if (p1_cards < p2_cards)
    {
        std::cout << "Congratulations, Player 2 is the winner!" << std::endl;
    }
    else
    {
        std::cout << "It's a tie!" << std::endl;
    }
    player1.finishedGame();
    player2.finishedGame();
}


void Game::printLog()
{
        for (auto iterator = gameLog.begin(); iterator != gameLog.end(); ++iterator) {
            string str = *iterator;
            std::cout << str << endl;
        }
}
void Game::printStats()
    {
    double p1_win_rate = static_cast<double>(p1Won) / static_cast<double>(numOfTurnsPlayed);
    double p2_win_rate = 1.0 - p1_win_rate;
    double draw_rate = static_cast<double>(drawTimes) / static_cast<double>(numOfTurnsPlayed);

    std::cout << player1.getName() << " has won " << player1.cardesTaken() << " cards, with a win rate of " << p1_win_rate << std::endl;
    std::cout << player2.getName() << " has won " << player2.cardesTaken() << " cards, with a win rate of " << p2_win_rate << std::endl;
    std::cout << "Number of draws: " << drawTimes << ", draw rate: " << draw_rate << std::endl;
};


