#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
int Partiton(vector<T>&A, int p, int r){
    int el = A[r];
    int i = p - 1;
    for(int j = p; j < r; j++){
        if(A[j] < el){
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i + 1;
}


template <class T>
void QuickSort(vector<T>&A, int p, int r){
    if(p < r){
        int q = Partiton(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

// test
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (auto &number : numbers) {
      cin >> number;
    }

    QuickSort(numbers, 0, n - 1);

    cout << n << endl;
    for (auto &number : numbers) {
      cout << number << ' ';
    }
}
