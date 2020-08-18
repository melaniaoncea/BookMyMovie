#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <Movie.h>
#include <string>

using namespace testing;
using namespace BMMBusinessLogic;
using std::string;

TEST(GetMovieName, CreatedWithEmptyName){
    // A default name is constructed when movieName is an empty string
    string movieName {""};
    Movie movie1 {movieName};
    auto expectedMovieName = defaultMovieNameRoot + std::to_string(movie1.movieId());
    EXPECT_EQ(movie1.movieName(), expectedMovieName);
}

TEST(GetMovieName, CreatedWithCustomName){
    // Custom movie name is returned
    string movieName {"Gone with the wind"};
    Movie movie1 {movieName};
    EXPECT_EQ(movie1.movieName(), movieName);
}

TEST(GetMovieName, CreatedUsingDefaultMovieName){
    // Custom movie name is returned
    // Might result in duplicate theater names
    string movieName1 {""};
    Movie movie1 {movieName1};
    string movieName2 {"NewMovie3"};
    Movie movie2 {movieName2};
    EXPECT_EQ(movie1.movieName(), movie2.movieName());
}

TEST(GetMovieId, PreviouslyCreatedMovieOutOfScope){
    // during one app run IDs are not reused
    // even if previously created objects are out of scope
    string movieName {"The Adventures of Sherlock Holmes"};
    Movie movie1 {movieName};
    EXPECT_EQ(movie1.movieId(), 5);
}

TEST(GetMovieId, PreviouslyCreatedMovieDeleted){
    // during one run IDs are not reused
    // even if previously heap created objects are deleted
    string movieName {"The Adventures of Sherlock Holmes"};
    Movie* movie1 =  new Movie{movieName};
    delete movie1;
    Movie* movie2 = new Movie{movieName};
    EXPECT_EQ(movie2->movieId(), 7);
    delete movie2;
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
