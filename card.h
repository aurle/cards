#ifndef CARD_H
#define CARD_H

#include <cstdint>

/// \brief All of the cards in a single suit
enum cards
{
    ace=1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king
};

/// \brief The suits available in a deck of cards.
enum suits
{
    hearts, clubs, diamonds, spades
};

/// \brief The point value assocated with face cards
const uint8_t FACE_VALUE = 10;

/**
 * \brief Class and methods associated with a playing card.
 */ 
class Card
{
  public:
    /// \brief returns the point value of the card 
    uint8_t getValue() const;

    /// \brief returns the card position, its order in a suit
    uint8_t getCard() const;
    
    /// \brief returns the suit the card is in
    uint8_t getSuit() const;
    
    /// \brief prints the card and its suit
    void print() const;

    /// \brief Constructors
    Card(uint8_t c, uint8_t s) : card(c), suit(s) {};
    Card() {};
    
  private:
    /// \brief The card position in the suit
    uint8_t card;

    /// \brief The suit the card is in
    uint8_t suit;

    /// \brief true if the card is a face card
    bool isFace() const;
};
#endif