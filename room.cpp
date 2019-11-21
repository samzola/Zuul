#include <iostream>
#include <cstring>
#include <vector>
#include <map>
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

bool Room::isValidRoom(char* room) {
  map<const char*, Room*>::iterator i;
  for (i = this->exits.begin(); i != this->exits.end(); ++i) {
    if (strcmp(i->first, room) == 0) {
      return true;
    }
  }
}

Room* Room::getExitRoom(char* room) {
  map<const char*, Room*>::iterator i;
  for (i = this->exits.begin(); i != this->exits.end(); ++i) {
    if (strcmp(i->first, room) == 0) {
      return i->second;
    }
  }
  return 0;
}

vector<Item*>* Room::getItems() {
  return &items;
}

map<const char*, Room*>* Room::getExits() {
  return &exits;
}

void Room::addItem(Item* item) {
  items.push_back(item);
}

