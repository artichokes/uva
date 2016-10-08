#include <iostream>
#include <queue>
#include <array>
#include <set>
#include <climits>

using namespace std;

class Graph {
 public:
  Graph() {}
  int adjmatrix[26][26] = {};

  void add_node(int node) {
    adjmatrix[node][node] = 1;
  }

  void add_edge(int source, int dest) {
    adjmatrix[source][dest] = 1;
    adjmatrix[dest][source] = 1;
  }
};

set<int> BFS(Graph graph, int root) {
  set<int> visited;

  priority_queue<int> Q;

  visited.insert(root);
  Q.push(root);

  while (!Q.empty()) {
    int current = Q.top();
    Q.pop();

    for (int i = 0; i < 26; ++i) {
      if ((i != current) // If the node is not itself
          && (graph.adjmatrix[current][i] != 0)) { // And there is a node
        if (visited.find(i) == visited.end()) {// If the node has not been visited
          visited.insert(i);
          Q.push(i);
        }
      }
    }
  }

  return visited;
}

int main() {
  int cases = 0;

  cin >> cases;
  cin.get();

  for (int i = 0; i < cases; ++i) {
    Graph graph;
    int subgraphs = 0;
    set<int> letters;
    string input;

    cin >> input;
    cin.ignore();
    graph.add_node(input[0] - 'A');
    letters.insert(input[0] - 'A');

    while (getline(cin, input) && !input.empty()) {
      graph.add_edge(input[0] - 'A', input[1] - 'A');
      letters.insert(input[0] - 'A');
      letters.insert(input[1] - 'A');
    }

    while (!letters.empty()) {
      set<int> result = BFS(graph, *letters.begin());

      for (auto letter : result) {
        auto it = letters.find(letter);
        letters.erase(it);
      }

      ++subgraphs;
    }

    cout << subgraphs << endl << endl;
  }

  return 0;
}
