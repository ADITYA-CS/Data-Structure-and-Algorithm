
/**
 * @author : Aditya Kumar Singh
 * Stack : Linked list implementation
 */

#include <iostream>
using namespace std;

template <class T>
struct Node{
    T data;
    Node *next;
    Node(T a){
        data = a;
    }
};


template <class StackType>
class Stack{
private:
    Node<StackType> *top_;
public:
    Stack();
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
    mychar.push('E');
    mychar.pop();
    cout << "mychar.top() is now " << mychar.top() << '\n';
    return 0;

}


template <class StackType>
Stack<StackType> :: Stack() : top_(NULL){}


template <class StackType>
void Stack<StackType> :: push(StackType object){
    auto temp = new Node<StackType>(object);
    temp->next = top_;
    top_ = temp;
}


template <class StackType>
void Stack<StackType> :: pop(){
    if(!empty()){
        auto temp = top_;
        top_ = top_->next;
        delete temp;
    }
}


template <class StackType>
StackType Stack<StackType> :: top(){
    try{
        if(empty()){
            throw 1;
        }
        return top_->data;
    }
    catch(int i){
        cout << "Called top() when stack is empty.\n";
        abort();
    }
}


template <class StackType>
bool Stack<StackType> :: empty(){
    return top_ == NULL;
}


template <class StackType>
bool Stack<StackType> :: isFull(){
    StackType a;
    auto temp = new Node<StackType>(a);
    if(temp){
        delete temp;
        return true;
    }
    return false;
}
