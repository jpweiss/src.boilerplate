// -*- C++ -*-
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
//static const char* const
//xFOOx_cc__="$Id$";
#ifndef _xFOOx_TCC_
#define _xFOOx_TCC_


// Includes
//

//#include <string>
//#include <boost/something.hpp>


// "using" Decl. for parent namespace not needed; this file is #include'd into
// that namespace.
//------- Remove the following if you are #include'ing this file into the
//------- header proper.
// Wrapper for parent namespace
namespace jpw_yFOOy {


// Other "using" Decls.
//using std::string;


// Convenience Macros for defining Template member functions.
//
#define TEMPL_M_MyComplexClass \
    template<typename T1, typename T2, typename T3, typename T4>

#define CT_M_MyComplexClass \
    MyComplexClass<T1, T2, T3, T4>


//
// Static variables
//


#if 0
 // This is just an example of how to define static member variables.
 template<class C> example_t xFOOx<C>::staticVar(initializer);
 TEMPL_M_MyComplexClass example_t CT_M_MyComplexClass::otherStaticVar(0);
#endif


/////////////////////////

//
// General Function Definitions
//


/////////////////////////

//
// xFOOx Member Functions
//


template<class C>
inline void
xFOOx<C>::y()
{
}


TEMPL_M_MyComplexClass
inline void
CT_M_MyComplexClass::z()
{
}


#if 0
// These are just examples. They don't compile.
// Or, more to the point... they don't compile because neither the classes
// used nor the members have been declared anywhere.  (But if they had been,
// the code would compile just fine.)
//
// Delete when you're finished looking at it.

// Example of a member template (i.e. a template fn. that's a member of a
// template class) definition.
TEMPL_M_MyComplexClass
template<typename RET_T>
inline const RET_T&
CT_M_MyComplexClass::alpha()
{
}

// Example of a member template definition with just the class specialized.
template<>
template<typename OUT_TYPE>
inline void
xFOOx<complex>::beta<>(OUT_TYPE& T)
{
}

// Example of a member template definition with the class template left alone
// and the member function specialized.
TEMPL_M_MyComplexClass
template<>
inline const string&
CT_M_MyComplexClass::alpha<string>()
{
}

// Example of a member template definition with full specialization (i.e. in
// both the class and the function template args).
template<>
template<>
inline void
xFOOx<complex>::beta<string>(string& T)
{
}

// Indeed, you need one template<....> declaration for each templatized
// entity, in "member nesting order", and it goes before the return type and
// qualifiers.  (The "member nesting order" means that the "template<...> for
// the class comes first, followed by the "template<...>" for the member class
// (if relevant), followed by the "template<...>" for the member class
// (if relevant), ..., followed by the "template<...>" for the member template
// function.)
#endif

//------- Remove the following if you are #include'ing this file into the
//------- header proper.
// End namespace wrapper decls.
}; //end namespace jpw_yFOOy



#endif //_xFOOx_TCC_
/////////////////////////
//
// End
