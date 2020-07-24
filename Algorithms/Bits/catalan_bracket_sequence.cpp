#include <iostream>
#include <vector>

using namespace std;

void Solve(int n) {
  int c = 0;
  n *= 2;
  unsigned int lo = 0, up = 0;
  lo = 1 << (n - 1);
  up = (1 << n) - 1;
  while( lo <= up) {
    int zero = 0, one = 0;
    for (int i = 0; zero >= one && i < n; i++) {
      if ((1 << i) & lo) {
        one++;
      } else {
        zero++;
      }
    }
    if (zero == one) {
      c++;
      for (int i = n - 1; i >= 0; i--) {
        if ((1 << i) & lo) {
          cout << "(";
        } else {
          cout << ")";
        }
      }
      cout << endl;
    }
    lo++;
  }
  cout << "There are " << c << " combination.\n";
}

int main() {
  int n;
  cout << "n = ";
  cin >> n;
  Solve(n);
}
