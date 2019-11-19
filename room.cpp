#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

Room::Room() {}

char* Room::getDescription() {
  return description;
}

char* Room::getName() {
  return name;
}

vector<Item*>* Room::getItems() {
  return &items;
}

