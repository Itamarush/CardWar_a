#include "player.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace ariel;

void Player::addCardToPack(card card)
{
    this->cardPack.push_back(card);
}

void Player::addCardToWinningPack(card card)
{
    this->cardPackWon.push_back(card);
}

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
    return isActive;
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
        throw std::runtime_error("Player's card pack is empty");

    }

    card card = cardPack.front();
    cardPack.erase(cardPack.begin());
    return card;
}

void Player::addCard(const std::vector<card>& card)
{
    for (const auto& card : card)
    {
        this->cardPackWon.push_back(card);
    }
}