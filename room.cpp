#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

Room::Room() {} //constructor

char* Room::getDescription() { //returns description
  return description;
}

char* Room::getName() { //returns name
  return name;
}

bool Room::isValidRoom(char* room) { //checks if a room exists
  map<const char*, Room*>::iterator i;
  for (i = this->exits.begin(); i != this->exits.end(); ++i) {
    if (strcmp(i->first, room) == 0) {
      return true;
    }
  }
}

Room* Room::getExitRoom(char* room) { //returns all exit rooms for a room
  map<const char*, Room*>::iterator i;
  for (i = this->exits.begin(); i != this->exits.end(); ++i) {
    if (strcmp(i->first, room) == 0) {
      return i->second;
    }
  }
  return 0;
}

vector<Item*>* Room::getItems() { //returns all items in a room
  return &items;
}

map<const char*, Room*>* Room::getExits() { //returns exits for a room
  return &exits;
}

void Room::addItem(Item* item) { //adds an item to a room
  items.push_back(item);
}

void Room::getExitDirections() { //returns exit directions for a room
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

bool Room::validItem(char* itemName) { //checks if an item exists in a room
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    if (strcmp((*it)->getName(), itemName) == 0) {
      return true;
    }
  }
  return false;
}

void Room::printItems() { //prints all items in a room
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    cout << (*it)->getName() << " ";
  }
  cout << endl;
}

Item* Room::getItem(char* itemName) { //method to pick up an item an put into inventory
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
