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

int main(){
    vector<int> v{5,4,8,9,21,0,516,35,4,168,1};
    QuickSort(v, 0, v.size() - 1);
    for(auto a : v){
        cout << a << " ";
    }
    cout << "\n";
}
