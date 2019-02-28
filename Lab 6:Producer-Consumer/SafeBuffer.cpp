#include "SafeBuffer.h"


SafeBuffer::SafeBuffer() {

  
  mutex = std::make_shared<Semaphore>(1);
  theSemaphore = std::make_shared<Semaphore>(0);
  // items.reset(new Semaphore(0) );
  // spaces.reset(new Semaphore(size) );
}//const


int SafeBuffer::put(Event e) {
  mutex->Wait();
  theEvents.push_back(e);
  int size = theEvents.size();
  mutex->Signal();
  theSemaphore->Signal();
  return size ;
}//put

Event SafeBuffer::get() {
  theSemaphore->Wait();
  mutex->Wait();
  Event e = theEvents.back();
  theEvents.pop_back();
  mutex->Signal();
  return e;
}//get

