#include <bits/stdc++.h>
using namespace std;

unsigned int ToggleKthBit(unsigned int n, int k) {
  return n ^ (1LL << k);
}

int main() {
  assert(5 == ToggleKthBit(7, 1));
  assert(7 == ToggleKthBit(5, 1));
}
