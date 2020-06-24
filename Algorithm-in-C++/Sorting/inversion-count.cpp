#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class T>
int Merge(vector<T> &A, const int &lo, const int &mid, const int &up){
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
    int inversion = 0;

    while(left_it != left.end() && right_it != right.end()){
        if(*left_it <= *right_it){
            *A_it++ = *left_it++;
        } else{
            *A_it++ = *right_it++;
            inversion += left.end() - left_it;
        }
    }

    while(left_it != left.end()){
        *A_it++ = *left_it++;
    }

    while(right_it != right.end()){
        *A_it++ = *right_it++;
    }
    return inversion;
}


template <class T>
int MergeSort(vector<T> &A, int lo, int up){
    if(lo >= up) return 0;

    int mid = lo + (up - lo) / 2;

    int left_inverion  = MergeSort(A, lo, mid);
    int right_inverion = MergeSort(A, mid + 1, up);

    int spilt_inversion = Merge(A, lo, mid, up);
    return left_inverion + right_inverion + spilt_inversion;
}

int main(){
    vector<int> v{5,4,8,9,21,0,516,35,4,168,1};
    cout << "Inversion : " << MergeSort(v, 0, v.size() - 1) << endl;
    for(auto a : v){
        cout << a << " ";
    }
    cout << "\n";
}
