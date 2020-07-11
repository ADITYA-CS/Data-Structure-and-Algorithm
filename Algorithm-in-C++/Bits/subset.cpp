/**
 *  @author : Aditya Kumar Singh
 *  Subset generation using bits
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> Subset(const vector<int> &set) {
  int n = set.size(), bound = pow(2, n);
  vector<vector<int>> res(bound);

  for (int i = 0; i < bound; i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        res[i].push_back(set[j]);
      }
    }
  }

  return res;
}

void PrintResult(const vector<vector<int>> &res) {
  for (auto subset : res) {
    bool first = true;
    cout << " {";
    for (auto el : subset) {
      if(!first)
        cout << ", ";
      first = false;
      cout << el;
    }
    cout << "}\n";
  }
}

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6};
  cout << " Subset of {1, 2, 3, 4, 5, 6}\n";
  auto res = Subset(v);
  PrintResult(res);
  cout << "\n";

  vector<int> u{1, 2, 3};
  cout << " Subset of {1, 2, 3}\n";
  res = Subset(u);
  PrintResult(res);
  cout << "\n";

  vector<int> w{123, 214, 3456, 99, 4532};
  cout << " Subset of {123, 214, 3456, 99, 4532}\n";
  cout << " First sorting it get lexicographical order\n";
  sort(w.begin(), w.end());
  res = Subset(w);
  PrintResult(res);
}
