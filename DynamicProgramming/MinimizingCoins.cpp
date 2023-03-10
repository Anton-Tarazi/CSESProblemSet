#include <bits/stdc++.h>

using namespace std;


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

    vector<int> dp(x + 1, x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int c: coins) {
            if (i >= c) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }

    }

    cout << (dp[x] == x + 1 ? -1 : dp[x]) << "\n";

    return 0;
}