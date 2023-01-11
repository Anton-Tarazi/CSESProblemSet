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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, b;
    cin >> n;
    while (n --> 0) {
        cin >> a >> b;
        cout << power(a, b) << "\n";
    }


    return 0;
}