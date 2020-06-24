
/**
 * @author : Aditya Kumar Singh
 * Standard Trie
 */

// Todo: Delete function

// working with english alphabet
// storing only lower alphabet
#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26


struct Node{
    bool is_end_of_word;
    Node *letters[ALPHABET_SIZE];
    Node();
    Node(bool);
    ~Node();
};

class Trie{
private:
    Node *root_;
    bool HasChild(Node *);
    Node * Delete(Node *, const string &, int);
public:
    Trie();
    ~Trie();
    void Insert(string);
    bool Search(string);
    void Destroy(Node *);
    void Delete(string);
};


int main(){
    Trie t;
    string a[] = {"aditya", "kumar", "singh", "hello", "how", "are", "you", "kaju"};
    for(auto x : a){
        t.Insert(x);
    }
    cout << "-------------------\n";
    cout << t.Search("kumar") << "\n";
    t.Delete("kumar");
    cout << t.Search("kumar") << "\n";
    t.Insert("kumar");
    cout << t.Search("kumar") << "\n";
    cout << "-------------------\n";
    t.Insert("kaju");
    cout << t.Search("kaju") << "\n";
    t.Delete("kaju");
    cout << t.Search("kaju") << "\n";
    cout << "-------------------\n";
    cout << t.Search("ad") << "\n";
    t.Insert("ad");
    cout << t.Search("ad") << "\n";
    t.Delete("ad");
    cout << t.Search("ad") << "\n";
    t.Insert("ad");
    cout << t.Search("ad") << "\n";
    cout << "-------------------\n";
}
Node :: Node(){
    is_end_of_word = false;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        letters[i] = nullptr;
    }
}

Node :: Node(bool b){
    is_end_of_word = b;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        letters[i] = nullptr;
    }
}

Node :: ~Node(){
    //delete[] letters;
}

Trie :: Trie(){
    root_ = new Node(false);
}

Trie :: ~Trie(){
    Destroy(root_);
}

void Trie :: Destroy(Node *root){
    if(!root) return;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(!root->letters[i]){
            Destroy(root->letters[i]);
        }
    }
    delete root;
}

void Trie :: Insert(string word){
    int len = word.size();

    auto ptr = root_;
    for(int i = 0, index; i < len; i++){
        index = word[i] - 'a';
        if(!ptr->letters[index])
            ptr->letters[index] = new Node;
        ptr = ptr->letters[index];
    }
    ptr->is_end_of_word = true;
}

bool Trie :: Search(string word){
    if(!root_) return false;

    auto ptr = root_;
    for(int i = 0, len = word.size(), index; i < len; i++){
        index = word[i] - 'a';
        if(ptr->letters[index])
            ptr = ptr->letters[index];
        else
            return false;
    }
    return ptr && ptr->is_end_of_word;
}

bool Trie :: HasChild(Node *root){
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(root->letters[i])
            return true;
    }
    return false;
}

void Trie :: Delete(string key){
    if(!root_) return;
    root_ = Delete(root_, key, 0);
}


Node * Trie :: Delete(Node *root, const string &key, int key_index = 0){
    if(!root) return nullptr;

    // case when we are processing last letter of key
    if(key_index == key.size()){

        // if the key present in trie,
        // then switch off the flag
        if(root->is_end_of_word){
            root->is_end_of_word = false;
        }

        // if current node is not a prefix of any word
        // then, delete it
        if(!HasChild(root)){
            delete root;
            return nullptr;
        }
    }

    // recursivly check for current letter in key
    int index = key[key_index] - 'a';
    root->letters[index] = Delete(root->letters[index], key, key_index + 1);


    // if root has no child and root is not the end of any word,
    // then delete the root
    if(!HasChild(root) && !root->is_end_of_word){
        delete root;
        return nullptr;
    }

    // otherwise, return root
    return root;
}
