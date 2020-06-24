/**
 * @author : Aditya Kumar Singh
 * Binary min heap
 */


#include <iostream>
using namespace std;


class MinHeap{
// private data
private:
    int *heap_; // pointer an array
    int capacity_;   // memory allocated to heap_
    int current_size_; // keep record of last element in heap_ array
//private function
private:
    int Parent(int) const;
    int Left(int) const;
    int Right(int) const;
    void BubbleUp(int);
    void BubbleDown(int);
//public function
public:
    MinHeap();
    MinHeap(int);
    MinHeap(int *, int);
    int get_min() const;
    int extract();
    void Insert(int);
    void Delete();
    bool Full() const;
    bool Empty() const;
    void Display();
};


int main(){
    MinHeap mh(5);
    mh.Insert(40);
    mh.Display();
    mh.Insert(30);
    mh.Display();
    mh.Insert(60);
    mh.Display();
    mh.Insert(20);
    mh.Display();
    mh.Insert(10);
    mh.Display();
    cout << " Min : " << mh.get_min() << "\n";
    mh.Display();
    cout << " Min : " << mh.extract() << "\n";
    mh.Display();
}

MinHeap :: MinHeap() : capacity_(100), current_size_(-1){
    heap_ = new int[100];
}

MinHeap :: MinHeap(int n) : capacity_(n), current_size_(-1){
    heap_ = new int[n];
}
// Todo
MinHeap :: MinHeap(int *arr, int n) : capacity_(n), current_size_(n-1){
    heap_ = new int[n];
    for(int i = 0; i < n; i++){
        heap_[i] = arr[i];
    }
    // Now building min heap
    int index = Parent(current_size_);
    while(index >= 0){
        BubbleDown(index);
    }

}

int MinHeap :: Parent(int i) const{
    return i > 0 ? (i - 1) / 2 : -1;
}
int MinHeap :: Left(int i) const{
    return 2 * i + 1;
}
int MinHeap :: Right(int i) const{
    return 2 * i + 2;
}

bool MinHeap :: Full() const{
    return current_size_ == capacity_ - 1;
}

bool MinHeap :: Empty() const{
    return current_size_ == -1;
}

void MinHeap :: Insert(int el){
    if(Full()){
        cerr << "Heap is full" << '\n';
        exit(1);
    }
    current_size_++;
    heap_[current_size_] = el;
    BubbleUp(current_size_);
}

void MinHeap :: BubbleUp(int index){
    int temp = heap_[index];
    int par = Parent(index);
    while(par >= 0 && heap_[par] > temp){
        heap_[index] = heap_[par];
        index = par;
        par = Parent(index);
    }
    heap_[index] = temp;
}

void MinHeap :: BubbleDown(int index){
    int left, right, smallest;
    while(true){
        left = Left(index);
        right = Right(index);
        smallest = index;
        if(left <= current_size_ && heap_[left] < heap_[smallest]){
            smallest = left;
        }
        if(right <= current_size_ && heap_[right] < heap_[smallest]){
            smallest = right;
        }
        if(smallest == index){
            break;
        }
        swap(heap_[index],heap_[smallest]);
        index = smallest;
    }
}
int MinHeap :: get_min() const{
    if(Empty()){
        cerr << "Heap is empty\n";
        exit(1);
    }
    return heap_[0];
}
int MinHeap :: extract(){
    if(Empty()){
        cerr << "Heap is empty\n";
        exit(1);
    }
    int res = heap_[0];
    heap_[0] = heap_[current_size_];
    current_size_--;
    BubbleDown(0);
    return res;
}
void MinHeap :: Display(){
    for(int i = 0; i <= current_size_; i++){
        cout << heap_[i] << " ";
    }
    cout << "\n";
}
