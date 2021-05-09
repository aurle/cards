#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>


/**
 * \brief Class and methods associated with a deck of playing cards
 */
class Deck
{
  public:
    /// \brief Construct a new unshuffled deck
    Deck();

    /// \brief Shuffle the cards currently in the deck
    void shuffle();

    /// \brief Return the card from the top of the deck and remove it
    /// \return A playing card object
    Card deal_card();

    /// \brief Print the cards currently in the deck
    void print();

  private:
    /// \brief Create a vector to hold the cards in the deck
    std::vector<Card> deck;
};
#endif