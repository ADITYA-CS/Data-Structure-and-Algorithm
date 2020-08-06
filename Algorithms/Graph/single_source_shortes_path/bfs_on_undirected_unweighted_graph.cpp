/**
 * @author: Aditya Kumar Singh
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> g;
vector<int> predecessor, dist;
int n;

void BFS(int s) {
  predecessor.resize(n, -1);
  dist.resize(n, -1);
  vector<bool> visited(n, false);

  visited[s] = true;
  dist[0] = 0;
  queue<int> q;
  q.push(s);
  while(q.size()) {
    auto u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (!visited[v]) {
        dist[v] = dist[u] + 1;
        predecessor[v] = u;
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

void DisplayPath(int u) {
  if (u == -1){
    return;
  }
  DisplayPath(predecessor[u]);
  cout << u << " ";
}

int main() {
  cin >> n;
  g.resize(n);
  int u, v;
  while (cin >> u >> v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  // cin >> u;
  u = 0;
  BFS(u);
  for (int i = 0; i < n; i++) {
    if (dist[i] != -1) {
      cout << "dist from " << u << " to " << i << " : " << dist[i] << endl;
      cout << "Path : ";
      DisplayPath(i);
      cout << endl;
    } else {
      cout << i << " is not reachable from " << u << endl;
    }
  }
  return 0;
}
