#include "Theater.h"
#include <Seat.h>

const string defaultTheaterNameRoot {"DefaultTheaterName"};
unsigned int BMMBusinessLogic::Theater::nextTheaterId {1};

 BMMBusinessLogic::Theater::Theater(string &theaterName, vector<Seat> theaterSeatsList)
    : m_theaterId(nextTheaterId++)
    , m_theaterName(theaterName.empty() ? defaultTheaterNameRoot + std::to_string(m_theaterId)
                                        : theaterName)
    , m_theaterSeatsList(theaterSeatsList)
{
}

unsigned int  BMMBusinessLogic::Theater::theaterId() const
{
    return m_theaterId;
}

string  BMMBusinessLogic::Theater::theaterName() const
{
    return m_theaterName;
}

vector<BMMBusinessLogic::Seat> BMMBusinessLogic::Theater::theaterSeatsList() const
{
    return m_theaterSeatsList;
}
