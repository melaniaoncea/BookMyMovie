#include "MovieRepository.h"

 static const std::initializer_list<string> defaultMovieTitlesList =
 {"Schindler's List", "Pride and Prejudice", "To Kill a Mockingbird"};

BMMDataAccess::MovieRepository::MovieRepository()
    : m_movieTitlesList(defaultMovieTitlesList)
{
}

list<std::string> BMMDataAccess::MovieRepository::getAllMovieTitles() const
{
    return m_movieTitlesList;
}
