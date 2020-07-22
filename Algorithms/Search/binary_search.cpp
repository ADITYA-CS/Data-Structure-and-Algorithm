#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int BinarySearch(const vector<int> &v, const int key) {
  int lo = 0, up = v.size() - 1, mid;

  while (lo <= up) {
    mid = (up - lo) / 2 + lo;
    if (v[mid] == key) {
      return mid;
    } else if (v[mid] < key) {
      lo = mid + 1;
    } else {
      up = mid - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> v{1, 2, 3, 7, 6, 8};

  cout << "found 3 at " << BinarySearch(v, 3) << "\n";
  cout << "found 4 at " << BinarySearch(v, 4) << "\n";
}
