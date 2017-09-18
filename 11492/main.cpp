/*
 * Peter Nguyen
 * UVa Online Judge Problem 11492
 */

#include <iostream>
#include <tuple>
#include <map>
#include <vector>
#include <climits>
#include <set>

using namespace std;

class Graph {
 public:
  // src, vec<(dest, edge)>
  map<string, map<string, string>> adjlist;

  void addEdge(string src, string dest, string edge) {
    adjlist[src][dest] = edge;
    adjlist[dest][src] = edge;
  }
};

string min_dist(set<string> &Q, map<string, int> &dist) {
  string min_edge = "";
  int min_dist = INT_MAX;

  for (auto it = Q.begin(); it != Q.end(); ++it) {
    if (dist[*it] < min_dist) {
      min_edge = *it;
      min_dist = dist[*it];
    }
  }

  return min_edge;
}

int dijkstra(Graph &graph, string &src, string &dest) {
  map<string, int> dist;
  map<string, string> prev_edge;
  map<string, string> prev_node;

  set<string> Q;

  for (auto it = graph.adjlist.begin(); it != graph.adjlist.end(); ++it) {
    dist[it->first] = INT_MAX;
    prev_edge[it->first] = "-";
    Q.insert(it->first);
  }

  dist[src] = 0;

  while (!Q.empty()) {
    string u = min_dist(Q, dist);
    Q.erase(u);

    for (auto it = graph.adjlist[u].begin(); it != graph.adjlist[u].end(); ++it) {
      string adj_node = it->first;
      string edge_name = it->second;

      if (edge_name[0] == prev_edge[u][0]) {
//        Q.insert(u);
//        dist[u] = INT_MAX;
//
//        graph.adjlist[prev_node[u]].erase(u);
//        graph.adjlist[u].erase(prev_node[u]);

        continue;
      };

      int alt = dist[u] + edge_name.size();
      if (alt < dist[adj_node]) {
        dist[adj_node] = alt;
        prev_edge[adj_node] = edge_name;
        prev_node[adj_node] = u;
      }
    }
  }

  return dist[dest];
}

int main() {
  unsigned cases = 0;

  while (!(cin >> cases).fail() && cases != 0) {
    string start, end;
    Graph thegraph;

    cin >> start >> end;

    for (int i = 0; i < cases; ++i) {
      string src, dest, edge;

      cin >> src >> dest >> edge;
      thegraph.addEdge(src, dest, edge);
    }

    int l = dijkstra(thegraph, start, end);
    if (l != INT_MAX)
      cout << l << endl;
    else
      cout << "impossivel" << endl;
  }
}
