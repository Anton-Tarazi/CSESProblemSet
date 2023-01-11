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

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0};

    for (int i = 1; i < (1 << n); i++) {
        dp[i] = {n + 1, 0};
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                auto option = dp[i ^ (1 << j)];
                if (option.second + weights[j] <= x) {
                    option.second += weights[j];
                } else {
                    option.first++;
                    option.second = weights[j];
                }
                dp[i] = min(dp[i], option);
            }
        }
    }

    cout << dp[(1 << n) - 1].first << "\n";


    return 0;
}