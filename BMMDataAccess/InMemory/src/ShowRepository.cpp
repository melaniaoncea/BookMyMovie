#include "ShowRepository.h"
#include "MovieRepository.h"
#include "Theater.h"
#include "Show.h"

BMMDataAccess::ShowRepository::ShowRepository()
{
    // get the list of all movies
    BMMDataAccess::MovieRepository movieRepository;
    vector<BMMBusinessLogic::Movie> allMovies = movieRepository.getAllMovies();

    vector<BMMBusinessLogic::Seat> seatList = createSeatsList();

    string theaterName = {"Reel Cinema"};
    BMMBusinessLogic::Theater theater1 {theaterName, seatList};

    theaterName = "Vox Cinema";
    BMMBusinessLogic::Theater theater2 {theaterName, seatList};

    theaterName = "Novo Cinema";
    BMMBusinessLogic::Theater theater3 {theaterName, seatList};



}

vector<BMMBusinessLogic::Seat> BMMDataAccess::ShowRepository::createSeatsList()
{
    vector<BMMBusinessLogic::Seat> result;

    string seatName {"a1"};
    BMMBusinessLogic::Seat seat1 {seatName};
    result.push_back(seat1);

    seatName = "a2";
    BMMBusinessLogic::Seat seat2 {seatName};
    result.push_back(seat2);

    seatName = "a3";
    BMMBusinessLogic::Seat seat3 {seatName};
    result.push_back(seat3);

    seatName = "a4";
    BMMBusinessLogic::Seat seat4 {seatName};
    result.push_back(seat4);

    seatName = "a5";
    BMMBusinessLogic::Seat seat5 {seatName};
    result.push_back(seat5);

    seatName = "b1";
    BMMBusinessLogic::Seat seat6 {seatName};
    result.push_back(seat6);

    seatName = "b2";
    BMMBusinessLogic::Seat seat7 {seatName};
    result.push_back(seat7);

    seatName = "b3";
    BMMBusinessLogic::Seat seat8 {seatName};
    result.push_back(seat8);

    seatName = "b4";
    BMMBusinessLogic::Seat seat9 {seatName};
    result.push_back(seat9);

    seatName = "b5";
    BMMBusinessLogic::Seat seat10 {seatName};
    result.push_back(seat10);

    seatName = "c1";
    BMMBusinessLogic::Seat seat11 {seatName};
    result.push_back(seat11);

    seatName = "c2";
    BMMBusinessLogic::Seat seat12 {seatName};
    result.push_back(seat12);

    seatName = "c3";
    BMMBusinessLogic::Seat seat13 {seatName};
    result.push_back(seat13);

    seatName = "c4";
    BMMBusinessLogic::Seat seat14 {seatName};
    result.push_back(seat14);

    seatName = "c5";
    BMMBusinessLogic::Seat seat15 {seatName};
    result.push_back(seat15);

    seatName = "d1";
    BMMBusinessLogic::Seat seat16 {seatName};
    result.push_back(seat16);

    seatName = "d2";
    BMMBusinessLogic::Seat seat17 {seatName};
    result.push_back(seat17);

    seatName = "d3";
    BMMBusinessLogic::Seat seat18 {seatName};
    result.push_back(seat18);

    seatName = "d4";
    BMMBusinessLogic::Seat seat19 {seatName};
    result.push_back(seat19);

    seatName = "d5";
    BMMBusinessLogic::Seat seat20 {seatName};
    result.push_back(seat20);

    return result;
}
