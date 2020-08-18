#include "Seat.h"

const string defaultSeatNameRoot {"DefaultSeatName"};
unsigned int BMMBusinessLogic::Seat::nextId {1};

BMMBusinessLogic::Seat::Seat(std::string & seatName)
    :m_seatName(seatName.empty() ? defaultSeatNameRoot + std::to_string(nextId++)
                                 : seatName)
{
}

std::string BMMBusinessLogic::Seat::seatName() const
{
    return m_seatName;
}
