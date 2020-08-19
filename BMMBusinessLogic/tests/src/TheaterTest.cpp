#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <Theater.h>
#include <Seat.h>

using namespace testing;
using namespace BMMBusinessLogic;

TEST(GetTheaterName, CreatedWithEmptyName){
    // A default unique name is returned
    string theaterName {""};
    vector<Seat> theaterSeatsList;
    string seatName {"a1"};
    Seat seat1 {seatName};
    theaterSeatsList.push_back(seat1);
    Theater theater1 {theaterName, theaterSeatsList};
    auto expectedTheaterName = defaultTheaterNameRoot + std::to_string(theater1.theaterId());
    EXPECT_EQ(theater1.theaterName(), expectedTheaterName);
}

TEST(GetTheaterName, CreatedWithCustomName){
    // Custom theater name is returned
    string theaterName {"Reel Cinema"};
    vector<Seat> theaterSeatsList;
    string seatName {"a1"};
    Seat seat1 {seatName};
    theaterSeatsList.push_back(seat1);
    Theater theater1 {theaterName, theaterSeatsList};
    EXPECT_EQ(theater1.theaterName(), theaterName);
}

TEST(GetTheaterName, CreatedUsingDefaultName){
    // Duplicate theater names might occur if using default naming as custom name
    string theaterName1 {""};
    vector<Seat> theaterSeatsList;
    string seatName {"a1"};
    Seat seat1 {seatName};
    theaterSeatsList.push_back(seat1);
    Theater theater1 {theaterName1, theaterSeatsList};
    string theaterName2 {"DefaultTheaterName3"};
    Theater theater2 {theaterName2, theaterSeatsList};
    EXPECT_EQ(theater1.theaterName(), theater2.theaterName());
}

TEST(GetTheaterId, PreviouslyCreatedTheatersOutOfScope){
    // during one app run IDs are not reused
    // even if previously created objects are out of scope
    string theaterName {"ABC"};
    vector<Seat> theaterSeatsList;
    string seatName {"b2"};
    Seat seat1 {seatName};
    theaterSeatsList.push_back(seat1);
    Theater theater1 {theaterName, theaterSeatsList};
    EXPECT_EQ(theater1.theaterId(), 5);
}

TEST(GetTheaterId, PreviouslyCreatedTheaterDeleted){
    // during one run IDs are not reused
    // even if previously heap created objects are deleted
    string theaterName {"ABC"};
    vector<Seat> theaterSeatsList;
    string seatName {"b2"};
    Seat seat1 {seatName};
    Theater* theater1 =  new Theater{theaterName, theaterSeatsList};
    EXPECT_EQ(theater1->theaterId(), 6);
    delete theater1;
    Theater* theater2 = new Theater{theaterName, theaterSeatsList};
    EXPECT_EQ(theater2->theaterId(), 7);
    delete theater2;
}

TEST(GetTheaterSeatsList, NonEmptySeatList){
    // return the appropriate seat list
    string theaterName {"ABC"};
    vector<Seat> theaterSeatsList;
    string seatName {"b2"};
    Seat seat1 {seatName};
    theaterSeatsList.push_back(seat1);
    Theater theater1 {theaterName, theaterSeatsList};
    vector<Seat> expectedSeatsList = theater1.theaterSeatsList();
    EXPECT_EQ(theaterSeatsList.size(), expectedSeatsList.size());
    EXPECT_EQ(theaterSeatsList.front().seatName(), expectedSeatsList.front().seatName());
}

TEST(GetTheaterSeatsList, EmptySeatList){
    // return an empty seat list
    string theaterName {"ABC"};
    vector<Seat> theaterSeatsList;
    Theater theater1 {theaterName, theaterSeatsList};
    vector<Seat> expectedSeatsList = theater1.theaterSeatsList();
    ASSERT_TRUE(expectedSeatsList.empty());
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
