///
/// \file BusinessLogicController
///
/// \brief Contains core controller class of BusinessLogic lib
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef BUSINESSLOGICCONTROLLER_H
#define BUSINESSLOGICCONTROLLER_H

#include <memory>
#include <vector>
#include <string>

#include <MoviesProvider.h>
#include <AbstractBusinessLogicController.h>

using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::string;

namespace BMMBusinessLogic {
    class AbstractAllMovieFetcher;

    ///
    /// \class Movie Movie.h
    ///

    class BusinessLogicController
    {
    public:
        /// \brief Create a new BusinessLogicController object
        /// \param[in] moviesfetcher an object that implements AbstractAllMoviesFetcher and provides a list of movie titles
        /// \since 1.0
        ///
        BusinessLogicController(shared_ptr<BMMBusinessLogic::AbstractAllMoviesFetcher> moviesFetcher);

        ///
        /// \brief Returns all the available movies and their associated details
        /// \return The vector<vector<string>, e.g., {{"1", "MovieTitle1"}, {"2", "MovieTitle2"}}
        ///
        vector<vector<string>> getAllMovies();

    private:
        // converts list<Movies> to vector<vector<string>>
        vector<vector<string>>convertMoviesList();

    private:
        unique_ptr<BMMBusinessLogic::MoviesProvider> m_moviesProvider {nullptr};
    };

}

#endif // BUSINESSLOGICCONTROLLER_H
