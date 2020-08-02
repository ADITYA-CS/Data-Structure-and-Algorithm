/**
 * @author: Aditya Kumar Singh
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Recursive
ll power(ll a, ll b) {
  if (b == 0)
    return 1;

  ll res = power(a, b/2);
  res *= res;

  if ( b & 1)
    return res * a;
  return res;
}

// Iterative
ll Power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

int main() {
  cout << power(2, 9) << endl;
  cout << Power(2, 9) << endl;
  return 0;
}
