/**
 * @author :    Aditya Kumar Singh
 * Quick Find
 */

#include <iostream>
using namespace std;

class DisjointSet{
private:
    int *set_;
    int size_;
public:
    DisjointSet(int);
    void MakeSet(int);
    int Find(int);
    void Union(int, int);
};

int main(){
    cout << "Set(s)\n";
    cout << "{0}, {9,3,2,4,7}, {5}, {6,1,8}\n";
    int n = 10;
    DisjointSet ds(n);
    for(int i = 0; i < n; i++)
       ds.MakeSet(i);
    ds.Union(9,3);
    ds.Union(2,4);
    ds.Union(9,7);
    ds.Union(2,9);
    ds.Union(6,8);
    ds.Union(1,8);

    if(ds.Find(9) == ds.Find(2))
       cout << 9 << " and " << 2 << " are in same set.\n";
    else
       cout << 9 << " and " << 2 << " are not in same set.\n";

    if(ds.Find(7) == ds.Find(5))
       cout << 7 << " and " << 5 << " are in same set.\n";
    else
       cout << 7 << " and " << 5 << " are not in same set.\n";

    if(ds.Find(1) == ds.Find(8))
       cout << 1 << " and " << 8  << " are in same set.\n";
    else
       cout << 1 << " and " << 8  << " are not in same set.\n";

    if(ds.Find(5) == ds.Find(0))
       cout << 5 << " and " << 0 << " are in same set.\n";
    else
       cout << 5 << " and " << 0 << " are not in same set.\n";
}


DisjointSet :: DisjointSet(int n) : size_(n){
    set_ =  new int[n];
}


void DisjointSet :: MakeSet(int x){
    // out of range, throw exception
    if(x < 0 || x >= size_){
        throw "Out of range";
    }
    set_[x] = x; // set the set id of x to x
}

void DisjointSet :: Union(int x, int y){

    int x_id, y_id; // to store the x, y set id

    // out of range, throw exception
    try{
        if(x < 0 || y < 0 || x >= size_ || y >= size_){
            throw "Out of range";
        }
        x_id = Find(x);
        y_id = Find(y);
    } catch(const char * e){
        cerr << e << '\n';
        cerr << "Union operatin failed" << '\n';
        return;
    }

    // if x and y are in same set, then do nothing
    if(x_id == y_id) return;

    int m = min(x_id, y_id);

    for(int i = 0; i < size_; i++){
        // if the element are size set containg x or y
        // then assignt their set id to m
        if(set_[i] == x_id || set_[i] == y_id){
            set_[i] = m;
        }
    }
}

int DisjointSet :: Find(int x){
    // out of range, throw exception
    if(x < 0 || x >= size_){
        throw "Out of range";
    }
    return set_[x];
}
