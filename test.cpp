/**
 * \brief Test code to demonstrate the functionality of the card and deck classes
 */
#include "card.h"
#include "deck.h"
#include <iostream>

int main(void)
{
    Deck deck;
    std::cout << "\nThe unshuffled deck\n"; 
    deck.print();
    std::cout << "\nShuffling the deck\n";
    deck.shuffle();
    std::cout << "\nThe shuffled deck\n";
    deck.print();
    
    Card card_dealt;
    bool cards_left = true;

    std::cout << "\nDeal the Cards\n";

    while (cards_left)
    {
        try
        {
            card_dealt = deck.deal_card();
            std::cout << "Card Dealt: ";
            card_dealt.print();
            std::cout << "\n";
        }
        catch (int e)
        {
            cards_left = false;
        }
    }

    std::cout << "\nAll cards have been dealt\n\n";
    
    return 1;
}