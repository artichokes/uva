/*
 * Peter Nguyen
 * UVa Online Judge Problem 10226
 */

#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {
  unsigned cases = 0;

  cin >> cases;

  cin.get();
  cin.ignore();

  for (unsigned i = 0; i < cases; ++i) {
    unsigned numtrees = 0;
    map<string, unsigned> trees;

    string tree;

    while (getline(cin, tree) && !tree.empty()) {
      auto search = trees.find(tree);

      ++trees[tree];
      ++numtrees;
    }

    for (auto  it = trees.begin(); it != trees.end(); ++it) {
      cout << it->first << ' ' << fixed << setprecision(4)
           << (static_cast<float>(it->second) / static_cast<float>(numtrees)) * 100 << endl;
    }

    if (i != cases - 1)
      cout << endl;
  }
}
