#include "ShowProvider.h"

BMMBusinessLogic::ShowProvider::ShowProvider(shared_ptr<BMMBusinessLogic::AbstractShowDetailsFetcher> showFetcher)
    :m_showFetcher(showFetcher)
{

}

vector<BMMBusinessLogic::Theater> BMMBusinessLogic::ShowProvider::alltheatersForSelectedMovie(unsigned int selectedMovie) const
{
    return m_showFetcher->findTheaterByMovieId(selectedMovie);
}

BMMBusinessLogic::Show BMMBusinessLogic::ShowProvider::findShowByMovieAndTheaterIDs(unsigned int selectedMovieId, unsigned int selectedTheaterId) const
{
   return m_showFetcher->findShowByMovieAndTheaterIds(selectedMovieId, selectedTheaterId);
}
