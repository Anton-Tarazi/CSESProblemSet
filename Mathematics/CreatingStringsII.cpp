#include <bits/stdc++.h>

using namespace std;

#define LETTERS 26
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

    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int counts[LETTERS];
    for (int &count: counts) {
        count = 0;
    }

    string s;
    cin >> s;
    for (char &c: s) {
        counts[c - 'a']++;

    }

    long long ans = factorial((int) s.size());
    for (int count : counts) {
        if (count > 1)
            ans = (ans * inverse(factorial(count))) % MOD;
    }

    cout << ans << "\n";

    return 0;
}