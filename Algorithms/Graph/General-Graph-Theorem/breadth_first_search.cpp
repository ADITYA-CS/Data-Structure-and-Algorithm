/**
 * @author : Aditya Kumar Singh
 * BFS
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
 * While using adjacency matrix
 *    time complexity : O(E + E.V)
 * 
 * E = Number of edge, V = Number of Vertices
 */
class Graph {
  enum class Type { kDirected, kUnDirected };

 private:
  int order_;
  std::vector<std::list<int>> adj_list_;
  Type type_;

 public:
  explicit Graph(int, Type);
  Graph(Graph&) = delete;
  Graph(Graph&&) = delete;
  Graph& operator=(Graph&) = delete;
  Graph& operator=(Graph&&) = delete;
  ~Graph() = default;

  void AddEdge(int, int);
  void BFS(int);
};

Graph::Graph(int order, Type type = Type::kUnDirected)
    : order_{order}, type_{type} {
  adj_list_.resize(order_);
}

void Graph::AddEdge(int u, int v) {
  adj_list_[u].push_back(v);
  if (type_ == Type::kUnDirected) adj_list_[v].push_back(u);
}

void Graph::BFS(int source) {
  if (source >= order_ || source < 0) {
    std::cerr << "Source is out of range" << std::endl;
    return;
  }
  std::vector<bool> visited(order_, false);
  std::queue<int> q;
  q.push(source);
  visited[source] = true;
  int dist = 0;
  while (q.size()) {
    int n = q.size();
    std::cout << "Vertex at distance " << dist++ << " from source : {";
    while (n--) {
      int u = q.front();
      q.pop();
      std::cout << u;
      std::cout << (n ? ", " : "}\n");
      for (auto v : adj_list_[u]) {
        if (visited[v] == false) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
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

  for (int u, v, i = 0; i < e; i++)  {
    std::cin >> u >> v;
    g.AddEdge(u, v);
  }
  int source = 0;
  g.BFS(source);
  return 0;
}
