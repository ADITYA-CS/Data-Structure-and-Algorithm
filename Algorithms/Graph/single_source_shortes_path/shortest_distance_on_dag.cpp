/**
 * @author: Aditya Kumar Singh
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
int INF = INT_MAX;

struct Edge {
  int to;
  int weight;
  Edge() : to{0}, weight{0}{}
  Edge(int a, int b) : to{a}, weight{b}{}
};

int n;
vector<vector<Edge>> g;
vector<int> dist, predecessor;

void DFS(int u, vector<bool> &visited, stack<int> &st) {
  visited[u] = true;
  for (auto v : g[u]) {
    if (!visited[v.to]) {
      DFS(v.to, visited, st);
    }
  }
  st.push(u);
}

void ShortestPath(int u) {
  stack<int> st;
  vector<bool> visited(n, false);
  predecessor.resize(n, -1);
  dist.resize(n, INF);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      DFS(i, visited, st);
    }
  }

  dist[u] = 0;
  while (st.size()) {
    u = st.top(), st.pop();
    if (dist[u] != INF) {
      for (auto v : g[u]) {
        if (dist[v.to] > dist[u] + v.weight) {
          dist[v.to] = dist[u] + v.weight;
          predecessor[v.to] = u;
        }
      }
    }
  }
}

void DisplayPath(int u) {
  stack<int> st;
  while (u != -1) {
    st.push(u);
    u = predecessor[u];
  }
  while (st.size()) {
    cout << st.top() << ' ';
    st.pop();
  }
}

int main() {
  cin >> n;
  g.resize(n);
  int u, v, w;
  while (cin >> u >> v >> w) {
    g[u].push_back(Edge(v, w));
  }
  u = 1;
  ShortestPath(u);
  for (int i = 0; i < n; i++) {
    if (dist[i] == INF) {
      cout << i << " not reachable from " << u << endl;
    } else {
      cout << "shortest distance from " << u << " to "  << i << " : " << dist[i] << endl;
      cout << "Path : ";
      DisplayPath(i);
      cout << endl;
    }
  }
  return 0;
}
