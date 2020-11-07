/**
 * @author : Aditya Kumar Singh
 * SCC (Strongly Connected Component) Using Kosaraju - Sharir Algorithm
 */

#include <iostream>
#include <list>
#include <stack>
#include <vector>

/**
 * keeping the class simple
 *
 * using adjacency list
 *    time complexity : O(E + V)
 *
 * E = Number of edge, V = Number of Vertices
 */
class Graph {
  enum class Type { kDirected, kUnDirected };

 private:
  int order_;
  std::vector<std::list<int>> g, gr;
  Type type_{Type::kDirected};
  void DFS1(int, std::vector<bool>&, std::stack<int>&);
  void DFS2(int, std::vector<bool>&, std::stack<int>&);

 public:
  explicit Graph(int);
  Graph(Graph&) = delete;
  Graph(Graph&&) = delete;
  Graph& operator=(Graph&) = delete;
  Graph& operator=(Graph&&) = delete;
  ~Graph() = default;

  void AddEdge(int, int);
  void Kosaraju();
};

Graph::Graph(int order) : order_{order} { g.resize(order_), gr.resize(order_); }

void Graph::AddEdge(int u, int v) {
  g[u].push_back(v);
  gr[v].push_back(u);
}

void Graph::DFS1(int u, std::vector<bool>& visited, std::stack<int>& st) {
  visited[u] = true;
  for (int v : g[u]) {
    if (visited[v] == false) {
      DFS1(v, visited, st);
    }
  }
  st.push(u);
}

void Graph::DFS2(int u, std::vector<bool>& visited, std::stack<int>& st) {
  visited[u] = true;
  st.push(u);
  for (auto v : gr[u]) {
    if (visited[v] == false) {
      DFS2(v, visited, st);
    }
  }
}

void Graph::Kosaraju() {
  std::vector<bool> visited(order_, false);
  std::stack<int> st;

  for (int i{0}; i < order_; i++) {
    if (visited[i] == false) {
      DFS1(i, visited, st);
    }
  }

  visited.assign(order_, false);
  int component{0};
  while (st.size()) {
    int u = st.top();
    st.pop();
    if (visited[u] == true) continue;
    std::stack<int> tmp;
    component++;
    DFS2(u, visited, tmp);
    std::cout << "Connected Component " << component << " : {";
    while (tmp.size()) {
      std::cout << tmp.top();
      tmp.pop();
      if (tmp.size()) std::cout << ", ";
    }
    std::cout << "}\n";
  }
}

int main() {
  int n, e;
  std::cout << "No of vertices : ";
  std::cin >> n;
  std::cout << "No of edges: ";
  std::cin >> e;
  std::cout << std::endl;
  Graph g(n);

  for (int u, v, i = 0; i < e; i++) {
    std::cin >> u >> v;
    g.AddEdge(u, v);
  }

  g.Kosaraju();
  return 0;
}
