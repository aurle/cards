/**
 * \brief methods for the Card class
 */
#include "card.h"
#include <iostream>
#include <exception>

struct invalid_card : public std::exception
{
   const char * what () const throw ()
   {
      return "Not a valid card";
   }
};

Card::Card(uint8_t c, uint8_t s) : card(c), suit(s) {
    if (!isValidCard())
    {
        throw invalid_card();
    }
};

// Public Methods
uint8_t Card::getCard() const
{
    return card;
}

uint8_t Card::getSuit() const
{
    if(!isValidSuit())
    {
        throw invalid_card();
    }
    return suit;
}

uint8_t Card::getValue() const
{
    if (!isValidCard())
    {
        throw invalid_card();
    }
    return isFace() ? FACE_VALUE : card;
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
            std::cout << +card;
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
bool Card::isValidSuit() const
{
    return suit < spades;
}
bool Card::isValidCard() const
{
    return (card >= ace && card <= king && isValidSuit());
}