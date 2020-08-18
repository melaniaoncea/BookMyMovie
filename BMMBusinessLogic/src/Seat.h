///
/// \file Seat.h
///
/// \brief Holds movie related info
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef SEAT_H
#define SEAT_H

#include <string>

using std::string;

extern const string defaultSeatNameRoot;

namespace BMMBusinessLogic {

    ///
    /// \class Seat Seat.h
    ///

    class Seat
    {
    public:
        /// \brief Create a new Seat object
        /// \param[in] seatName Insert name of the seat. If given an empty string, a default name will be constructed
        /// \attention Format of default name  defaultSeatNameRoot + current value of nextId e.g., "DefaultSeatName1".
        /// \warning To avoid duplicate seat names, do not use the default format when creating your Seat objects
        /// \since 1.0
        ///
        explicit Seat(string &seatName);

        ///
        /// \brief Return the seat name
        /// \return The seat name string, e.g., "a1". Never returns an empty string;
        /// \since 1.0
        /// \see Seat(string &seatName)
        ///
        string seatName() const;

    private:
        static unsigned int nextId;
        string m_seatName;
    };

}

#endif // SEAT_H
