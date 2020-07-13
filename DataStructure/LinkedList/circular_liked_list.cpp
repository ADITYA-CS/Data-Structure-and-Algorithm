/**
 * @author : Aditya Kumar Singh
 * Doubly circular list
 */

#include <iostream>
#include <algorithm>

using namespace std;

template <class NodeType>
struct Node {
  NodeType data;
  Node<NodeType> *prev, *next;
  Node();
  Node(NodeType);
};


template <class ListType>
class CircularList {
private:
  Node<ListType> *tail_;
public:
  CircularList();
  Node<ListType> * search(ListType);
  void PushFront(ListType);
  void PushBack(ListType);
  void PopFront();
  void PopBack();
  void Display();
  void RDisplay();
  void Reverse();
};


int main() {
  CircularList<int> li;
  li.PushFront(10);
  li.PushFront(20);
  li.PushFront(40);
  li.Display();
  li.RDisplay();
  li.PushBack(30);
  li.PushBack(50);
  li.PushFront(70);
  li.PushFront(80);
  li.PushFront(99);
  li.Display();
  li.RDisplay();
  li.Reverse();
  li.Display();
  li.RDisplay();
}

template <class NodeType>
Node<NodeType>::Node() {
  prev = next = nullptr;
}

template <class NodeType>
Node<NodeType>::Node(NodeType el) {
  prev = next = nullptr;
  data = el;
}

template <class ListType>
CircularList<ListType>::CircularList() {
  tail_ = nullptr;
}

template <class ListType>
void CircularList<ListType>::PushFront(ListType el) {
  if (!tail_) {
    tail_ = new Node<ListType>(el);
    tail_->next = tail_->prev = tail_;
    return;
  }

  auto temp = new Node<ListType>(el);
  // case when there is only one node
  if (tail_->prev == tail_) {
    tail_->prev = temp;
    tail_->next = temp;
    temp->prev = tail_;
    temp->next = tail_;
  } else { // case when there is more than one node
    temp->prev = tail_;
    temp->next = tail_->next;
    tail_->next->prev = temp;
    tail_->next = temp;
  }
}

template <class ListType>
void CircularList<ListType>::PushBack(ListType el) {
  if (!tail_) {
    PushFront(el);
    return;
  }
  PushFront(el);
  tail_ = tail_->next;
}

template <class ListType>
void CircularList<ListType>::Display() {
  cout << "List : [";
  if (!tail_) {
    cout << "]\n";
    return;
  }

  Node<ListType> *ptr = tail_->next;
  while (ptr != tail_) {
    cout << ptr->data << ", ";
    ptr = ptr->next;
  }

  cout << tail_->data << "]\n";
}

template <class ListType>
void CircularList<ListType>::PopFront() {
  if (!tail_)
    return;

  // case when there is only one node
  if (tail_->next == tail_) {
    delete tail_;
    tail_ =  nullptr;
    return;
  }

  auto temp =  tail_->next;

  // case when there is only two node
  if(temp->next == tail_) {
    tail_->prev = tail_->next = tail_;
  } else { // case when there is more than two node
    temp->next->prev = tail_;
    tail_->next = temp->next;
  }

  delete temp;
}

template <class ListType>
void CircularList<ListType>::PopBack() {
  if (!tail_)
    return;

  // when there is only one node
  if (tail_->next == tail_) {
    delete tail_;
    tail_ = nullptr;
    return;
  }

  tail_ = tail_->prev;
  PopFront();
}

template <class ListType>
Node<ListType> * CircularList<ListType>::search(ListType key) {
  if(!tail_)
    return nullptr;

  auto ptr = tail_;
  do {
    if (ptr->data == key) {
      return ptr;
    }
    ptr = ptr->next;
  } while (ptr != tail_);

  return nullptr;
}

template <class ListType>
void CircularList<ListType>::RDisplay() {
  cout << "List in reverse order : [";
  if (!tail_) {
    cout << "]\n";
    return;
  }

  Node<ListType> *ptr = tail_;
  while (ptr->prev != tail_) {
    cout << ptr->data << ", ";
    ptr = ptr->prev;
  }

  cout << ptr->data << "]\n";
}

template <class ListType>
void CircularList<ListType>::Reverse() {
  // when there is less than 3 elements, then do not nothing as
  // they already satifies the condittion
  if(!tail_ || tail_->next == tail_->prev) {
    return;
  }

  auto ptr = tail_->next;
  auto br = tail_->next;
  do {
    auto temp = ptr->next;
    ptr->next = ptr->prev;
    ptr->prev = temp;
    ptr = ptr->prev;
  } while (ptr != br);
  tail_ = br;
}
