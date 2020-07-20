#include <bits/stdc++.h>
using namespace std;

unsigned int SetKthBit(unsigned int n, int k) {
  return n | (1LL << k);
}

int main() {
  assert(7 == SetKthBit(7, 1));
  assert(7 == SetKthBit(5, 1));
}
