#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int INVERSE2 = (MOD + 1) / 2;


long long sigma(long long x) {
    x %= MOD;
    return ((x * (x + 1)) % MOD) * INVERSE2 % MOD;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    long long n;
    cin >> n;

    long long total = 0;
    for (long long i = 1; i * i <= n; i++) {
        total = (total + (n / i) * i) % MOD;
    }

    auto left = (long long) sqrt(n);
    for (long long i = left; i >= 1; i--) {

        long long right = n / i;
        long long sum = 0;
        sum = (sum + sigma(right)) % MOD;
        sum = (sum - sigma(left) + MOD) % MOD;
        sum = (sum * i) % MOD;

        total = (total + sum) % MOD;
        left = right;

    }

    cout << total << "\n";


    return 0;
}