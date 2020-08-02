/**
 * @author: Aditya Kumar Singh
 */

#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int  b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }

  int x1, y1;
  int d = gdc(b, a % b, x1, y1);
  x = y1;
  y = x1 - (int)a/b * y1;
  return d;
}

int main() {

  return 0;
}
