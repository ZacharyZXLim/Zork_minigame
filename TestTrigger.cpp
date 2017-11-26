//ONLY TEST TRIGGERSAMPLE.XML OR SAMPLETXT.XML

#include "Zork.h"
#include "Trigger.h"
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
    xml_node<>* trigger_node = creature_node->first_node("trigger");
    Trigger trigger1(trigger_node);
    
    cout << "Trigger 1: " << endl;
    cout << trigger1.getType() << endl;
    cout << trigger1.getCommand() << endl;

    if(trigger1.getActionSize() > 0) {
      for(int i = 0; i < trigger1.getActionSize(); i++)
	cout << trigger1.getAction(i) << endl;
    }

    cout << trigger1.getPrint() << endl;
    cout << "Conditon: " << endl;
    cout << trigger1.condition.getObject() << endl;
    cout << trigger1.condition.getStatus() << endl;
    cout << trigger1.condition.getOwner() << endl;
    cout << trigger1.condition.getHas() << endl;
    cout << endl;
    
    trigger_node = creature_node->next_sibling("creature")->first_node("trigger");
    Trigger trigger2(trigger_node);

    cout << "Trigger 2: " << endl;
    cout << trigger2.getType() << endl;
    cout << trigger2.getCommand() << endl;

    if(trigger2.getActionSize() > 0) {
      for(int i = 0; i < trigger2.getActionSize(); i++)
	cout << trigger2.getAction(i) << endl;
    }

    cout << trigger2.getPrint() << endl;
    cout << "Conditon: " << endl;
    cout << trigger2.condition.getObject() << endl;
    cout << trigger2.condition.getStatus() << endl;
    cout << trigger2.condition.getOwner() << endl;
    cout << trigger2.condition.getHas() << endl;
    cout << endl;
    cout << endl;
  }

  else if(string(argv[1]) == "sampletxt.xml") {
    xml_node<>* creature_node = map_node->first_node("creature");
    xml_node<>* trigger_node = creature_node->first_node("trigger");
    Trigger trigger1(trigger_node);
    
    cout << "Trigger 1: " << endl;
    cout << trigger1.getType() << endl;
    cout << trigger1.getCommand() << endl;

    if(trigger1.getActionSize() > 0) {
      for(int i = 0; i < trigger1.getActionSize(); i++)
	cout << trigger1.getAction(i) << endl;
    }

    cout << trigger1.getPrint() << endl;
    cout << endl;
    cout << "Conditon: " << endl;
    cout << trigger1.condition.getObject() << endl;
    cout << trigger1.condition.getStatus() << endl;
    cout << trigger1.condition.getOwner() << endl;
    cout << trigger1.condition.getHas() << endl;
    cout << endl;
  }

  return 0;
}
