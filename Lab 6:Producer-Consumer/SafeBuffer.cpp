#include "SafeBuffer.h"


SafeBarrier::SafeBarrier(int size) {

  
  mutex.reset(new Semaphore(1) );
  items.reset(new Semaphore(0) );
  spaces.reset(new Semaphore(size) );
}


void SafeBarrier::put(std::shared_ptr<Event> e) {

  
}

std::shared_ptr<Event> SafeBarrier::get() {

  
}

SafeBarrier::~SafeBarrier() {
  mutex.reset();
  items.reset();
  spaces.reset();
  
}
