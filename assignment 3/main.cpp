#include <iostream>
using namespace std;

int main() {
  cout << "Hello World!\n";

  // what is the i for?

  // for(setup; test; action) { code }
  for (int loopCount = 0; true; loopCount += 1) {
    cout << loopCount << "\n";

    if (loopCount > 5) {
      break;
    } // end of if statement

  } // end of for loop

  if (true) {
    // an array can only hold one type of variable.
    // var type, var name [size of array]
    string pizzaToppings[5];

    int scores[10];

    pizzaToppings[0] = "Pepperoni";
    pizzaToppings[1] = "Ham";
    pizzaToppings[2] = "Pineapple";

    cout << pizzaToppings[0] << "\n";
    cout << pizzaToppings[1] << "\n";
    cout << pizzaToppings[2] << "\n";

    cout << "\nSame thing but with a for loop:\n\n";

    for (int i = 0; i < 3; i += 1) {
      cout << pizzaToppings[i] << "\n";
    }

    string name = "Brian foster";
    // .size() = 12

    cout << name << " has a size of " << name.size() << ".\n";

    string favGames[100];

    int index = 0;
      cout << "\n\n\nwhat are your 10 favorite games?\n\n";
    while (true) {
      cout << "What would you like to do?\n";
      cout << "Type 'quit' to quit the program.\n";
      cout << "Type 'add' to add a game.\n";
      cout << "Type 'bulkadd' to add multiple games.'\n'";
      cout << "Type 'show' to show your favourite games.\n";
      cout << "Type 'edit' to ...\n";
      cout << "Type 'editlast' ...\n";

      cout << ">>";

      // get input
      string input;
      cin >> input;

      // test the input
      if (input == "quit") {
        cout << "Shutting down...\n";
        break; // or return 0 to REALLY quit the program.
      }

      else if (input == "add") {
        cout << "What game would you like to add?\n";
        cin >> input;
        favGames[index] = input; // ex: favGames[0] = "Mario";
        index++;                 // index is now pointing at the next spot.
      }
      
      else if (input == "bulkadd") {
        while (true){
          cout << "What games would you like to add? type 'exit' to stop adding names.\n";
          cin >> input;
            if (input == "exit"){
              cout << "returning\n";
              break;
            }
          else {
            favGames[index] = input;
            index++;
          }
          }
      }
        else if (input == "show") {
        cout << "Here are your favourite games:\n";
        for (int i = 0; i < index; i += 1) {
          cout << i + 1 << ". " << favGames[i] << "\n";
        }
      }

      // what if we mess up?
      else if (input == "edit") {
        cout << "What is the number of the name you want to change?\n";
        int numInput;
        cin >> numInput;

        cout << "What would you like to change " << favGames[numInput - 1]
             << " to?\n";
        cin >> input;
        favGames[numInput - 1] = input;
      }

      else if (input == "editlast") {
        cout << "last entry was " << favGames[index - 1]
             << ", change to what?\n>>";
        cin >> input;
        favGames[index - 1] = input;
      }

      else if (input == "find") {
        cout << "what game do you want to find?\n";
        cin >> input;

        // look through the games to see if you can find input
        for (int i = 0; i < index; i += 1) {

          if (input == favGames[i]) {
            cout << "Found it!\n";
            cout << "what'd'ya wanna change it to?\n";
            cin >> input;

            favGames[i] = input;
            break;
          }

          if (i + 1 == index) {
            cout << "I looked through the entire list and couldn't find "
                 << input << ".\n";
          }
        } // end of for loop
      }

      else {
        cout << "[command not recognized]\n";
      }

    } // end of while(true)

  } // end of if(true)
} // end of program