
/**
 * @author : Aditya Kumar Singh
 * Deque
 */

#include <iostream>
using namespace std;

template <class DequeType>
class Deque{
private:
    DequeType *deque_;
    int front_;
    int rare_;
    int size_;
public:
    Deque();
    Deque(int);
    ~Deque();
    void push_back(DequeType);
    void push_front(DequeType);
    void pop_back();
    void pop_front();
    bool empty();
    bool full();
    DequeType back();
    DequeType front();
};

int main(){
    Deque<int> my_deque1;

    cout << "is my_deque1 empty : " << boolalpha << my_deque1.empty() << "\n";
    cout << "is my_deque1 full  : " << my_deque1.full() << "\n\n";
    my_deque1.push_back(10);
    my_deque1.push_back(20);
    my_deque1.push_front(30);
    my_deque1.push_front(40);
    cout << "back of my_deque1  : " << my_deque1.back() << "\n";
    cout << "front of my_deque1 : " << my_deque1.front() << "\n";
    cout << "is my_deque1 empty : " << my_deque1.empty() << "\n";
    cout << "is my_deque1 full  : " << my_deque1.full() << "\n\n";

    my_deque1.push_back(70);
    my_deque1.push_front(60);
    my_deque1.push_back(80);
    my_deque1.push_front(90);
    my_deque1.pop_back();
    my_deque1.pop_front();

    cout << "back of my_deque1  : " << my_deque1.back() << "\n";
    cout << "front of my_deque1 : " << my_deque1.front() << "\n";
    cout << "is my_deque1 empty : " << my_deque1.empty() << "\n";
    cout << "is my_deque1 full  : " << my_deque1.full() << "\n\n";

    Deque<char> my_deque2;

    cout << "is my_deque2 empty : " << my_deque2.empty() << "\n";
    cout << "is my_deque2 full  : " << my_deque2.full() << "\n\n";
    my_deque2.push_back('A');
    my_deque2.push_back('B');
    my_deque2.push_front('C');
    my_deque2.push_front('D');

    cout << "back of my_deque2  : " << my_deque2.back() << "\n";
    cout << "front of my_deque2 : " << my_deque2.front() << "\n";
    cout << "is my_deque2 empty : " << my_deque2.empty() << "\n";
    cout << "is my_deque2 full  : " << my_deque2.full() << "\n\n";

    my_deque2.push_back('X');
    my_deque2.push_front('Y');
    my_deque2.push_back('Z');
    my_deque2.push_front('Q');
    my_deque2.pop_back();
    my_deque2.pop_front();

    cout << "back of my_deque2  : " << my_deque2.back() << "\n";
    cout << "front of my_deque2 : " << my_deque2.front() << "\n";
    cout << "is my_deque2 empty : " << my_deque2.empty() << "\n";
    cout << "is my_deque2 full  : " << my_deque2.full() << "\n\n";
}

template <class DequeType>
Deque<DequeType> :: Deque():front_(-1), rare_(-1), size_(1000){
    deque_ = new DequeType[1000];
}

template <class DequeType>
Deque<DequeType> :: Deque(int n) :front_(-1), rare_(-1), size_(n){
    deque_ = new DequeType[n];
}

template <class DequeType>
Deque<DequeType> :: ~Deque(){
    delete []deque_;
}

template <class DequeType>
bool Deque<DequeType> :: empty(){
    return rare_ == -1;
}

template <class DequeType>
bool Deque<DequeType> :: full(){
    return front_ == (rare_ + 1) % size_;
}

template <class DequeType>
DequeType Deque<DequeType> :: front(){
    if(empty()){
        cout << "Called front() when queue is empty.\n";
        abort();
    }
    return deque_[front_];
}

template <class DequeType>
DequeType Deque<DequeType> :: back(){
    if(empty()){
        cout << "Called back() when queue is empty.\n";
        abort();
    }
    return deque_[rare_];
}

template <class DequeType>
void Deque<DequeType> ::pop_back(){
    if(empty()){
        return;
    }
    if(rare_ == front_){
        front_ = rare_ = -1;
    }
    else if(rare_ == 0){
        rare_ = size_ - 1;
    }
    else{
        rare_--;
    }
}

template <class DequeType>
void Deque<DequeType> :: pop_front(){
    if(empty()){
        return;
    }
    if(rare_ == front_){
        front_ = rare_ = -1;
    }
    else{
        front_ = (front_ + 1) % size_;
    }
}

template <class DequeType>
void Deque<DequeType> :: push_back(DequeType el){
    if(full()){
        cout << "Deque is full\n";
        return;
    }
    if(front_ == -1){
        front_ = rare_ = 0;
    }
    else{
        rare_++;
    }
    deque_[rare_] = el;
}

template <class DequeType>
void Deque<DequeType> ::push_front(DequeType el){
    if(full()){
        cout << "Deque is full\n";
        return;
    }
    if(front_ == -1){
        front_ = rare_ = 0;
    }
    else if(front_ == 0){
        front_ = size_ - 1;
    }
    else{
        front_--;
    }
    deque_[front_] = el;
}
