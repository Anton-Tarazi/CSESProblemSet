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

    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][1] = 1;

    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '.') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n][n] << "\n";


    return 0;
}