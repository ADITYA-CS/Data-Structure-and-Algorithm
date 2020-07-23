#include <iostream>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int   data;
    int   height;

    Node();
    ~Node();
    Node(int);
};

class AVL{
private:
    Node* root_;

    Node* RotateLeft(Node*);
    Node* RotateRight(Node*);
    Node* RotateLeftRight(Node*);
    Node* RotateRightLeft(Node*);
    Node* Insert(Node*, int);
    Node* Delete(Node*, int);
    Node* Search(Node*, int);
    Node* MinNode(Node*);

    void  PreOrder(Node*);
    void  PostOrder(Node*);
    void  InOrder(Node*);
    void  Destroy(Node*);
    int   Height(Node*);
    int   BalanceFactor(Node*);

public:
    AVL();
    ~AVL();

    void PreOrder();
    void PostOrder();
    void InOrder();
    void Insert(int);
    void Delete(int);

    int Height();
    Node* Search(int);
};

int main() {}

Node::Node() : left(nullptr), right(nullptr), data(0), height(0) {}

Node::Node(int val) : left(nullptr), right(nullptr), data(val), height(0) {}

// Do not delete left and right pointer
// as they may result in deletion of left or right or both subtree
Node::~Node() {
  left = right = nullptr;
}

AVL::AVL() : root_(nullptr){}

AVL::~AVL(){
  Destroy(root_);
}

// delete all nodes in PostOrder manner
void  AVL::Destroy(Node* root) {
  if(!root)
    return;
  Destroy(root->left);
  Destroy(root->right);
  delete root;
}

// Wrapper for Height()
int AVL::Height() {
  return Height(root_);
}

// return the height of the tree
int AVL::Height(Node* root) {
  if (!root)
    return -1;
  return root->height;
}

// calculate balance factor
int AVL::BalanceFactor(Node* root) {
  return Height(root->left) - Height(root->right);
}

// rotate the tree right and update the height of nodes
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

// rotate the tree left and update the height of nodes
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

// rotate the tree left then rotate right and update the height of nodes
Node* AVL::RotateLeftRight(Node* parent) {
  parent->left = RotateLeft(parent->left);
  return RotateRight(parent);
}

// rotate the tree right then rotate left and update the height of nodes
Node* AVL::RotateRightLeft(Node* parent) {
  parent->right = RotateRight(parent->right);
  return RotateLeft(parent);
}

// wrapper for Insert()
void AVL::Insert(int el) {
  root_ = Insert(root_, el);
}

// Insert the element el, balances the tree
Node* AVL::Insert(Node* root, int el) {
  if  (!root) {
    return new Node(el);
  }

  if (el < root->data) { // add in left subtree
    root->left = Insert(root->left, el);
    // balance the tree when balance factor is 2
    if (BalanceFactor(root) == 2) {
      // when you add new element in left subtree of left child of root
      // then only rotate right
      if (el < root->left->data) {
        root = RotateRight(root);
      } else  { // otherwise rotate left then right
        root = RotateLeftRight(root);
      }
    }
  } else if (el > root->data) { // add in right subtree
    root->right = Insert(root->right, el);
    // balance the tree when balance factor is -2
    if (BalanceFactor(root) == -2) {
      // when you add new element in right subtree of right child of root
      // then only rotate left
      if (el > root->right->data) {
        root = RotateLeft(root);
      } else { // otherwise rotate right then left
        root = RotateRightLeft(root);
      }
    }
  }
  // always update the height
  root->height = max(Height(root->left), Height(root->right)) + 1;
  return root;
}

// Wrapper for PreOrder()
void AVL::PreOrder() {
  return PreOrder(root_);
}

// Here,i'm printing node data and balance factor of the node in PreOrder fashion
void AVL::PreOrder(Node*root) {
    if (!root) {
      return;
    }
    cout << "val = " << root->data << " " <<  "bf = "
      << BalanceFactor(root) << endl;
    PreOrder(root->left);
    PreOrder(root->right);
}

// Wrapper for PostOrder()
void AVL::PostOrder() {
  return PostOrder(root_);
}

// Here,i'm printing node data and balance factor of the node in PostOrder fashion
void AVL::PostOrder(Node*root) {
    if (!root) {
      return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << "val = " << root->data << " " <<  "bf = "
      << BalanceFactor(root) << endl;
}

// Wrapper for InOrder()
void AVL::InOrder() {
  return InOrder(root_);
}

// Here,i'm printing node data and balance factor of the node in InOrder fashion
void AVL::InOrder(Node*root) {
    if (!root) {
      return;
    }
    InOrder(root->left);
    cout << "val = " << root->data << " " <<  "bf = "
      << BalanceFactor(root) << endl;
    InOrder(root->right);
}

// Wrapper for Search()
Node* AVL::Search(int key) {
  return Search(root_, key);
}

// Return Node address when search is successful, otherwise nullptr
Node* AVL::Search(Node* root, int key) {
  if (!root)
    return nullptr;

  if (root->data == key)
    return root;

  if (root->data < key)
    return Search(root->right, key);

  return Search(root->left, key);
}

// Return address of left most node in inorder start from Node root
Node* AVL::MinNode(Node* root) {
  if (root->left)
    return MinNode(root->left);
  return root;
}

// Wrapper for Delete()
void AVL::Delete(int el) {
  root_ = Delete(root_, el);
}

// Delete an element el if found in the tree
Node* AVL::Delete(Node* root, int el) {
  if (!root) { // when there is no element el in the tree
    return root;
  } else if (root->data > el) { // when element is smaller, check left-subtree
    root->left = Delete(root->left, el);
    // when the balance factor is -2, rebalace it
    if (BalanceFactor(root) == -2) {
      // if balance factor of right child is not 1
      // then rotate left
      if (BalanceFactor(root->right) != 1) {
        root = RotateLeft(root);
      } else { // otherwise rotate right then rotate left
        root = RotateRightLeft(root);
      }
    }
  } else if (root->data < el) { // when element is larger, check right-subtree
    root->right = Delete(root->right, el);
    // when the balance factor is 2, rebalace it
    if (BalanceFactor(root) == 2) {
      // if balance factor of left child is not -1
      // then rotate right
      if (BalanceFactor(root->left) != -1) {
        root = RotateRight(root);
      } else { // otherwise rotate left then rotate right
        root = RotateLeftRight(root);
      }
    }
  } else { // when found the element el, delete it
    // case when node has both right and left child
    if (root->left && root->right) {
      auto successor = MinNode(root->right);
      root->data  = successor->data;
      root->right = Delete(root->right, el);
      if (BalanceFactor(root) == 2) {
        // if balance factor of left child is not -1
        // then rotate right
        if (BalanceFactor(root->left) != -1) {
          root = RotateRight(root);
        } else { // otherwise rotate left then rotate right
          root = RotateLeftRight(root);
        }
      }
    } else {
      auto temp = root;
      if (root->left) { // when node has only left child
        root = root->left;
      } else if (root->right) { // when node has only right child
        root = root->right;
      } else { // when node has no child
        root = nullptr;
      }
      delete temp;
    }
  }
  // only update the height when root is not null
  if(root) {
    root->height = max(Height(root->left), Height(root->right)) + 1;
  }
  return root;
}
