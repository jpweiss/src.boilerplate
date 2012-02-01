// -*- Java -*-
// Implementation of interface xFOOx
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
// $Id: javaSrc.java 2087 2010-12-30 22:58:59Z candide $
//


// FIXME:  Don't forget to do <code>svn propset svn:keywords "Id"</code>
// on the new file if you've added it through Eclipse!
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
public interface xFOOx
{
    //----------
    //
    // Constants
    //
    //----------

    // N.B.:  The String __ID__ field should never be part of an Interface.
    // All member constants in an Interface are implicitly 'public'.
    // [You can remove this comment.]

    public static final long CONST=42;
    public static final String OTHER_CONST="foo";


    //--------------
    //
    // Member Classes & Interfaces
    //
    //--------------

    @SuppressWarnings("serial")
    static public class MyException extends Exception
    {
        MyException(String mesg) { super(mesg); }
    }


    //----------------
    //
    // Methods
    //
    //----------------


    /**
     *
     */
    public abstract void foo()
        throws Exception;
    // N.B.:  All Interface methods are implicitly 'public' and 'abstract'.
    // These keywords are, therefore, not necessary, as shown below.
    // The member methods can also be declared 'strictfp'.
    // [You can remove this comment.]


    /**
     *
     */
    public abstract void bar();


    //
    // Accessors
    //


    /**
     *
     */
    String get_myField();

    /**
     *
     */
    void set_myField(String x);


}


/////////////////////////
//
// End
