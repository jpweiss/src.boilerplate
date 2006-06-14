// -*- C++ -*-
// Implementation of class xFOOx
// 
// Copyright (C) 2006 by John Weiss
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
//xFOOx_cc__="RCS $Id$";
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


/////////////////////////

//
// General Function Definitions
//


/////////////////////////

//
// xFOOx Member Methods
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


//------- Remove the following if you are #include'ing this file into the
//------- header proper.
// End namespace wrapper decls.
}; //end namespace jpw_yFOOy



#endif //_matrix_facade_TCC_
/////////////////////////
//
// End
