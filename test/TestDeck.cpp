#include "TestDeck.hpp"
CPPUNIT_TEST_SUITE_REGISTRATION(TestDeck);

void TestDeck::setUp()
{

    Deck deck;
}

void TestDeck::tearDown()
{
    delete deck;
}
