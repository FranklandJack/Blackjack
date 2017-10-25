#include "Deck.hpp"


int Deck::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX)+1.0);
    return static_cast<int>(rand()*fraction*(max-min+1)+min);
}

void Deck::swapCard(Card &card1, Card &card2)
{
    Card tempCard = card1;
    card1         = card2;
    card2         = tempCard;
}

Deck::Deck()
{
    int card = 0;
    for(int suit=0;suit<Card::SUIT_MAX_SUIT;++suit)
    {
        for (int rank=0; rank<Card::RANK_MAX_RANK; ++rank) 
        {
            m_array[card]=Card(static_cast<Card::Rank>(rank),static_cast<Card::Suit>(suit));
            ++card;
        }
    }
}

void Deck::printDeck() const
{
    for(auto const &card : m_array)
    { 
        card.printCard();
        std::cout<<' ';
    }
    std::cout<<'\n';
}

void Deck::shuffleDeck()
{
    for(auto &card : m_array)
    {
        int swapIndex = getRandomNumber(0, 51);
        swapCard(card, m_array[swapIndex]);
    }
    m_cardIndex=0;
}

const Card& Deck::dealCard()
{
    assert(m_cardIndex<52);
    return m_array[m_cardIndex++];
}

