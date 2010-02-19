// -*- C++ -*-
// Implementation of: ????
//
// Copyright (C) 2010 by John Weiss
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
xFOOx_cc__="RCS $Id$";


// Includes
//
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include <boost/test/minimal.hpp>
#include <boost/lexical_cast.hpp>
//#include <boost/something.hpp>

#include "RandomDataSrc.h"
#include "TestException.h"

#include "xFOOx.h"


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
using jpwTools::RandomDataSrc;


//
// Static variables
//


//
// Typedefs
//


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
    unsigned long elSeed(0);

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
            hasSeed = true;
            bool hasLeading_x = ( (((*argIter)[0] & 0xDF) == 'X') ||
                                  (((*argIter)[1] & 0xDF) == 'X') );
            bool hasLeading_nil = (((*argIter)[0] == '0') ||
                                   ((*argIter)[0] == '\\'));
            std::stringstream iss(*argIter);
            if(hasLeading_nil) {
                char trash;
                iss >> trash;
            }
            if(hasLeading_x) {
                char trash;
                iss >> trash;
            }
            iss >> hex >> elSeed;
            //elSeed = lexical_cast<unsigned long>(*argIter);
        }
    }

    // Use the seed if provided.
    if(hasSeed) {
        cout << "Using provided seed: 0x" << hex << elSeed << dec << endl;
        xi.seed(elSeed);
    } else {
        cout << "Seed: 0x" << hex << xi.seed() << dec << endl;
    }
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
    static const char* testSep="%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";

    RandomDataSrc xi;
    // Also sets the seed if provided amongst the cmdline args.
    processParams(argv, xi);


    cout << testSep << endl << endl;
    cout << "Doing test blah blah blah" << endl;

    cout << testSep << endl << endl;
    cout << "Doing next test blah blah blah" << endl;

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
    try {
        return cxx_main(myName, myPath, argVec);
    } catch(FooException& ex) {
        cerr << "Caught Foo: " << ex.what() << endl;
        return 3;
    } catch(exception& ex) {
         cerr << endl << "(Std) Exception caught: \""
              << ex.what() << "\"" << endl;
    } catch(...) {
        cerr << "Unknown exception caught." << endl;
    }
    return -1;
}


/////////////////////////
//
// End
