/**
 * \brief methods for the Card class
 */
#include "card.h"
#include <iostream>

// Public Methods
uint8_t Card::getCard() const
{
    return card;
}

uint8_t Card::getSuit() const
{
    return suit;
}

uint8_t Card::getValue() const
{
    return isFace() ? 10 : card;
}

void Card::print() const
{
    switch(card)
    {
        case ace:
            std::cout << "Ace";
            break;
        case jack:
            std::cout << "Jack";
            break;
        case queen:
            std::cout << "Queen";
            break;
        case king:
            std::cout << "King";
            break;
        default:
            std::cout << (int)card;
            break;
    }
    std::cout << " of ";
    switch (suit)
    {
        case hearts:
            std::cout << "Hearts";
            break;
        case spades:
            std::cout << "Spades";
            break;
        case diamonds:
            std::cout << "Diamonds";
            break;
        case clubs:
            std::cout << "Clubs";
            break;
    }
}

// Private Methods
bool Card::isFace() const
{
    return (card == jack || card == queen || card == king) ? true : false;
}