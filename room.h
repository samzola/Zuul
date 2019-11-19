#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"

using namespace std;
class Item;

class Room {
 public:
  Room();
  char* getName();
  char* getDescription();
  vector<Item*>* getItems();
 private:
  char name[25];
  char description[500];
  vector<Item*> items;
};

#endif
  
