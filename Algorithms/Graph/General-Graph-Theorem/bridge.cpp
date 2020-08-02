/**
 * @author: Aditya Kumar Singh
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<vector<int>> g;

vector<int> in, low;
vector<bool> visited;
int timer;

void DFS(int u, int p = -1) {
  visited[u] = true;
  in[u] = low[u] = timer++;

  for (int v : g[u]) {
    if (v == p) // v is parent, then do nothing
      continue;

    if (visited[v]) { // v is ancestor, then update low[u]
      low[u] = min(low[u], in[v]);
    } else {
      DFS(v, u);
      // update low[u], because if child can reach low[v], so can u
      low[u] = min(low[u], low[v]);
      if (in[u] < low[v]) {
        cout << '{' << u << ", " << v << "}\n";
      }
    }
  }
}


void FindBridge() {
  in.resize(n, 0);
  low.resize(n, 0);
  visited.resize(n, false);
  timer = 1;

  for (int i = 0; i < n; i++) {
    if(!visited[i])
      DFS(i, -1);
  }
}


int main() {
  cin >> n;
  int u, v;
  g.resize(n);
  while(cin >> u >> v){
    g[u].push_back(v);
    g[v].push_back(u);
  }

  FindBridge();
  return 0;
}
