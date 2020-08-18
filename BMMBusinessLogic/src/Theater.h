///
/// \file Theater.h
///
/// \brief Holds theater related info
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef THEATER_H
#define THEATER_H

#include <string>
#include <list>

using std::string;
using std::list;

///
/// \brief Global const variable that holds the default theater name;
/// It will be used as the root string for m_theaterName when the value
/// received in constructor is equal to empty string
///
extern const string defaultTheaterNameRoot;

namespace BMMBusinessLogic {

    ///
    /// \class Theater Theater.h
    ///

    class Seat;

    class Theater final
    {
    public:
        /// \brief Create a new Theater object
        /// \param[in] theaterName Insert name of the theater. If given an empty string, a default name will be constructed
        /// \param[in] theaterSeatsList Insert a non empty theater seats list
        /// \attention Default theater name format  defaultTheaterNameRoot + theaterId e.g., DefaultTheaterName1
        /// \warning The use of default theater name format might result in duplicated theather names
        /// \since 1.0
        ///
        Theater(string &theaterName, list<BMMBusinessLogic::Seat> theaterSeatsList);

        ///
        /// \brief Return the theater Id
        /// \return The Id int, e.g., 1. [from 1 to max unsigned int]
        /// \since 1.0
        ///
        unsigned int theaterId() const;

        ///
        /// \brief Return the theater name
        /// \return The theater name string, e.g., "Reel Cinema". Never returns an empty string;
        /// \since 1.0
        /// \see Theater(string &theaterName, list<BMMBusinessLogic::Seat> theaterSeatsList);
        ///
        string theaterName() const;

        ///
        /// \brief Return the theater seats list
        /// \return The theater seats list list<Seats>
        /// \since 1.0
        ///
        list<BMMBusinessLogic::Seat> theaterSeatsList() const;

    private:
        static unsigned int nextTheaterId;
        unsigned int m_theaterId;
        string m_theaterName;
        list<BMMBusinessLogic::Seat> m_theaterSeatsList;

    };
}

#endif // THEATER_H
