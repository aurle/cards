/**
 * \brief Methods for the Deck Class
 */
#include "deck.h"
#include <iostream>
#include <stdlib.h>
#include <exception>

// Build a new deck
// Most common arrangement for a new deck is
// A->K(hearts) A->K(spades) K->A (Diamonds) K->A (Clubs)
Deck::Deck()
{
    for (uint8_t suit = hearts; suit <= spades; suit++)
    {
        for (uint8_t card = ace; card <= king; card++)
        {
            Card new_card(card, suit);
            deck.push_back(new_card);
        }
    }
    for (uint8_t suit = diamonds; suit <= clubs; suit++)
    {
        for (uint8_t card = king; card >= ace; card--)
        {
            Card new_card(card, suit);
            deck.push_back(new_card);
        }
    }
}

struct empty_deck : public std::exception {
   const char * what () const throw () {
      return "The deck is empty";
   }
};

Card Deck::deal_card()
{
    if (deck.size())
    {
        Card top_card = deck.front();
        deck.erase(deck.begin());
        return top_card;
    }
    else
    {
        throw empty_deck(); // Throw an exception if no cards are found
    }
}

void Deck::shuffle()
{
    srand(time(NULL));
    int items = deck.size();
    for (uint8_t item = 0; item < items; item++)
    {
        int swap = rand() % items; // Get a random position in the deck
        std::cout << "Swap "; //For debug only
        deck[item].print();   //For debug only
        std::cout << " with ";//For Debug only
        deck[swap].print();   //For Debug only
        std::cout << " item=" << +item << " swap=" << swap << "\n"; //For debug only
        std::iter_swap(&deck[item], &deck[swap]);
    }
}

void Deck::print()
{
    for (int index = 0; index < deck.size(); index++)
    {
        std::cout << index + 1 << " - ";
        deck[index].print();
        std::cout << "\n";
    }
}

