#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

class Player {
 public:
  Player(Room*);
  Room* getCurrentRoom();
  vector<Item*>* getItems();
  void setCurrentRoom(Room*);
  void addItem(Item*);
  Item* getItem(char*);
  void printInventory();
  bool validItem(char*);
 private:
  Room* currentRoom;
  vector<Item*> items;
  };

#endif
