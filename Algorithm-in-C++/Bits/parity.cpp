#include <iostream>
#include <cassert>

using namespace  std;

int Parity(int n) {
    bool parity = false;
    while(n) {
        parity = !parity;
        n &= n - 1;
    }
    return parity;
}

int main() {

    assert(Parity(9788)      == __builtin_parity(9788));
    assert(Parity(1)         == __builtin_parity(1));
    assert(Parity(88)        == __builtin_parity(88));
    assert(Parity(97)        == __builtin_parity(97));

    assert(Parity(8)         == __builtin_parity(8));
    assert(Parity(15)        == __builtin_parity(15));
    assert(Parity(100)       == __builtin_parity(100));
    assert(Parity(0)         == __builtin_parity(0));
}
