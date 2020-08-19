///
/// \file Movie.h
///
/// \brief Holds movie related info
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef SHOW_H
#define SHOW_H

#include <vector>
#include <string>

#include <Movie.h>
#include <Seat.h>
#include <Theater.h>
#include <Booking.h>

using std::vector;
using std::string;

namespace BMMBusinessLogic {

    ///
    /// \class Movie Movie.h
    ///

    class Show final
    {
    public:
        /// \brief Create a new Show object
        /// \param[in] movie Pass a Movie object type
        /// \param[in] theater Pass a Theater object type
        /// \since 1.0
        ///
        Show(Movie &movie, Theater &theater);

        /// \brief Add a new booking
        /// \param[in] booking Pass a Booking object type
        /// \since 1.0
        ///
        void addBooking(const Booking& booking);

        /// \brief Get the Movie of this show
        /// \return Returns the Movie played in this show
        /// \since 1.0
        ///
        Movie getMovie() const;

        /// \brief Get the Theater that hosts show
        /// \return Returns the Theater where this show plays
        /// \since 1.0
        ///
        Theater getTheater() const;

        /// \brief Get the Bookings made for this show
        /// \return Returns the current list of bookings made for this show
        /// \since 1.0
        ///
        vector<Booking> getBookings() const;

    private:
        Movie m_movie;
        Theater m_theater;
        vector<Booking> m_bookings;
    };
}

#endif // SHOW_H
