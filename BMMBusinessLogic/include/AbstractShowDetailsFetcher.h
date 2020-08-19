///
/// \file AbstractShowDetailsFetcher.h
///
/// \brief Interface for DataAccess layer - establishes contract
/// to get Shows details from the DataAccess lib
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef ABSTRACTSHOWDETAILSFETCHER_H
#define ABSTRACTSHOWDETAILSFETCHER_H

#include<vector>

using std::vector;

namespace BMMBusinessLogic {
    class Theater;
    class Show;
    ///
    /// \class AbstractAbstractShowDetailsFetcher AbstractAbstractShowDetailsFetcher.h
    ///
    class AbstractShowDetailsFetcher {
    public:
        AbstractShowDetailsFetcher() = default;
        virtual ~AbstractShowDetailsFetcher() = default;

        /// \brief When implemented, returns a list of the theaters that play a certain movie
        /// \param  movieId Movie id selected by the user
        /// \since 1.0
        ///
        virtual  vector<Theater> findTheaterByMovieId(int movieId) const = 0;

        /// \brief When implemented, returns a list of the theaters that play a certain movie
        /// \param movieId Movie id selected by the user
        /// \param theaterId Theater id selected by the user
        /// \since 1.0
        ///
        virtual  Show findShowByMovieAndTheaterIds(int movieId, int theaterId) const = 0;

    };
}

#endif // ABSTRACTSHOWDETAILSFETCHER_H
