#include "MoviesProvider.h"
#include <AbstractAllMoviesFetcher.h>

BMMBusinessLogic::MoviesProvider::MoviesProvider(shared_ptr<BMMBusinessLogic::AbstractAllMoviesFetcher> moviesFetcher)
{
    vector<BMMBusinessLogic::Movie> allMovieTitles = moviesFetcher->getAllMovies();
    if (!allMovieTitles.empty()) {
        for (auto & movieTitle : allMovieTitles) {
            BMMBusinessLogic::Movie movie {movieTitle};
            m_allAvailableMovies.push_back(movie);
        }
    }
}

vector<BMMBusinessLogic::Movie> BMMBusinessLogic::MoviesProvider::allAvailableMovies() const
{
    return m_allAvailableMovies;
}
