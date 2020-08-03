/**
 * @author: Aditya Kumar Singh
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void Dfs(int, int&);
int n, timer;
vector<vector<int>> g;
vector<bool> on_stack, visited;
vector<int> low, in;
stack<int> st;

void SCC() {
  timer = 0;
  on_stack.resize(n, false);
  visited.resize(n, false);
  low.resize(n,0);
  in.resize(n, 0);
  int c = 0;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      Dfs(i, c);
    }
  }
  cout << "There are "<< c << " strongly connected componenets\n";
}

void Dfs(int u, int &c) {
  st.push(u);
  on_stack[u] = true;
  visited[u] = true;
  low[u] = in[u] = timer++;

  for (auto v : g[u]) {
    if (!visited[v]) {
      Dfs(v, c);
      low[u] = min(low[u], low[v]);
    } else if (on_stack[v]) {
      low[u] = min(low[u], in[v]);
    }
  }

  if (in[u] == low[u]) {
    c++;
    int v;
    cout << "SCC : ";
    do {
      v = st.top();
      st.pop();
      on_stack[v] = false;
      cout << v << " ";
    } while (v != u);
    cout << endl;
  }
}


int main() {

  cin >> n;
  g.resize(n);
  int u, v;
  while(cin >> u >> v){
    g[u].push_back(v);
  }
  SCC();
  return 0;
}
