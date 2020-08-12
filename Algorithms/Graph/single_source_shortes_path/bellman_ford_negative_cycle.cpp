/**
 * @author: Aditya Kumar Singh
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

struct Edge{
  int u, v, w;
  Edge(int a, int b, int c) : u{a}, v{b}, w{c}{}
};
int INF = INT_MAX, n, m, last_relaxed;
vector<Edge> g;
vector<int> predecessor, dis;

void BellmanFord(int s) {
  predecessor.resize(n, -1);
  dis.resize(n, INF);
  m = g.size();
  dis[s] = 0;

  for (int i = 0; i < n; i++) {
    last_relaxed = -1;
    for (int j = 0; j < m; j++) {
      if (dis[g[j].u] < INF) {
        if (dis[g[j].v] > dis[g[j].u] + g[j].w) {
          dis[g[j].v] = dis[g[j].u] + g[j].w;
          predecessor[g[j].v] = g[j].u;
          last_relaxed = g[j].v;
        }
      }
    }
  }
}

void PrintPath(int u, int v) {
  if (dis[v] == INF)
    return;
  if(v == u) {
    cout << v << " ";
    return;
  }
  PrintPath(u, predecessor[v]);
  cout << v << " ";
}

void PrintCycle(int u) {
  for  (int i = 0; i < n; i++)
    u = predecessor[u];

  stack<int> st;
  int v = predecessor[u];
  st.push(u);
  while (v != u) {
    st.push(v);
    v = predecessor[v];
  }
  st.push(u);
  cout << "Negative cycle: ";
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}

int main() {
  return 0;
}
