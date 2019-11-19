#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

Item::Item(char* newName) {
  name = newName;
}

char* Item::getName() {
  return name;
};

