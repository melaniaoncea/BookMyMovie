#include "MoviesProvider.h"
#include <AbstractAllMoviesFetcher.h>

BMMBusinessLogic::MoviesProvider::MoviesProvider(shared_ptr<BMMBusinessLogic::AbstractAllMoviesFetcher> moviesFetcher)
{
    list<string> allMovieTitles = moviesFetcher->getAllMovieTitles();
    if (!allMovieTitles.empty()) {
        for (string & movieTitle : allMovieTitles) {
            BMMBusinessLogic::Movie movie {movieTitle};
            m_allAvailableMovies.push_back(movie);
        }
    }
}

list<BMMBusinessLogic::Movie> BMMBusinessLogic::MoviesProvider::allAvailableMovies() const
{
    return m_allAvailableMovies;
}
