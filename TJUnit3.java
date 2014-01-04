// -*- Java -*-
// Implementation of class TJUnit3_xREPLACEMEx:
// A JUnit Test for class xCLASS_BEING_TESTEDx
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


package jpw.utests.xPKGx;


// Imports
//
import junit.framework.TestCase;
import junit.framework.TestSuite;
//import junit.framework.Test;

// FIXME:  Uncomment whichever ones you need; remove the rest.
//import java.lang.*;
//import java.util.*;
//import java.io.*;
//import java.text.*;

// FIXME:  Your Imports Go Here
import jpw.libs.xPACKAGEx.xWITHx.xCLASSESx.xBEINGx.xTESTEDx.*;
// FIXME:  End local lib imports

import jpw.utests.TJwJUnitTools;

import static jpw.utests.TJwJUnitTools.requireNonNull;
import static jpw.utests.TJwJUnitTools.utestRng;

import static jpw.utests.TJwJUnitTools.printTestName;
import static jpw.utests.TJwJUnitTools.printEndOfTest;


//
// The Public Class
//


/**
 * JUnit (v3) Test for class TJUnit3_xREPLACEMEx.
 *
 * <p>
 * FIXME:  Everything below are just notes for implementers.  Remove them and
 * replace with whatever you want.
 * </p>
 *
 * This file is designed for use with JUnit v3.
 *
 * <p>
 * Naming:  Use one of the following naming conventions:
 * <pre>
 * - T{ClassBeingTested}
 * - Tju{ClassBeingTested}
 * </pre>
 * </p>
 *
 *
 * @author John Weiss
 * @version 1.0
 */
public class TJUnit3_xREPLACEMEx extends TestCase
{
    //----------
    //
    // Constants
    //
    //----------

    // Leave in main program files to incorporate version numbers into the
    // code.
    @SuppressWarnings("unused")
    private static final String __ID__
    ="$Id$";


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
        MyException(final String mesg) { super(mesg); }
    }


    //======================================================================


    //----------------
    //
    // Methods
    //
    //----------------

    //
    // Constructors & Static Public Methods
    //


    /**
     * Creates a new <code>TJUnit3_xREPLACEMEx</code> instance.
     *
     * @param name test name
     */
    public TJUnit3_xREPLACEMEx(final String name)
    {
        super(name);
    }


    /**
     * @return a <code>TestSuite</code>
     */
    static public TestSuite suite()
    {
        TestSuite suite = new TestSuite ();
        suite.addTest(new TJUnit3_xREPLACEMEx("tTest"));
        suite.addTest(new TJUnit3_xREPLACEMEx("tOtherTest"));
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
                System.out.println("usage: TJUnit3_xREPLACEMEx [--verbose]\n");
                return;
            } // else
            if ("--verbose".equals(args[i])) {
                verbose = true;
            }
        }
        // Console mode:
//        junit.textui.TestRunner.run(suite());
        // ...or, for the Swing interface:
//        junit.swingui.TestRunner.run(TJUnit3_xREPLACEMEx.class);
    }


    //----------------
    //
    // The Test Methods
    //
    //----------------


    public void tTest()
    {
        printTestName(verbose, "A description.");
    }


    public void tOtherTest()
    {
        printTestName(verbose, "A second test.");
    }


    //----------------
    //
    // Additional Methods
    //
    //----------------


    private void someOtherUtilMethod()
    {
    }
}


/////////////////////////
//
// End
