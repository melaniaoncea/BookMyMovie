#include "Show.h"

void BMMBusinessLogic::Show::addBooking(const BMMBusinessLogic::Booking & booking)
{

}

vector<BMMBusinessLogic::Booking> BMMBusinessLogic::Show::getBookings() const
{
    return m_bookings;
}

BMMBusinessLogic::Theater BMMBusinessLogic:: Show::getTheater() const
{
    return m_theater;
}

BMMBusinessLogic::Movie BMMBusinessLogic::Show::getMovie() const
{
    return m_movie;
}
