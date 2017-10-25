#include "Card.hpp"
#include <iostream>

Card::Card(Rank rank,Suit suit):m_rank{rank},m_suit{suit}{}

int Card::getValue() const
{
    switch (m_rank) {
        case RANK_2: return 2;
        case RANK_3: return 3;
        case RANK_4: return 4;
        case RANK_5: return 5;
        case RANK_6: return 6;
        case RANK_7: return 7;
        case RANK_8: return 8;
        case RANK_9: return 9;
        case RANK_10: return 10;
        case RANK_JACK: return 10;
        case RANK_QUEEN: return 10;
        case RANK_KING: return 10;
        case RANK_ACE: return 11;
            
            
            
        default:
            break;
    }
    
    return 0;
}

void Card::printCard() const
{
    switch (m_rank) {
        case RANK_2: std::cout<< '2'; break;
        case RANK_3: std::cout<< '3'; break;
        case RANK_4: std::cout<< '4'; break;
        case RANK_5: std::cout<< '5'; break;
        case RANK_6: std::cout<< '6'; break;
        case RANK_7: std::cout<< '7'; break;
        case RANK_8: std::cout<< '8'; break;
        case RANK_9: std::cout<< '9'; break;
        case RANK_10: std::cout<< 'T'; break;
        case RANK_JACK: std::cout<< 'J'; break;
        case RANK_QUEEN: std::cout<< 'Q'; break;
        case RANK_KING: std::cout<< 'K'; break;
        case RANK_ACE: std::cout<< 'A'; break;
            
            default:
                break;
    }
    
    switch (m_suit) {
        case SUIT_SPADE: std::cout<<'A'<<'\n'; break;
        case SUIT_CLUB: std::cout<<'A'<<'\n'; break;
        case SUIT_HEART: std::cout<<'A'<<'\n'; break;
        case SUIT_DIOMOND: std::cout<<'A'<<'\n'; break;
            
        default:
            break;
    }
}