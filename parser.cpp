#include <iostream>
#include <cstring>
#include <vector>
#include "parser.h"
#include "room.h"
#include "player.h"
#include "item.h"

using namespace std;

char* Parser::substr(char* str, int start, int end) { //returns substring Credit: Tejash Panda
  char* sub = new char[end-start+1]; //allocate to heap (via Tejash and Andrew)
  int x = 0; //counter
  for (int i = start; i < end; i++) {
    sub[x] = str[i]; //make characters equal
    x++; //add 1 to counter
  }
  return sub; //return substring
}

bool Parser::processCommand(char* str, Player* player) {
  if (strncmp(str, "go ", 3) == 0) { //if user enters go, use the string to find the direction
    char* direction = substr(str, 3, strlen(str) + 1);
    if (player->getCurrentRoom()->isValidRoom(direction)) { //if exit exits, go there
      player->setCurrentRoom(player->getCurrentRoom()->getExitRoom(direction));
      //display the new room's description, exits, and items
      cout << endl << player->getCurrentRoom()->getDescription() << endl << endl << "Exits: ";
      player->getCurrentRoom()->getExitDirections();
      cout << endl << "Items: ";
      player->getCurrentRoom()->printItems();
      cout << endl;
      delete direction; //delete direction char
    }
    else {
      cout << "Invalid direction." << endl;
    }
  }
  
  else if (strncmp(str, "get ", 4) == 0) { //if user enters get, use string to find the item
    char* ItemName = substr(str, 4, strlen(str) + 1);
    if (player->getCurrentRoom()->validItem(ItemName)) { //check if item exists, and pick up
      player->addItem(player->getCurrentRoom()->getItem(ItemName));
      cout << "You picked up " << ItemName << "." << endl; //tell user
    }
    else {
      cout << "Invalid item." << endl;
    }
  }
  
  else if (strncmp(str, "drop ", 5) == 0) { //if user enters drop, use string to find item
    char* ItemName = substr(str, 5, strlen(str) + 1);
    if (player->validItem(ItemName)) { //if the user has the selected item, drop it
      player->getCurrentRoom()->addItem(player->getItem(ItemName));
      cout << "You dropped " << ItemName << "." << endl; //tell user
    }
    else {
      cout << "Invalid item." << endl;
    }
  }
  
  else if (strcmp(str, "exits") == 0) { //print exits
    player->getCurrentRoom()->getExitDirections();
  }
  
  else if (strcmp(str, "inventory") == 0) { //print inventory
    player->printInventory();
  }
  
  else if (strcmp(str, "room items") == 0) { //print items in a room
    player->getCurrentRoom()->printItems();
  }

  else if (strcmp(str, "cook") == 0) { //WINNING CONDITION
    //if user has all items in the kitchen, they win
    if (strcmp(player->getCurrentRoom()->getName(), "Kitchen") == 0) {
      if (player->validItem("Tomato") && player->validItem("Bun") && player->validItem("Cheese")&& player->validItem("Pickles") && player->validItem("Lettuce") && player->validItem("Patty")) {
	cout << "You collected all of the ingredients and have cooked a delicious burger. Suddenly, the security guard comes running into the kitchen, telling you that he smelled the burger from across the school." << endl << "\"Thank you for this delicious, succulent burger. You may leave the school whenever you would like!\"" << endl << endl;

	cout << "Congratulations, you win! Thanks for playing!" << endl; //tell user
	return false; //end game
      }
    }
    else {
      cout << "It looks like you don't have all of the ingredients to make the burger!" << endl;
    }
  }
  
  else if (strcmp(str, "quit") == 0) { //quit the game
    cout << "Goodbye. Thanks for playing!" << endl;
    return false;
  }
  
  else {
    cout << "Invalid command." << endl;
  }
  
  return true;
}
