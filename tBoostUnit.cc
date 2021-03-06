// -*- C++ -*-
// Unit Tests for: ????
//
// Copyright (C) 2014 by John Weiss
// This program is free software; you can redistribute it and/or modify
// it under the terms of the Artistic License, included as the file
// "LICENSE" in the source code archive.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
// You should have received a copy of the file "LICENSE", containing
// the License John Weiss originally placed this program under.
//
static const char* const
xFOOx_cc__="$Id$";


// Includes
//
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include <boost/lexical_cast.hpp>
//#include <boost/something.hpp>

#include "RandomDataSrc.h"

#include "xFOOx.h"

#include "UnitTestTools.h"


//
// Using Decls.
//
using std::string;
using std::vector;
using std::exception;
using std::cerr;
using std::cout;
using std::endl;
using std::flush;
using jpwTools::random::RandomDataSrc;

using namespace jpwTools::unitTesting;


//
// Typedefs
//


//
// Static variables
//


namespace {
};


//////////////////////////////////////////////////////////////////////////////

//
// Utility Class:  TestFoo
//


//////////////////////////////////////////////////////////////////////////////

//
// General Function Definitions
//


void processParams(const vector<string>& argv, RandomDataSrc& xi)
{
    bool hasSeed(false);

    // This is just a crude sample. You can process args however you wish.
    typedef vector<string>::const_iterator vec_iter_t;
    for(vec_iter_t argIter=argv.begin(); argIter!=argv.end(); ++argIter)
    {
        if((*argIter == "--seed") || (*argIter == "-s")) {
            ++argIter;
            if(argIter == argv.end()) {
                // Error:
                cerr << "Error:  --seed passed without a value" << endl;
                return;
            } // else

            // Parse, then check for incomplete or failed reads:
            if( xi.parse_seed(*argIter) ) {
                hasSeed = true;
            } else {
                cout << "ERROR!  Failed to parse seed value:  \""
                     << (*argIter) << "\"" << endl
                     << "Using autogenerated seed instead..." << endl;
            }
        }
    }

    // Use the seed if provided.
    cout << (hasSeed ? "Using provided seed:  " : "Seed:  ")
         << xi.print_seed() << endl;
}


/////////////////////////

//
// Functions "tst_main()" and "cxx_main()"
//


// This is where all of your main handling should go.
int cxx_main(const string& myName,
             const string& myPath,
             const vector<string>& argv)
{
    RandomDataSrc xi;
    // Also sets the seed if provided amongst the cmdline args.
    processParams(argv, xi);


    markTestStart("testName or testFnName()");
    cout << "Doing test blah blah blah" << endl;

    markTest("testName or testFnName()");
    cout << "Doing next test blah blah blah" << endl;

    markTestEnd();
    return 0;
}


int test_main(int argc, char* argv[])
{
    // Split off the name of the executable from its path.
    string myName(argv[0]);
    string::size_type last_pathsep = myName.find_last_of('/');
    string myPath;
    if(last_pathsep != string::npos) {
        myPath = myName.substr(0, last_pathsep+1);
        myName.erase(0, last_pathsep+1);
    }

    // Build a vector of strings for the arg list, which is much easier to
    // handle than the old-style char** argv.
    vector<string> argVec;
    argVec.reserve(argc);
    for(int i=1; i < argc; ++i) {
        argVec.push_back(string(argv[i]));
    }

    // Call cxx_main(), which is where almost all of your code should go.
#if GUARD_AGAINST_UNSUPPORTED_EXCEPTIONS_OR_DELETE_ME
    try {
        return cxx_main(myName, myPath, argVec);
    } catch(FooException& ex) {
        cerr << "Caught Foo: " << ex.what() << endl;
        return 3;
    }
    // Don't catch generic exceptions; let the Boost Test Framework do that.
    return -1;
#else // Delete if you want/need to guard against certain exceptions.
    // Don't catch exceptions; let the Boost Test Framework do that.
    return cxx_main(myName, myPath, argVec);
#endif
}


/////////////////////////
//
// End
