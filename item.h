#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

class Item { //class for items that keeps track of their name
 public:
  Item(char*); //constructor
  char* getName();
  //getters and setters
 private:
  char* name;
};

#endif
