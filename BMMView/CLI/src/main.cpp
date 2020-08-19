#include <AbstractAllMoviesFetcher.h>
#include <MovieRepository.h>
#include <BusinessLogicController.h>
#include "ViewController.h"
#include <AbstractShowDetailsFetcher.h>
#include <ShowRepository.h>
#include <ShowProvider.h>

using namespace BMMBusinessLogic;
using namespace BMMDataAccess;

int main() {
    shared_ptr<AbstractAllMoviesFetcher> allMovieFetcher (new MovieRepository());
    shared_ptr<BusinessLogicController> businessLogicController (new BusinessLogicController(allMovieFetcher));
    ViewController viewController {businessLogicController};
    viewController.displayMainMenu();
    return 0;
}
