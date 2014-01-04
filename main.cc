// -*- C++ -*-
// Implementation of: ????
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
#include <exception>

//#include <boost/something.hpp>

//TODO// Note:  The guts of the ProgramOptions helper code now resides in its
//TODO//        own class.  You will need to do one of the following:
//TODO//        1. Use -ljpwTools and -I$JPWLIB_BASE/include
//TODO//        2. Symlink to the following files in $JPWLIB_BASE/src:
//TODO//           - tracing/Trace.{h,cc}
//TODO//           - tracing/LibTrace.h
//TODO//           - boost_helpers/ProgramOptions_Base.{h,cc}
//TODO//           You'll need to add the two *.cc files to your Makefile.
//TODO//        3. Like #2, but copy the files instead of symlinking to them.
#include "ProgramOptions_Base.h"
#include "xFOOx.h"

//TODO// Uncomment or remove, depending on what you need.
//#include "config.h"


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


//TODO// Uncomment, modify, or remove as needed.
/*
namespace g__ {
 const string CopyrightInfo="Copyright (C) 2014 by John Weiss\n"
     "This program is free software; you can redistribute it and/or modify\n"
     "it under the terms of the Artistic License.\n"
     "\n"
     "This program is distributed in the hope that it will be useful,\n"
     "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
     "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
     "\n"
     "Sourceforge project page:\n"
     "    \"" PACKAGE_URL "\"";
};
*/


//
// Typedefs
//


/////////////////////////

//
// Class:  ProgramOptions
//


// NOTE:
//
// When using boost::program_options, you need to compile or link using:
//   '-lboost_program_options-mt'
// (Check your Boost build to see if you have to remove the '-mt' suffix.)
class ProgramOptions : public jpwTools::boost_helpers::ProgramOptions_Base
{
    typedef jpwTools::boost_helpers::ProgramOptions_Base Base_t;
public:
    // Member variables for individually storing program options.
    //   ADD HERE:
    /*
    example_type myExample;
     */

    // C'tor
    //
    // There are a few different ways you can use the base-class.
    //
    explicit ProgramOptions(const string& theProgramName)
        : Base_t(theProgramName)
    {
        m__docDetails_FakeOption[2] = 0;
    }

    // Implement this function (see below).
    void defineOptionsAndVariables();

    // Implement this function (below), or remove this fn.
    bool validateParsedOptions();
};


/////////////////////////

//
// ProgramOptions Member Functions
//


// Define your commandline options in this function.
//
// The options "--help", "--verbose", "--config", and "--help-config" will
// be defined for you.  No need to put them in here.
void ProgramOptions::defineOptionsAndVariables()
{
    using namespace boost::program_options;

    //
    // Commandline-only Options
    //

    //-----
    // About the Documentation String:
    //
    // - Long lines are automatically wrapped.
    // - It can contain '\n' chars.
    // - Any space following a '\n' indents the first line accordingly, but
    //   not any wrapped lines.
    // - The '\t' character is always removed.
    // - A '\t' character in the first "line" adds extra indentation to all
    //   subsequently-wrapped lines.  Its position marks the position of the
    //   left margin for the wrapped lines.
    //-----

    addOpts()
        ("exampleOpt,e", "Documentation of the --exampleOpt.")
        //("ex2", value<example_type>(&myExample)
        // "Example with a specific storage variable.")
        ("ex3", value<int>()->default_value(42),
         "Example with a default value and fixed data type.")
        //("xil", value< <std::vector<int> >()->compositing(),
        // "Example of a \"list option\".  Specifying \"--xil\" multiple "
        // "times just adds another element to the list.")
        ;

    // Define the "Hidden" Commandline Parameters
    //
    // These options will not appear in the "usage" message.

    /*
    addOpts(Base_t::HIDDEN)
        ("secretExampleOpt,s", bool_switch(&secretExampleSwitch),
         "Documentation of the --secretExampleOpt.\t"
         "This example shows how to define a \"boolean switch\" option."
         )
        ("ex2",
         value<int>(&m_ex2)->default_value(-1)
         ->implicit_value(42)->zero_tokens(),
         "Example of how to have an option that takes a value, but doesn't "
         "_require_ it.\n"
         "In this example, the variable \"m_ex2\" has the value '-1' if the "
         "option isn't specified on the cmdline.  Specifying \"--ex2\" "
         "sets \"m_ex2\" to '42'.  Specifying \"--ex2=12345\" sets "
         "\"m_ex2\" to '12345', the value used.")
        ("ex3", value<int>(&m_ztEx)->zero_tokens(),
         "Like \"--ex2\", but without a default value or an implicit "
         "value.  If you pass \"--ex3\" on the commandline, \"m_ztEx\" "
         "isn't set.  Instead, you'll have to use "
         "'progOptInst[\"ex3\"].empty()' to determine if it's set (where "
         "'progOptInst' is a ProgramOptions object).")
        ;
    */

    //
    // The Positional Parameters:
    //

    /*
    addPosnParam("pp1",
                 "The description of the first positional parameter.");
    addPosnParam("pp2",
                 "The description of the second positional parameter.");
    addPosnParam("pp_list::all_remaining",
                 //value< std::vector<std::string> >,
                 "The description of the remaining positional parameters.",
                 -1);
    */

    //
    // The Configuration File Variables:
    //

    /*
    addCfgVars()
        ("example", "An example")
        ("group1.example",
         "An example of a configfile variable in a group.  You can specify "
         "the group using ini-file syntax, or you can use Java-style "
         "synax for the group+variable name.")
        ("oddname.group.foo",
         "Here, if you used ini-file style groups, you'd have to specify "
         "[oddname.group] as the group heading.  Cfgfile vars never have "
         "a '.' in their names, unless you're using Java-style syntax.")
        ;
    */

    //
    // Configuration File Variables that can also be passed as Commandline
    // Options:
    //

    /*
    addCfgVars(Base_t::SHARED)
        ("sharedEx", "A common opt.")
        ;

    // Can also do this:
    //addOpts(Base_t::SHARED)
    //    ("sharedEx", "A common opt.")
    //    ;
    */

    //
    // Define the additional/verbose/enhanced configuration file
    // documentation:
    //

    addConfigHelpDetails("\n"
                         "* \tHeading\n"
                         "\n  \t" // Line end/begin boilerplate
                         "Some stuff about one or more of the config "
                         "file variables."
                         "\n");
}


// Performs more complex program option validation.
//
// Remove this override if you don't need it.
bool ProgramOptions::validateParsedOptions()
{
    // Example:  Handle a missing configuration file.
    // Delete or modify as needed.
    if(m__cfgfile.empty()) {
        throw boost::program_options::invalid_option_value(
            "No configuration file specified!  \"--config\" is "
            "a required option.");
    }
}


/////////////////////////

//
// General Function Definitions
//


/////////////////////////

//
// Functions "main()" and "cxx_main()"
//


// This is where all of your main handling should go.
int cxx_main(const string& myName,
             const string& myPath,
             const ProgramOptions& opts)
{
    // How to retrieve entries from 'opts':
    //     opts["option"].as<type>()
    //
    // To check if the option is unset or wasn't passed:
    //     opts["option"].empty()
    //
    // To check if an option with a default value wasn't passed:
    //     opts["option"].defaulted()
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
        ProgramOptions myOpts(myName /*, (ACPATH_SYSCONFDIR "/")*/);
        //myOpts.setVersion(PACKAGE_VERSION, g__::CopyrightInfo);

        bool parsedOk = myOpts.parse(argc, argv);
        //TODO// This next block may be required to prevent the program from
        //TODO// segfaulting when options are missing.  Or it might not.  Test
        //TODO// your program with and without it.
        /*
        if(!parsedOk) {
            cerr << "Fatal Error:  "
                 << endl
                 << "Unable to parse commandline arguments "
                 << "and/or configuration file."
                 << endl
                 << endl
                 << "Cannot continue."
                 << endl;
            return 1;
        }
        */

        return cxx_main(myName, myPath, myOpts);
    } catch(FooException& ex) {
        cerr << "Caught Foo: " << ex.what() << endl;
        return 3;
    } catch(boost::program_options::duplicate_option_error& ex) {
        cerr << "Fatal Internal Programming Error:  "
             << endl
             << ex.what()
             << endl << endl;
        return 9;
    } catch(boost::program_options::error& ex) {
        cerr << "Error while parsing program options: " << ex.what()
             << endl << endl
             << "Rerun as \"" << myName << " --help\" for usage."
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
// End
