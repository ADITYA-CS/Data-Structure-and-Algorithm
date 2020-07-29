/**
 * @author: Aditya Kumar Singh
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> g;
vector<bool> visited;
vector<bool> vertex_set;
int n;

bool DFS(int u, bool set_id) {
  visited[u] = true;
  vertex_set[u] = set_id;

  for (auto v : g[u]) {
    if (!visited[v] && !DFS(v, !set_id)) {
        return false;
    }
    
    if (vertex_set[u] == vertex_set[v])
      return false;

  }

  return true;
}

bool IsBipartite() {
  visited.resize(n, false);
  vertex_set.resize(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i] && DFS(i, false) == false)
      return false;
  }

  return true;
}

int main() {
  cin >> n;
  g.resize(n);
  int u, v;
  while(cin >> u >> v) {
    if (u == -1)
      break;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  if (IsBipartite()) {
    cout << "Vertex set 1 : ";
      for (int i = 0; i < n; i++) {
        if (vertex_set[i]) {
          cout  << i << " ";
        }
      }
    cout << "\nVertex set 2 : ";
    for (int i = 0; i < n; i++) {
      if (!vertex_set[i]) {
        cout  << i << " ";
      }
    }
    cout << endl;
  } else {
    cout << "Not a bipartite graph\n";
  }
  return 0;
}
