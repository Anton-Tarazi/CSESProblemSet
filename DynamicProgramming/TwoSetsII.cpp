#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MOD_INVERSE = (MOD + 1) / 2;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int total = n * (n + 1) / 2;

    if (total % 2 == 1) {
        cout << "0\n";
        return 0;
    }

    total /= 2;
    vector<long long> dp(total + 1, 0);
    dp[0] = 1;

    for (int num = 1; num <= n; num++) {
        for (int amount = total - num; amount >= 0; amount--) {
            dp[amount + num] = (dp[amount + num] + dp[amount]) % MOD;
        }
    }

    cout << (dp[total] * MOD_INVERSE) % MOD << "\n";

    return 0;
}