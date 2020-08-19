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

vector<BMMBusinessLogic::Theater> BMMBusinessLogic::BusinessLogicController::getTheatersByMovieId(unsigned int selectedMovieId)
{
    return  m_showProvider->alltheatersForSelectedMovie(selectedMovieId);
}

vector<BMMBusinessLogic::Seat> BMMBusinessLogic::BusinessLogicController::searchAvailableSeatsByMovieAndTheaterIds(unsigned int selectedMovieId, unsigned int selectedTheaterId)
{
    vector<BMMBusinessLogic::Seat> result;
    auto Show = m_showProvider->findShowByMovieAndTheaterIDs(selectedMovieId, selectedTheaterId);

    return result;
}

