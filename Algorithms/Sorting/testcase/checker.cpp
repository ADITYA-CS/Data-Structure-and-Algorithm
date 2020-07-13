/**
 * @author : Aditya Kumar Singh
 * Check the list is sorted or not
 */
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n, 0);

  for (auto &el : v) {
    cin >> el;
  }

  for (int i = 1; i < n; i++) {
    assert(v[i + 1] <= v[i]);
  }
}
