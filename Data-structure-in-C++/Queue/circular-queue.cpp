
/**
 * @author : Aditya Kumar Singh
 * Circular Queue
 */

#include <iostream>
using namespace std;


template <class QueueType>
class Queue{
private:
    QueueType* queue_;
    int size_;
    int front_;
    int rare_;
public:
    Queue();
    ~Queue();
    Queue(int);
    void pop();
    void push(QueueType);
    QueueType front();
    QueueType back();
    bool empty();
    bool full();
};
int main(){
    Queue<int> my_queue1;

    cout << "is my_queue1 empty : " << boolalpha << my_queue1.empty() << "\n";
    cout << "is my_queue1 full  : " << my_queue1.full() << "\n\n";
    my_queue1.push(10);
    my_queue1.push(20);

    cout << "back of my_queue1  : " << my_queue1.back() << "\n";
    cout << "front of my_queue1 : " << my_queue1.front() << "\n";
    cout << "is my_queue1 empty : " << my_queue1.empty() << "\n";
    cout << "is my_queue1 full  : " << my_queue1.full() << "\n\n";

    my_queue1.push(70);
    my_queue1.push(60);
    my_queue1.push(80);
    my_queue1.push(90);
    my_queue1.pop();

    cout << "back of my_queue1  : " << my_queue1.back() << "\n";
    cout << "front of my_queue1 : " << my_queue1.front() << "\n";
    cout << "is my_queue1 empty : " << my_queue1.empty() << "\n";
    cout << "is my_queue1 full  : " << my_queue1.full() << "\n\n";

    Queue<char> my_queue2;

    cout << "is my_queue2 empty : " << my_queue2.empty() << "\n";
    cout << "is my_queue2 full  : " << my_queue2.full() << "\n\n";
    my_queue2.push('A');
    my_queue2.push('B');

    cout << "back of my_queue2  : " << my_queue2.back() << "\n";
    cout << "front of my_queue2 : " << my_queue2.front() << "\n";
    cout << "is my_queue2 empty : " << my_queue2.empty() << "\n";
    cout << "is my_queue2 full  : " << my_queue2.full() << "\n\n";

    my_queue2.push('X');
    my_queue2.push('Y');
    my_queue2.push('Z');
    my_queue2.push('Q');
    my_queue2.pop();

    cout << "back of my_queue2  : " << my_queue2.back() << "\n";
    cout << "front of my_queue2 : " << my_queue2.front() << "\n";
    cout << "is my_queue2 empty : " << my_queue2.empty() << "\n";
    cout << "is my_queue2 full  : " << my_queue2.full() << "\n\n";
}

template <class QueueType>
Queue<QueueType> :: Queue(): size_(1000), front_(-1), rare_(-1){
    queue_ = new QueueType[1000];
}

template <class QueueType>
Queue<QueueType> :: Queue(int n): size_(n), front_(-1), rare_(-1){
    queue_ = new QueueType[n];
}

template <class QueueType>
Queue<QueueType> :: ~Queue(){
    delete []queue_;
}

template <class QueueType>
bool Queue<QueueType> :: empty(){
    return rare_ == -1;
}

template <class QueueType>
bool Queue<QueueType> :: full(){
    return (rare_ + 1) % size_ == front_;
}

template <class QueueType>
QueueType Queue<QueueType> :: front(){
    if(empty()){
        cout << "Called front() when queue is empty.\n";
        abort();
    }
    return queue_[front_];
}

template <class QueueType>
QueueType Queue<QueueType> :: back(){
    if(empty()){
        cout << "Called back() when queue is empty.\n";
        abort();
    }
    return queue_[rare_];
}

template <class QueueType>
void Queue<QueueType> :: pop(){
    if(empty()){
        return;
    }
    if(front_ == rare_){
        front_ = rare_ = -1;
    }
    front_ = (front_ + 1) % size_;
}

template <class QueueType>
void Queue<QueueType> :: push(QueueType el){
    if(full()){
        cout << "Queue is full\n";
        return;
    }

    if(empty()){
        front_ = rare_ = 0;
    }
    else{
        rare_ = (rare_ + 1) % size_;
    }
    queue_[rare_] = el;
}
