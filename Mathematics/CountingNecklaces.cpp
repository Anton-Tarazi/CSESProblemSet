#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    long long total = 0;
    for (int k = 0; k < n; k++) {
        total = (total + power(m, gcd(k, n))) % MOD;
    }
    total = (total * inverse(n)) % MOD;

    cout << total << "\n";


    return 0;
}