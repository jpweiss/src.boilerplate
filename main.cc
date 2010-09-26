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
#include <exception>

#include <boost/program_options.hpp>
//#include <boost/something.hpp>

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


//
// Static variables
//


//
// Typedefs
//


/////////////////////////

//
// General Function Definitions
//


/////////////////////////

//
// Function:  "process_opts()"
//


void process_opts(const string& myName,
                  int argc, char* argv[],
                  boost::program_options::variables_map& optMap)
{
    using boost::program_options;

    // // // // N.B.:
    // Change the signature of this fn. to take a struct containing all of
    // your program options.  You can then pass the address of the individual
    // struct members to the value<T>(...) operators.
    // 
    // - It's possible to allow "unregistered" options on the cmdline.  See
    //   the Boost docs for details.

    options_description cmdlineOpts("Options:");
    bool show_help(false);
    bool show_help_config(false);
    string cfgfile;

    // About the Documentation String:
    // - Long lines are automatically wrapped.
    // - It can contain '\n' chars.
    // - Any space following a '\n' indents the first line accordingly, but
    //   not any wrapped lines.
    // - The '\t' character is always removed.
    // - A '\t' character in the first "line" adds extra indentation to all
    //   subsequently-wrapped lines.  It must appear near the start of the
    //   line.  (Usually, you'll put it after the first word or before the
    //   second.)

    // BEGIN:  Define the Commandline Options
    cmdlineOpts.add_options()
        ("help,h", bool_switch(&show_help), "This message.")
        ("verbose,v", value<int>()->default_value(0)->zero_tokens(),
         "Make this program more verbose.")
        ("config", value<string>(&cfgfile),
         "Configuration file, containing additional options.\n\n")
        ("help-config", bool_switch(&show_help_config),
         "Additional information about the configuration file.")
        ;
    // END:  Define the Commandline Options

    // // // REMOVE_IF_UNUSED:
    // Define the Positional Parameters, which must be "bound" to a
    // commandline option.
    positional_options_description posnParams;
    options_description posnParamOpts("Positional Parameters");

    // BEGIN:  Define the Positional Parameters
    posnParamOpts.add_options()
        ("pp1", "The description of the first positional parameter.")
        ("pp2", "The description of the second positional parameter.")
        ("pp_list::all_remaining",
         // value< std::vector<std::string> >,
         "The description of the remaining positional parameters.")
        ;
    posnParams.add("pp1", 1);
    posnParams.add("pp2", 1);
    posnParams.add("pp_list::all_remaining", -1);
    // END:  Define the Positional Parameters

    // Add the positional parameters to the commandline options.
    cmdlineOpts.add(posnParamOpts);
    // // // REMOVE_IF_UNUSED: END

    // // // REMOVE_IF_UNUSED: BEGIN
    options_description cfgOpts("ConfigFile Variables");
    // BEGIN:  Define the Configfile Options
    cfgOpts.add_options()
        ("example", "An example")
        ;
    // END:  Define the Configfile Options
    // // // REMOVE_IF_UNUSED: END

    // // // REMOVE_IF_UNUSED: BEGIN
    options_description sharedOpts;
    // BEGIN:  Define the Configfile Options
    sharedOpts.add_options()
        ("example2", "An example")
        ;
    // END:  Define the Configfile Options

    cfgOpts.add(sharedOpts);
    cmdlineOpts.add(sharedOpts);
    // // // REMOVE_IF_UNUSED: END


    // Parse the commandline
    store(parse_command_line(argc,argv, cmdlineOpts),optMap);
    // // // OR:
    command_line_parser complexParser(argc, argv);
    complexParser.options(cmdlineOpts);
    complexParser.positional(posnParams);
    store(complexParser.run(), optMap);
    // // // REMOVE_IF_UNUSED: BEGIN
    if(cfgfile.empty()) {
        // Error message goes here.
        // Maybe throw an exception?
    } else {
        std::ifstream cfg_ifs(cfgfile);
        if(!cfg_ifs) {
            string errmsg("Invalid/unknown configuration file: \"");
            errmsg += cfgfile;
            errmsg += '"';
            throw invalid_option_value(errmsg);
        }
        try {
            store(parse_config_file(cfg_ifs, cfgOpts), optMap);
            cfg_ifs.close();
        } catch(std::ios_base::failure& ex) {
            string errmsg("Failed to read configuration file: \"");
            errmsg += cfgfile;
            errmsg += "\"\nReason:\n\t\"";
            errmsg += ex.what();
            errmsg += '"';
            throw invalid_option_value(errmsg);
        }
    }
    // // // REMOVE_IF_UNUSED: END
    notify(vm);

    // Common Options Handling.
    //

    // // // // // REMOVABLE_NOTE:
    // You can actually have the boost::program_options library do some of this
    // for you by using 'value<T>()->notifier(function1<void, const T&>)'.
    // See the Boost documentation for details.
    //
    // Note:  By using a placeholder options_description object, we can
    // control which options we describe using "--help".
    // This also lets us create "--help-all" or "--help-config" output.

    // --help:
    //     This is easy:  Just send the appropriate options_description to
    //     cout.
    //
    // We will still need to hand-write the traditional "usage: ..." line.
    if(show_help)
    {
        cout << "usage: " << myName
             << " [options] [posn params]"
             << endl << endl
             << cmdlineOpts
             << endl;
        exit(0);
    }

    // // // REMOVE_IF_UNUSED: BEGIN
    // --help-config:
    //     Additional help about the configuration file.
    if(show_help_config)
    {
        cout << myName << " - Configuration File:"
             << endl << endl
             << "Settings in the configuration file are of the form:"
             << endl
             << "    settingName=value"
             << endl
             << "Multiple settings can be grouped into sections.  "
             << "Each option in a group"
             << endl
             << "has the form \"sectionName.settingName\", and appears in "
             << "the configuration "
             << endl
             << "file as follows:"
             << endl
             << "    [sectionName]"
             << endl
             << "    settingName=value"
             << endl << endl
             << "The comment delimiter is '#' and may appear anywhere "
             << "on a line."
             << endl << endl
             << cfgOpts
             << endl;
        exit(0);
    }
    // // // REMOVE_IF_UNUSED: END

    // Validate other options (i.e. relationships between options) here.
}


/////////////////////////

//
// Functions "main()" and "cxx_main()"
//


// This is where all of your main handling should go.
int cxx_main(const string& myName,
             const string& myPath,
             const boost::program_options::variables_map& optMap)
{
    // How to retrieve entries from 'optMap':
    //     optMap["option"].as<type>()
    //
    // To check if the option is unset or wasn't passed:
    //     optMap["option"].empty()
    //
    // To check if an option with a default value wasn't passed:
    //     optMap["option"].defaulted()
}


int main(int argc, char* argv[])
{
    // Split off the name of the executable from its path.
    string myName(argv[0]);
    string::size_type last_pathsep = myName.find_last_of('/');
    string myPath;
    if(last_pathsep != string::npos) {
        myPath = myName.substr(0, last_pathsep+1);
        myName.erase(0, last_pathsep+1);
    }

    // Call cxx_main(), which is where almost all of your code should go.
    try {
        boost::program_options::variables_map& optionsMap;
        process_opts(myName, argc, argv, optionsMap);

        return cxx_main(myName, myPath, argVec);
    } catch(FooException& ex) {
        cerr << "Caught Foo: " << ex.what() << endl;
        return 3;
    } catch(boost:program_options::error& ex) {
        cerr << "Error while parsing program options: " << ex.what()
             << endl << endl
             << "Rerun \"" << myName << " --help\" for usage."
             << endl;
        return 1;
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
// Older Versions of "main()" and "cxx_main()"
// Rever to these if you're not/can't use Boost. 
//

#ifdef NOT_USING_BOOST__PROGRAM_OPTIONS
// This is where all of your main handling should go.
int cxx_main(const string& myName,
             const string& myPath,
             const vector<string>& argv)
{
}


int main(int argc, char* argv[])
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
#endif


/////////////////////////
//
// End
