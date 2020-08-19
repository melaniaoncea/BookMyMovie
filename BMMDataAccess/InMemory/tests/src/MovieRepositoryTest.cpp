#include <gtest/gtest.h>
#include <MovieRepository.h>
#include <Movie.h>

using namespace testing;
using namespace BMMDataAccess;

TEST(GetAllMovies, GetDefaultMovieList){
//    MovieRepository movieRepository;
//    vector<BMMBusinessLogic::Movie> allMovieTitles = movieRepository.getAllMovies();
//    EXPECT_EQ(allMovieTitles.size(), 3);
//    EXPECT_EQ(allMovieTitles.at(0).movieId(), 1);
//    EXPECT_EQ(allMovieTitles.at(1).movieId(), 2);
//    EXPECT_EQ(allMovieTitles.at(2).movieId(), 3);
//    EXPECT_EQ(allMovieTitles.at(0).movieName(), "To kill a mocking bird");
//    EXPECT_EQ(allMovieTitles.at(1).movieName(), "Schindler's List");
//    EXPECT_EQ(allMovieTitles.at(2).movieName(), "Pride and Prejudice");
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
