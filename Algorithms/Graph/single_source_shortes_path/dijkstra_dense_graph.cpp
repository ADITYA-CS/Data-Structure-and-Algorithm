/**
 * Dijkstra algorithms for sssp
 * time complexity : O(n*n + m)
 */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>> g;
vector<int> dis, parent;

void Dijkstra(int s) {
  dis.assign(n, INF);
  parent.assign(n, -1);

  vector<bool> visited(n, false);
  dis[s] = 0;
  for (int i = 0, u; i < n; i++) {
    u = -1;
    for (int j = 0; j < n; j++) {
      if (visited[j] == false && (u == -1 || dis[j] < dis[u]))
        u = j;
    }

    if (dis[v] == INF)
      break;
    visited[v] = true;
    for (auto edge : g[v]) {
      int v = edge.first;
      int weight = edge.second;
      if (dis[u] + weight < dis[v]) {
        dis[v] = dis[u] + weight;
        parent[v] = u;
      }
    }
  }
}

int main() {
  return 0;
}
