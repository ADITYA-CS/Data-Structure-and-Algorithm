/**
 * Dijkstra algorithms for sssp
 * Priority queue version
 * time complexity : O(E log V)
 */

#include <bits/stdc++.h>
using namespace std;

int n;
long INF = 1e9;
vector<vector<pair<int, int>>> g;
vector<int> dis, parent;

void Dijkstra(int s) {
  dis.assign(n, INF);
  parent.assign(n, -1);

  vector<bool> visited(n, false);
  dis[s] = 0;

  priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto t = pq.top(); pq.pop();
    int u =  t.second;
    int len = t.first;

    if(dis[u] != len) // handling duplicate data in pq
      continue;

    for (auto edge : g[u]) {
      int v = edge.first;
      int weight = edge.second;

      if (dis[u] + weight < dis[v]) {
        dis[v] = dis[u] + weight;
        parent[v] = u;
        pq.push({dis[v], v});
      }
    }
  }
}

void PrintPath(int s, int d) {
  if (s == d) {
    cout << s << " ";
    return;
  }
  PrintPath(s, parent[d]);
  cout << d << " ";
}

int main() {
  return 0;
}
