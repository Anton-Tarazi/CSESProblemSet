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
    vector<int> prices(n + 1);
    vector<int> pages(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> prices[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> pages[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - prices[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i]] + pages[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][x] << "\n";


    return 0;
}