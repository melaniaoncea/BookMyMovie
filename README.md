# BookMyMovie
# Short project description
Book tickets for movies. The user should pick a movie from a list, then choose one of the theaters that is playing it.
Book one or more seats from the available seats of that theater for that movie;

# Development tools and platforms
The project was made to build on two platforms : Windows and Linux/Unix (tested on Ubuntu distribution)

Development tools used:
IDE: QtCreator 4.11.1

a) WINDOWS: V. 10.0
- Compiler: gcc 8.1.0
- Debugger: GDB 8.1.0
- Build process manager: Cmake 13.18 (for ensuring ease of cross platform build)
- Automatic docs generator: Doxygen 1.8.13
- googletest & googlemock: release-1.10.0

b) UBUNTU: V. 18.04
- Compiler: gcc 7.5.0
- Debugger: GDB 8.10
- Build process manager: Cmake 3.18
- Automatic docs generator: Doxygen 1.8.19
- googletest & googlemock: release-1.10.0

# Prerequisites:

1. Minimum Cmake required version: 3.13 - chosen to be able to use certain modern features of the language
2. Have installed a C++ compiler (note: instructions will be given for gcc compiler)
3. Have doxygen installed as Cmake will look for the executable when preparing files for the build

Note: googletest and google mock are not a prerequisite as they are automatically downloaded and built by Cmake if not found installed on the system


# Cloning the project
1. Clone the project in your preferred location
	- Clone address: https://github.com/melaniaoncea/BookMyMovie.git
	- Repository details: The project will be public
  
# Building the project:
- Notes:
  - each app layer (Data Presentation - BMMView, Business Rules - BMMBusinessLogic, Data Persistence - BMMDataAccess) was made as a stand alone project
  - reasons: to make separation between them obvious, to allow an easy way to replace one Data Presentation tool with another (now it has a CLI, later on GUI or REST API projects can include the same Business Rules and Data Persistence to display data in other ways);
  - each project has to be built one by one;
  - the build order is : BMMBusinessLogic, BMMDataAccess, BMMView. 
    - Reason: the first two are exported into a package by Cmake as static libraries, BMMDataAccess depends on finding BMMBusinessLogic package and BMMView depends on finding BMMDataAccess and BMMBusinessLogic packages.
    - Note: configuration file for creating the packages for each static library can be found under:
      - BMMBusinessLogic: projectsourcecode/cmake/BMMBusinessLogicConfig.cmake.in 
      - BMMDataAccess: projectsourcecode/cmake/BMMDataAccessConfig.cmake.in
  - build steps below can be applied for each subproject from the project source directory
    - BMMBusinessLogic ..\BookMyMovie\BMMBusinessLogic
    - BMMDataAccess ..\BookMyMovie\BMMDataAccess
    - BMMView ..\BookMyMovie\BMMView
- can be done in two ways:
	- Build project from the command line
	- Build project from your chosen IDE

- 1. Building the project from the command line - out-of-place build is performed i.e., the source code, libraries, and executables are produced in a directory separate from the source code directory(ies).
	mkdir build-BMMBusinessLogic
	cd build-BMMBusinessLogic
	cmake -G "MinGW Makefiles" \path\to\cloned\repository\BookMyMovie\BMMBusinessLogic
Note: with this option, the doxygen documentation does not appear to be generated
You can generate it manually following these steps:
	- go to the appropriate source directory\docs\Doxyfile.in
	- hardcode INPUT with paths sourceDirectory\src sourceDirectory\include
	- hardcode OUTPUT_DIRECTORY to buildDirectory\docs
	- close file and save changes
	- run doxygen path\to\file\Doxyfile.in
	- the documentation should be found under buildDirectory/docs/doc_doxygen

    
- 2. Build project from your chosen IDE
    e.g. using QTCreator on Windows
      - 2.1 Create Kit(development tool chain): Projects -> Manage Kits -> Add;
      - 2.2 Setup Kit: make sure that you have at least one compiler, debugger, cmake build tool autodetected, if not, add manually one by clicking add in each coresponding subwindow
      - 2.3 Once step 2 is completed, return to Kits subwindow and choose the coresponding tools to use; choose one of the MinGw cmake generators. (I used MinGw Makefiles)
      - 2.4 Go on Welcome tab (left side panel) -> Open project -> projectsourcefiles (location where project was cloned) -> pick CmakeLists.txt of the corresponding project
      - 2.5 Choose the previously set up Kit and configure the build with the desired build path and build name; a default location and name will be generated
      - 2.6 Build the project
      - 2.7 Binaries can be found at path specified as build path;

# Running the project:
- Notes: as BMMBusinessLogic and BMMDataAccess are exported by Cmake as static libraries, the executable can be found under BMMView build folder
- can be done in two ways:
	- run BMMView from the command line
	- run BMMView from your chosen IDE
  
  - 1. run BMMView from the command line
      - cd to BMMView build folder
      - type dir (Windows) / ls (Ubuntu) to see directory contents
      - type:
        - Windows: BMMView.exe/BMMView and press RETURN
        - Ubuntu: BMMView and press RETURN
      - Follow the menu instructions displayed in the command line
      
   - 2. run BMMView from your chosen IDE
    - e.g. using QtCreator : open and build project BMMView from the source files directory -> set project as active project -> press run or Ctrl - R

# More in depth documentation 
- Automatic documentation in html format is generated at build time by using doxygen
- Each static library has its own documentation found under librarybuildfolder\docs\docs\doc_doxygen\html\index.html
- CMake code for generating it can be found under librarysourcefolder\docs\CmakeLists.txt

# Testing
- tests were written using googletest and google mock libraries
- if the libraries are not already installed on the machine building the projects, Cmake will download and build them
- CMake code for generating it can be found under librarysourcefolder\cmake\GoogleTest-CMakeLists.txt.in
- each test suite can be run one by one when the project is opened in QtCreator; Just select the test suite and then run;

# Future improvements
- integrate gcov with Cmake to generate test coverage reports + integrate 
- complete all the functionality
- make multithreaded bookings. To make sure no other threads in the same instance book the same seats at the same time optimistic locking could be used.
  If app can be used as a service for a web app, distributed locking could also be considered since there can be more instances of  the same app.

 
# Some of the C++11 features used
 - initializer lists
 - parenthesized initialization
 - auto data type

# Added also:
1. Project overview diagram
Notes on intended project architecture: 
- The architecture was build by following the recommendations found in  Clean Architecture by Robert C. Martin. 
- It keeps the more stable business rules from BMMBusinessLogic project independent from the other more volatile layers such as BMMView and BMMDataAccess. 
- The architecture also was intended to allow to easily plug in another way to view data (such as GUI app or REST API) or to add a database without affecting BMMBusinessLogic. 
- Dependency inversion at component level is achieved by using interfaces between BMMBusinessLogic and BMMDataAccess;

How to interpret the diagram:
- The grey curved lines = boundaries between application layers
- The arrows show the direction of dependencies
- The dotted line = a separator between what is implemented and what could be implemented
- e.g. = examples of concrete classes in my project that fullfil the role mentioned above
- The colored background = marks what is implemented
  ![resources](./resources/BookMyMovieProjectOverview.svg)
  
2. Samples of some screen captures of the running app.
- they are located in /resources folder
  
