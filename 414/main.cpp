/*
 * Peter Nguyen
 * UVa Online Judge Problem 414
 */

#include <iostream>

using namespace std;

int main() {
  int lines = 0;

  while (!(cin >> lines).fail() && lines != 0) {
    char characters[26];
    int totalspaces = 0;
    int minspaces = 25;

    for (int i = 0; i < lines; ++i) {
      int linespaces = 0;

      cin.ignore();
      cin.get(characters, 25);
      cin.ignore();
//      cout << characters << endl;

      for (auto character : characters) {
        if (character == ' ') {
          ++totalspaces;
          ++linespaces;
        }
      }

      if (linespaces < minspaces)
        minspaces = linespaces;
    }

//    cout << totalspaces << ' ' << minspaces << endl;
    cout << totalspaces - (lines * minspaces) << endl;
  }

  return 0;
}
