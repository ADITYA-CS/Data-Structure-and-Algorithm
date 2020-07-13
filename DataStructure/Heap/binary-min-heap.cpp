/**
 * @author : Aditya Kumar Singh
 * Binary min heap
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class MinHeap{
// private data
private:
    vector<int> heap_; // pointer an array
    int max_size_;   // memory allocated to heap_
    int size_; // keep record of last element in heap_ array

//private function
private:
    int Parent(int) const;
    int LeftChild(int) const;
    int RightChild(int) const;
    void BubbleUp(int);
    void BubbleDown(int);

//public function
public:
    explicit MinHeap(int);
    int Top() const;
    void Push(int);
    int Pop();
    bool Full() const;
    bool Empty() const;
};


int main() {
    MinHeap heap(5);
    heap.Push(40);
    cout << "Top : " << heap.Top() << "\n";
    heap.Push(30);
    cout << "Top : " << heap.Top() << "\n";
    heap.Push(60);
    cout << "Top : " << heap.Top() << "\n";
    heap.Push(20);
    cout << "Top : " << heap.Top() << "\n";
    heap.Push(10);
    cout << "Top : " << heap.Top() << "\n";
    heap.Pop();
    cout << "Top : " << heap.Top() << "\n";
}

MinHeap::MinHeap(int size) : max_size_(size + 1), size_(0) {
    heap_.resize(size);
}

/**
 *  return parent node of the child node
 *  parent node index = floor(node index / 2);
 */
int MinHeap::Parent(int child) const {
    return child / 2;
}

/**
 *  return left child node index of the node
 *  left child index = 2 * parent node index
 */
int MinHeap::LeftChild(int parent) const {
    return 2 * parent;
}

/**
 * return right child node index of the node
 * right child index = 2 * parent node index + 1
 */
int MinHeap::RightChild(int parent) const {
    return 2 * parent + 1;
}

/**
 * check heap if full or not
 */
bool MinHeap::Full() const {
    return size_ == max_size_ - 1;
}

/**
 * check heap if empty or not
 */
bool MinHeap::Empty() const {
    return size_ == 0;
}

/**
 *  push an element in heap
 */
void MinHeap::Push(int el) {
    if (Full()) {
        return;
    }

    size_++;
    heap_[size_] = el;
    BubbleUp(size_);
}


/**
 * pop the element with lowest value
 */
int MinHeap::Pop() {
    int result = heap_[1];
    heap_[1] = heap_[size_];
    size_--;
    BubbleDown(1);
    return result;
}

/**
 * return the element with lowest value
 */
int MinHeap::Top() const {
    return heap_[1];
}

/**
 * moves the element towards the root and place it at right place
 */
void MinHeap::BubbleUp(int index) {
    int parent = Parent(index);
    while (index > 1 && heap_[parent] > heap_[index]) {
        swap(heap_[parent], heap_[index]);
        index = parent;
        parent = Parent(index);
    }
}

/**
 * moves the element towards the bottom and place it at right place
 */
void MinHeap::BubbleDown(int index) {
    int left = LeftChild(index);
    int right = RightChild(index);
    int min_index = index;

    if (left <= size_ && heap_[left] < heap_[index])
        min_index = left;

    if (right <= size_ && heap_[right] < heap_[min_index])
        min_index = right;

    if (index != min_index) { // base case
        swap(heap_[index], heap_[min_index]);
        BubbleDown(min_index);
    }
}
