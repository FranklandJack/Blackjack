#ifndef TestCard_hpp
#define TestCard_hpp

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "Card.hpp"
#include <iostream>

/**
 *
 * \file
 *
 * \class TestCard
 *
 * \brief Tests the Card class.  
 *
 * This test class is written using the CppUnit test framework and tests the various methods of the Card class.
 *
 *
 */
class TestCard : public CPPUNIT_NS::TestFixture
{

        /// Establish the test suit of TestCell
        CPPUNIT_TEST_SUITE(TestCard);

        /// Add test method to test the card value getter.
        CPPUNIT_TEST(testGetValue);

        /// Add test method to test the constructor.
        CPPUNIT_TEST(testConstructor);


        /// Finish the process.
        CPPUNIT_TEST_SUITE_END();

    public:

        /// Override setUp(), initialise test cases etc.
        void setUp();

        /// Override tearDown(), free allocated memory in test cases, etc.
        void tearDown();

    protected:

        /**
         *
         * \brief Test method for Card::getValue() method.
         *
         * Tests that the getter returns the correct card value.
         *
         */
        void testGetValue();

        /**
         *
         * \brief Test method for Card::Card() method.
         *
         * Test the constructor to see it behaves as expected.
         *
         */
        void testConstructor();

    private:

        /// Test case for a generic card e.g. Ace of Spades.
        Card *card;

};

#endif /* TestCard_hpp */
