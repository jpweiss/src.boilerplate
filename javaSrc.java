// -*- Java -*-
// Implementation of class xFOOx
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


package xPKGx;


// Imports
//
import java.lang.*;
import java.util.*;
import java.io.*;
import java.text.*;


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
public class xFOOx
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

    // Keep Eclipse Happy
    private static final long serialVersionUID=0L; // TBC:  Boilerplate val.

    public static final String OTHER_CONST="foo";


    //--------------
    //
    // Member Classes
    //
    //--------------

    @SuppressWarnings("serial")
    static public class MyException extends Exception
    {
        public MyException(String mesg) { super(mesg); }
    }


    //--------------
    //
    // Member Fields
    //
    //--------------

    private String m__myField = null;
    public byte m__nCounterField = 0;



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
    public void foo()
        throws Exception
    {
    }


    //
    // Access Methods
    //


    /**
     *
     */
    public String getMyField()
    {
        return m__myField;
    }

    /**
     *
     */
    public void setMyField(String nuField)
    {
        m__myField = nuField;
    }


    //
    // Private Methods
    //


    /**
     *
    private void bar()
        throws Exception
    {
    }
     */


}


/////////////////////////
//
// End
