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

vector<Item*>* Player::getItems() {
  return &items;
}

void Player::addItem(Item* item) {
  items.push_back(item);
}

Item* Player::getItem(char* itemName) {
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    if (strcmp((*it)->getName(), itemName) == 0) {
      Item* i = (*it);
      it = items.erase(it);
      return (i);
    }
  }
  return 0;
}

bool Player::validItem(char* itemName) {
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    if (strcmp((*it)->getName(), itemName) == 0) {
      return true;
    }
  }
	 return false;
}

void Player::printInventory() {
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    cout << "\"" << (*it)->getName() << "\"" << " ";
  }
  cout << endl;
}
