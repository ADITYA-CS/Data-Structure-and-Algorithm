#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
void Merge(vector<T> &A, const int &lo, const int &mid, const int &up){
    int left_len  = mid - lo + 1;
    int right_len = up - mid;

    vector<T> left(left_len), right(right_len);

    auto A_it = A.begin() + lo;
    for(auto it = left.begin(); it != left.end(); it++){
        *it = *A_it++;
    }

    for(auto it = right.begin(); it != right.end(); it++){
        *it = *A_it++;
    }

    A_it = A.begin() + lo;
    auto left_it  = left.begin();
    auto right_it = right.begin();

    while(left_it != left.end() && right_it != right.end()){
        if(*left_it < *right_it){
            *A_it++ = *left_it++;
        } else{
            *A_it++ = *right_it++;
        }
    }

    while(left_it != left.end()){
        *A_it++ = *left_it++;
    }

    while(right_it != right.end()){
        *A_it++ = *right_it++;
    }
}


template <class T>
void MergeSort(vector<T> &A, int lo, int up){
    if(lo >= up) return;

    int mid = lo + (up - lo) / 2;

    MergeSort(A, lo, mid);
    MergeSort(A, mid + 1, up);

    Merge(A, lo, mid, up);
}

// test
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (auto &number : numbers) {
      cin >> number;
    }

    MergeSort(numbers, 0, n - 1);

    cout << n << endl;
    for (auto &number : numbers) {
      cout << number << ' ';
    }
}
