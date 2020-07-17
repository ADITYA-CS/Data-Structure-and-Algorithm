/**
 * @author : Aditya Kumar Singh
 * Max heap
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap{
private:
    vector<int> heap_;
    int max_size_; // maximum size of heap
    int size_; // current size of heap

private:
    int Parent(int);
    int LeftChild(int);
    int RightChild(int);
    void BubbleUp(int);
    void BubbleDown(int);

public:
    explicit MaxHeap(int n);
    void Push(int); // pushing an element when heap is  full,
                    // may produce undefined behaviour
    int Pop();      // popping an element when heap is empty,
                    // may produce undefined behaviour
    int Top();
    bool Full();
    bool Empty();
};
int main() {
    MaxHeap heap(10);
    heap.Push(5);
    cout << "Top : " << heap.Top() << "\n";
    heap.Push(4);
    cout << "Top : " << heap.Top() << "\n";
    heap.Push(7);
    cout << "Top : " << heap.Top() << "\n";
    heap.Push(1);
    cout << "Top : " << heap.Top() << "\n";
    heap.Pop();
    cout << "Top : " << heap.Top() << "\n";
}

MaxHeap::MaxHeap(int size) : max_size_(size), size_(0) {
    heap_.resize(size);
}

/**
 *  return parent node of the child node
 *  parent node index = floor(node index / 2);
 */
int MaxHeap::Parent(int child) {
    return child / 2;
}

/**
 *  return left child node index of the node
 *  left child index = 2 * parent node index
 */
int MaxHeap::LeftChild(int parent) {
    return parent * 2;
}

/**
 * return right child node index of the node
 * right child index = 2 * parent node index + 1
 */
int MaxHeap::RightChild(int parent) {
    return parent * 2 + 1;
}

/**
 * moves the element towards the root and place it at right place
 */
void MaxHeap::BubbleUp(int index) {
    int parent = Parent(index);
    while (index > 1 && heap_[parent] < heap_[index]) {
        swap(heap_[parent], heap_[index]);
        index = parent;
        parent = Parent(index);
    }
}

/**
 * moves the element towards the bottom and place it at right place
 */
void MaxHeap::BubbleDown(int index) {
    int left = LeftChild(index);
    int right = RightChild(index);
    int max_index = index;

    if (left <= size_ && heap_[left] > heap_[max_index])
        max_index = left;

    if (right <= size_ && heap_[right] > heap_[max_index])
        max_index = right;

    if (index != max_index) { // base case
        swap(heap_[index], heap_[max_index]);
        BubbleDown(max_index);
    }
}

/**
 *  push an element in heap
 */
void MaxHeap::Push(int el) {
    if (Full()) {
        return;
    }
    size_++;
    heap_[size_] = el;
    BubbleUp(size_);
}

/**
 * pop the element with highest value
 */
int MaxHeap::Pop(){
    int result = heap_[1];
    heap_[1] = heap_[size_];
    size_--;
    BubbleDown(1);
    return result;
}

/**
 * return the element with highest value
 */
int MaxHeap::Top() {
    return heap_[1];
}

/**
 * check heap if full or not
 */
bool MaxHeap::Full() {
    return size_ == max_size_ - 1;
}

/**
 * check heap if empty or not
 */
bool MaxHeap::Empty() {
    return size_ == 0;
}
