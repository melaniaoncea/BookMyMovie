#include "ViewController.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

static const int subMenuNoOfOptions {3};

ViewController::ViewController(shared_ptr<BMMBusinessLogic::BusinessLogicController> businessLogicController)
    : m_selectedMovieId(0)
    , m_selectedTheaterId(0)
    , m_businessLogicController(businessLogicController)

{
}

void ViewController::displayMainMenu()
{
    cout << "Welcome to Book My Movie App!" << "\n"
         << "MAIN MENU" << "\n"
         << "Please choose an option from the menu below:" << "\n"
         << " 1 - View all playing movies" << "\n"
         << " 2 - Exit" << endl;
    readUserMenuOption(Menu::MainMenu, 2);
}

void ViewController::readUserMenuOption(Menu menuType, int noOfMenuOptions)
{
    int option;
    cin >> option;

    while (option < 0 || option > noOfMenuOptions) {
        cout << "Not a valid menu option. Please choose one of the options listed above." << endl;
        cin >> option;
    }

    processMenuOption(menuType, option);
}

void ViewController::processMenuOption(Menu menuType, int option)
{
    if (option == 1) {
        switch (menuType)
        {
            case Menu::MainMenu : displayAllMovies(m_businessLogicController->getAllMovies()); break;
            case Menu::MoviesMenu : readSelectedMovie(); break;
            case Menu::TheatersMenu : displayTheathersPlayingMovie(); break;
            case Menu::TheaterSelectionMenu: readSelectedTheater(); break;
            case Menu::SeatsMenu : displayAvailableSeats(); break;
            case Menu::SeatSelectionMenu : readBookedSeats();
            case Menu::EndMenu : displayMainMenu();
        }
    } else if (option == 2 && menuType != Menu::MainMenu && menuType != Menu::EndMenu) {
        displayMainMenu();
    } else if (option == 2 || option == 3) {
        // stop menu looping
        cout << "EXITED" << endl;
    }
}

void ViewController::displaySubmenu(std::string customMenuOption)
{
    cout << "Please choose an option from the menu below:" << "\n"
         << " 1 - " << customMenuOption << "\n"
         << " 2 - Go to Main Menu" << "\n"
         << " 3 - Exit" << endl;
}

void ViewController::displayAllMovies(vector<vector<std::string> > allAvailableMovies)
{
    cout << "Movie Id" << "        "  << "Title" << endl;
    for (const auto & movieDetails : allAvailableMovies) {
        for(const auto & detail : movieDetails) {
            cout << "       " << detail << " ";
        }
        cout << endl;
    }
    cout << endl;
    displaySubmenu("Select movie");
    readUserMenuOption(Menu::MoviesMenu, subMenuNoOfOptions);
}

void ViewController::readSelectedMovie()
{
    cout << "Please select one Id of the movies listed above: " << endl;
    cin >> m_selectedMovieId;
    displaySubmenu("See all theaters where selected movie is playing");
    readUserMenuOption(Menu::TheatersMenu, subMenuNoOfOptions);
}

void ViewController::displayTheathersPlayingMovie()
{
    cout << "Theater Id" << "         "  << "Theater Name" << endl;
    displaySubmenu("Select theater");
    readUserMenuOption(Menu::TheaterSelectionMenu, subMenuNoOfOptions);
}

void ViewController::readSelectedTheater()
{
    cout << "Please select one Id of the theaters listed above: " << endl;
    cin >> m_selectedTheaterId;
    displaySubmenu("See all available seats for the selected movie and theater");
    readUserMenuOption(Menu::SeatsMenu, subMenuNoOfOptions);
}

void ViewController::displayAvailableSeats()
{
    cout << "Available seats: " << endl;
    cout << "s1 " << "s2 " << "s3 " << "s4 " << "s5 " << endl
         << "s6 " << "s7 " << "s8 " << "s9 " << "s10 " << endl;
    displaySubmenu("Book your seats");
    readUserMenuOption(Menu::SeatSelectionMenu, 3);
}

void ViewController::readBookedSeats()
{
    cout << "Please enter the chosen seats: "
         <<  "You can choose one or more seats separated by spaces" << endl;
    string seats;


    cout << seats << "SEATS";

//    for (auto const & seat : bookedSeats) {
//        cout << seat << " " << endl;
//    }

    displayEndMenu();
    readUserMenuOption(Menu::EndMenu, 2);
}

void ViewController::displayEndMenu()
{
    cout << "You have successfully booked your movie seats! You can: " << endl
         << " 1 - Go to the main menu to make another booking" << endl
         << " 2 - Exit" << endl;
}

void ViewController::bookSeats()
{

}
