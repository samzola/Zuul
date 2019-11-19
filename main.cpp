#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

int main() {
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
  strcpy(computer->getDescription(), "You step into the computer lab. An enraged Mr. Galbraith asks you why you aren't in class.");  
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
  return 0;
}
