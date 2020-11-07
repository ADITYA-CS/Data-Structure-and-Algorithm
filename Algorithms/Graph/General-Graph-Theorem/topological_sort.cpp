/**
 * @author : Aditya Kumar Singh
 * Topological Sort
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
 public:
  enum class Type { kDirected, kUnDirected };

 private:
  enum class Status { kDiscovered, kProcessing, kUnDiscovered };
  int order_;
  std::vector<std::list<int>> adj_list_;
  Type type_;
  bool DFS(int, std::vector<Status>&, std::stack<int>&);

 public:
  explicit Graph(int, Type);
  Graph(Graph&) = delete;
  Graph(Graph&&) = delete;
  Graph& operator=(Graph&) = delete;
  Graph& operator=(Graph&&) = delete;
  ~Graph() = default;

  void AddEdge(int, int);
  void TopologicalSort();
  void Print(std::stack<int>& );
};

Graph::Graph(int order, Type type = Type::kUnDirected)
    : order_{order}, type_{type} {
  adj_list_.resize(order_);
}

void Graph::AddEdge(int u, int v) {
  adj_list_[u].push_back(v);
  if (type_ == Type::kUnDirected) adj_list_[v].push_back(u);
}

void Graph::Print(std::stack<int>& st) {
  std::cout << "Topological order: {";
  const int flag = -1;
  st.pop();  // removing flag
  while (st.size()) {
    int v = st.top();
    st.pop();
    if (v == flag) continue;
    std::cout << v;
    if (st.size()) std::cout << ", ";
  }
  std::cout << "}\n";
}

bool Graph::DFS(int u, std::vector<Status>& visited,
                std::stack<int>& topological_order) {
  visited[u] = Status::kProcessing;
  for (auto v : adj_list_[u]) {
    if (visited[v] == Status::kUnDiscovered) {
      if (DFS(v, visited, topological_order)) return true;
    } else if (visited[v] == Status::kProcessing) {
      return true;
    }
  }
  visited[u] = Status::kDiscovered;
  topological_order.push(u);
  return false;
}

void Graph::TopologicalSort() {
  std::vector<Status> visited(order_, Status::kUnDiscovered);
  std::stack<int> topological_order;
  bool cycle = false;
  const int flag = -1;
  for (int i = 0; i < order_ && cycle == false; i++) {
    if (visited[i] == Status::kUnDiscovered) {
      cycle = DFS(i, visited, topological_order);
      topological_order.push(flag);
    }
  }
  if (cycle == true) {
    std::cerr << "Graph has cycle" << std::endl;
    return;
  }

  Print(topological_order);
}

int main() {
  int n, e;
  std::cout << "No of vertices : ";
  std::cin >> n;
  std::cout << "No of edges: ";
  std::cin >> e;
  std::cout << std::endl;
  Graph g(n, Graph::Type::kDirected);

  for (int u, v, i = 0; i < e; i++) {
    std::cin >> u >> v;
    g.AddEdge(u, v);
  }
  g.TopologicalSort();
  return 0;
}
