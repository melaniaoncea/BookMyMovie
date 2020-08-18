#include "Movie.h"

const string defaultMovieNameRoot {"NewMovie"};
unsigned int BMMBusinessLogic::Movie::nextId {1};

BMMBusinessLogic::Movie::Movie(std::string &movieName)
    : m_movieId(nextId++)
    , m_movieName(movieName.empty() ? defaultMovieNameRoot + std::to_string(m_movieId)
                                    : movieName)
{
}

unsigned int BMMBusinessLogic::Movie::movieId() const
{
    return m_movieId;
}

string BMMBusinessLogic::Movie::movieName() const
{
    return m_movieName;
}
