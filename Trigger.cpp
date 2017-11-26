#include "Trigger.h"
#include <iostream>

using namespace std;
using namespace rapidxml;

Trigger::Trigger(xml_node<>* newTrigger) : condition(newTrigger->first_node("condition")) {
  if(newTrigger != NULL) {
    if(newTrigger->first_node("type") != nullptr)
      this->type = newTrigger->first_node("type")->value();
    else
      this->type = "";
    
    if(newTrigger->first_node("command") != nullptr) 
      this->command = newTrigger->first_node("command")->value();
    else
      this->command = "";

    xml_node<>* action_listnode = nullptr;
    
    if(newTrigger->first_node("action") != nullptr) {
      action_listnode = newTrigger->first_node("action");
      action.push_back(action_listnode->value());

      while(action_listnode->next_sibling("action") != NULL) {
	action_listnode = action_listnode->next_sibling("action");
	action.push_back(action_listnode->value());
      }
    } 

    if(newTrigger->first_node("print") != nullptr) 
      this->print = newTrigger->first_node("print")->value();
    else
      this->print = "";
  }
}

string Trigger::getType() {
  return this->type;
}

string Trigger::getCommand() {
  return this->command;
}

string Trigger::getAction(int i) {
  return this->action[i];
}

int Trigger::getActionSize() {
  return this->action.size();
}

string Trigger::getPrint() {
  return this->print;
  }

Trigger::~Trigger(){

}