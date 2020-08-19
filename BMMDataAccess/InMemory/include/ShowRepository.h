#ifndef SHOWREPOSITORY_H
#define SHOWREPOSITORY_H

///
/// \file ShowRepository.h
///
/// \brief Holds in memory all the current running shows
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#include <AbstractShowDetailsFetcher.h>
#include <Seat.h>

class Theater;
class Show;


namespace BMMDataAccess {

    ///
    /// \class ShowRepository ShowRepository.h implements an abstract class from BusinessLogic lib
    ///
    class ShowRepository : public BMMBusinessLogic::AbstractShowDetailsFetcher
    {
    public:
        ///
        /// \brief Create a new ShowRepository object with predefined movie titles
        /// \since 1.0
        ///
        ShowRepository();


        /// \brief When implemented, returns a list of the theaters that play a certain movie
        /// \param  movieId Movie id selected by the user
        /// \since 1.0
        ///
        virtual vector<BMMBusinessLogic::Theater> findTheaterByMovieId(unsigned int movieId) const override;

        /// \brief When implemented, returns a list of the theaters that play a certain movie
        /// \param movieId Movie id selected by the user
        /// \param theaterId Theater id selected by the user
        /// \since 1.0
        ///
        virtual BMMBusinessLogic::Show findShowByMovieAndTheaterIds(unsigned int movieId, unsigned theaterId) override;

    private:
        vector<BMMBusinessLogic::Seat> createSeatsList();

    private:
        vector<BMMBusinessLogic::Show> m_showsList;
    };
}


#endif // SHOWREPOSITORY_H
