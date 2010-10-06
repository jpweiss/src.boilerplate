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
#include <fstream> // Required for reading config files.
#include <sstream> // Required by --help-config.
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
// Class:  ProgramOptions
//


// NOTE:
//
// When using boost::program_options, you need to compile or link using:
//   '-lboost_program_options-mt'
// (Check your Boost build to see if you have to remove the '-mt' suffix.)
class ProgramOptions
{
    // Internal Member Variables
    // No User Serviceable Parts
    string m__progName;
    bool m__showHelp;
    bool m__showHelpConfig;
    string m__cfgfile;
    boost::program_options::positional_options_description m__posnParams;
    boost::program_options::options_description m__posnParamOpts;
    boost::program_options::variables_map m__opts;
    boost::program_options::options_description m__cmdlineOpts;
    boost::program_options::options_description m__hiddenCmdlineOpts;
    boost::program_options::options_description m__sharedOpts;
    boost::program_options::options_description m__cfgfileOpts;

public:
    // Member variables for individually storing program options.
    //   ADD HERE:
    /*
    example_type myExample;
     */

    // C'tor
    //
    // Usually, you can get away with omitting your public member variables.
    // It's better to use the:
    //
    //     value<T>(m__myMemberVar)->default_value(...)
    //
    // ...arg in the 'add_options()' call when defining your options.
    //
    ProgramOptions(const string& programName, int lineLength=78)
        : m__progName(programName)
        , m__showHelp(false)
        , m__showHelpConfig(false)
        , m__cfgfile()
        , m__opts()
        , m__posnParams()
        , m__posnParamOpts("Positional Parameters", lineLength)
        , m__cmdlineOpts(lineLength)
        , m__hiddenCmdlineOpts("Hidden Options", lineLength)
        , m__sharedOpts(lineLength)
        , m__cfgfileOpts("Configuration File Variables", lineLength)
    {}

    // Complete the body of this function (see below).
    void defineCommandlineOptions();

    // Complete the body of this function (see below).
    void defineCfgfileOptions();

    // Complete the body of this function (see below).
    bool validateParsedOptions();

    void parse(int argc, char* argv[]);

    const boost::program_options::variable_value&
    operator[](const string& varName) const
    {
        return m__opts[varName];
    }

private:
    typedef boost::program_options::value_semantic b_po_value_semantic_t;

    // Add the named positional parameter.
    //
    void addPosnParam(const char* paramName,
                      const char* paramDocstring,
                      int max_count=1)
    {
        m__posnParams.add(paramName, max_count);
        m__posnParamOpts.add_options()
            (paramName, paramDocstring);
    }

    // Add the named positional parameter.
    //
    void addPosnParam(const char* paramName,
                      const b_po_value_semantic_t* value_obj,
                      const char* paramDocstring,
                      int max_count=1)
    {
        m__posnParams.add(paramName, max_count);
        m__posnParamOpts.add_options()
            (paramName, value_obj, paramDocstring);
    }
};


/////////////////////////

//
// ProgramOptions Member Functions
//


// Define your commandline options in this function.
//
// The options "--help", "--verbose", "--config", and "--help-config" will
// be defined for you.  No need to put them in here.
void ProgramOptions::defineCommandlineOptions()
{
    using namespace boost::program_options;

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

    // Define the "Normal" Commandline Parameters:

    m__cmdlineOpts.add_options()
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
    m__hiddenCmdlineOpts.add_options()
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

    // Define the Positional Parameters:

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
}


// Define your configuration file variables in this function.
//
// If your program doesn't use a configfile, just delete everything in the
// body of this function.
//
void ProgramOptions::defineCfgfileOptions()
{
    using namespace boost::program_options;

    // Define the Configuration File Variables:

    /*
    m__cfgfileOpts.add_options()
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

    // Define the Configuration File Variables that can also be passed as
    // Commandline Options:

    /*
    m__sharedOpts.add_options()
        ("sharedEx", "A common opt.")
        ;
    */
}


// Performs more complex program option validation.
//
// The boost::program_options engine handles most forms of validation.  More
// complicated processing, such as cross-option dependencies, should go in
// this member function.
//
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


// There's very little to change in this function.
//
void ProgramOptions::parse(int argc, char* argv[])
{
    using namespace boost::program_options;

    defineCommandlineOptions();
    defineCfgfileOptions();

    options_description cmdline_descr;
    options_description cmdline_documented_descr("Options");
    options_description config_descr;

    // Define the default/std. commandline options
    cmdline_documented_descr.add_options()
        ("help,h", bool_switch(&m__showHelp), "This message.")
        ("verbose,v", value<int>()->default_value(0)->zero_tokens(),
         "Make this program more verbose.")
        ("config", value<string>(&m__cfgfile),
         "Configuration file, containing additional options.")
        ;
    if(!m__cfgfileOpts.options().empty()) {
        cmdline_documented_descr.add_options()
            ("help-config", bool_switch(&m__showHelpConfig),
             "Additional information about the configuration file.")
            ;
    }

    // Set up the local 'options_description' vars from the members.

    // Comandline:
    cmdline_documented_descr.add(m__cmdlineOpts);
    if(!m__sharedOpts.options().empty()) {
        cmdline_documented_descr.add(m__sharedOpts);
    }
    if(!m__posnParamOpts.options().empty()) {
        cmdline_documented_descr.add(m__posnParamOpts);
    }

    cmdline_descr.add(cmdline_documented_descr);
    cmdline_descr.add(m__hiddenCmdlineOpts);

    // Config File:
    if(!m__cfgfileOpts.options().empty()) {
        config_descr.add(m__cfgfileOpts);
    }
    if(!m__sharedOpts.options().empty()) {
        config_descr.add(m__sharedOpts);
    }

    // Parse the Commandline:
    command_line_parser theParser(argc, argv);
    theParser.options(cmdline_descr);
    if(!m__posnParamOpts.options().empty()) {
        theParser.positional(m__posnParams);
    }
    store(theParser.run(), m__opts);

    // Read the Config File (if any):
    if(!config_descr.options().empty()) {
        // Unfortunately, m__cfgfile is still empty at this point.  Calling
        // notify() fixes that.
        notify(m__opts);
    }
    if(!config_descr.options().empty() && !m__cfgfile.empty()) {
        std::ifstream cfg_ifs(m__cfgfile.c_str());
        if(!cfg_ifs) {
            string errmsg("Invalid/unknown configuration file: \"");
            errmsg += m__cfgfile;
            errmsg += '"';
            throw invalid_option_value(errmsg);
        }
        try {
            store(parse_config_file(cfg_ifs, config_descr), m__opts);
            cfg_ifs.close();
        } catch(std::ios_base::failure& ex) {
            string errmsg("Failed to read configuration file: \"");
            errmsg += m__cfgfile;
            errmsg += "\"\nReason:\n\t\"";
            errmsg += ex.what();
            errmsg += '"';
            throw invalid_option_value(errmsg);
        }
    }

    notify(m__opts);

    // Print out the help message(s), as needed:

    if(m__showHelp)
    {
        cout << "usage: " << m__progName
             << " [options] [posn params]"
             << endl << endl
             << cmdline_documented_descr
             << endl;
        exit(0);
    }

    if(m__showHelpConfig)
    {
        cout << m__progName << " - Configuration File:"
             << endl << endl
             << "Settings in the configuration file are of the form:"
             << endl << endl
             << "    settingName=value"
             << endl << endl
             << "Multiple settings can be grouped into sections.  "
             << "Each option in a group"
             << endl
             << "has the form \"sectionName.settingName\", and appears in "
             << "the configuration "
             << endl
             << "file as follows:"
             << endl << endl
             << "    [sectionName]"
             << endl
             << "    settingName=value"
             << endl << endl
             << "The comment delimiter is '#' and may appear anywhere "
             << "on a line."
             << endl << endl;

        // Unfortunately, boost::program_options doesn't provide a means of
        // printing out the configuration file variables as anything other
        // than options.  So, we'll fake it by printing to a stringstream and
        // editing each line before printing it out.
        std::stringstream configDoc_sst;
        configDoc_sst << config_descr << endl;
        string::size_type unindent(0);
        while(configDoc_sst) {
            string line;
            getline(configDoc_sst, line);

            // Look for lines beginning with an option name.  Ignore any lines
            // with a margin more than 1/3 of the size of the line.
            string::size_type leftMargin = line.find_first_not_of(' ');
            if( (leftMargin == string::npos) ||
                (leftMargin > line.length()/3) )
            {
                leftMargin = 0;
            }

            if(line.find("--") == leftMargin) {
                // Erase a leading '--'
                line[leftMargin] = ' ';
                line[leftMargin + 1] = ' ';
                unindent = 2;
            } else if( (line.find(" [ --") == (leftMargin+2)) &&
                       (line[leftMargin] == '-') &&
                       (line[leftMargin+1] != '-') )
            {
                // Erase the short option and remove the '['...']' surrounding
                // the long name.
                line.replace(leftMargin, 7, 7, ' ');
                string::size_type bracketPos = line.find(']', leftMargin);
                if(bracketPos != string::npos) {
                    line.erase(bracketPos-1, 2);
                    line.insert(0, 2, ' ');
                }
                unindent = 9;
            } else if(leftMargin = 0) {
                unindent = 0;
            }

            // Remove excess indentation, if any.
            if(unindent && (line.length() > unindent)) {
                line.erase(0, unindent);
            }

            cout << line << endl;
        }
        exit(0);
    }

    validateParsedOptions();
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
        ProgramOptions myOpts(myName);
        myOpts.parse(argc, argv);

        return cxx_main(myName, myPath, myOpts);
    } catch(FooException& ex) {
        cerr << "Caught Foo: " << ex.what() << endl;
        return 3;
    } catch(boost::program_options::error& ex) {
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
// End
