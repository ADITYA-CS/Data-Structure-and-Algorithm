#include <iostream>

using namespace std;

long long ncr(long long n, long long r) {
    if(r > n) return 0;
    if(r == 0 || r == n)
        return 1;

    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}

long long BinomialCoefficient(long long n, long long r) {
    if (r > n)
        return (long long) 0;
    if (r == 0 || r == n)
        return (long long) 1;

    r = min(r, n - r);
    long long res = 1;
    for (long long i = 1; i <= r; i++) {
        res *= (n - r + i);
        res /= i;
    }

    return res;
}

int main() {
    long long n, r;
    cout << "n : ";
    cin >> n;
    cout << "r : ";
    cin >> r;
    cout << "Result : " << BinomialCoefficient(n, r) << "\n";
}
