/**
 * @author : Aditya Kumar Singh
 * Generate testcase for sorting problem
 */

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[]) {
  if(argc != 4) {
    cout << "usage: filename n min max\n";
    cout << "n is number of numbers\n";
    cout << "min is least value the he list\n";
    cout << "max is maximum value the he list\n";
    exit(1);
  }
  int n = stoi(argv[1]), mx = stoi(argv[3]), mi = stoi(argv[2]);

  int number;
  random_device random_device;
  mt19937 random_engine(random_device());
  uniform_int_distribution<int> dist(mi, mx);

  cout << n << endl;
  for (int i = 0; i < n; i++) {
    number = dist(random_engine);
    cout << number << ' ';
  }
  return 0;
}
