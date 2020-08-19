///
/// \file ShowProvider.h
///
/// \brief Holds the collection of available shows
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef SHOWPROVIDER_H
#define SHOWPROVIDER_H

#include <Theater.h>
#include <AbstractShowDetailsFetcher.h>
#include <Movie.h>
#include <Show.h>

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

#include "AbstractShowDetailsFetcher.h"

namespace BMMBusinessLogic {

    ///
    /// \class ShowProvider ShowProvider.h
    ///

    class ShowProvider : public AbstractShowDetailsFetcher
    {
    public:
        /// \brief Create a new ShowProvider object
        /// \param[in] showFetcher Populate with the derived ShowRepository obj from DataAcess lib
        /// \since 1.0
        ///
        ShowProvider(shared_ptr<BMMBusinessLogic::AbstractShowDetailsFetcher> showFetcher);

        ///
        /// \brief Return the list of theaters that play user selected movie
        /// \return list of Theater objects (Theater Id , Theater Name, Theater seats)
        /// \since 1.0
        ///
        vector<BMMBusinessLogic::Theater> alltheatersForSelectedMovie(unsigned int selectedMovie) const;

        ///
        /// \brief Return the show with the user selected movie and theater
        /// param[in] selectedMovieId id of movie selected by user
        /// param[in] selectedTheaterId id of theater selected by user
        /// \return a show
        /// \since 1.0
        ///
        BMMBusinessLogic::Show findShowByMovieAndTheaterIDs(unsigned int selectedMovieId,
                                                            unsigned int selectedTheaterId) const;

    private:
        shared_ptr<BMMBusinessLogic::AbstractShowDetailsFetcher> m_showFetcher;
    };
}

#endif // SHOWPROVIDER_H
