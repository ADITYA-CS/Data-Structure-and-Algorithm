/**
 * @author : Aditya Kumar Singh
 * Heap sort
 */
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// function declaration
int Parent(const int);
int LeftChild(const int);
int RightChild(const int);
void BuildHeap(vector<int> &, const int);
void BuildDown(vector<int> &, int, const int);
void HeapSort(vector<int> &);


// function definition
int Parent(const int child) {
    return (child - 1) / 2;
}

int LeftChild(const int parent) {
    return 2 * parent + 1;
}

int RightChild(const int parent) {
    return 2 * parent + 2;
}

void BubbleDown(vector<int> &v, int index, const int sz) {
    int left = LeftChild(index);
    int right = RightChild(index);
    int max_index = index;

    if (left <= sz && v[left] > v[max_index]) {
        max_index = left;
    }

    if (right <= sz && v[right] > v[max_index]) {
        max_index = right;
    }

    if (index != max_index) { // base case
        swap(v[index], v[max_index]);
        BubbleDown(v, max_index, sz);
    }

}

void BuildHeap(vector<int> &v, const int sz) {
    for (int i =  sz / 2 + 1; i >= 0; i--) {
        BubbleDown(v, i, sz);
    }
}

void HeapSort(vector<int> &v) {
    int sz = v.size();

    for (int i = sz - 1; i > 0; i--) {
        BuildHeap(v, i);
        swap(v[0], v[i]);
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

    HeapSort(numbers);

    cout << n << endl;
    for (auto &number : numbers) {
      cout << number << ' ';
    }
}
