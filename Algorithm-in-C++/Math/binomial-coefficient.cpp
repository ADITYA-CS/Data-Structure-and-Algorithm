#include <iostream>

using namespace std;

long long ncr(long long n, long long r) {
    if(r > n) return 0;
    if(r == 0 || r == n)
        return 1;

    return ncr(n - 1, k - 1) + ncr(n - 1, k);
}

long long BinomialCoefficient(long long n, long long r) {
    if (r > n)
        return (long long) 0;
    if (r == 0 || r == n)
        return (long long) 1;
    if (2 * r > n) // use symmetry
        r = n - r;

    long long num = n - r + 1;
    long long res = num;
    for (long long i = 2; i <= r; i++) {
        num++;
        res *= num;
        res /= i;
    }

    return res;
}

int main() {
    long long n, r;
    cout << "Calcaulate\n";
    cout << "n\n";
    cout << "  C\n";
    cout << "   r\n\v";
    cout << "n : ";
    cin >> n;
    cout << "r : ";
    cin >> r;
    cout << "Result : " << BinomialCoefficient(n, r) << "\n";
}
