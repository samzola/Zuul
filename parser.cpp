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
      cout << endl << player->getCurrentRoom()->getDescription() << endl << endl;
      delete direction;
    }
    else {
      cout << "Invalid direction." << endl;
    }
  }
  else if (strcmp(str, "quit") == 0) {
    cout << "Goodbye. Thank you for playing!" << endl;
    return false;
  }
  return true;
}
