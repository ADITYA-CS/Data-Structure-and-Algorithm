/**
 * @Author: Aditya Kumar Singh <the__martian>
 * @Email:  cr7.aditya.cs@gmail.com
 * @Last modified by:   the__martian
 */



/*
 *
 *   Stack : Array implementation
 *
 */

#include <iostream>
using namespace std;

template <class StackType>
class Stack{
private:
    StackType* st_;
    int size_;
    int top_;
public:
    Stack();
    Stack(int);
    void push(StackType);
    void pop();
    StackType top();
    bool empty();
    bool isFull();
};

int main(int argc, char const *argv[]) {
    Stack<int>  mystack;
    //cout << "mystack.top() is now " << mystack.top() << '\n';
    mystack.push(10);
    mystack.push(20);

    cout << "mystack.top() is now " << mystack.top() << '\n';

    mystack.push(30);
    mystack.push(40);

    cout << "mystack.top() is now " << mystack.top() << '\n';

    Stack<char> mychar;
    //cout << "mychar.top() is now " << mychar.top() << '\n';
    mychar.push('A');
    mychar.push('B');

    cout << "mychar.top() is now " << mychar.top() << '\n';

    mychar.push('C');
    mychar.push('D');

    cout << "mychar.top() is now " << mychar.top() << '\n';
    return 0;

}

template <class StackType>
Stack<StackType> :: Stack() : size_(1000), top_(-1){
    st_ = new StackType[size_];
}


template <class StackType>
Stack<StackType> :: Stack(int n) : size_(n), top_(-1){
    st_ = new StackType[size_];
}


template <class StackType>
void Stack<StackType> :: push(StackType object){
    try{
        if(isFull())
            throw "Stack if full.\n";
        top_++;
        st_[top_] = object;
    }
    catch(const char * s){
        cout << s;
    }
}


template <class StackType>
void Stack<StackType> :: pop(){
    if(empty()){
        return;
    }
    top_--;
}


template <class StackType>
StackType Stack<StackType> :: top(){
    try{
        if(empty()){
            throw 1;
        }
        return st_[top_];
    }
    catch(int i){
        cout << "Called top() when stack is empty.\n";
        abort();
    }
}


template <class StackType>
bool Stack<StackType> :: empty(){
    return top_ == -1;
}


template <class StackType>
bool Stack<StackType> :: isFull(){
    return top_ == size_ - 1;
}
