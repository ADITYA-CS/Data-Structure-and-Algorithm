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
vector<int> visited, is_cutpoint;
int timer;


void DFS(int u, int p = -1) {
  visited[u] = true;
  in[u] = low[u] = timer++;

  int child = 0;
  for (int v : g[u]) {
    if (v == p) // when v is parent, then do nothing
      continue;

    if (visited[v]) { // when v is ancestor then update low[u]
      low[u] = min(low[u], in[v]);
    } else {
      DFS(v, u);
      // update low[u] as if v can reach vertex x with in[x] = low[v], so can u
      low[u] = min(low[u], low[v]);
      if(low[v] >= in[u] && p != -1) {
        is_cutpoint[u] = true;
      }
      // increase the child
      ++child;
    }
  }
  // when root has more than 1 child, then it is articulate point
  if (p == -1 && child > 1) {
    is_cutpoint[u] = true;
  }
}


void ArticulatePoint() {
  low.resize(n, -1);
  visited.resize(n, false);
  is_cutpoint.resize(n, false);
  in.resize(n, -1);
  timer = 1;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      DFS(i);
    }
  }

  for (int i = 0; i < n; i++) {
    if (is_cutpoint[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
}

int main() {
  cin >> n;
  g.resize(n);
  int u, v;
  while(cin >> u >> v){
    if(u == -1)
      break;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ArticulatePoint();
  return 0;
}
