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

void Room::getExitDirections() {
  int i = 0;
  map<const char*, Room*>::iterator it;
  for (it = this->exits.begin(); it != this->exits.end(); ++it) {
    if (i == 0) {
      cout << it->first;
      i++;
    }
    else {
      cout << ", " << it->first;
    }
  }
  cout << endl;
}

bool Room::validItem(char* itemName) {
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    if (strcmp((*it)->getName(), itemName) == 0) {
      return true;
    }
  }
  return false;
}

void Room::printItems() {
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    cout << (*it)->getName() << " ";
  }
  cout << endl;
}

Item* Room::getItem(char* itemName) {
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    if (strcmp((*it)->getName(), itemName) == 0) {
      Item* i = (*it);
    it:items.erase(it);
      return (i);
    }
  }
  return NULL;
}
