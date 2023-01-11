#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    string s, p;
    cin >> s >> p;

    int m = (int) s.size();
    int n = (int) p.size();

    int dp[m + 1][n + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j - 1] + 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                   min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    cout << dp[m][n] << "\n";

    return 0;
}