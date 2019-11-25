#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"

using namespace std;

Player::Player(Room* startRoom) { //constructor that includes a room
  currentRoom = startRoom;
}

Room* Player::getCurrentRoom() { //returns room that player is in
  return currentRoom;
}

void Player::setCurrentRoom(Room* newRoom) { //sets room that player is in
  currentRoom = newRoom;
}

vector<Item*>* Player::getItems() { //returns all items that the player has
  return &items;
}

void Player::addItem(Item* item) { //adds item to inventory
  items.push_back(item);
}

Item* Player::getItem(char* itemName) { //picks up item and adds to inventory
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

bool Player::validItem(char* itemName) { //checks if an item exists in inventory
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    if (strcmp((*it)->getName(), itemName) == 0) {
      return true;
    }
  }
	 return false;
}

void Player::printInventory() { //prints items that the player has
  vector<Item*>::iterator it;
  for (it = items.begin(); it != items.end(); ++it) {
    cout << "\"" << (*it)->getName() << "\"" << " ";
  }
  cout << endl;
}
