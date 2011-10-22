// -*- Java -*-
// JUnit Test for class tJUnit_xREPLACEMEx
//
// Copyright (C) 2011 by John Weiss
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


package jpw.libs.xPKGx.utest;


// Imports
//
//import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

//import java.lang.*;
//import java.util.*;
//import java.io.*;
//import java.text.*;


/**
 * Unit Test for class tJUnit_xREPLACEMEx.java
 *
 * FIXME:
 * You should probably upcase the first character of this file, in keeping
 * with Java naming conventions.
 *
 *
 * @author John Weiss</a>
 * @version 1.0
 */
public class tJUnit_xREPLACEMEx extends TestCase
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
     * Creates a new <code>tJUnit_xREPLACEMEx</code> instance.
     *
     * @param name test name
     */
    public tJUnit_xREPLACEMEx (String name)
    {
        super(name);
    }

    /**
     * @return a <code>TestSuite</code>
     */
    static public TestSuite suite()
    {
        TestSuite suite = new TestSuite ();
        suite.addTest(new tJUnit_xREPLACEMEx("tTest"));
        suite.addTest(new tJUnit_xREPLACEMEx("tOtherTest"));
        return suite;
    }

    /**
     * Entry point
     */
    static public void main(String[] args)
    {
        for (int i=0; i < args.length; ++i)
        {
            if ("-h".equals(args[i]) || "--help".equals(args[i])) {
                System.out.println("usage: tJUnit_xREPLACEMEx [--verbose]\n");
                return;
            } // else
            if ("--verbose".equals(args[i])) {
                verbose = true;
            }
        }
        // Console mode:
//        junit.textui.TestRunner.run(suite());
        // ...or, for the Swing interface:
//        junit.textui.TestRunner.run(tJUnit_xREPLACEMEx.class);
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


    public void tOtherTest()
    {
        printTestName("A second test.");
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
