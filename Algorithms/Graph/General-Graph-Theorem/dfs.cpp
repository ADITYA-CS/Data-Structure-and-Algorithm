/**
 * @author : Aditya Kumar Singh
 * DFS
 */

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::cin;
using std::vector;

/**
 *  For the keeping record of current status of node in dfs
 */
enum class Status{
  kUnDiscoverd,
  kDiscoverd,
  kVisited
};

/**
 * keeping the class simple, Just for learning purpose
 */
class Graph {
private:
  int order_;
  bool is_cycle_;
  vector<vector<int>> adj_list_;

private:
  void DfsVisit(int, vector<Status>&);

public:
  explicit Graph(int);
  void AddEdge(int, int);
  void Dfs();
  bool IsCycle();
};

int main() {
  int n;
  cin >> n;
  Graph g(n);

  int a, b;
  while (cin >> a >> b, a != -1) {
    g.AddEdge(a, b);
  }
  g.Dfs();
  cout << "Is Cycle : " << std::boolalpha << g.IsCycle() << "\n";
}


Graph::Graph(int order) {
  order_ = order;
  is_cycle_ = false;
  adj_list_.resize(order_);
}

void Graph::AddEdge(int u, int v) {
  adj_list_[u].push_back(v);
}

void Graph::Dfs() {
  vector<Status> status(order_, Status::kUnDiscoverd);
  int time = 0;
  cout << "---------------------------------------------------\n";
  for (int i = 0; i < order_; i++) {
    if (status[i] == Status::kUnDiscoverd) {
      cout << "dfs spanning-tree\n";
      DfsVisit(i, status);
      cout << "\n---------------------------------------------------\n";
    }
  }
}

void Graph::DfsVisit(int u, vector<Status>& status) {
  status[u] = Status::kDiscoverd;
  cout << u << " --> ";
  for (auto v : adj_list_[u]) {
    if (status[v] == Status::kUnDiscoverd) {
      status[v] = Status::kDiscoverd;
      DfsVisit(v, status);
    } else if (status[v] == Status::kDiscoverd) {
      is_cycle_ = true;
    }
  }
  status[u] = Status::kVisited;
}

bool Graph::IsCycle() {
  return is_cycle_;
}
