#include <bits/stdc++.h>

using namespace std;

#define ONES_TURN(i, j, n) (((j) - (i) + 1) % 2 == ((n) % 2))


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(n));
    if (ONES_TURN(0, 0, n))
        for (int i = 0; i < n; i++) dp[i][i].first = nums[i];
    else
        for (int i = 0; i < n; i++) dp[i][i].second = nums[i];


    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {

            if (ONES_TURN(i, j, n)) {
                long long take_left = nums[i] + dp[i + 1][j].first;
                long long take_right = nums[j] + dp[i][j - 1].first;

                if (take_left > take_right) {
                    dp[i][j].first = take_left;
                    dp[i][j].second = dp[i + 1][j].second;
                } else {
                    dp[i][j].first = take_right;
                    dp[i][j].second = dp[i][j - 1].second;
                }

            } else {
                long long take_left = nums[i] + dp[i + 1][j].second;
                long long take_right = nums[j] + dp[i][j - 1].second;

                if (take_left > take_right) {
                    dp[i][j].second = take_left;
                    dp[i][j].first = dp[i + 1][j].first;
                } else {
                    dp[i][j].second = take_right;
                    dp[i][j].first = dp[i][j - 1].first;
                }

            }
        }
    }

    cout << dp[0][n - 1].first << "\n";


    return 0;
}