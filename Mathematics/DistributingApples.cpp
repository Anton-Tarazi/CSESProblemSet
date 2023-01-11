#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

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


long long binomial_coefficient(int a, int b) {
    long long numerator = factorial(a);
    long long denominator = factorial(b) * factorial(a - b) % MOD;
    return numerator * inverse(denominator) % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    cout << binomial_coefficient(n + m - 1, m) << "\n";


    return 0;
}