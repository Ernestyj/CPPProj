#include "gtest/gtest.h"
#include <iostream>

//#include "../../src/snippet/range.cpp"

using namespace std;


namespace {
    // Normal Test case
    TEST(Example, E) {
      EXPECT_EQ(1, 1);
      cout<<"Test finished."<<endl;
    }

    // The fixture for testing class Foo.
    class SnippetTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if its body is empty.

        SnippetTest() {
          // You can do set-up work for each test here.
        }

        virtual ~SnippetTest() {
          // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up and cleaning up each test, you can define the following methods:
        virtual void SetUp() {
          // Code here will be called immediately after the constructor (right before each test).
        }

        virtual void TearDown() {
          // Code here will be called immediately after each test (right before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for Foo.
    };

    // Tests that Foo does Xyz.
    TEST_F(SnippetTest, DoesXyz) {
      // Exercises the Xyz feature of Foo.
    }
}

//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
