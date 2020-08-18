///
/// \file Movie.h
///
/// \brief Holds movie related info
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using std::string;
///
/// \brief Global const variable that holds the default Movie Name;
/// It will be used as the root string for m_movieName when the value
/// received in constructor is equal to empty string
///
extern const string defaultMovieNameRoot;

namespace BMMBusinessLogic {


    ///
    /// \class Movie Movie.h
    ///

    class Movie final
    {
    public:
        /// \brief Create a new Movie object
        /// \param[in] movieName Insert name of the movie. If given an empty string, a default name will be constructed
        /// \attention Default movie name format  defaultMovieNameRoot + movieId e.g., NewMovie1
        /// \warning The use of default movie name format might result in duplicated movie names
        /// \since 1.0
        ///

        explicit Movie(string &movieName);

        ///
        /// \brief Return the Movie Id
        /// \return The Id int, e.g., 1. [from 1 to max unsigned int]
        /// \since 1.0
        ///
        unsigned int movieId() const;

        ///
        /// \brief Return the Movie name
        /// \return The Movie name string, e.g., "Abc". Never returns an empty string;
        /// \since 1.0
        /// \see Movie(string &movieName)
        ///
        string movieName() const;

    private:
        static unsigned int nextId;
        const unsigned int m_movieId;
        string m_movieName;
    };

}

#endif // MOVIE_H
