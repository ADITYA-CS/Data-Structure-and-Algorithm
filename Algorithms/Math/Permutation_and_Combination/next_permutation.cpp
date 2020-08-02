#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool NextPermutation(string &str) {
  int n = str.size();
  int i = n - 1;

  while(i && str[i - 1] >= str[i])
    i--;
  if (!i) return false;

  int j = n - 1;
  while(j && str[i - 1] >= str[j])
    j--;

  swap(str[i - 1], str[j]);
  reverse(str.begin() + i, str.end());
  return true;
}

int main() {
  string str;
  cout << "Enter string : ";
  cin >> str;
  NextPermutation(str);
  cout << "Next Permutation : " << str << "\n";
}
