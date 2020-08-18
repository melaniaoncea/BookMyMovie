///
/// \file AbstractAllTheatersFetcher.h
///
/// \brief Interface for DataAccess layer
///
/// \author Melania Oncea
/// \date 2020 08 17
/// \since 1.0
///
/// Copyright (c) 2020, Melania Oncea. All rights reserved.
///

#ifndef ABSTRACTALLTHEATERSFETCHER_H
#define ABSTRACTALLTHEATERSFETCHER_H

#include<list>
#include<string>

using std::list;
using std::string;
namespace BMMBusinessLogic {
    ///
    /// \class AbstractAllTheatersFetcher AbstractAllTheatersFetcher.h
    ///
    class AbstractAllTheatersFetcher {
    public:
        AbstractAllTheatersFetcher() = default;
        virtual ~AbstractAllTheatersFetcher() = default;

        /// \brief When implemented, returns a list of theater names
        /// \since 1.0
        ///
        virtual  list<string> getAllTheaterNames() const = 0;

    };
}

#endif // ABSTRACTALLTHEATERSFETCHER_H
