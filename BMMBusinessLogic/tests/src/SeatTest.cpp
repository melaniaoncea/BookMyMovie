#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Seat.h>

using namespace testing;
using namespace BMMBusinessLogic;
using std::string;

TEST(GetSeatName, CreatedUsingEmptyName){
    // a unique default seat name will be created
    string seatName {""};
    Seat seat1 {seatName};
    EXPECT_EQ(seat1.seatName(), defaultSeatNameRoot + "1");

    // if another seat object with empty name is created
    // the name will be different from the previous one
    Seat seat2 {seatName};
    EXPECT_EQ(seat2.seatName(), defaultSeatNameRoot + "2");
}

TEST(GetSeatName, PreviouslyCreatedSeatOutOfScopeEmptySeatName){
    // a unique default seat name will be created
    string seatName {""};
    Seat seat1 {seatName};
    EXPECT_EQ(seat1.seatName(), defaultSeatNameRoot + "3");
}

TEST(GetSeatName, PreviouslyCreatedSeatDeletedEmptySeatName){
     // a unique default seat name will be created
    string seatName {""};
    Seat * seat1 = new Seat(seatName);
    EXPECT_EQ(seat1->seatName(), defaultSeatNameRoot + "4");
    delete seat1;
    Seat * seat2 = new Seat(seatName);
    EXPECT_EQ(seat2->seatName(), defaultSeatNameRoot + "5");
    delete seat1;
}

TEST(GetSeatName, CreatedWithDefaultSeatNameFormat){
     // the given name will be assigned
     // might result in duplicate seat names
    string seatName1 {""};
    Seat seat1 {seatName1};
    EXPECT_EQ(seat1.seatName(), defaultSeatNameRoot + "6");
    string seatName2 {defaultSeatNameRoot + "6"};
    Seat seat2 {seatName2};
    EXPECT_EQ(seat2.seatName(), seatName2);
    EXPECT_EQ(seat1.seatName(), seat2.seatName());
}

TEST(GetSeatName, CreatedUsingCustomSeatName){
    // a custom seat name will be created
    string seatName {"a1"};
    Seat seat1 {seatName};
    EXPECT_EQ(seat1.seatName(), seatName);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
