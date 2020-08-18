#include "BusinessLogicController.h"
#include <Movie.h>

#include<list>

using std::list;


BMMBusinessLogic::BusinessLogicController::BusinessLogicController(shared_ptr<BMMBusinessLogic::AbstractAllMoviesFetcher> moviesFetcher)
    : m_moviesProvider(new MoviesProvider(moviesFetcher))
{

}

vector<vector<std::string> > BMMBusinessLogic::BusinessLogicController::getAllMovies()
{
    vector<vector<string>> result = convertMoviesList();
    return result;
}

vector<vector<string> > BMMBusinessLogic::BusinessLogicController::convertMoviesList()
{
    list<BMMBusinessLogic::Movie> moviesList = m_moviesProvider->allAvailableMovies();
    vector<vector<string>> convertedList;

    for(auto const & movie : moviesList) {
        vector<string> result;
        result.push_back(std::to_string(movie.movieId()));
        result.push_back(movie.movieName());
        convertedList.push_back(result);
    }

    return convertedList;
}
