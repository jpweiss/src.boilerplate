// -*- Java -*-
// Implementation of class xFOOx
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
 * TODO::Add:  JavaDoc goes here.  Don't forget to use \<p\>...\</p\> for
 * paragraph breaks.
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
 * <p>
 * Stylistic Note:
 * <br/>
 * <code>public static final</code> for fields.
 * <code>[final] static public</code> for methods.
 * <code>abstract public</code> for methods.
 * <code>[static] public (abstract|final) (class|interface|enum)</code>
 * for types.
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
    private static final String __ID__
    ="$Id$";
    // FIXME:  Don't forget to do <code>svn propset svn:keywords "Id"</code>
    // on the new file if you've added it through Eclipse!

    // Keep Eclipse Happy
    private static final long serialVersionUID=0L; // TBC:  Boilerplate val.

    public static final String OTHER_CONST="foo";


    //--------------
    //
    // Member Classes
    //
    //--------------


    /**
     *
     */
    @SuppressWarnings("serial")
    static public class MyException extends Exception
    {
        public MyException(final String mesg) { super(mesg); }
    }


    /**
     *
     */
    static public enum MyEnum
    {
        TAG1(-1),
        TAG2(1);

        //----------------
        // Non-Tag Members
        //----------------

        // FIXME::Remove:  If not making a bit-flag enum
        //private final EnumBits<MyEnum> m__val;
        // FIXME::Change:  Remove or change the type appropriately
        private final int m__val;

        private MyEnum(final int val) { m__val = val; }

        public int value() { return m__val; }
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
    public xFOOx(final int someParam)
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
    // Accessors
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
    public void setMyField(final String nuField)
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
