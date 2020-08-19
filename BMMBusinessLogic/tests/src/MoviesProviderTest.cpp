#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "MocMovieRepository.h"
#include "MoviesProvider.h"
#include "Movie.h"

#include <list>
#include <string>
#include <memory>

using namespace testing;
using namespace BMMBusinessLogic;
using std::string;
using std::list;
using std::shared_ptr;

TEST(AllAvailableMovies, CanReturnAllMovies){
    shared_ptr<MocMovieRepository> movieRepository (new MocMovieRepository());
    vector<Movie> expectedMovies;
    string movieName {"Movie1"};
    Movie movie1 {movieName};
    expectedMovies.push_back(movie1);
    movieName = "Movie2";
    Movie movie2 {movieName};
    expectedMovies.push_back(movie2);
    movieName = "Movie3";
    Movie movie3 {movieName};
    expectedMovies.push_back(movie3);

    EXPECT_CALL((*movieRepository), getAllMovies())
        .Times(1)
        .WillOnce(Return(expectedMovies));
    MoviesProvider movieProvider {movieRepository};
    vector<Movie> returnedMovies = movieProvider.allAvailableMovies();
    ASSERT_TRUE(!returnedMovies.empty());
    ASSERT_TRUE(returnedMovies.size() == 3);
    EXPECT_EQ(returnedMovies.at(0).movieId(), expectedMovies.at(0).movieId());
    EXPECT_EQ(returnedMovies.at(1).movieId(), expectedMovies.at(1).movieId());
    EXPECT_EQ(returnedMovies.at(2).movieId(), expectedMovies.at(2).movieId());
    EXPECT_EQ(returnedMovies.at(0).movieName(), expectedMovies.at(0).movieName());
    EXPECT_EQ(returnedMovies.at(1).movieName(), expectedMovies.at(1).movieName());
    EXPECT_EQ(returnedMovies.at(2).movieName(), expectedMovies.at(2).movieName());

}

TEST(AllAvailableMovies, ReturnsEmptyList){
    shared_ptr<MocMovieRepository> movieRepository (new MocMovieRepository());
    const vector<Movie> expectedMovies;
    EXPECT_CALL((*movieRepository), getAllMovies())
        .Times(1)
        .WillOnce(Return(expectedMovies));
    MoviesProvider movieProvider {movieRepository};
    vector<Movie> returnedMovies = movieProvider.allAvailableMovies();
    ASSERT_TRUE(returnedMovies.empty());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
