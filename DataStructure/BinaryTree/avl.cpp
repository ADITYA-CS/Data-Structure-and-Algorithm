#include <iostream>

using namespace std;

struct Node{
    Node *left;
    int data;
    Node *right;
    int height;
    Node();
    Node(int);
    ~Node();
};

class AVL{
private:
    Node* root_;

    Node* RotateLeft(Node*);
    Node* RotateRight(Node*);
    Node* RotateLeftRight(Node*);
    Node* RotateRightLeft(Node*);
    Node* Insert(Node *, Node *, int);

    void PreOrder(Node *);
    void PostOrder(Node *);
    void InOrder(Node *);
    int Height(Node*);


public:
    AVL();
    ~AVL();

    void PreOrder();
    void PostOrder();
    void InOrder();
    void Insert(int);

    int Height();
};

int main() {
  int t = -1, el;
  AVL avl;
  while (t) {
    if (t == 1)  {
      cin >> el;
      avl.Insert(el);
    } else if (t == 2) {
      avl.PreOrder();
    } else if (t == 3) {
      avl.PostOrder();
    } else if (t == 4) {
      avl.InOrder();
    }
    cin >> t;
  }
}

Node::Node() {
    left    = nullptr;
    right   = nullptr;
    data    = 0;
    height  = 0;
}

Node::Node(int val) {
    left    = nullptr;
    right   = nullptr;
    data    = val;
    height  = 0;
}

Node::~Node(){
    delete left;
    delete right;
}

AVL::AVL(){
  root_ = nullptr;
}
AVL::~AVL() {
  delete root_;
}

Node* AVL::RotateRight(Node* parent) {
    Node* left_child    = parent->left;
    parent->left        = left_child->right;
    left_child->right   = parent;

    parent->height      = max(Height(parent->left),
        Height(parent->right)) + 1;
    left_child->height  = max(Height(left_child->left),
        Height(left_child->right)) + 1;
    return left_child;
}

Node* AVL::RotateLeft(Node* parent) {
    Node* right_child   = parent->right;
    parent->right       = right_child->left;
    right_child->left   = parent;

    parent->height      = max(Height(parent->left),
        Height(parent->right)) + 1;
    right_child->height = max(Height(right_child->left),
        Height(right_child->right)) + 1;
    return right_child;
}

Node* AVL::RotateLeftRight(Node* parent) {
  parent->left = RotateLeft(parent->left);
  return RotateRight(parent);
}

Node* AVL::RotateRightLeft(Node* parent) {
  parent->right = RotateRight(parent->right);
  return RotateLeft(parent);
}

int AVL::Height(Node* root) {
  if (!root)
    return -1;
  return root->height;
}

void AVL::Insert(int el) {
  root_ = Insert(root_, nullptr, el);
}
Node * AVL::Insert(Node * root, Node * parent, int el) {
  if  (!root) {
    return new Node(el);
  }

  if (el < root->data) {
    root->left = Insert(root->left, root, el);
    if (Height(root->left) - Height(root->right) == 2) {
      if (el < root->left->data) {
        root = RotateRight(root);
      } else  {
        root = RotateLeftRight(root);
      }
    }
  } else if (el > root->data) {
    root->right = Insert(root->right, root, el);
    if (Height(root->left) - Height(root->right) == -2) {
      if (el < root->right->data) {
        root = RotateLeft(root);
      } else {
        root = RotateRightLeft(root);
      }
    }
  }
  root->height = max(Height(root->left), Height(root->right)) + 1;
  return root;
}

int AVL::Height() {
  return Height(root_);
}



void AVL::PreOrder() {
  return PreOrder(root_);
}
void AVL::PostOrder() {
  return PostOrder(root_);
}
void AVL::InOrder() {
  return InOrder(root_);
}

void AVL::PreOrder(Node *root) {
    if (!root) {
      return;
    }
    cout << "val = " << root->data << " " <<  "bf = "
      << Height(root->left) - Height(root->right) << endl;
    PreOrder(root->left);
    PreOrder(root->right);
}
void AVL::PostOrder(Node *root) {
    if (!root) {
      return;
    }
    PostOrder(root->right);
    PostOrder(root->left);
    cout << "val = " << root->data << " " <<  "bf = "
      << Height(root->left) - Height(root->right) << endl;
}
void AVL::InOrder(Node *root) {
    if (!root) {
      return;
    }
    InOrder(root->left);
    cout << "val = " << root->data << " " <<  "bf = "
      << Height(root->left) - Height(root->right) << endl;
    InOrder(root->right);
}
