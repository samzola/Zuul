#include <iostream>
#include <cstring>
#include <vector>
#include "parser.h"
#include "room.h"
#include "player.h"
#include "item.h"

using namespace std;

char* Parser::substr(char* str, int start, int end) { //Credit: Tejash Panda
  char* sub = new char[end-start+1];
  int x = 0;
  for (int i = start; i < end; i++) {
    sub[x] = str[i];
    x++;
  }
  return sub;
}

bool Parser::processCommand(char* str, Player* player) {
  if (strncmp(str, "go ", 3) == 0) {
    char* direction = substr(str, 3, strlen(str) + 1);
    if (player->getCurrentRoom()->isValidRoom(direction)) {
      player->setCurrentRoom(player->getCurrentRoom()->getExitRoom(direction));
      cout << endl << player->getCurrentRoom()->getDescription() << endl << endl << "Exits: ";
      player->getCurrentRoom()->getExitDirections();
      cout << endl << "Items: ";
      player->getCurrentRoom()->printItems();
      cout << endl;
      delete direction;
    }
    else {
      cout << "Invalid direction." << endl;
    }
  }
  
  else if (strncmp(str, "get ", 4) == 0) {
    char* ItemName = substr(str, 4, strlen(str) + 1);
    if (player->getCurrentRoom()->validItem(ItemName)) {
      player->addItem(player->getCurrentRoom()->getItem(ItemName));
      cout << "You picked up " << ItemName << "." << endl;
    }
    else {
      cout << "Invalid item." << endl;
    }
  }
  
  else if (strncmp(str, "drop ", 5) == 0) {
    char* ItemName = substr(str, 5, strlen(str) + 1);
    if (player->validItem(ItemName)) {
      player->getCurrentRoom()->addItem(player->getItem(ItemName));
      cout << "You dropped " << ItemName << "." << endl;
    }
    else {
      cout << "Invalid item." << endl;
    }
  }
  
  else if (strcmp(str, "exits") == 0) {
    player->getCurrentRoom()->getExitDirections();
  }
  
  else if (strcmp(str, "inventory") == 0) {
    player->printInventory();
  }
  
  else if (strcmp(str, "room items") == 0) {
    player->getCurrentRoom()->printItems();
  }

  else if (strcmp(str, "cook") == 0) {
    if (strcmp(player->getCurrentRoom()->getName(), "Kitchen") == 0) {
      if (player->validItem("Tomato") && player->validItem("Bun") && player->validItem("Cheese")&& player->validItem("Pickles") && player->validItem("Lettuce") && player->validItem("Patty")) {
	cout << "You collected all of the ingredients and have cooked a delicious burger. Suddenly, the security guard comes running into the kitchen, telling you that he smelled the burger from across the school." << endl << "\"Thank you for this delicious, succulent burger. You may leave the school whenever you would like!\"" << endl << endl;

	cout << "Congratulations, you win! Thanks for playing!" << endl;
	return false;
      }
    }
    else {
      cout << "It looks like you don't have all of the ingredients to make the burger!" << endl;
    }
  }
  
  else if (strcmp(str, "quit") == 0) {
    cout << "Goodbye. Thanks for playing!" << endl;
    return false;
  }
  
  else {
    cout << "Invalid command." << endl;
  }
  
  return true;
}
