#include <bits/stdc++.h>
using namespace std;

unsigned int ClearKthBit(unsigned int n, int k) {
  return n & ~(1LL << k);
}

int main() {
  assert(5 == ClearKthBit(7, 1));
  assert(5 == ClearKthBit(5, 1));
}
