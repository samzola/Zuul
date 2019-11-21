#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"

using namespace std;

Player::Player(Room* startRoom) {
  currentRoom = startRoom;
}

Room* Player::getCurrentRoom() {
  return currentRoom;
}

void Player::setCurrentRoom(Room* newRoom) {
  currentRoom = newRoom;
}
