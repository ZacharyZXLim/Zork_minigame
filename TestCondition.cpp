//ONLY TEST TRIGGERSAMPLE.XML OR SAMPLETXT.XML

#include "Zork.h"
#include "Condition.h"
#include <iostream>

using namespace std;
using namespace rapidxml;

int main(int argc, char** argv) {
  Zork zork;
  zork.initializeGame(argv[1]);

  xml_document<>* xml_doc = zork.getXMLDocument();
  xml_node<>* map_node = NULL;
  xml_node<>* list_node = NULL;

  if(xml_doc->first_node() != NULL) {
    map_node = xml_doc->first_node();
  }

  if(string(argv[1]) == "triggersample.xml") {
    xml_node<>* creature_node = map_node->first_node("creature");
    xml_node<>* condition_node = creature_node->first_node("trigger")->first_node("condition");
    Condition condition1(condition_node);
    
    cout << "Condition 1: " << endl;
    cout << condition1.getObject() << endl;
    cout << condition1.getStatus() << endl;
    cout << condition1.getOwner() << endl;
    cout << condition1.getHas() << endl;
    cout << endl;
    
    condition_node = creature_node->next_sibling("creature")->first_node("trigger")->first_node("condition");
    Condition condition2(condition_node);

    cout << "Condition 2: " << endl;
    cout << condition2.getObject() << endl;
    cout << condition2.getStatus() << endl;
    cout << condition2.getOwner() << endl;
    cout << condition2.getHas() << endl;
    cout << endl;
  }

  else if(string(argv[1]) == "sampletxt.xml") {
    xml_node<>* creature_node = map_node->first_node("creature");
    xml_node<>* condition_node = creature_node->first_node("trigger")->first_node("condition");
    Condition condition1(condition_node);
    
    cout << "Condition 1: " << endl;
    cout << condition1.getObject() << endl;
    cout << condition1.getStatus() << endl;
    cout << condition1.getOwner() << endl;
    cout << condition1.getHas() << endl;
    cout << endl;
  }

  return 0;
}