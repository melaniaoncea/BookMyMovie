///
/// \file Booking.h
///
/// \brief Holds Booking related info
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef BOOKING_H
#define BOOKING_H

#include <vector>

#include "Seat.h"

using std::vector;
namespace BMMBusinessLogic {

    ///
    /// \class Booking Booking.h
    ///
    class Booking
    {
    public:
        /// \brief Create a new Booking object
        /// \param[in] bookedSeats Provide a list of booked seats
        /// \since 1.0
        ///
        Booking(vector<BMMBusinessLogic::Seat> bookedSeats) ;

        ///
        /// \brief Return the seats booked in this Booking
        /// \return The vector of Seats
        /// \since 1.0
        ///

        vector<BMMBusinessLogic::Seat> bookedSeats() const;

    private:
        vector<BMMBusinessLogic::Seat> m_bookedSeats;
    };
}

#endif // BOOKING_H
