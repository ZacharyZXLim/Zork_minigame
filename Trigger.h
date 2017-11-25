#ifndef TRIGGER_H
#define TRIGGER_H
#include "Condition.h"
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

class Item{
public:  
  Item(rapidxml::xml_node<>*);
  virtual ~Item();
  
  std::string getName();
  std::string getWriting();
  std::string getStatus();
  std::string getTurnonPrint();
  std::string getTurnonAction();
  
private:
  std::string name;
  std::string writing;
  std::string status;
  turnon TurnOn;
};

#endif
