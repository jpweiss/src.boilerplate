// -*- C++ -*-
// Header file for class xFOOx
//
// Copyright (C) 2009 by John Weiss
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
#include <boost/utility.hpp>


// Forward Declarations
//
//#include <iosfwd>
class yFOOy;


// Enclosing namespace
//
namespace jpwTools {
 // Using decls.
 //
 //using std::string;


 // Class xFOOx
 /**
  * <Document it here>
  */
 // Note: Remove the "private boost::noncopyable" if this class will be
 // copyable.
 class xFOOx : private boost::noncopyable
 {
 public:
     /// Default Constructor
     xFOOx();

     /// Destructor
     ~xFOOx() {}

     //--------------- Cut Here if inheriting from "boost::noncopyable"
     /// Copy Constructor
     xFOOx(const xFOOx& other) {
     }

     /// Assignment Operator
     xFOOx& operator=(const xFOOx& other) {
         return *this;
     }

     //--------------- End Cut Here.
     //--------------- Cut Here if not using "boost::noncopyable"
 private:
     // Assignment Operator
     xFOOx& operator=(const xFOOx& other);
     //--------------- End Cut Here.
 };


}; //end namespace


#endif //_xFOOx_H_
/////////////////////////
//
// End
