#include <iostream>
#include "Deck.hpp"

// Quick function to get the action of the player on their go.
char getPlayerChoice()
{
    std::cout<<"Enter h to hit; s to stand: \n";

    char playerChoice;

    // Make sure the player enters a valid character. 
    do
    {

        std::cin>>playerChoice;

    }while (playerChoice!='h'&& playerChoice!='s');
    
    return playerChoice;
}


// Function that takes care of the blackjack game logic.
bool playBlackJack(Deck &deck)
{

    // Both the dealer and player start with a total of zero.
    int playerTotal=0;
    int dealerTotal=0;
    

    // Dealer initially gets two cards, but for the second card is always shown face down,
    // so we can equivlently deal the dealer only one card to begin with.
    dealerTotal+=deck.dealCard().getValue();
    std::cout<<"The dealer is showing " <<dealerTotal<<'\n';
    
    // Player starts with two cards.
    playerTotal+=deck.dealCard().getValue();
    playerTotal+=deck.dealCard().getValue();
    
    
    while(true)
    {

        std::cout<<"You have " <<playerTotal<<'\n';

        char choice = getPlayerChoice();

        if(choice=='s')
        {
            break;
        }
        
        playerTotal+=deck.dealCard().getValue();

        // The player looses if they exceed 21.
        if(playerTotal>21)
        {
            return false;
        }
            
    }
    

    // In this implementation the dealer will always twist if their total is below 17.
    while(dealerTotal<17)
    {
        dealerTotal+=deck.dealCard().getValue();
        std::cout<<"the dealer has "<<dealerTotal<<'\n';
    }
    

    // The dealer also looses if they exceed 21, and so in this case the player would win by default. 
    if(dealerTotal>21)
    {
        return true;
    }
    
    // If the players score is greater than the dealers, and they are not bust, the player wins. This means that if the player and dealer
    // both get 21 then the dealer wins. 
    return(playerTotal>dealerTotal);
}

int main(int argc, const char * argv[]) 
{
    // Seed the psuedo random number generation.
    srand(static_cast<unsigned int>(time(0)));

    // Discard the first result since it can cause problems on some systems. 
    rand();


    Deck deck;


    // The deck will initially be in order so needs shuffling. 
    deck.shuffleDeck();


    // It is now ready to play.
    if(playBlackJack(deck)) std::cout<<"You have won, well done.\n";
    else std::cout<<"You loose, sorry...\n";
    return 0;
}
