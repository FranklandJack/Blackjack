#ifndef Card_hpp
#define Card_hpp


/**
 *
 * \class Card
 *
 * \brief Models a playing card that has suit and rank.
 *
 */
class Card
{
public:
   

   /*
    *
    * \enum Suit
    * 
    * \brief Enumeration for the suit of a card.
    *
    * This user defined data type will be utilized in the class. This data type is useful since it allows us to use the enumerated 
    * suit type to initialize a card, instead of using say a magic number between 1-4. SUIT_MAX_SUIT is a useful value which is just 
    * the maximum number of suits, so good for looping through a deck of cards, for example. 
    *
    */
    enum Suit
    {
        SUIT_SPADE,
        SUIT_CLUB,
        SUIT_DIOMOND,
        SUIT_HEART,
        SUIT_MAX_SUIT
    };
    

    /*
    *
    * \enum Rank
    * 
    * \brief Enumeration for the rank of a card.
    *
    * This user defined data type will be utilized in the class. This data type is useful since it allows us to use the enumerated 
    * rank type to initialize a card, instead of using say a magic number between 1-13. SUIT_MAX_RANK is a useful value which is just 
    * the maximum number of suits, so good for looping through a deck of cards, for example.  
    *
    */
    enum Rank
    {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,
        RANK_MAX_RANK
    };
    
private:


    /// Member variable to hold the suit of the card. 
    Suit m_suit;


    /// Member variable to hold the rank of the card.
    Rank m_rank;
    
public:


    /**
     *
     * \brief Constructor to create a card of given rank and suit.
     *
     * (defaults to the ace of spades if no arguments are provided ;) ).
     *
     * \param rank Rank enumeration type which is the rank of the card being created (defaults to Ace).
     *
     * \param suit Suit enumeration type which is the suit of the card being created (deatults to Spade).
     *
     */
    Card(Rank rank=RANK_ACE,Suit suit = SUIT_SPADE);
    

    /**
     * \brief returns the value of a card.
     *
     * The value of a card is given by its rank unless its a jack, queen or king in which case its value is 10, aces
     * are considered always high and have a value of 11.
     *
     * \return Integer value representing the value of the card.
     *
     */
    int getValue() const;


    /**
     * \brief prints the card to the standard output. 
     *
     * The cards are printed in the form XY where X is the rank of the card(1-10, J(= jack), Q(= queen), K(= king), A(= Ace)) and Y 
     * is the suit (S(= Spades), D(= Diamonds), H(= Hearts), C(= Clubs)).
     *
     */
    void printCard() const;
    
    
    
};

#endif /* Card_hpp */
