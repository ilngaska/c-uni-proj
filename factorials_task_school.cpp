#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int countFactorizations(int n) {
    if (isPrime(n)) {
        return 0;
    }
    int count = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++count;
            n /= i;
        }
    }
    if (n > 1) {
        ++count;
    }
    return count;
}
int main() {
    int N;
    cin >> N;
    int result = countFactorizations(N);
    cout << result << endl;
    return 0;
}
