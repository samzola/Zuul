#include <iostream>
#include <cstring>
#include "room.h"
#include "player.h"
#include "parser.h"

using namespace std;

int main() {
  char command[50];
  bool playing = true;
  Parser parser;
    
  cout << "As you try to open the door and leave your school, a very large security guard yells, \"You can'tleave unless you bring me a cheeseburger!!!!\"" << endl << endl << "It looks like you must go around the school and find ingredients, then bring them to the kitchenand make a burger." << endl << "Then, the security guard will hopefully let you leave!" << endl;
  
  Room* entrance = new Room();
  strcpy(entrance->getName(), "Main Entrance");
  strcpy(entrance->getDescription(), "You just stepped into the school and currently stand by the main entrance. There's an office to your right and a big hallway ahead of you.");
  Room* office = new Room();
  strcpy(office->getName(), "Main Office");
  strcpy(office->getDescription(), "You are in the main office, where all of the official business goes down. The only door is the one that you entered through.");
  Room* mainHall = new Room();
  strcpy(mainHall->getName(), "Main Hallway");
  strcpy(mainHall->getDescription(), "You are in the main hallway. There are two halls, one in front of you and one to your left.");
  Room* westHall1 = new Room();
  strcpy(westHall1->getName(), "West Hallway");
  strcpy(westHall1->getDescription(), "You are in the middle of the west hallway, on the way to the west wing of the school. You can only keep going forward or turn back.");  
  Room* westHall2 = new Room();
  strcpy(westHall2->getName(), "West Hallway");
  strcpy(westHall2->getDescription(), "You've reached the end of the west hallway, and see three classrooms around you. In one class, some cool students are doing some awesome coding.");
  Room* computer = new Room();
  strcpy(computer->getName(), "Computer Lab");
  strcpy(computer->getDescription(), "You step into the computer lab. An extremely unhappy Mr. Galbraith asks you why you aren't in class.");  
  Room* english = new Room();
  strcpy(english->getName(), "English Classroom");
  strcpy(english->getDescription(), "You walk into the english classroom. Even though this is a high school, the teacher is going over the alphabet.");
  Room* history = new Room();
  strcpy(history->getName(), "History Classroom");
  strcpy(history->getDescription(), "You walk into a room decorated as Ancient Rome. This must be the history classroom. The teacher greets you in Latin.");  
  Room* northHall1 = new Room();
  strcpy(northHall1->getName(), "North Hallway");
  strcpy(northHall1->getDescription(), "You step into the north hallway, which continues forward. There is a classroom on your right.");
  Room* northHall2 = new Room();
  strcpy(northHall2->getName(), "North Hallway");
  strcpy(northHall2->getDescription(), "You continue through the north hallway. You can either go straight, walk left into another hallway, or take a right into a classroom.");
  Room* northHall3 = new Room();
  strcpy(northHall3->getName(), "North Hallway");
  strcpy(northHall3->getDescription(), "You've reached the end of the main hallway. You can take a right or go back towards where you came from.");  
  Room* biology = new Room();
  strcpy(biology->getName(), "Biology Classroom");
  strcpy(biology->getDescription(), "You are in the biology classroom. All of the students look bored reading their textbooks.");
  Room* chemistry = new Room();
  strcpy(chemistry->getName(), "Chemistry Classroom");
  strcpy(chemistry->getDescription(), "You walk into the chemistry room. The teacher demonstrates a crazy chemical reaction.");
  Room* physics = new Room();
  strcpy(physics->getName(), "Physics Classroom");
  strcpy(physics->getDescription(), "You enter the physics classroom. The teacher is playing with circuits and swinging bowling balls on pendulums.");
  Room* math = new Room();
  strcpy(math->getName(), "Math Classroom");
  strcpy(math->getDescription(), "You've reached the math classroom, where the students are trying to solve complex equations that make no sense to you.");  
  Room* gymHall = new Room();
  strcpy(gymHall->getName(), "Gym Hallway");
  strcpy(gymHall->getDescription(), "You are in the gym hallway, with two sets of double doors in front of you and  two doors on your right that read 'Boys' and 'Girls.'");
  Room* lockers = new Room();
  strcpy(lockers->getName(), "Locker Room");
  strcpy(lockers->getDescription(), "You walk into the locker room. Nobody is currently inside, but it smells like people were here recently.");
  Room* gym = new Room();
  strcpy(gym->getName(), "Gym");
  strcpy(gym->getDescription(), "You are now inside the gym, the biggest room in the school. On your right, a group of students are playing pickup basektball, while on your left, students are playing soccer.");
  Room* kitchen = new Room();
  strcpy(kitchen->getName(), "Kitchen");
  strcpy(kitchen->getDescription(), "You are in the kitchen. Smells fill your nose and you suddenly feel like you could make a burger in this room.");
  
  Item* patty = new Item((char*) "Patty");
  lockers->addItem(patty);
  Item* bun = new Item((char*) "Bun");
  history->addItem(bun);
  Item* cheese = new Item((char*) "Cheese");
  computer->addItem(cheese);
  Item* tomato = new Item((char*) "Tomato");
  math->addItem(tomato);
  Item* lettuce = new Item((char*) "Lettuce");
  biology->addItem(lettuce);
  Item* pickles = new Item((char*) "Pickles");
  gym->addItem(pickles);
  Item* burger = new Item((char*) "Burger");

  entrance->getExits()->insert(pair<const char*, Room*>("north", mainHall));
  entrance->getExits()->insert(pair<const char*, Room*>("east", office));
  office->getExits()->insert(pair<const char*, Room*>("west", entrance));
  mainHall->getExits()->insert(pair<const char*, Room*>("east", math));
  mainHall->getExits()->insert(pair<const char*, Room*>("north", northHall1));
  mainHall->getExits()->insert(pair<const char*, Room*>("west", westHall1));
  mainHall->getExits()->insert(pair<const char*, Room*>("south", entrance));
  westHall1->getExits()->insert(pair<const char*, Room*>("west", westHall2));
  westHall1->getExits()->insert(pair<const char*, Room*>("east", mainHall));
  westHall2->getExits()->insert(pair<const char*, Room*>("west", english));
  westHall2->getExits()->insert(pair<const char*, Room*>("north", computer));
  westHall2->getExits()->insert(pair<const char*, Room*>("south", history));
  westHall2->getExits()->insert(pair<const char*, Room*>("east", westHall1));
  computer->getExits()->insert(pair<const char*, Room*>("south", westHall2));
  english->getExits()->insert(pair<const char*, Room*>("east", westHall2));
  history->getExits()->insert(pair<const char*, Room*>("north", westHall2));
  northHall1->getExits()->insert(pair<const char*, Room*>("south", mainHall));
  northHall1->getExits()->insert(pair<const char*, Room*>("north", northHall2));
  northHall1->getExits()->insert(pair<const char*, Room*>("west", kitchen));
  northHall1->getExits()->insert(pair<const char*, Room*>("east", physics));
  northHall2->getExits()->insert(pair<const char*, Room*>("south", northHall1));
  northHall2->getExits()->insert(pair<const char*, Room*>("north", northHall3));
  northHall2->getExits()->insert(pair<const char*, Room*>("west", gymHall));
  northHall2->getExits()->insert(pair<const char*, Room*>("east", chemistry));
  northHall3->getExits()->insert(pair<const char*, Room*>("south", northHall2));
  northHall3->getExits()->insert(pair<const char*, Room*>("east", biology));
  biology->getExits()->insert(pair<const char*, Room*>("west", northHall3));
  chemistry->getExits()->insert(pair<const char*, Room*>("west", northHall2));
  physics->getExits()->insert(pair<const char*, Room*>("west", northHall1));
  math->getExits()->insert(pair<const char*, Room*>("west", mainHall));
  gymHall->getExits()->insert(pair<const char*, Room*>("west", gym));
  gymHall->getExits()->insert(pair<const char*, Room*>("north", lockers));
  gymHall->getExits()->insert(pair<const char*, Room*>("east", northHall2));
  lockers->getExits()->insert(pair<const char*, Room*>("south", gymHall));
  gym->getExits()->insert(pair<const char*, Room*>("east", gymHall));
  kitchen->getExits()->insert(pair<const char*, Room*>("east", northHall1));

  Player* player = new Player(entrance);

  player->getCurrentRoom()->getDescription();
  cout << endl << "Exits: ";
  player->getCurrentRoom()->getExitDirections();
  cout << endl << "Items: ";
  player->getCurrentRoom()->printItems();
  cout << endl;
  
  while (playing == true) {
    cout << "Please type in a command." << endl;
    cin.get(command, 50);
    cin.clear();
    cin.ignore(1000000, '\n');
    playing = parser.processCommand(command, player);
  }
  
  return 0;
}
