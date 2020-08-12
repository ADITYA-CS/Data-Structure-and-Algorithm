/**
 * @author: Aditya Kumar Singh
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

struct Edge{
  int u, v, w;
  Edge(int a, int b, int c) : u{a}, v{b}, w{c}{}
};
int INF = INT_MAX, n, m;
vector<Edge> g;
vector<int> predecessor, dis;

void BellmanFord(int s) {
  m = g.size();
  predecessor.resize(n, -1);
  dis.resize(n, INF);
  dis[s] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      if (dis[g[j].u] < INF) {
        if (dis[g[j].v] > dis[g[j].u] + g[j].w) {
          dis[g[j].v] = dis[g[j].u] + g[j].w;
          predecessor[g[j].v] = g[j].u;
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

int main() {
  return 0;
}
