#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#include<BusinessLogicController.h>

#include <memory>

using std::shared_ptr;

enum class Menu {MainMenu,
                 MoviesMenu,
                 TheatersMenu,
                 TheaterSelectionMenu,
                 SeatsMenu,
                 SeatSelectionMenu,
                 EndMenu};

class ViewController
{
public:
    ViewController(shared_ptr<BMMBusinessLogic::BusinessLogicController> businessLogicController);
    void displayMainMenu();

private:
    void readUserMenuOption(Menu menuType, int noOfMenuOptions);
    void processMenuOption(Menu menuType, int option);
    void displayAllMovies(vector<vector<std::string>> allAvailableMovies);
    void displaySubmenu(std::string customMenuOption);
    void readSelectedMovie();
    void displayTheatersMenu();
    void displayTheathersPlayingMovie();
    void readSelectedTheater();
    void displayAvailableSeats();
    void readBookedSeats();
    void displayEndMenu();
    void bookSeats();


private:
    unsigned int m_selectedMovieId;
    unsigned int m_selectedTheaterId;
    shared_ptr<BMMBusinessLogic::BusinessLogicController> m_businessLogicController {nullptr};
};

#endif // VIEWCONTROLLER_H
