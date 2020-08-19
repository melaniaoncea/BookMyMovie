#include "MovieRepository.h"
#include "Movie.h"

BMMDataAccess::MovieRepository::MovieRepository()
{
    string movieName {"To kill a mocking bird"};
    BMMBusinessLogic::Movie movie1 {movieName};
    m_movieTitlesList.push_back(movie1);
    movieName = "Schindler's List";
    BMMBusinessLogic::Movie movie2 {movieName};
    m_movieTitlesList.push_back(movie2);
    movieName = "Pride and Prejudice";
    BMMBusinessLogic::Movie movie3 {movieName};
    m_movieTitlesList.push_back(movie3);
}

vector<BMMBusinessLogic::Movie> BMMDataAccess::MovieRepository::getAllMovies() const
{
    return m_movieTitlesList;
}
