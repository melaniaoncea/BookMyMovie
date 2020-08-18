#ifndef SHOW_H
#define SHOW_H

#include <list>
#include <vector>
#include <string>

using std::list;
using std::vector;
using std::string;

class Movie;
class Theater;
class Booking;
class Seat;

namespace BMMBusinessLogic {

    class Show final
    {
    public:
        Show(Movie &movie, Theater &theater, Booking &booking);

        void addBooking(const Booking& booking);
        vector<vector<string>> getAvailableSeats(const unsigned int movieId, const unsigned int theaterId) const;

    private:
        Movie& m_movie;
        Theater& m_theater;
        list<Booking>& m_bookings;
    };
}

#endif // SHOW_H
