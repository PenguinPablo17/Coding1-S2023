#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

int health = 30;
int totalTreasure = 0;

int rollDie(int sides = 6) {
  int roll = rand() % sides + 1;
  return roll;
}
bool askYN(string question) {
  while (true) {
    cout << question << " (y/n)\n";
    char input;
    cin >> input;

    if (input == 'y' || input == 'Y') {
      return true;
    } else if (input == 'n' || input == 'N') {
      return false;
    }
  }
}
void adventure() {
  int attack = rollDie();
  int block = rollDie();
  int treasure = rollDie(20); // replacing the middle space with 20 turns it
                              // into the 20 sided die you need
  if (askYN("You spot a goblin, would you like to attack it? (y/n)") == true) {
    cout << "You make an attack!\n";
    cout << "You strike for " << rollDie() << " damage.\n";
    cout << "The Goblin blocks " << rollDie() << " damage.\n";
  } else {
    cout << "You return home.\n";
  }
  if (attack > block) {
    cout << "You have been hit!\n";
    health -= attack;
  } else {
    cout << "successful block!\n";
    totalTreasure += treasure;
  }
}

int main() {
  srand(time(0));
  cout << "Hello adventurer! \nThe family business is close to going "
          "bankrupt.\nThe only way to save it is to go and fight goblins for "
          "their gold.\n";
  while (true) {
    if (askYN("Would you like to go forth and fight?") == true) {
      cout << "Good luck adventurer! You are going to need at least 100 gold\n"
              "before your family can rest easy\n";
      adventure();
    } else {
      cout << "Well let's hope ma and pa can make due selling the bad crops.\n";
      return 0;
    }
  }
}