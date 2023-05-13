#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
/*
  Your assignment is to modify the BulkAdd assignment from Week 5 (duplicate it,
to save the original please) to use functions (for code readability), to load
your array from a text file at the beginning, and to save your array to a text
file at the end. Create functions for Show Add Remove Edit Load from file Save
to file
*/
string favGames[100];
int index = 0;

void load() {
  string line;
  ifstream gamesList("list.txt");

  if (gamesList.is_open()) {
    while (getline(gamesList, line)) {
      favGames[index++] = line;
    }
  } else {
    cout << "File could not be loaded.\n";
  }
}

void save() {
  ofstream gamesList;
  gamesList.open("list.txt");
  for (int i = 0; i < index; i++) {
    gamesList << favGames[i] << "\n";
  }
  gamesList.close();
}

void add() {
  cout << "What would you like to add?\n";
  cout << "Type 'quit' to exit add mode.\n";
  while (true) {
    string input;
    getline(cin, input);
    if (input == "quit") {
      break;
    }
    favGames[index++] = input;
  }
  save();
}

void show() {
  if (index == 0) {
    cout << "Whoopsie! Your list is empty.\n";
    return;
  }
  cout << "Here is your list of games.\n";
  for (int i = 0; i < index; i++) {
    if (favGames[i] == "") {
      continue;
    }
    cout << favGames[i] << "\n";
  }
}

void remove() {
  string input;
  cout << "What game would you like to remove?\n";
  getline(cin, input);

  for (int i = 0; i < index; i++) {
    if (favGames[i] == input) {
      cout << "Found it!\n";
      cout << "Are you sure you want to remove? This cannot be undone. (y/n)\n";
      cin >> input;
      if (input == "y") {
        favGames[i] = "";
      } else if (input == "n") {
        break;
      }
    }
  }
}

void edit() {
  string input;
  cout << "Which game would you like to edit?\n";
  getline(cin, input);
  for (int i = 0; i < index; i++) {
    if (favGames[i] == input) {
      cout << "Found it!\n";
      cout << "What would you like to change it to?\n";
      getline(cin, input);
      favGames[i] = input;
    }
  }
  save();
}

int main() {
  load();
  while (true) {
    cout << "What would you like to do?\n";
    cout << "Type 'add' to add games to your list.\n";
    cout << "Type 'show' to show your list.\n";
    cout << "Type 'remove' to remove games from your list.\n";
    cout << "Type 'edit' to edit a specific entry.\n";
    cout << "Type 'quit' to quit\n";

    string input;
    getline(cin, input);
    if (input == "add") {
      add();
    }
    if (input == "show") {
      show();
    }
    if (input == "remove") {
      remove();
    }
    if (input == "edit") {
      edit();
    }
    if (input == "quit") {
      break;
    }
  }
}