#include <gtest/gtest.h>
#include <TheaterRepository.h>

using namespace testing;
using namespace BMMDataAccess;

TEST(GetAllTheatersTitles, GetDefaultTheaterList){
    TheaterRepository TheaterRepository;
    list<string> allTheaterTitles = TheaterRepository.getAllTheaterNames();
    list<string> expectedResults;
    expectedResults.push_back("Reel Cinema");
    expectedResults.push_back("Vox Cinema");
    expectedResults.push_back("Novo Cinema");
    EXPECT_EQ(allTheaterTitles, expectedResults);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
