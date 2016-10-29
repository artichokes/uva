#include <iostream>
#include <climits>

using namespace std;


int main() {
  int nodes, edges;
  string isColor = "BICOLORABLE";

  while(!(cin >> nodes).fail()) {
    int adjMat[nodes][nodes];
    for (int i = 0; i < nodes; i++)
      for (int j = 0; j < nodes; j++)
        adjMat[i][j] = 0;

    cin >> edges;

    int first, second;
    for (int k = 0; k < edges; k++) {
      cin >> first >> second;
      adjMat[first][second] = 1;
    }

    char color[nodes];
    for (int i = 0; i < nodes; i++) {
      color[i] = ' ';
    }

    color[0] = 'r';

    for (int i = 0; i < nodes; i++) {
      for (int j = i + 1; j < nodes; j++) {
        if (adjMat[i][j] == 1) {
          if (color[j] == ' ') {
            if (color[i] == 'r')
              color[j] = 'b';
            else
              color[j] = 'r';
          }
          else if (color[i] == color[j]) {
            isColor = "NOT BICOLORABLE";
          }
        }
      }
    }
    cout << isColor << endl;
  }
}
