/**
 * @author : Aditya Kumar Singh
 * DFS
 */

#include <iostream>
#include <list>
#include <queue>
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
  std::vector<std::list<int>> adj_list_;
  Type type_;
  void DFS(int, std::vector<bool>&);

 public:
  explicit Graph(int, Type);
  Graph(Graph&) = delete;
  Graph(Graph&&) = delete;
  Graph& operator=(Graph&) = delete;
  Graph& operator=(Graph&&) = delete;
  ~Graph() = default;

  void AddEdge(int, int);
  void DFS(int);
};

Graph::Graph(int order, Type type = Type::kUnDirected)
    : order_{order}, type_{type} {
  adj_list_.resize(order_);
}

void Graph::AddEdge(int u, int v) {
  adj_list_[u].push_back(v);
  if (type_ == Type::kUnDirected) adj_list_[v].push_back(u);
}

void Graph::DFS(int u, std::vector<bool>& visited) {
  std::cout << u;
  visited[u] = true;
  for (auto v : adj_list_[u]) {
    if (visited[v] == false) {
      std::cout << ", ";
      DFS(v, visited);
    }
  }
}

void Graph::DFS(int source) {
  if (source >= order_ || source < 0) {
    std::cerr << "Source is out of range" << std::endl;
    return;
  }
  std::vector<bool> visited(order_, false);

  std::cout << "Vertices reachable from " << source << " {";
  DFS(source, visited);
  std::cout << "}\n";
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
  int source = 0;
  g.DFS(source);
  return 0;
}
