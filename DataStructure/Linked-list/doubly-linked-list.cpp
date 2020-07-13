
/**
 * @author : Aditya Kumar Singh
 * Doubly linked list
 */

#include <iostream>
#include <stack>
#include <new>
using namespace std;


template <class NodeType>
struct Node{
    NodeType data;
    Node<NodeType> * next, *prev;
    Node(NodeType el);
    Node();
};


template <class ListType>
class List{
private:
    Node<ListType> *head_;
    Node<ListType> *tail_;
    int number_of_el;
public:
    List();
    Node<ListType> * search(ListType);
    void push_front(ListType);
    void push_back(ListType);
    void push_at(int, ListType);
    void pop_front();
    void pop_back();
    void pop_at(int);
    int  positon(ListType);
    void display();
    void rdisplay();
    ListType back();
    ListType front();
    void reverse();
};

int main(){
    List<int> li;

    li.push_front(10);
    li.push_back(20);
    li.push_at(4, 30);
    li.push_at(1, 30);

    li.display();
    li.rdisplay();

    cout << "Positon of 40 : " << li.positon(40) <<"\n";
    cout << "Positon of 30 : " << li.positon(30) <<"\n";
    cout << "Found 30 at memory location : " << li.search(20) <<"\n";
    li.push_back(70);
    li.push_back(60);
    li.push_front(80);
    li.push_back(50);

    li.display();
    li.rdisplay();

    li.pop_back();
    li.pop_front();
    li.pop_at(3);

    li.display();
    li.rdisplay();

    cout << "Front() : " << li.front() << "\n";
    cout << "Back()  : " << li.back() << "\n";
    cout << "Found 30 at memory location : " << li.search(100) <<"\n";
    li.reverse();

    li.display();
    li.rdisplay();

    cout << "Front() : " << li.front() << "\n";
    cout << "Back()  : " << li.back() << "\n";
}

template <class NodeType>
Node<NodeType> :: Node(){
    next = prev = nullptr;
}


template <class NodeType>
Node<NodeType> :: Node(NodeType el){
    next = prev = nullptr;
    data = el;
}


template <class ListType>
List<ListType> :: List(){
    head_ = tail_ = nullptr;
    number_of_el = 0;
}


template <class ListType>
Node<ListType> * List<ListType> :: search(ListType el){
    auto temp = head_;
    while(temp){
        if(temp->data == el){
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}


template <class ListType>
void List<ListType> :: push_front(ListType el){
    Node<ListType> *temp;
    try{
        temp = new Node<ListType>(el);
    } catch (const bad_alloc & e){
        cout << "In push_front(), Allocation failed: " << e.what() << "\n";
        return;
    }
    temp->next = head_;
    if(head_){
        head_->prev = temp;
    }
    head_ = temp;

    if(!tail_){
        tail_ = head_;
    }
    number_of_el++;
}


template <class ListType>
void List<ListType> ::push_back(ListType el){
    if(!tail_){
        push_front(el);
        return;
    }
    Node<ListType> *temp;
    try{
        temp = new Node<ListType>(el);
    } catch (const bad_alloc & e){
        cout << "In push_back(), Allocation failed: " << e.what() << "\n";
        return;
    }
    tail_->next = temp;
    temp->prev = tail_;
    tail_ = temp;
    number_of_el++;
}


template <class ListType>
void List<ListType> :: push_at(int n, ListType el){
    if(n > number_of_el){
        cout << "Out of range\n";
        return;
    }
    if(n == 0){
        push_front(el);
        return;
    } else if(n == number_of_el){
        push_back(el);
        return;
    }
    Node<ListType> *temp;
    try{
        temp = new Node<ListType>(el);
    } catch (const bad_alloc & e){
        cout << "In push_back(), Allocation failed: " << e.what() << "\n";
        return;
    }

    auto ptr = head_;
    for(int i = 0; i < n - 1; i++){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    temp->next->prev = temp;
    ptr->next = temp;
    number_of_el++;
}


template <class ListType>
void List<ListType> :: pop_front(){
    if(head_ == nullptr){
        return;
    }
    if(head_ == tail_){
        delete head_;
        head_ = tail_ = nullptr;
    }
    auto temp = head_;
    head_ = head_->next;
    head_->prev = nullptr;
    delete temp;
    number_of_el--;
}


template <class ListType>
void List<ListType> :: pop_back(){
    if(head_ == nullptr){
        return;
    }
    if(head_ == tail_){
        delete head_;
        head_ = tail_ = nullptr;
    }
    auto temp = tail_;
    tail_ = tail_->prev;
    tail_->next = nullptr;
    delete temp;
}


template <class ListType>
void List<ListType> :: pop_at(int n){
    if(n > number_of_el){
        cout << "Out of range\n";
        return;
    }
    if(n == 0){
        pop_front();
        return;
    } else if(n == number_of_el - 1){
        pop_back();
        return;
    }

    auto ptr = head_;
    for(int i = 0; i < n - 1; i++){
        ptr = ptr->next;
    }
    auto temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    delete temp;
    number_of_el--;
}


template <class ListType>
void List<ListType> :: display(){
    auto ptr = head_;
    cout << "List : [";
    while(ptr){
        cout << ptr->data;
        if(ptr != tail_){
            cout << ", ";
        }
        ptr = ptr->next;
    }
    cout << "]\n";
}


template <class ListType>
void List<ListType> :: rdisplay(){
    auto ptr = head_;
    stack<ListType> st;
    while(ptr){
        st.push(ptr->data);
        ptr = ptr->next;
    }
    cout << "List : [";
    if(st.size() == 0){
        cout << "]\n";
        return;
    }
    while(st.size() != 1){
        cout << st.top() << ", ";
        st.pop();
    }
    cout << st.top() << "]\n";
    st.pop();
}


template <class ListType>
ListType List<ListType> :: back(){
    if(!tail_){
        cout << "Called back() when list is empty\n";
        abort();
    }
    return tail_->data;
}


template <class ListType>
ListType List<ListType> :: front(){
    if(!tail_){
        cout << "Called front() when list is empty\n";
        abort();
    }
    return head_->data;
}


template <class ListType>
int List<ListType> :: positon(ListType el){
    int pos = -1;
    auto ptr = head_;
    while(ptr){
        pos++;
        if(ptr->data == el){
            return pos;
        }
        ptr = ptr->next;
    }
    return -1;
}

template <class ListType>
void List<ListType> :: reverse(){
    if(!head_ || head_ == tail_){
        return;
    }
    tail_ = head_;
    auto ptr = head_;
    Node<ListType> *temp;
    while(ptr){
        head_ = ptr;
        temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;
        ptr = ptr->prev;
    }
}
