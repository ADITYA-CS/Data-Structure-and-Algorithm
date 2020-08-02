/**
 * @author: Aditya Kumar Singh
 */

#include <bits/stdc++.h>
using namespace std;

int N = 1000005;
vector<bool> prime;

void Prime() {
  prime.resize(N, true);
  prime[0] = prime[1] = false;
  for(int i = 2; i * i <= N; i++) {
      if (!prime[i])
      	continue;
    int j = i * i;
    while(j < N){
      prime[j] = false;
      j += i;
    }
  }
  for (int i = 2; i < N; i++) {
    if (prime[i])
      cout << i << " " ;
  }
}

int main() {
  Prime();
  return 0;
}
