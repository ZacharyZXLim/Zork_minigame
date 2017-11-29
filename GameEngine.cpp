#include "GameEngine.h"
#include <iostream>

using namespace std;

void GameEngine::Error() {
  cout << "Error" << endl;
}

void GameEngine::Operation(Map* map_ptr, Input input, int* currentRoom, int* gameOverStatusPtr) {
  if(map_ptr == nullptr) {
    cout << "map_ptr is null in GameEngine::Operation" << endl;
    *gameOverStatusPtr = 1;
    return;
  }

  //navigation
  if(input.getDirection() != "") {
    if (input.getDirection() == "north" || input.getDirection() == "n") {
      this->direction = "north";
    }

    else if (input.getDirection() == "south" || input.getDirection() == "s") {
      this->direction = "south";
    }

    else if (input.getDirection() == "east" || input.getDirection() == "e") {
      this->direction = "east";
    }

    else if (input.getDirection() == "west" || input.getDirection() == "w") {
      this->direction = "west";
    }

    //find the room name based on the border name and change currentRoom to that room
    for(int i = 0; i < map_ptr->getRoom(*currentRoom).getBorderlistSize(); i++) {
      if(map_ptr->getRoom(*currentRoom).getBorder(i).getDirection() == this->direction) {
	for(int j = 0; j < map_ptr->getRoomlistSize(); j++) {
	  if(map_ptr->getRoom(j).getName() == map_ptr->getRoom(*currentRoom).getBorder(i).getName()) {
	    *currentRoom = j;
	    cout << map_ptr->getRoom(*currentRoom).getDescription() << endl;
	    return;
	  }
	}
      }
    }

    cout << "Can't go that way." << endl;
  }

  //
  
  return;
}

void RunGame(Map* map_ptr) {
  Input input;
  GameEngine gameEngine;
  
  int gameOverStatus = 0;
  int currentRoom = 0;

  if(map_ptr->getRoomlistSize() == 0) {
    gameEngine.Error();
    return;
  }

  cout << map_ptr->getRoom(currentRoom).getDescription() << endl;
  
  while(!gameOverStatus) {
    input.getInput();
    gameEngine.Operation(map_ptr, input, &currentRoom, &gameOverStatus);
  }
  
  return;
}
