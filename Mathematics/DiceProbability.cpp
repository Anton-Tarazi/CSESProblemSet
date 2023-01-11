#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
#define MAX_B (6 * MAX_N)

double dp[MAX_N + 1][MAX_B + 1];
const double one_sixth = (double) 1/6;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif

    int n, a, b;
    cin >> n >> a >> b;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= b; j++) {
            double prob = 0;
            for (int last_dice = 1; last_dice <= 6; last_dice++) {
                if (j - last_dice >= 0) {
                    prob += one_sixth * dp[i - 1][j - last_dice];
                }
            }

            dp[i][j] = prob;

        }
    }

    double ans = 0;
    for (int j = a; j <= b; j++) {
        ans += dp[n][j];
    }


    printf("%.6f\n", ans);

    return 0;
}