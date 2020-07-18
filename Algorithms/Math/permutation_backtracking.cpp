#include <iostream>
#include <vector>
using namespace std;


void Permutation(string str, int i = 0) {
  int n = str.size();
  if (i == n - 1) {
    cout << str << endl;
    return;
  }

  for (int j = i; j < n; j++) {
    swap(str[i], str[j]);
    Permutation(str, i + 1);
    swap(str[i], str[j]);
  }
}

int main() {
  string str = "123456789";
  Permutation(str);
}
