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
  void setCurrentRoom(Room*);
 private:
  Room* currentRoom;
};

#endif
