// -*- C++ -*-
// Header file for template class xFOOx
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
// $Id$
//
#ifndef _xFOOx_H_
#define _xFOOx_H_

// Includes
//
#include <boost/utility.hpp>


// Forward Declarations
//
class yFOOy;


// Enclosing namespace
//
namespace jpwTools {
 // Using decls.
 //
 using std::string;


 // Class xFOOx
 /**
  * <Document it here>
  */
 // Note: Remove the "private boost::noncopyable" if this class will be
 // copyable.
  template<class C>
  class xFOOx : private boost::noncopyable
  {
  public:
      /// Default Constructor
      xFOOx();

      /// Destructor
      ~xFOOx() {}

      //--------------- Cut Here if inheriting from "boost::noncopyable"
      /// Copy Constructor
      xFOOx(const xFOOx& other) { copy(other); }

      /// Assignment Operator
      xFOOx& operator=(const xFOOx& other) {
          copy(other);
          return *this;
      }

  private:
      void copy(const xFOOx& other);
      //--------------- End Cut Here.
  };


 // Include any large function bodies.
#include "xFOOx.tcc"

}; //end namespace


#endif //_xFOOx_H_
/////////////////////////
//
// End
