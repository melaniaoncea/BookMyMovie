#include "ShowRepository.h"
#include "MovieRepository.h"
#include "Theater.h"
#include "Show.h"

BMMDataAccess::ShowRepository::ShowRepository()
{
    // get the list of all movies
    BMMDataAccess::MovieRepository movieRepository;
    vector<BMMBusinessLogic::Movie> allMovies = movieRepository.getAllMovies();

    // generate the seat list for a theatre assuming that they are all equal to 20 seats
    vector<BMMBusinessLogic::Seat> seatList = createSeatsList();

    // create theaters
    string theaterName = {"Reel Cinema"};
    BMMBusinessLogic::Theater theater1 {theaterName, seatList};

    theaterName = "Vox Cinema";
    BMMBusinessLogic::Theater theater2 {theaterName, seatList};

    theaterName = "Novo Cinema";
    BMMBusinessLogic::Theater theater3 {theaterName, seatList};

    // create shows
    BMMBusinessLogic::Show show1 {allMovies.at(0), theater1};
    m_showsList.push_back(show1);

    BMMBusinessLogic::Show show2 {allMovies.at(0), theater2};
    m_showsList.push_back(show2);

    BMMBusinessLogic::Show show3 {allMovies.at(0), theater3};
    m_showsList.push_back(show3);

    BMMBusinessLogic::Show show4 {allMovies.at(1), theater1};
    m_showsList.push_back(show4);

    BMMBusinessLogic::Show show5 {allMovies.at(1), theater3};
    m_showsList.push_back(show5);

    BMMBusinessLogic::Show show6 {allMovies.at(2), theater1};
    m_showsList.push_back(show6);

}

vector<BMMBusinessLogic::Theater> BMMDataAccess::ShowRepository::findTheaterByMovieId(unsigned int movieId) const
{
    // search for theaters that play the movie
    vector<BMMBusinessLogic::Theater> theaters;

    for (auto & show : m_showsList) {
        if (show.getMovie().movieId() == movieId) {
            theaters.push_back(show.getTheater());
        }
    }

    return theaters;
}

BMMBusinessLogic::Show BMMDataAccess::ShowRepository::findShowByMovieAndTheaterIds(unsigned int movieId, unsigned theaterId)
{
    // search for shows with that movie id and theater id
    // in reality the same theater might play the same movie twice a day
    // for our purposes, we assume that there is only one matching show
    // no show found should be handled better;

    string movieName {" "};
    BMMBusinessLogic::Movie movie {movieName};
    vector<BMMBusinessLogic::Seat> seatList = this->createSeatsList();
    BMMBusinessLogic::Theater theater{movieName, seatList};

    BMMBusinessLogic::Show emptyShow {movie, theater};

    for (auto & show : m_showsList) {
        if (show.getMovie().movieId() == movieId && show.getTheater().theaterId() == theaterId) {
            return show;
        }
    }

    return emptyShow;
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
