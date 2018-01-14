#ifndef Deck_hpp
#define Deck_hpp


// For the cards in the deck.
#include "Card.hpp"


// For the array of cards.
#include <array>


// For shuffling of cards.
#include <cstdlib>


// For printing the deck.
#include <iostream>


// For bounds checking on arrays.
#include <cassert>


/**
 *
 * \class Deck
 *
 * \brief Models a 52 deck of playing cards.
 *
 * Consists of a 52 deck of normal playing cards, i.e. 4 suits each with cards 2 - 10, then jack, queen, king ace.  
 *
 */
class Deck
{
private:


    /// Member variable to hold the 52 playing cards. 
    std::array<Card, 52> m_array;


    /// Member variable to hold the index of the current card at the top of the deck. 
    int m_cardIndex=0;
    

    /** 
     *
     * \brief Generates a random number in a given range (inclusive).
     *
     * The function is static since it doesn't belong to or model a behaviour of a deck of cards. Rather it is a helper function
     * used in the shuffling of the cards, for this reason it is private. 
     *
     * \param min Integer value which is the minimum value for the range in which random numbers should be generated.
     *
     * \param max Integer value which is the maximum value for the range in which random numbers should be generated.
     *
     * \return Int value which is the random integer generated between min and max (inclusive).  
     *
     */
    static int getRandomNumber(int min, int max);


    /**
     *
     * \brief Swaps two cards witin the deck.
     * 
     * This function is really a helper function for the public shuffle function, hence it is private. It is static since it makes
     * perfect sense to swap two cards without a deck existing, however the functional is still strongly related to the deck, so 
     * it is defined here. 
     *
     * \param card1 reference to first Card object to be swapped.
     *
     * \param card2 reference to the second Card object to be swapped with the first one. 
     *
     */
    static void swapCard(Card &card1, Card &card2);

    /** 
     * 
     * \brief Test class for the Card.
     * 
     * Declare a TestCard friend member variable to allow access to private member variables in test class.
     *
     */
    friend class TestDeck;
    
public:


    /*
     * \brief Constructor for a deck of cards.
     * 
     * All decks of cards are the same, they all contain the same cards and the index of the card on the top of the deck always starts 
     * at 0, therefore this constructor does not have any parameters, since any two deck of cards are the same (up to ordering).
     *
     */
    Deck();
    

    /*
     *
     * \brief Prints the deck of cards to the standard output. 
     *
     * The cards are printed in the form XY where X is the rank of the card(1-10, J(= jack), Q(= queen), K(= king), A(= Ace)) and Y 
     * is the suit (S(= Spades), D(= Diamonds), H(= Hearts), C(= Clubs)).
     *
     */
    void printDeck() const;


    /*
     *
     * \brief Shuffles the deck of cards.
     *
     * The function iterates through the deck, swapping each card with another randomly selected card from the deck, utilizing the swapCard()
     * function.
     *
     */
    void shuffleDeck();
    
    /*
     * 
     * \brief Deals a card from the deck.
     *
     * The card on the top of the deck is returned, and the m_cardIndex member variable representing the  index of the card on top
     * of the deck is incremented so the next card returned is the one below it.  
     *
     * \return Constant Card reference to the card that was ontop of the deck.
     *
     */
    const Card& dealCard();
};

#endif /* Deck_hpp */
