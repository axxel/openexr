///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2002, Industrial Light & Magic, a division of Lucas
// Digital Ltd. LLC
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Industrial Light & Magic nor the names of
// its contributors may be used to endorse or promote products derived
// from this software without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////



#ifndef INCLUDED_IMF_THREADING_H
#define INCLUDED_IMF_THREADING_H

//-----------------------------------------------------------------------------
//
//    Imf-threading support stuff
//
// The Imf library uses threads to perform the (de)compression of files in
// parallel. The thread calling the library always performs the actual file IO
// (this is usually the main application thread) whereas the "worker" threads
// perform the (de)compression. The number of worker threads can be any
// non-negative value (a value of 0 reverts to single-threading). As long as
// there is at least 1 worker thread, file IO and (de)compression can
// potentially be done concurrently through pinelining. If there are more than
// two worker threads, then pipelining, as well as concurrent (de)compression
// of multiple blocks can be performed.
// 
// Threading in the Imf library is controllable at two granularities.
//
// *    The functions in this file query and control the number of worker
// threads which will be created globally for the whole library. Regardless of
// how many input or output files are opened simultaneously the library will
// use this number of threads to perform all work. The default number of global
// worker threads is zero (i.e. a single-threaded library).
//
// *    Furthermore, it is possible to set the number of threads that each
// input or output file should keep busy. This number can be explicitly set
// for each file. The default behavior is for each file to try to occupy all
// threads in the global threadpool.
//
//-----------------------------------------------------------------------------

namespace Imf {


//-----------------------------------------------------------------------------
// Returns the number of Imf-global worker threads used for parallel
// (de)compression of EXR files.
//-----------------------------------------------------------------------------
    
int     globalThreadCount ();


//-----------------------------------------------------------------------------
// Change the number of Imf-global worker threads
//-----------------------------------------------------------------------------

void    setGlobalThreadCount (int count);

} // namespace Imf

#endif