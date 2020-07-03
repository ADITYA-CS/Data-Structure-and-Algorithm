/**
 * @author : Aditya Kumar Singh
 * Quick Find
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class DisjointSet{
private:
    vector<int> set_;

public:
    DisjointSet(int);
    void MakeSet(int);
    int Find(int);
    void Union(int, int);
};

DisjointSet::DisjointSet(int sz){
    set_.resize(sz);
    for (int i = 0; i < sz; i++) { // make set for each element
        MakeSet(i);
    }
}


void DisjointSet::MakeSet(int x) { // make a set of one element
    set_[x] = x; // set the set id of x to x
}

void DisjointSet::Union(int x, int y) {  // union two sets
    int x_id = Find(x);
    int y_id = Find(y);

    // if x and y are in same set, then do nothing
    if (x_id == y_id)
        return;

    int m = min(x_id, y_id);
    for (int i = 0; i < set_.size(); i++) {
        // if the element are size set containg x or y
        // then assignt their set id to m
        if(set_[i] == x_id || set_[i] == y_id){
            set_[i] = m;
        }
    }
}

int DisjointSet::Find(int x) {
    return set_[x];
}

int main() {
    //  Example set
    // {0}, {9,3,2,4,7}, {5}, {6,1,8}
    //
    DisjointSet set(10);
    assert(set.Find(0) == 0);
    assert(set.Find(2) != set.Find(5));

    set.Union(9,3);
    set.Union(2,4);
    assert(set.Find(3) != set.Find(4));
    assert(set.Find(2) == set.Find(4));

    set.Union(9,7);
    set.Union(2,9);
    assert(set.Find(3) == set.Find(7));
    assert(set.Find(9) == set.Find(4));

    set.Union(6,8);
    set.Union(1,8);
    assert(set.Find(1) == set.Find(6));
    assert(5 == set.Find(5));
}
