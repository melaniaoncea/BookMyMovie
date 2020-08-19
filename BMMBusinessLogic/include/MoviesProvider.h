///
/// \file MoviesProvider.h
///
/// \brief Holds the collection of available movies
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef MOVIESPROVIDER_H
#define MOVIESPROVIDER_H

#include <Movie.h>

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

namespace BMMBusinessLogic {
    class AbstractAllMoviesFetcher;

    ///
    /// \class MoviesProvider MoviesProvider.h
    ///

    class MoviesProvider
    {
    public:
        /// \brief Create a new MoviesProvider object
        /// \param[in] moviesFetcher Populate with the derived MovieRepository obj from DataAcess lib
        /// \since 1.0
        ///
        MoviesProvider(shared_ptr<BMMBusinessLogic::AbstractAllMoviesFetcher> moviesFetcher);

        ///
        /// \brief Return the list of available movies
        /// \return list of Movie objects (Movie Id and Movie Name)
        /// \since 1.0
        ///
        vector<BMMBusinessLogic::Movie> allAvailableMovies() const;

    private:
        vector<BMMBusinessLogic::Movie> m_allAvailableMovies;
    };

}

#endif // MOVIESPROVIDER_H
