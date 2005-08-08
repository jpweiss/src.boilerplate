// -*- C++ -*-
// Implementation of class xFOOx
// 
// Copyright (C) 2005 by John Weiss
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
static const char* const 
xFOOx_cc__="RCS $Id$";


// Includes
//
#include "xFOOx.h"
//#include <string>


using namespace jpwTools;


//
// Static variables
// 


//
// Typedefs
// 


/////////////////////////

//
// Implementation Definition
//


// Note: Remove the "private boost::noncopyable" if this class will be
// copyable.
struct xFOOx::xFOOx_Impl : private boost::noncopyable
{
 public:
     /// Default Constructor
     xFOOx_Impl();

     /// Destructor
     ~xFOOx_Impl() {}

     //--------------- Cut Here if inheriting from "boost::noncopyable"
     /// Copy Constructor
     xFOOx_Impl(const xFOOx_Impl& other) {
     }

     /// Assignment Operator
     xFOOx_Impl& operator=(const xFOOx_Impl& other) {
         return *this;
     }

     //--------------- End Cut Here.
     //--------------- Cut Here if not using "boost::noncopyable"
 private:
     // Assignment Operator
     xFOOx_Impl& operator=(const xFOOx_Impl& other);
     //--------------- End Cut Here.
};


/////////////////////////

//
// Internal Template Definitions
//


/////////////////////////

//
// General Function Definitions
//


/////////////////////////

//
// xFOOx_Impl Member Methods
//


void xFOOx::xFOOx_Impl::y()
{
}


/////////////////////////

//
// xFOOx Member Methods
//


// Default Constructor
xFOOx::xFOOx() : m__spImpl(new xFOOx_Impl())
{
}


// Use this for copyable implementations.
#ifdef UNSHARED_COPYABLE_IMPL
// Copy Constructor
// Note how we must copy construct the xFOOx_Impl object, not the _spImpl
// pointer.
void xFOOx::xFOOx(const xFOOx& other)
    : m__spImpl(new xFOOx_Impl(*other.m__spImpl))
{}


// Assignment Operator
xFOOx& xFOOx::operator=(const xFOOx& other)
{
    // We must create a copy of the implementation object in "other".  We
    // don't want to copy the 
    m__spImpl.reset(new xFOOx_Impl(*other.m__spImpl));
    return *this;
}
#else
// Use this for shared implemenations.
#ifdef SHARED_IMPL
// Copy Constructor
void xFOOx::xFOOx(const xFOOx& other)
    : m__spImpl(other.m__spImpl)
{}


// Assignment Operator
xFOOx& xFOOx::operator=(const xFOOx& other)
{
    m__spImpl = other.m__spImpl;
    return *this;
}
#endif
#endif


void xFOOx::y()
{
}


/////////////////////////
//
// End
