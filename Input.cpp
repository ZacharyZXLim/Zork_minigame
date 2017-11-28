#include <iostream>
#include <string>
#include "Input.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

void Input::getInput() {
  string str1("");
  string str2("");
  string str3("");
  string str4("");
  
  //reset all variables
  direction = "";
  command = "";
  container = "";
  item = "";
  creature = "";
  direction = "";
  
  cin >> str1;
  
  if (str1 == "n" || str1 == "s" || str1 == "e" || str1 == "w" || str1 == "north" || str1 == "south" || str1 == "east" || str1 == "west") {
    direction = str1;
  }
  
  else if (str1 == "i" || str1 == "inventory") {
    command = str1;
  }
  
  else if (str1 == "take" || str1 == "read" || str1 == "drop") {
    command = str1;
    
    cin >> str2;
    item = str2;
  }
  
  else if (str1 == "open") {
    command = str1;
    
    cin >> str2;
    
    if (str2 == "exit") {
      //call game over function
      cout << "Game over" << endl;
      return;
    }
    
    else
      container = str2;
  }
  
  else if (str1 == "attack" || str1 == "put") { //four word input special case
    command = str1;
    
    cin >> str2;
    if (str1 == "attack")
      creature = str2;
    
    else
      item = str2;
    
    cin >> str3;
    
    cin >> str4;
		if (str1 == "attack")
		  item = str4;
		
		else
		  container = str4;
  }
  
  //not working
  else if (str1 == "turn") { //double letter special case
    cin >> str2;
    if (str2 == "on") {
      command = "turn_on";
			
      cin >> str3;
      item = str3;
    }
  }
  
  else {
    cout << "I do not recognize what you want to do." << endl;
  }
}

string Input::getDirection() {
  return direction;
}

string Input::getCommand() {
  return command;
}

string Input::getContainer() {
  return container;
}

string Input::getItem() {
  return item;
}

string Input::getCreature() {
	return creature;
}