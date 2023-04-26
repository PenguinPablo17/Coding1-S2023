#include "enemy.h"
#include <iostream>
using namespacestd;

int main() {
  std::cout << "Hello World!\n";

  enemy duke("Duke");
  duke.status();

  cout << "there was a storm! Duke loses 2 health.\n";
  duke.changeHealth(-2);
  cout << "Dukes's health is now " << duke.getHealth() << ".\n";

  cout << "What would you like to name duke?\n";
  string input;
  cin >> input;

  duke.name = input;
  cout << "Duke is now named " << duke.name << ".\n";
}