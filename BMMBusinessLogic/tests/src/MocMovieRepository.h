#ifndef MOCMOVIEREPOSITORY_H
#define MOCMOVIEREPOSITORY_H

#include "gmock/gmock.h"
#include "AbstractAllMoviesFetcher.h"

#include <list>
#include <string>

using std::list;
using std::string;

class MocMovieRepository : public BMMBusinessLogic::AbstractAllMoviesFetcher
{
public:
    MOCK_METHOD(list<string>, getAllMovieTitles, (), (const, override));
};

#endif // MOCMOVIEREPOSITORY_H
