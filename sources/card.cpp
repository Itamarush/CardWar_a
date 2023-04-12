#include "card.hpp"
using namespace ariel;

string card::toString()
{
    string str = "";
    switch (this->num)
    {
    case 1:
        str += "Ace";
        break;
    case 11:
        str += "Jack";
        break;
    case 12:
        str += "Queen";
        break;
    case 13:
        str += "King";
        break;

    default:
        str += to_string(num);
        break;
    }
    
    switch (kind)
    {
    case 1:
        str += " of Hearts";
        break;
    case 2:
        str += " of Diamonds";
        break;
    case 3:
        str += " of Spades";
        break;
    case 4:
        str += " of Clubs";
        break;
    default:
        break;
    }
    return str;
}
