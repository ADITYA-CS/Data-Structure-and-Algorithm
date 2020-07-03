/*
 * @author : Aditya Kumar Singh
 * Disjoint set : Union by rank
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DisjointSet{
private:
    vector<int> parent_;
    vector<int> rank_;

public:
    explicit DisjointSet(int);
    void MakeSet(int);
    int Find(int);
    void Union(int, int);
};


DisjointSet::DisjointSet(int sz) {
    parent_.resize(sz);
    rank_.resize(sz);
    for (int i = 0; i < sz; i++) {  // make set for each element
        MakeSet(i);
    }
}

void DisjointSet::MakeSet(int x) { // make a set of one element
    parent_[x] = x;
    rank_[x] = 0;
}

int DisjointSet::Find(int x) { // find the root of the set
    while (x != parent_[x]) {
        x = parent_[x];
    }
    return x;
}

void DisjointSet::Union(int x, int y) { // union two sets
    int x_set = Find(x);
    int y_set = Find(y);

    if (x_set == y_set) { // when x and y are in same set
        return;
    } else if (rank_[x_set] > rank_[y_set]) {
        parent_[y_set] = x_set;
    } else if (rank_[x_set] < rank_[y_set]) {
        parent_[x_set] = y_set;
    } else { // when both set have same rank
        parent_[x_set] = y_set;
        rank_[x_set]++;
    }
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
