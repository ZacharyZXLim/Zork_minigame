#ifndef BORDER_H
#define BORDER_H
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

class Border{
private:
  std::string direction;
  std::string name;

public:
  Border(rapidxml::xml_node<>*);
  virtual ~Border();
  
  std::string getDirection();
  std::string getName();
};

#endif
