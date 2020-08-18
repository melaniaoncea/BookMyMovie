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
    const list<string> expectedMoviesTitles {"Movie 1", "Movie 2", "Movie 3"};
    EXPECT_CALL((*movieRepository), getAllMovieTitles())
        .Times(1)
        .WillOnce(Return(expectedMoviesTitles));
    MoviesProvider movieProvider {movieRepository};
    list<Movie> returnedMovies = movieProvider.allAvailableMovies();
    ASSERT_TRUE(!returnedMovies.empty());
    const list<int> expectedMoviesIds {1, 2, 3};
    list<int> actualMoviesIds;
    list<string> actualMoviesTitles;
    for (auto const & movie  : returnedMovies) {
        actualMoviesIds.push_back(movie.movieId());
        actualMoviesTitles.push_back(movie.movieName());
    }

    EXPECT_EQ(actualMoviesIds, expectedMoviesIds);
    EXPECT_EQ(actualMoviesTitles, expectedMoviesTitles);

}

TEST(AllAvailableMovies, ReturnsEmptyList){
    shared_ptr<MocMovieRepository> movieRepository (new MocMovieRepository());
    const list<string> expectedMoviesTitles;
    EXPECT_CALL((*movieRepository), getAllMovieTitles())
        .Times(1)
        .WillOnce(Return(expectedMoviesTitles));
    MoviesProvider movieProvider {movieRepository};
    list<Movie> returnedMovies = movieProvider.allAvailableMovies();
    ASSERT_TRUE(returnedMovies.empty());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
