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

    // std::cout << "Try to create a bogus card\n";
    // Card bogus_card(0, 10);
    
    Card card_dealt;
    bool cards_left = true;

    std::cout << "Ask for the value of an uninitialized card\n";
    int value = 0;
    try
    {
        value = card_dealt.getValue();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\nDeal the Cards\n";

    int cards_dealt = 0;

    while (cards_left)
    {
        try
        {
            card_dealt = deck.deal_card();
            cards_dealt++;
            std::cout << cards_dealt << " Card Dealt: ";
            card_dealt.print();
            std::cout << "\n";
        }
        catch (std::exception &e)
        {
            std::cerr << "Caught: " << e.what() << "\n";
            cards_left = false;
        }
    }

    std::cout << "\nAll cards have been dealt\n\n";
    
    return 1;
}