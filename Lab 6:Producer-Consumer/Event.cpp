#include "Event.h"
#include <iostream>
#include <stdlib.h>

Event::Event() {

  myChar = 'a'+rand()%26;
  std::cout << "producing" << myChar << std::endl;
}

bool Event::consume() {
  char newChar = myChar-32;
  std::cout << "consuming" << myChar << std::endl;
}

