#include <gtest/gtest.h>

int add (int a, int b) {return a + b;}

TEST(Addition, CanAddTwoNumbers)
{
	EXPECT_TRUE(add(2, 2) == 4);
}

TEST(Addition2, CanAddTwoNumbers2) {
	EXPECT_EQ(4, add(2,2)) << "Two plus two must equal four";
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


