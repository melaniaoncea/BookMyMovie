///
/// \file BusinessLogicController.h
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
#include <ShowProvider.h>

using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::string;

namespace BMMBusinessLogic {
    class AbstractAllMovieFetcher;
    class AbstactShowDetailsFetcher;

    ///
    /// \class Movie Movie.h
    ///

    class BusinessLogicController
    {
    public:
        /// \brief Create a new BusinessLogicController object
        /// \param[in] moviesFetcher an object that implements AbstractAllMoviesFetcher and provides a list of movie titles
        /// \param[in] showFetcher an object that implements AbstactShowDetailsFetcher and returns a list of theaters
        /// \since 1.0
        ///
        BusinessLogicController(shared_ptr<BMMBusinessLogic::AbstractAllMoviesFetcher> moviesFetcher);
        ///
        /// \brief Returns all the available movies and their associated details
        /// \return The vector<vector<string>, e.g., {{"1", "MovieTitle1"}, {"2", "MovieTitle2"}}
        ///
        vector<BMMBusinessLogic::Movie> getAllMovies();
        vector<BMMBusinessLogic::Theater> getTheatersByMovieId(unsigned int selectedMovieId);
        vector<BMMBusinessLogic::Seat> searchAvailableSeatsByMovieAndTheaterIds(unsigned int selectedMovieId, unsigned int selectedTheaterId);

    private:
        unique_ptr<BMMBusinessLogic::MoviesProvider> m_moviesProvider {nullptr};
        shared_ptr<BMMBusinessLogic::ShowProvider> m_showProvider {nullptr}; // should have been initialized in constructor
    };

}

#endif // BUSINESSLOGICCONTROLLER_H
