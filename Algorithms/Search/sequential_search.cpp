#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int SequentialSearch(const vector<int> &v, const int key) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == key) {
      return i;
    }
  }
  return -1;
}


int main() {
  vector<int> v{1, 2, 3, 7, 6, 8};

  cout << "found 3 at " << SequentialSearch(v, 3) << "\n";
}
