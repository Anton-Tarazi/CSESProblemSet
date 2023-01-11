#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long a, int b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return result;
}

long long inverse(long long a) {
    return power(a, MOD - 2);
}

long long factorial(int x) {
    long long result = 1;
    for (int i = 1; i <= x; i++) {
        result = (result * i) % MOD;
    }

    return (int) result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << "0\n";
        return 0;
    }

    long long numerator = factorial(n);
    long long fact = factorial(n / 2);
    long long denominator = ((n / 2 + 1) * ((fact * fact) % MOD)) % MOD;

    long long cn = numerator * inverse(denominator) % MOD;
    cout << cn << "\n";


    return 0;
}