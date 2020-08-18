#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Show.h>

using namespace testing;
using std::string;

TEST(GetBookings, NoBookings){
//    string movieName {"CineMax"};
//    Movie movie1 = Movie(movieName);
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
