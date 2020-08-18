#include <gtest/gtest.h>
#include <MovieRepository.h>

using namespace testing;
using namespace BMMDataAccess;

TEST(GetAllMovies, GetDefaultMovieList){
    MovieRepository movieRepository;
    list<string> allMovieTitles = movieRepository.getAllMovieTitles();
    list<string> expectedResults;
    expectedResults.push_back("Schindler's List");
    expectedResults.push_back("Pride and Prejudice");
    expectedResults.push_back("To Kill a Mockingbird");
    EXPECT_EQ(allMovieTitles, expectedResults);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
