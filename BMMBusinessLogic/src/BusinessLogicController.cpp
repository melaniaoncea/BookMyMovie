#include "BusinessLogicController.h"
#include <Movie.h>

#include<list>

using std::list;


BMMBusinessLogic::BusinessLogicController::BusinessLogicController(shared_ptr<BMMBusinessLogic::AbstractAllMoviesFetcher> moviesFetcher)
    : m_moviesProvider(new MoviesProvider(moviesFetcher))
{

}

vector<BMMBusinessLogic::Movie> BMMBusinessLogic::BusinessLogicController::getAllMovies()
{
    return m_moviesProvider->allAvailableMovies();;
}
