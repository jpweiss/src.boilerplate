// -*- C++ -*-
// Header file for class xFOOx
// 
// Copyright (C) 2007 by John Weiss
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
#ifndef _xFOOx_H_
#define _xFOOx_H_

// Includes
//
#include <boost/scoped_ptr.hpp>
//#include <boost/shared_ptr.hpp>


// Forward Declarations
//
//#include <iosfwd>


// Enclosing namespace
// 
namespace jpwTools {
//using std::string;


// Class xFOOx
/**
 * <Document it here>
 */
 class xFOOx
 {
 public:
     /// Default Constructor
     xFOOx();

     /// Destructor
     ~xFOOx();

     /// Copy Constructor
     xFOOx(const xFOOx& other);

     /// Assignment Operator
     xFOOx& operator=(const xFOOx& other);

 private:
     struct xFOOx_Impl;
     boost::scoped_ptr<xFOOx_Impl> m__spImpl;
     // Remove if the implementation isn't shared.
     //boost::shared_ptr<xFOOx_Impl> m__spImpl;
 };


}; //end namespace


#endif //_xFOOx_H_
/////////////////////////
//
// End
