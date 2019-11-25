#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

Item::Item(char* newName) { //constructor, allows name to be set
  name = newName;
}

char* Item::getName() { //returns item name
  return name;
};

