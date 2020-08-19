#include "Booking.h"

BMMBusinessLogic::Booking::Booking(vector<BMMBusinessLogic::Seat> bookedSeats)
    : m_bookedSeats(bookedSeats)
{

}

vector<BMMBusinessLogic::Seat> BMMBusinessLogic::Booking::bookedSeats() const
{
    return m_bookedSeats;
}

