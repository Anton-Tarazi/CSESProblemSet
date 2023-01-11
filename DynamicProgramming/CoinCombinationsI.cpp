#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int total = 1; total <= x; total++) {
        for (int c: coins) {
            if (total - c >= 0) {
                dp[total] = (dp[total] + dp[total - c]) % MOD;
            }
        }
    }

    cout << dp[x] << "\n";


    return 0;
}