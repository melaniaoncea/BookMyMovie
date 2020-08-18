///
/// \file AbstractAllMoviesFetcher.h
///
/// \brief Interface for DataAccess layer
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef ABSTRACTALLMOVIESFETCHER_H
#define ABSTRACTALLMOVIESFETCHER_H

#include<list>
#include<string>

using std::list;
using std::string;
namespace BMMBusinessLogic {
    ///
    /// \class AbstractAllMoviesFetcher AbstractAllMoviesFetcher.h
    ///
    class AbstractAllMoviesFetcher {
    public:
        AbstractAllMoviesFetcher() = default;
        virtual ~AbstractAllMoviesFetcher() = default;

        /// \brief When implemented, returns a list of movie titles
        /// \since 1.0
        ///
        virtual  list<string> getAllMovieTitles() const = 0;

    };
}

#endif // ABSTRACTALLMOVIESFETCHER_H
