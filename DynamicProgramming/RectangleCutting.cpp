#include <bits/stdc++.h>

using namespace std;

#define MAX_N 500

int dp[MAX_N + 1][MAX_N + 1];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    constexpr int max_moves = MAX_N * MAX_N;

    int a, b;
    cin >> a >> b;

    int x = max(a, b);
    int y = min(a, b);

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            dp[i][j] = i == j ? 0 : max_moves;
        }
    }

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= i; j++) {
            if (dp[i][j] == max_moves) {
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                }
            }

            dp[j][i] = dp[i][j];
        }
    }

    cout << dp[x][y] << "\n";

    return 0;
}