
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"
#include <stdexcept>

using namespace ariel;

TEST_CASE("Checking if the given name is actually the name")
{
    Player player1("Itamar");
    Player player2("Guetta");
    CHECK(player1.name == "Itamar");
    CHECK(player2.name == "Guetta");
    CHECK(player1.name != player2.name);
}

TEST_CASE("Checking if the intiallization of the player is good")
{
    Player player1("Itamar");
    Player player2("Guetta");
    CHECK(player1.stacksize() == 0);
    CHECK(player1.cardesTaken() == 0);
    CHECK(player1.stacksize() == player2.stacksize());
}

TEST_CASE("Checking if we starts the game with 52 cards")
{
    Player p1("Itamar");
    Player p2("Guetta");
    int total = p1.stacksize() + p2.stacksize();
    CHECK(total == 52);
}

TEST_CASE("Checking if each player starts the game with 0 cards taken")
{
    Player p1("Itamar");
    Player p2("Guetta");
    int p1CardsTaken = p1.cardesTaken();
    int p2CardsTaken = p2.cardesTaken();
    CHECK(p1CardsTaken == 0);
    CHECK(p2CardsTaken == 0);
}

TEST_CASE("checks if the cards are well set")
{
    card card1(4, "hearts");
    card card2(7, "hearts");
    card card3(9, "diamonds");
    CHECK(card1.getNum() == 4);
    CHECK(card1.getKind() == "hearts");
    CHECK(card1.getKind() == card1.getKind());
    CHECK(card1.getKind() == card2.getKind());
    CHECK(card1.getKind() != card3.getKind());
}

TEST_CASE("checks if its throws any excepetions")
{
    Player player1("Itamar");
    Player player2("Guetta");
    Game game(player1, player2);
    CHECK_THROWS(game.playAll());
    CHECK_THROWS(game.printWiner());
    CHECK_THROWS(game.printLog());
    CHECK_THROWS(game.printLastTurn());
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.printStats());
}

