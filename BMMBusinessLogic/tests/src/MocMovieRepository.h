#ifndef MOCMOVIEREPOSITORY_H
#define MOCMOVIEREPOSITORY_H

#include "gmock/gmock.h"
#include "AbstractAllMoviesFetcher.h"
#include "Movie.h"

#include <vector>

using std::vector;
using std::string;

class MocMovieRepository : public BMMBusinessLogic::AbstractAllMoviesFetcher
{
public:
    MOCK_METHOD(vector<BMMBusinessLogic::Movie>, getAllMovies, (), (const, override));
};

#endif // MOCMOVIEREPOSITORY_H
