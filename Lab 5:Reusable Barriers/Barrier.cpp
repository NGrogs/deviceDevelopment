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
std::shared_ptr<Semaphore> turnstile1( new Semaphore(0) );
std::shared_ptr<Semaphore> turnstile2( new Semaphore(0) );
int count = 0;
Barrier::Barrier(int numThreads) {

  this->numThreads = numThreads;
  
}


void Barrier::phase1() {

  aSemaphore->Wait();
  count ++;
  if(count == numThreads)
    {
      for(int i= 0; i <= numThreads; i++)
	{
	  turnstile1->Signal();
	}
    }
  aSemaphore->Signal();

  turnstile1->Wait();
   turnstile1->Signal();
  
}

void Barrier::phase2() {
  
  aSemaphore->Wait();
  count --;
  if(count ==0)
    {
      for(int i =0; i <= numThreads; i++)
	{
	  turnstile2->Signal();
	}
    }
  aSemaphore->Signal();
  
  turnstile2->Wait();
  turnstile2->Signal();

}

void Barrier::wait() {

  phase1();
  phase2();
  
}


Barrier::~Barrier() {

  numThreads = NULL;
  

}

// 
// Barrier.cpp ends here
