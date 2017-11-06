#include <string>
#include "Input.h"
#include "rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

int main() {
	Input input;

	while (true) {
		cout << "Type input here :" << endl;
		input.getInput();

		cout << "direction: " << input.returnDirection() << endl;
		cout << "command: " << input.returnCommand() << endl;
		cout << "creature: " << input.returnCreature() << endl;
		cout << "item: " << input.returnItem() << endl;
		cout << "container: " << input.returnContainer() << endl;
	}

	return 0;
}