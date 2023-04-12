#include "player.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ariel;


int Player::stacksize()
{
    return cardPack.size();
}

int Player::cardesTaken()
{
    return cardPackWon.size();
}

bool Player::isPlaying()
{
    return isPlaying;
};

void Player::joinedGame()
{
    isActive = true;
};

void Player::finishedGame()
{
    isActive = false;
};

void Player::setCardsTaken(int num)
{
    this->numOfTimeWon = num;
}

card Player::pullCard()
{
    if (cardPack.empty())
    {
        throw std::runtime_error("The game is over!");
    }

    card card = cardPack.front();
    cardPack.erase(cardPack.begin());
    return card;
}

void Player::addCard(const std::vector<card>& cards_to_add)
{
    for (const auto& card : cards_to_add)
    {
        this->cardPackWon.push_back(card);
    }
}