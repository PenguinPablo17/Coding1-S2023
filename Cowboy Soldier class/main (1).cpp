#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

/*
  at least two data members,
  constructors that will randomly populate the data or
  allow for customization (for example: robot("artoo", 5))
  a status() member function and at least one other member function.
  also create a UML diagram for the class, either on paper or digitally.
*/

string guns[5];

class soldier {
public:
  string name;
  int health;
  string favGun;
  int ammo;
  bool alive;

  soldier() {
    name = "John Doe";
    health = 0;
    favGun = "pew pew";
    ammo = 0;
    alive = true;
  }

  soldier(string givenName, int givenHealth, string givenGun, int givenAmmo) {
    name = givenName;
    health = givenHealth;
    favGun = givenGun;
    ammo = givenAmmo;
    alive = true;
  }

  void status() {
    cout << name << " has " << health << " health left and " << ammo
         << " rounds left.\n";
  }

}; // end of class

soldier soldiers[5];

void startNextDay() {
  cout << "\n\nAnother day passes...\n\n";

  for (int i = 0; i < 5; i++) {
    if (soldiers[i].alive == false) {
      continue;
    }
    soldiers[i].health -= rand() % 20 + 10;
    if (soldiers[i].health <= 0) {
      cout << "\n" << soldiers[i].name << " has died.\n\n";
      soldiers[i].alive = false;
    }
    soldiers[i].ammo -= rand() % 100 + 50;
    if (soldiers[i].ammo <= 0 && soldiers[i].alive == true) {
      cout << soldiers[i].name << " is out of ammo.\n";
      soldiers[i].ammo = 0;
    }
    if (soldiers[i].alive == true) {
      soldiers[i].status();
    }
  }
}

bool askYN(string question = "Continue...? (y/n)\n") {
  while (true) {
    cout << question;
    char input;
    cin >> input;
    if (input == 'y') {
      return true;
    } else if (input == 'n') {
      return false;
    }
  }
}

int main() {

  string gunNames[] = {"AK-74",    "SPAZ",       "Deagle", "Magnum",  "Dao12",
                       "Crossbow", "M1 Garande", "Glock",  "Banelli", "AR-15"};
  string soldierNames[] = {"Arthur", "Dutch", "Jebubbadiah", "Karen", "Morgan",
                           "Abby",   "Jack",  "Hosea",       "Chuck", "Sean"};
  for (int i = 0; i < 5; i++) {
    soldiers[i] = soldier(soldierNames[rand() % 10], rand() % 25 + 75,
                          gunNames[rand() % 10], rand() % 250 + 100);
    cout << soldiers[i].name << " has " << soldiers[i].health << " health.\n";
    cout << "They are using " << soldiers[i].favGun << " with "
         << soldiers[i].ammo << " rounds of ammo.\n";
  }

  while (askYN()) {
    startNextDay();
  }
}