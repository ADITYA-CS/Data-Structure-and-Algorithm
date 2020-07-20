#include <bits/stdc++.h>
using namespace std;

int RemoveRightMostBit(unsigned int n) {
  return n & (n - 1);
}

int main() {
  unsigned int a = 7;
  assert(RemoveRightMostBit(8) == 0);
  assert(RemoveRightMostBit(7) == 6);
  assert(RemoveRightMostBit(10) == 8);
  assert(RemoveRightMostBit(14) == 12);

}
