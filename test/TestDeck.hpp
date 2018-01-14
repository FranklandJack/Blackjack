#ifndef TestDeck_hpp
#define TestDeck_hpp

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "Deck.hpp"
#include <iostream>

/**
 *
 * \file
 *
 * \class TestDeck
 *
 * \brief Tests the Deck class.  
 *
 * This test class is written using the CppUnit test framework and tests the various methods of the Deck class.
 *
 *
 */
class TestDeck : public CPPUNIT_NS::TestFixture
{

        /// Establish the test suit of TestCell
        CPPUNIT_TEST_SUITE(TestDeck);


        /// Finish the process.
        CPPUNIT_TEST_SUITE_END();

    public:

        /// Override setUp(), initialise test cases etc.
        void setUp();

        /// Override tearDown(), free allocated memory in test cases, etc.
        void tearDown();

    protected:

        

    private:

        /// Test case for a generic deck.
        Deck *deck;

};

#endif /* TestDeck_hpp */