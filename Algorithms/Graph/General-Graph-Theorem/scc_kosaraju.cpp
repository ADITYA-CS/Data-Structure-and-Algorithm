/**
 * @author: Aditya Kumar Singh
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void Dfs1(int u);
void Dfs2(int u);

int n;
vector<vector<int>> g, rev;
vector<bool> visited;
stack<int> st;

void SCC() {
  visited.resize(n, false);

  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      Dfs1(i);
    }
  }

  visited.assign(n, false);
  int c = 0;
  while (st.size()) {
    int u = st.top();
    st.pop();
    if (visited[u] == false) {
      c++;
      cout << "Component vertex: ";
      Dfs2(u);
      cout << endl;
    }
  }
  cout << "There are total "<< c << " strongly connected components\n";
}

void Dfs1(int u) {
  visited[u]  = true;
  for (auto v : g[u]) {
    if (visited[v] == false) {
      Dfs1(v);
    }
  }
  st.push(u);
}

void Dfs2(int u) {
  cout << u << " ";
  visited[u] = true;
  for (auto v : rev[u]) {
    if (visited[v] == false) {
      Dfs2(v);
    }
  }
}

int main() {
  cin >> n;
  g.resize(n);
  rev.resize(n);

  int u, v;
  while (cin >> u >> v) {
    g[u].push_back(v);
    rev[v].push_back(u);
  }
  SCC();
  return 0;
}
