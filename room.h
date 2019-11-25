#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;
class Item;

class Room {
 public:
  Room(); //constructor
  //getters and setters
  char* getName();
  char* getDescription();
  bool isValidRoom(char*);
  Room* getExitRoom(char*);
  vector<Item*>* getItems();
  map<const char*, Room*>* getExits();
  void addItem(Item*);
  void getExitDirections();
  Item* getItem(char*);
  void printItems();
  bool validItem(char* itemName);
 private:
  char name[25];
  char description[500];
  vector<Item*> items;
  map<const char*, Room*> exits;
};

#endif
  
