/**
 * @author : Aditya Kumar Singh
 * TOPOLOGICAL SORT
 */

#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::cin;
using std::vector;
using std::stack;

/**
 *  For the keeping record of current status of node in dfs
 */
enum class Status{
  kUnDiscoverd,
  kDiscoverd,
  kVisited
};
/**
 *  For the keeping record of current status of node in dfs
 */
class Graph {
private:
  int order_;
  vector<vector<int>> adj_list_;

private:
  bool TopologicalSort(int, stack<int>&, vector<Status>&);

public:
  explicit Graph(int);
  void AddEdge(int, int);
  void TopologicalSort();
};

int main() {
  int n;
  cin >> n;
  Graph g(n);

  int a, b;
  while (cin >> a >> b, a != -1) {
    g.AddEdge(a, b);
  }
  g.TopologicalSort();
}


Graph::Graph(int order) {
  order_ = order;
  adj_list_.resize(order_);
}

void Graph::AddEdge(int u, int v) {
  adj_list_[u].push_back(v);
}

void Graph::TopologicalSort() {
  stack<int> reverse_topo_sort;
  vector<Status> status(order_, Status::kUnDiscoverd);

  for (int i = 0; i < order_; i++) {
    if (status[i] == Status::kUnDiscoverd) {
      if (!TopologicalSort(i, reverse_topo_sort, status)) {
        cout << "Graph is not a DAG\n";
        return;
      }
    }
  }

  cout << "Topological Sort : ";
  while (!reverse_topo_sort.empty()) {
    cout << reverse_topo_sort.top() << " ";
    reverse_topo_sort.pop();
  }
  cout << "\n";

}

bool Graph::TopologicalSort(int u, stack<int> &st, vector<Status> &status) {
  status[u] = Status::kDiscoverd;

  for (auto v : adj_list_[u]) {
    if (status[v] == Status::kDiscoverd) {
      return false;
    } else if (status[v] == Status::kUnDiscoverd) {
      if (!TopologicalSort(v, st, status)) {
        return false;
      }
    }
  }
  st.push(u);
  status[u] = Status::kVisited;
  return true;
}
