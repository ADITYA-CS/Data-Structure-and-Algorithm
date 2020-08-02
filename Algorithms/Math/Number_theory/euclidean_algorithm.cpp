/**
 * @author: Aditya Kumar Singh
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Recursive
ll gcd(ll a, ll  b) {
  return b == 0 ? a : gcd(b, a % b);
}

// Iterative
ll Gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  cout << gcd(15, 39) << endl;
  cout << Gcd(15, 39) << endl;
  return 0;
}
