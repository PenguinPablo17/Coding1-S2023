#include "enemy.h"
#include <iostream>
using std::cout;
// define the constructor
enemy::enemy(string givenName) {
  name = givenName;
  health = 10;
  cout << name << " has appeared.\n";
}

void enemy::status() {
  cout << "My name is " << name << " and my health is ";
  cout << health << ".\n";
}

void enemy::changeHealth(int by) {
  health += by;
  if (health < 0)
    health = 0;
  if (health > 10)
    health = 10;
}
int enemy::getHealth() {
    return health;
}

void enemy::setName(string to) {
  name = to;
}

string enemy::getName() {
    return name;
}