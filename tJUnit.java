// -*- Java -*-
// JUnit Test for class xFOOx
// 
// Copyright (C) 2009 by John Weiss
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
// RCS $Id$
//


package utest;

// Imports
//
import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import java.lang.*;
import java.util.*;
import java.io.*;
import java.text.*;


/**
 *  Unit Test for class tJUnit.java
 *
 *
 * Created: Fri Aug  6 15:12:34 2004
 *
 * @author <a href="mailto:candide@tloen.vslannet">John Weiss</a>
 * @version 1.0
 */
public class tJUnit extends TestCase 
{
    //----------
    //
    // Constants
    //
    //----------

    // Leave in main program files to incorporate version numbers into the
    // code.
    private static final String __ID__=
    "RCS $Id$";


    public static final String OTHER_CONST="foo";


    //--------------
    //
    // Member Fields
    //
    //--------------

    public static boolean verbose = false;


    //--------------
    //
    // Member Classes
    //
    //--------------

    static public class MyException extends Exception 
    { 
        MyException(String mesg) { super(mesg); }
    }


    //======================================================================


    /** 
     * Creates a new <code>tJUnit</code> instance.
     *
     * @param name test name
     */
    public tJUnit (String name)
    {
        super(name);
    }

    /**
     * @return a <code>TestSuite</code>
     */
    public static TestSuite suite()
    {
        TestSuite suite = new TestSuite ();
        suite.addTest(new tJSFolderWriterStack("tTest"));        
        return suite;
    }

    /** 
     * Entry point 
     */ 
    public static void main(String[] args) 
    {
        for (int i=0; i < args.length; ++i)
        {
            if ("-h".equals(args[i]) || "--help".equals(args[i])) {
                System.out.println("usage: tJUnit [--verbose]\n");
                return;
            } // else
            if ("--verbose".equals(args[i])) {
                verbose = true;
            }
        }
        junit.textui.TestRunner.run(suite());
    }


    //----------------
    //
    // The Test Methods
    //
    //----------------


    public void tTest()
    {
        printTestName("A description.");
    }


    //----------------
    //
    // Additional Methods
    //
    //----------------


    private void printTestName(String mesg)
    {
        if (!verbose) { return; }
        System.out.print("\nRunning Test: \"");
        System.out.print(mesg);
        System.out.println("\".");
    }
}


/////////////////////////
//
// End
