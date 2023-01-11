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

    int n, x, c;

    cin >> n >> x;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        cin >> c;
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= c) {
                (dp[i][j] += dp[i][j - c]) %= MOD;
            }
        }
    }

    cout << dp[n][x] << "\n";


    return 0;
}