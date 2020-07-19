/**
 * @author : Aditya Kumar Singh
 * BFS
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 *  For the keeping record of current status of node in bfs
 */
enum class Status{
  kUnDiscoverd,
  kDiscoverd,
  kVisited
};

/**
 * keeping the class simple, Just for learning purpose
 *
 * using adjacency list, bfs has time complexity O(E + V)
 * While using adjacency matrix, bfs has time complexity O(E + E.V)
 * E = Number of edge, V = Number of Vertices
 */
class Graph {
private:
  int order_;
  int component_; // how many component the graph has;
  bool has_cycle_;
  vector<vector<int>> adj_list_;

private:
  void BfsVisit(int, vector<Status>&);

public:
  explicit Graph(int);
  void AddEdge(int, int);
  void Bfs();
  bool HasCycle();
  int Component();
};

int main() {
  int n;
  cin >> n;
  Graph g(n);

  int a, b;
  while (cin >> a >> b, a != -1) {
    g.AddEdge(a, b);
  }
  g.Bfs();
  cout << "Has Cycle : " << boolalpha << g.HasCycle() << "\n";
  cout << "Number of component : " << g.Component() << "\n";
}


Graph::Graph(int order) : order_(order), component_(0), has_cycle_(false) {
  adj_list_.resize(order_);
}

void Graph::AddEdge(int u, int v) {
  adj_list_[u].push_back(v);
}

void Graph::Bfs() {
  vector<Status> status(order_, Status::kUnDiscoverd);
  component_ = 0;
  has_cycle_ = false;

  cout << "---------------------------------------------------\n";
  for (int i = 0; i < order_; i++) {
    if (status[i] == Status::kUnDiscoverd) {
      component_ += 1;
      cout << "bfs spanning-tree\n";
      BfsVisit(i, status);
      cout << "\n---------------------------------------------------\n";
    }
  }
}

void Graph::BfsVisit(int source, vector<Status> & status) {
  queue<int> q;
  q.push(source);

  while (!q.empty()) {
    auto u = q.front();
    cout << u << " --> ";
    //
    // you can processes the vertex here
    //
    status[u] = Status::kDiscoverd;
    q.pop();
    for (auto v : adj_list_[u]) {
      if (status[v] != Status::kUnDiscoverd) {
        has_cycle_ = true;
      } else {
        status[v] = Status::kVisited;
        //
        // or you can processes the vertex here
        //
        q.push(v);
      }
    }
    //
    // or you can processes the vertex here
    //
    status[u] = Status::kVisited;
  }
}

bool Graph::HasCycle() {
  return has_cycle_;
}

int Graph::Component() {
  return component_;
}
