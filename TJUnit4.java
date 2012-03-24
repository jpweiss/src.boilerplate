// -*- Java -*-
// Implementation of class TJUnit4_xREPLACEMEx
// A JUnit Test for class xCLASS_BEING_TESTEDx
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


package jpw.libs.xPKGx.utest;


// Imports
//
import org.junit.*;
import org.junit.rules.*;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import static org.junit.Assert.*;
// FIXME:  Remove if not needed:
import static org.junit.Assume.*;

// FIXME:  Uncomment whichever ones you need; remove the rest.
//import java.lang.*;
//import java.util.*;
//import java.io.*;
//import java.text.*;
//import javax.swing.*;

// FIXME:  Your Imports Go Here
import jpw.libs.xPACKAGEx.xWITHx.xCLASSESx.xBEINGx.xTESTEDx.*;
// FIXME:  End local lib imports

import jpw.utests.TJwJUnitTools;
// FIXME:  Use this import for Swing-Based Unit Tests.
//import jpw.utests.ui.*;

import static jpw.utests.TJwJUnitTools.requireNonNull;
import static jpw.utests.TJwJUnitTools.utestRng;

import static jpw.utests.TJwJUnitTools.printTestName;
import static jpw.utests.TJwJUnitTools.printEndOfTest;


//
// The Public Class
//


/**
 * JUnit (v4) Tests for class {@link xCLASS_BEING_TESTEDx}.
 *
 * <p>
 * FIXME:  Everything below are just notes for implementers.  Remove them and
 * replace with whatever you want.
 * </p>
 *
 * <p>
 * This file is designed for use with JUnit v4.
 * </p>
 *
 * <p>
 * Naming:  Use one of the following naming conventions:
 * <pre>
 * - T{ClassBeingTested}
 * - Tju{ClassBeingTested}
 * </pre>
 * </p>
 *
 * <p>
 * The test cases are any nonstatic <code>public void</code> member methods
 * annotated with "<code>&#064;Test</code>".  If you want to temporarily
 * disable some unit test cases, you add the annotation
 * "<code>&#064;Ignore</code>" to any methods annotated with
 * "<code>&#064;Test</code>".
 * </p>
 *
 * <p>
 * The "<code>&#064;RunWith</code>" annotation on this class ensures that it
 * is always run using the default JUnit4 runner-class.
 * </p>
 *
 * @author John Weiss
 * @version 1.0
 */
@RunWith(JUnit4.class)
public class TJUnit4_xREPLACEMEx
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
    // FIXME:  Don't forget to do <code>svn propset svn:keywords "Id"</code>
    // on the new file if you've added it through Eclipse!

    public static final String OTHER_CONST="foo";

    // FIXME:  For Swing-Based Unit Tests only:
    //public static final int c_PRE_CLOSE_DELAY_MS = 10000;
    //public static final String
    //c_END_OF_TEST_MSG = "...some message...";


    //--------------
    //
    // Member Fields
    //
    //--------------

    //
    // Static
    //


    public static boolean verbose = false;

    // FIXME:  For Swing-Based Unit Tests only:
    //private static TJwJUnitSwingHelper m__swingTester
    //    = new TJwJUnitSwingHelper();


    //
    // Private Local
    //


    @Rule
    private TestName m__myName = new TestName();

    //private ComplicatedType<String, Integer,
    //                        Double, Map<String, Double>> m__testVar=null;


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
        MyException(String mesg) { super(mesg); }
    }


    //======================================================================


    //----------------
    //
    // Methods
    //
    //----------------

    //
    // Constructors
    // FIXME::Note:  C'tors are optional in JUnit4.  Use the Setup & Teardown
    // methods (below) whenever possible.
    //


    /**
     * Default Constructor.
     */
    public TJUnit4_xREPLACEMEx()
    {
    }//end TJUnit4_xREPLACEMEx()


    //
    // JUnit4 Setup & Tear-Down Functions
    //


    /**
     * Create Fixtures that are static members of this class.
     *
     * <p>
     * A test fixture is just data, state, or resources shared by all of the
     * tests.  JUnit4 runs <b>any</b> argless <code>public void </code> method
     * annotated with "<code>&#064;BeforeClass</code>" just <u>once</u>,
     * sometime prior to running any of the tests.
     * </p>
     *
     * <p>
     * If you have a tree of test classes, the
     * "<code>&#064;BeforeClass</code>" methods are run in canonical
     * inheritance order.  (I.e. in the same order as c'tors in the class tree
     * are called.)  It's not clear from the documentation what JUnit4 does if
     * a class has multiple "<code>&#064;BeforeClass</code>" methods.
     * </p>
     *
     * <p>
     * <em>However:</em>
     * <br/>
     * Empirically, this is not true ... at least, not for ancestor classes
     * that have no "<code>&#064;Test</code>" methods.  Only the
     * "<code>&#064;BeforeClass</code>" methods inherited by the first child
     * class with at least one "<code>&#064;Test</code>" are called.
     * <br/>
     * So, for every "<code>&#064;BeforeClass</code>" method that you
     * override, you'll need to call your parent's implementation from your
     * own <em>if</em> the parent has no "<code>&#064;Test</code>"s.  (To
     * ensure proper call behavior, make the very <u>first</u> statement of
     * your override the call to the parent's implementation.)
     * </p>
     *
     * <p>
     * "<code>&#064;BeforeClass</code>" methods can throw exceptions (and have
     * a "<code>throws</code>" clause), but aren't required to.
     * </p>
     *
     * FIXME:  This Javadoc is just information for implementers.  Feel free
     * to remove or replace it.
     */
    @BeforeClass
    public static void setUpBeforeClass()
    {
        TJwJUnitTools.IS_VERBOSE = verbose;

        // FIXME:  For Swing-Based Unit Tests only:
        //m__swingTester.start();

    }


    /**
     * Create Fixtures that are members (usually private) of this class.
     *
     * <p>
     * A test fixture is just data, state, or resources shared by all of the
     * tests.  JUnit4 runs <b>any</b> <code>public void </code> method
     * annotated with "<code>&#064;Before</code>" <u>before <b>each</b>
     * test</u>.
     * </p>
     *
     * <p>
     * If you have a tree of test classes, the "<code>&#064;Before</code>"
     * methods are run in the same order as the
     * "<code>&#064;BeforeClass</code>" methods are.
     * <br/>
     * Similarly if you have ancestor classes with no
     * "<code>&#064;Test</code>" methods, you have the same empirical
     * behavior.  For each "<code>&#064;Before</code>" method from a
     * non-"<code>&#064;Test</code>" parent that you override, you'll need to
     * call your parent's implementation of that method.  (To ensure proper
     * call behavior, make the very <u>first</u> statement of your override
     * the call to the parent's implementation.)
     * </p>
     *
     * <p>
     * "<code>&#064;Before</code>" methods can throw exceptions (and have a
     * "<code>throws</code>" clause), but aren't required to.
     * </p>
     *
     * FIXME:  This Javadoc is just information for implementers.  Feel free
     * to remove or replace it.
     *
     * @see #setUpBeforeClass
     */
    @Before
    public void setUp()
    {
        printTestName(this.getClass(), m__myName);
    }


    /**
     * Release any resources allocated by {@link #setUp}.
     *
     * More specifically, releases any resources allocated by
     * "<code>&#064;Before</code>" methods.
     *
     * <p>
     * JUnit4 runs <b>any</b> <code>public void </code> method
     * annotated with "<code>&#064;After</code>" <u>after <b>each</b>
     * test</u>.  An "<code>&#064;After</code>" method runs even if the
     * "<code>&#064;Before</code>" method(s) or the test case throws an
     * exception.
     * </p>
     *
     * <p>
     * The behavior of "<code>&#064;After</code>" methods w.r.t. exceptions,
     * more than one per class, and call order in a class-tree are the same as
     * those for "<code>&#064;Before</code>" methods... with one exception.
     * In a class tree, "<code>&#064;After</code>" methods are called in the
     * reverse-order of "<code>&#064;Before</code>" methods.
     * <br/>
     * Similarly if you have ancestor classes with no
     * "<code>&#064;Test</code>" methods, you have the same empirical
     * behavior.  For each "<code>&#064;After</code>" method from a
     * non-"<code>&#064;Test</code>" parent that you override, you'll need to
     * call your parent's implementation of that method.  (To ensure proper
     * call behavior, make the very <u>last</u> statement of your override the
     * call to the parent's implementation.)
     * </p>
     *
     * FIXME:  This Javadoc is just information for implementers.  Feel free
     * to remove or replace it.
     *
     * @see #setUp
     */
    @After
    public void tearDown()
    {
        // FIXME:  Optional - For Swing-Based Unit Tests only:
        //m__swingTester.removeAll();
        //m__swingTester.pack_centerOnScreen();

        printEndOfTest(this.getClass(), m__myName);
    }


    /**
     * Release any resources allocated by {@link #setUpBeforeClass}.
     *
     * More specifically, releases any resources allocated by
     * "<code>&#064;BeforeClass</code>" methods.
     *
     * <p>
     * JUnit4 runs <b>any</b> <code>public void </code> method annotated with
     * "<code>&#064;AfterClass</code>" just <u>once</u>, sometime after
     * running all of the tests.  An "<code>&#064;AfterClass</code>" method
     * runs even if the "<code>&#064;BeforeClass</code>" method(s) or the test
     * cases throw an exception.
     * </p>
     *
     * <p>
     * The behavior of "<code>&#064;AfterClass</code>" methods
     * w.r.t. exceptions, more than one per class, and call order in a
     * class-tree are the same as those for "<code>&#064;BeforeClass</code>"
     * methods... with one exception.  In a class tree,
     * "<code>&#064;AfterClass</code>" methods are called in the reverse-order
     * of "<code>&#064;BeforeClass</code>" methods.
     * </p>
     *
     * <p>
     * <em>However:</em>
     * <br/>
     * Like "<code>&#064;BeforeClass</code>" methods,
     * "<code>&#064;AfterClass</code>" methods, empirically, behave
     * differently for ancestor classes that have no "<code>&#064;Test</code>"
     * methods.  Only the "<code>&#064;AfterClass</code>" methods inherited by
     * the first child class with at least one "<code>&#064;Test</code>" are
     * called.
     * <br/>
     * So, for every "<code>&#064;AfterClass</code>" method that you override,
     * you'll need to call your parent's implementation from your own
     * <em>if</em> the parent has no "<code>&#064;Test</code>"s.  (To ensure
     * proper call behavior, make the very <u>last</u> statement of your
     * override the call to the parent's implementation.)
     * </p>
     *
     * FIXME:  This Javadoc is just information for implementers.  Feel free
     * to remove or replace it.
     *
     * @see #setUpBeforeClass
     */
    @AfterClass
    public static void tearDownAfterClass()
    {
        // FIXME:  For Swing-Based Unit Tests only:
        //m__swingTester.end(c_END_OF_TEST_MSG, false, c_PRE_CLOSE_DELAY_MS);
        //
        // Pass 'null' instead of c_END_OF_TEST_MSG for no pre-close
        // JwMsgBox.
        // Pass '0' instead of c_PRE_CLOSE_DELAY_MS for no delay.
    }


    //----------------
    //
    // The Test Methods
    //
    //----------------


    /**
     * Test method for
     * {@link xCLASS_BEING_TESTEDx#__MethodBeingTested__}.
     *
     * <p>
     * FIXME:  Everything from here on is just information for unit-test
     * authors.  It should all be removed.
     * </p>
     *
     * Some useful testing methods are listed below.
     *
     * @see TJwJUnitTools#safeSleep
     * @see TJwJUnitTools#printTestName(TestName)
     * TJwJUnitTools.printTestName(...) overloads
     * @see TJwJUnitTools#printEndOfTest(TestName)
     * TJwJUnitTools.printEndOfTest(...) overloads
     * @see TJwJUnitTools#requireNonNull
     * @see TJwJUnitTools#failedToThrow(String, Object[])
     * TJwJUnitTools.failedToThrow(...) overloads
     * @see TJwJUnitTools#utestRng
     * @see TJwJUnitTools#removeRandomSubset(java.util.Map, double)
     * TJwJUnitTools.removeRandomSubset(...) overloads
     * @see TJwJUnitTools#getRandomSubset(java.util.Map, java.util.Map,
     * double)
     * TJwJUnitTools.getRandomSubset(...) oveerloads
     * @see TJwJUnitTools#getRandomElement(List)
     * TJwJUnitTools.getRandomElement(...) overloads
     * @see TJwJUnitTools#getRandomKey
     * @see jpw.libs.utests.ui.TJwJUnitTools#askUser2Verify
     * @see jpw.libs.utests.ui.TJwJUnitTools#delayed_askUser2Verify
     */
    @Ignore("not yet implemented")
    @Test
    public void test__MethodBeingTested__()
    {
        // NOTE:  Nonfatal Preconditions.
        //
        // If you need to abort a test w/o failing when some requirement isn't
        // met, use one of the static member methods from 'Assume':
        //
        // - assumeNoException(Throwable)
        // - assumeTrue(boolean predicate)
        // - assumeNotNull(Object ...)
        // - <T> assumeThat(T actual, Matcher<T> matcher)
        //
        // The last two require some explanation.  '(Object ...)' represents
        // what we call "a list of varargs" in C/C++.  The last one uses a
        // 'Matcher', a JUnit4 interface described below under the
        // 'Assert.assertThat' method.

        printTestName(m__myName);

        // NOTE:  Ways to test:
        //
        // Typically, you'll use one of the static member methods of
        // 'Assert'.  Here's a summary of them.  Anything marked 'T' below can
        // be a placeholder for a primitive type or Object.
        //
        // - assertArrayEquals(T[] expected, T[] actual)
        // - assertArrayEquals(String mesg, T[] expected, T[] actual)
        //
        // - assertEquals(long expected, long actual)
        // - assertEquals(Object expected, Object actual)
        // - assertEquals(double expected, double actual, double epsilon)
        //
        // - assertEquals(String mesg, long expected, long actual)
        // - assertEquals(String mesg, Object expected, Object actual)
        // - assertEquals(String mesg, double expected, double actual,
        //                double epsilon)
        //
        // - assertSame(Object expected, Object actual)
        // - assertSame(String mesg, Object expected, Object actual)
        //
        // - assertNotSame(Object expected, Object actual)
        // - assertNotSame(String mesg, Object expected, Object actual)
        //
        // - assertNull(Object o)
        // - assertNull(String mesg, Object o)
        //
        // - assertNotNull(Object o)
        // - assertNotNull(String mesg, Object o)
        //
        // For tests that don't fit any of the above, you can use the
        // following:
        //
        // - assertTrue(boolean testPredicate)
        // - assertTrue(String mesg, boolean testPredicate)
        //
        // - assertFalse(boolean testPredicate)
        // - assertFalse(String mesg, boolean testPredicate)
        //
        // - fail()
        // - fail(String mesg)
        //
        // The most general testing methods are the following:
        //     - <T> assertThat(T actual, Matcher<T> matcher)
        //     - <T> assertThat(String mesg, T actual, Matcher<T> matcher)
        // There are several concrete classes that implement 'Matcher' in
        // JUnit4, as well as ways to create your own.  Have a look at
        // 'CoreMatchers' and 'JUnitMatchers' in the JUnit4 Javadoc for static
        // methods that return various kinds of 'Matcher's
        //


        fail("Not yet implemented"); // TODO

        // FIXME:  Use this as boilerplate for all of your tests.
    }


    /**
     * Test method for
     * {@link xCLASS_BEING_TESTEDx#__MethodBeingTested__} when it throws an
     * expected {@link Exception}.
     *
     * <p>
     * Will only test <em>one</em> operation that throws an exception.
     * </p>
     */
    @Ignore("not yet implemented")
    @Test(expected = Exception.class)
    public void test__MethodBeingTested_ExpectedException_()
    {
        printTestName(verbose, "A description.");
        fail("Not yet implemented"); // TODO
    }


    /**
     * Test method for
     * {@link xCLASS_BEING_TESTEDx#__VerySlowMethodBeingTested__} to make sure
     * that it doesn't run forever.
     *
     * The test fails if the method runs for longer than <em>timeout</em>,
     * which is in milliseconds.
     */
    @Ignore // Note that @Ignore doesn't require args.
    @Test(timeout = 60000)
    public void test__MethodBeingTested_VerySlowMethodBeingTested_()
    {
        printTestName(verbose, "A description.");
        fail("Not yet implemented"); // TODO
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
