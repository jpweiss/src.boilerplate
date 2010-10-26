// -*- C++ -*-
// Header file for Singleton class xFOOx
//
// Copyright (C) 2010 by John Weiss
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
 *
 * As a form of the Singleton pattern, this class in noncopyable.
 */
 class xFOOx : private boost::noncopyable
 {
 public:
     // Use the compiler-generated destructor.

     /// Accessor
     /**
      * Get the instance of this Singleton.  Creates it if it doesn't yet
      * exist.
      *
      * DesignNote: Remove the "const" if other member functions need to alter
      *             internal state.
      *
      * Note that nothing destroys the Singleton except program termination.
      */
     static const xFOOx& instance() {
         if(m__TheInstance_p == 0) {
             m__TheInstance_p = new xFOOx;
         }
         return *m__TheInstance_p;
     }

 protected:
     /// Default Constructor
     xFOOx();

 private:
     static xFOOx* m__TheInstance_p;

     // Assignment Operator
     xFOOx& operator=(const xFOOx& other);
 };


}; //end namespace


#endif //_xFOOx_H_
/////////////////////////
//
// End
