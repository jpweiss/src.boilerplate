// -*- Java -*-
// Implementation of class xFOOx
//
// Copyright (C) 2012 by John Weiss
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
// $Id$
//


package xPKGx;


// Imports
//
import java.lang.*;
import java.util.*;
import java.io.*;
import java.text.*;

import jpw.libs.progtools.*;


//
// The Public Class
//


/**
 * JavaDoc goes here.  Don't forget to use \<p\>...\</p\> for paragraph
 * breaks.
 *
 * <p>
 * Here's a code sample:
 * <br/>
 * <pre>
 * String x="";
 * Boolean flag = new Boolean(false);
 * </pre>
 * </p>
 *
 * <p>
 * Use HTML markup for bold/italics/emphasized.  Use <code>code</code> for
 * inlined code samples.
 * </p>
 *
 * <p>
 * Here is an example of a link: {@link java.util.Properties Properties}.
 * This references a member: {@link #foo}
 * This references a member in another class: {@link java.lang.System#in}
 * </p>
 * 
 * @author John Weiss
 * @version 1.0
 */
public final class xFOOx
{
    //----------
    //
    // Constants
    //
    //----------

    // Leave in main program files to incorporate version numbers into the
    // code.
    @SuppressWarnings("unused")
    private static final String __ID__=
        "$Id$";

    // [TODO:  BEGIN:  Remove this if not using ProgramProperties]

    // Our Name and usage-string.

    public static final String OUR_NAME="xFOOx";
    public static final String OUR_USAGE=
        "Descriptive message saying what this program's for, and any other "+
        "initial information that should follow the \"usage:\" line(s)"+
        "but precede the doc-lines for options & posn. params.";

    //
    // Commandline options constants, used by ProgramProperties:
    //

    public static final String OP_IX="--eks";
    public static final String OP_IX_USG
    ="Put Usage String here.  Separate lines with \n\t.";
    public static final String OP_WAI="--why";
    public static final String OP_WAI_USG
    ="Put Usage String here.  Separate lines with \n\t.";

    // The full option-syntax array to pass to the ProgramProperties c'tor
    public static final String[][] OPTION_SYNTAX_DEFNS
    ={ {OP_IX, "[-x", "[defaultValHere", "[nArgs_Here]]]", OP_IX_USG},
       // :
       // :
       // :
       {OP_WAI, "-y", null, "1", OP_WAI_USG}
     };

    //
    // Additional Constants.
    //

    // [TODO:  END:  Remove this if not using ProgramProperties]
    public static final String CFGFILE="";
    public static final String PROPFILE="";
    public static final String[] PROPFILE_PATHSPEC=new String[]
        { "foo",
          "bar"
        };


    //--------------
    //
    // Member Classes
    //
    //--------------

    /**
     * A POJO-class for holding this program's options.
     *
     * <p>
     * Long
     * </p>
     */
    static public class Options
    {
        public String someString = "some sane default";
        public int someInt = -1;
        public boolean someFlag = false;
        // ...and so on...
    }


    //--------------
    //
    // Member Fields
    //
    //--------------

    private final ProgramProperties m__optsParser =
        new ProgramProperties(OUR_NAME, OPTION_SYNTAX_DEFNS,
                              makeCfgfile(CFGFILE,
                                          PROPFILE_PATHSPEC).toString());
    // [NOTE:  You can use a ProgramProperties object, but you don't have to.
    // If all that you have/need is a configuration file, Properties will work
    // for you just fine.]
    private final Properties m__propsHandler = new Properties();
    private final File m__cfgfileFullPath = makeCfgfile(PROPFILE,
                                                        PROPFILE_PATHSPEC);
    private final Options m__opts = new Options();



    //----------------
    //
    // Main
    //
    //----------------


    static public void main(String[] args)
    {
    }


    //----------------
    //
    // Methods
    //
    //----------------

    //
    // Construction
    //

    /**
     * Default Constructor.
     */
    public xFOOx()
    {
    }//end xFOOx()


    /**
     * Constructor.
     */
    public xFOOx(int someParam)
    {
    }//end xFOOx()


    //
    // Public Methods
    //


    /**
     *
     */
    public void foo() throws Exception
    {
        // Note:  There will probably not be any public methods.
    }


    //
    // Private Methods
    //


    /**
     * Constructs a configuration file from the specified name and list of
     * relative paths.
     */
    static private File makeCfgfile(String name, String[] pathspec)
    {
        final Properties sysProps = System.getProperties();
        // user.dir :== The CWD that the program was run from.
        String cwd = sysProps.getProperty("user.dir", ".");
        // user.home :== The user's home-directory ($HOME under unix).
        String home = sysProps.getProperty("user.home", ".");

        File parentPath_fromCWD = new File(cwd);
        File parentPath_fromHome = new File(home);

        if(pathspec != null) {
            for(String dir : pathspec) {
                parentPath_fromCWD = new File(parentPath_fromCWD, dir);
                parentPath_fromHome = new File(parentPath_fromHome, dir);
            }
        }


        File cfgfile = null;
        if(parentPath_fromHome.canRead()) {
            cfgfile = new File(parentPath_fromHome, name);
            if(!cfgfile.canRead()) {
                // Abandon the File object if it's not an actual file.
                cfgfile = null;
            }
        } //else

        // Wasn't under the home directory?  Assume that it's under the CWD.
        if(cfgfile == null) {
            cfgfile = new File(parentPath_fromCWD, name);
        }

        return cfgfile;
    }


    /**
     * Additional ProgramProperties setup tasks.
     */
    private void setupProgramProperties()
    {
        m__optsParser.setProgramUsage(OUR_USAGE, __ID__);

        m__optsParser.definePositionalParameters(new String[]{"someString",
                                                              "s2"},
                                                 /*aByteVal*/(byte)0);

        m__optsParser.setCfgfileParamIndex(/*bytePosn*/(byte)1);
        // OR
        m__optsParser.setCfgfileOption("optNm",
                                       /*charShortForm_or_0char*/'\0',
                                       "cfgOpt-usage");
    }


    /**
     *
     */
    private void parseProgramProperties(String[] args)
        throws ProgramProperties.RequirementException,
        ProgramProperties.SyntaxStringsError, NumberFormatException
    {
        m__optsParser.parseArgs(args);

        m__opts.someString = m__optsParser.getProperty(OP_IX);
        m__opts.someInt = m__optsParser.getIntProperty(OP_WAI);
        // ...and so on.
    }


    /**
     *
     */
    private void handleFileReadErr(Throwable ex, boolean isFatal)
    {
        System.out.print("Error reading file:  \"");
        System.out.print(m__cfgfileFullPath.toString());
        System.out.println("\":");
        System.out.println(ex.toString());
        if(isFatal) {
            System.out.println();
            System.out.println("Cowardly refusing to continue.");

            System.exit(1);
        }
    }


    /**
     * Read configuration from a {@link Properties} file.
     *
     * For when you don't want/need to use a {@link ProgramProperties}.
     */
    private void readProperties(boolean failedReadIsFatal)
        throws NumberFormatException
    {
        // [NOTE:  You don't need to use ProgramProperties to read a
        // configfile.  Properties.load() works just fine all by itself.  Or,
        // use Properties.loadFromXML() if you prefer that format.]

        InputStream ifs;
        try {
            ifs = new FileInputStream(m__cfgfileFullPath);
        } catch(FileNotFoundException ex) {
            handleFileReadErr(ex, failedReadIsFatal);
        } catch(SecurityException ex) {
            handleFileReadErr(ex, true);
        }

        try {
            m__propsHandler.load(ifs);
        } catch(IOException ex) {
            handleFileReadErr(ex, failedReadIsFatal);
        } catch(IllegalArgumentException ex) {
            handleFileReadErr(ex, failedReadIsFatal);
        }

        // OR

        try {
            m__propsHandler.loadFromXML(ifs);
        } catch(IOException ex) {
            handleFileReadErr(ex, failedReadIsFatal);
        } catch(NullPointerException ex) {
            Error fatal = new Error("FileInputStream can't possibly be null!"+
                                    "\n\n"+
                                    "Aborting:  Impossible Exception "+
                                    "Occurred (computer on fire?)",
                                    ex);
            throw fatal;
        }

        // Convert the props to the Options members
        m__opts.someString = m__optsParser.getProperty("prop.ix");
        m__opts.someInt = m__optsParser.getIntProperty("prop.wai");
        // ...and so on.
    }


}


/////////////////////////
//
// End
