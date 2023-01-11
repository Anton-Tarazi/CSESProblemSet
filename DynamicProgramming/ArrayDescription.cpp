#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    const int MOD = 1e9 + 7;

    int m, n;
    cin >> n >> m;
    int nums[n];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (m == 1) {
        cout << "1\n";
        return 0;
    }

    int dp[n][m];
    if (nums[0] == 0) {
        for (int j = 0; j < m; j++) {
            dp[0][j] = 1;
        }
    } else {
        for (int j = 0; j < m; j++) {
            dp[0][j] = 0;
        }

        dp[0][nums[0] - 1] = 1;
    }


    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
        }

        int num = nums[i];
        if (num != 0) {
            int val = dp[i - 1][num - 1];
            if (num > 1)
                val = (val + dp[i - 1][num - 2]) % MOD;
            if (num < m)
                val = (val + dp[i - 1][num]) % MOD;

            dp[i][num - 1] = val;
        } else {

            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            for (int j = 1; j < m - 1; j++) {
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % MOD
                        + dp[i - 1][j + 1]) % MOD;
            }
            dp[i][m - 1] = (dp[i - 1][m - 2] + dp[i - 1][m - 1]) % MOD;

        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        ans = (ans + dp[n - 1][j]) % MOD;
    }

    cout << ans << "\n";


    return 0;
}