// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: 
// Author: Joseph
// Maintainer: 
// Created: Tue Jan  8 12:14:02 2019 (+0000)
// Version: 
// Package-Requires: ()
// Last-Updated: Tue Jan  8 12:15:21 2019 (+0000)
//           By: Joseph
//     Update #: 2
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

// Code:
#include "Semaphore.h"
#include <iostream>
#include "Barrier.h"

std::shared_ptr<Semaphore> aSemaphore( new Semaphore(1) );
int count = 0;
Barrier::Barrier(int numThreads) {

  this->numThreads = numThreads;
  
}

void Barrier::wait() {

  // count ++;
 
  // if number of threads is not at max, wait / else all can go
  if(count < numThreads){
    // increment thread count
    //  count ++;
    
    // lock other threads out
    aSemaphore->Wait();
    count ++;
    aSemaphore->Signal();
  }
  else{
    aSemaphore->Signal();
    count = 0;
  }
  
  // aSemaphore->Signal();
}


Barrier::~Barrier() {

  numThreads = NULL;

}

// 
// Barrier.cpp ends here
