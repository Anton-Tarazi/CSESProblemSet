#include <bits/stdc++.h>

using namespace std;

#define MAX_VAL (int) (1e6)
constexpr int MOD = 1e9 + 7;
long long factorials[MAX_VAL + 1];

static inline long long power(long long a, int b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return result;
}

static inline long long inverse(long long a) {
    return power(a, MOD - 2);
}

static inline long long binomial_coefficient(int a, int b) {
    long long numerator = factorials[a];
    long long denominator = factorials[b] * factorials[a - b] % MOD;
    return numerator * inverse(denominator) % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    factorials[0] = 1;
    for (int i = 1; i <= MAX_VAL; i++) {
        factorials[i] = (factorials[i - 1] * i) % MOD;
    }


    int n, a, b;
    cin >> n;

    while (n --> 0) {
        cin >> a >> b;
        cout << binomial_coefficient(a, b) << "\n";

    }


    return 0;
}