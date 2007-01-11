// -*- Javascript -*-
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


// A JS Class
function xFOOx(a1, a2, a3)
{
    // Constructor body
    //

    // Setup for inheritance.  Uncomment if needed.
    //this.base_t = yBARy;
    //this.base_t("args for parent's ctor");
    this.member1 = a1;
    this.member2 = a2;
    this.member3 = a3 || 0; // "a3" can be omitted from the ctor call.

    //----------------------------------------
    // Accessor methods
    //

    this.member1 getter = function() {
        // Computes or returns member1.  Example:
        if (cond) {
            return 0;
        } // else
        return this.member1;
    }
    this.member1 setter = function(val) {
        // Example:
        this.member1 = val + 1;
    }

    //----------------------------------------
    // General methods
    //

    this.myMethod = function(itsargs) {
        // ... does something ...
    }
}
// Setup for inheritance.  Uncomment if needed.
//xFOOx.prototype = new yBARy;




/////////////////////////
//
// End
