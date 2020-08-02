/**
 * @author: Aditya Kumar Singh
 */

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;


// time complexity: sqrt(n)
int TotientValue(int n) {
  int res = n;
  for(int i = 2; i * i <= n; i++) {
    if ( n % i == 0) {
      while(n % i == 0)
        n /= i;
      res /=  i;
      res *= i - 1;
    }
  }
  if (n > 1) {
    res /=  n;
    res *= n - 1;
  }
  return res;
}

// generating totient value for [1, n] in O(n*logn*logn) time;
void TotientInRange(int n) {
  vector<int> phi(n+1);
  iota(phi.begin(), phi.end(), 0);

  for(int i = 2; i <= n; i++) {
    if (phi[i] == i) { // when i is a prime number
      for (int j = i; j <= n; j += i) {
        phi[j] /= i;
        phi[j] *= i - 1;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << "{" << i << ", totient value =  "<< phi[i] << "}\n";
  }

}

int main() {
  int n;
  cout << "n = ", cin >> n;
  for (int i = 2; i <= n; i++) {
    cout << i << ' ' << TotientValue(i) << endl;
  }
  TotientInRange(n);
  return 0;
}
