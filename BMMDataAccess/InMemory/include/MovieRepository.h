///
/// \file MovieRepository.h
///
/// \brief Holds in memory all movie titles available
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef MOVIEREPOSITORY_H
#define MOVIEREPOSITORY_H

#include <AbstractAllMoviesFetcher.h>

namespace BMMDataAccess{
    ///
    /// \class MovieRepository MovieRepository.h implements an abstract class from BusinessLogic lib
    ///
    class MovieRepository : public BMMBusinessLogic::AbstractAllMoviesFetcher
    {
    public:
        ///
        /// \brief Create a new MovieRepository object with predefined movie titles
        /// \since 1.0
        ///
        MovieRepository();

        /// \brief Returns the predefined list of movie titles
        /// \since 1.0
        ///
        virtual  list<string> getAllMovieTitles() const override;

    private:
        list<string> m_movieTitlesList;
    };
}

#endif // MOVIEREPOSITORY_H
