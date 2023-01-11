#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int MOD = 1e9 + 7;
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {

        int options = 0;
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                options = (options + dp[i - j]) % MOD;
            }
        }

        dp[i] = options;
    }

    cout << dp[n] << "\n";

    return 0;
}