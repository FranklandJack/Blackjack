#include "TestCard.hpp"
CPPUNIT_TEST_SUITE_REGISTRATION(TestCard);

void TestCard::setUp()
{

    card = new Card(Card::RANK_ACE, Card::SUIT_SPADE);
}

void TestCard::tearDown()
{
    delete card;
}

void TestCard::testGetValue()
{
    // Ace has card value of 11.
    CPPUNIT_ASSERT(11==card->getValue());
}

void TestCard::testConstructor()
{
    CPPUNIT_ASSERT(card->m_suit == Card::SUIT_SPADE && card->m_rank == Card::RANK_ACE);
}




