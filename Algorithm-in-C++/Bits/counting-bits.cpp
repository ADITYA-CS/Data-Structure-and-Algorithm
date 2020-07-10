#include <iostream>
#include <cassert>

using namespace std;


int CountBits(int n) {
    int c = 0;
    while(n) {
        c += n & 1;
        n >>= 1;
    }
    return c;
}

// Brian Kernighan's approach
int Brian(int n) {
    int c = 0;
    while(n) {
        cout << n << " ";
        c++;
        n &= n - 1;
    }
    cout << "\n";
    return c;
}


int main() {
    assert(CountBits(9788)  == __builtin_popcount(9788));
    assert(CountBits(1)     == __builtin_popcount(1));
    assert(CountBits(88)    == __builtin_popcount(88));
    assert(CountBits(97)    == __builtin_popcount(97));

    assert(CountBits(8)     == __builtin_popcount(8));
    assert(CountBits(15)    == __builtin_popcount(15));
    assert(CountBits(100)   == __builtin_popcount(100));
    assert(CountBits(0)     == __builtin_popcount(0));

    assert(Brian(9788)      == __builtin_popcount(9788));
    assert(Brian(1)         == __builtin_popcount(1));
    assert(Brian(88)        == __builtin_popcount(88));
    assert(Brian(97)        == __builtin_popcount(97));

    assert(Brian(8)         == __builtin_popcount(8));
    assert(Brian(15)        == __builtin_popcount(15));
    assert(Brian(100)       == __builtin_popcount(100));
    assert(Brian(0)         == __builtin_popcount(0));
}
