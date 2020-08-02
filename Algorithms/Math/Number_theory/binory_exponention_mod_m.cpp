/**
 * @author: Aditya Kumar Singh
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll power(ll a, ll b, ll m) {
  if (b == 0)
    return 1;

  ll res = power(a, b/2);
  res = (res * res) % m;

  if ( b & 1)
    return (res * a) % m;
  return res;
}

int main() {
  cout << power(2, 9, 5) << endl;
  cout << power(2, 9, 7) << endl;
  return 0;
}
